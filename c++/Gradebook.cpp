


#include <iostream>
using std::cout;
using std::endl;

#include "Gradebook.h"


Graidbook::Graidbook(string name)
{
    setcourecename(name);
}


void Graidbook::setcourecename(string name)
{
    namecource = name ;
}


string Graidbook::getcourcename()
{
    return namecource ;
}


void Graidbook::dismassage()
{

    cout << "welcome the grade book for\n" << getcourcename()
    <<"!" << endl ;
}
