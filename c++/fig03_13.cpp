


#include <iostream>
using namespace std;

#include "Gradebook.h"


int main()
{

    Graidbook graidbook1("cs101");
    Graidbook graidbook2("cs102");


    cout << "grade book one creat for cource: " << graidbook1.getcourcename()
    << "\ngrade book two create for cource: " << graidbook2.getcourcename()
    << endl ;
    return 0 ;
}
