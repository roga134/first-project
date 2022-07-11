



#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
using std::getline;


class gradebook
{
    public :

        void setcoursename (string name)
        {
            coursename = name;
        }


        string getcoursename()
        {
            return coursename;
        }


        void dismassage ()
        {


        cout << "welcom to grade bool for \n" << getcoursename() << "!"
        << endl ;
        }
    private:
        string coursename ;
};


int main()
{
    string nameofcourse ;
    gradebook mygradebook ;


    cout << "initial course name is: " << mygradebook.getcoursename()
    <<endl ;


    cout << "\npleaseenter the course name:" << endl ;
    getline(cin , nameofcourse);
    mygradebook.setcoursename(nameofcourse);

    cout << endl ;
    mygradebook.dismassage();
    return 0 ;
}
