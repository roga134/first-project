#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;

class human
{
    public :
        void mmad(string namecource)
        {
            cout << namecource ;
        }
};

int main() {
    string mmad;
    cout << "enter your name : \n" ;
    getline(cin , mmad) ;
    human myhuman;
    myhuman.mmad(mmad);
    return 0 ;
}
