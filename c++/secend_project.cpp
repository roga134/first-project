#include <iostream>

using namespace std;



class gradebook
{
	public:
		void setmassage(int hi)
		{
			hi = number1;
		}
		void setmassage2(int hi2)
		{
            hi2 = number2;
		}
		string getmassage()
		{
            return hi1 + hi2 ;
		}
    private:
        int number1 , number2;
} ;


int main()
{
    int c , q;
	gradebook mygradebook ;
	mygradebook.setmassage(c);
	mygradebook.setmassage2(q);
	cout << "enter first number : \n ";
	cin >> c ;
	cout << "enter secend number : \n";
	cin >> q ;
	mygradebook.getmassage();
	return 0 ;
}
