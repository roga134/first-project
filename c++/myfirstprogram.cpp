#include <iostream>
#include <string>
using namespace std;

int main() {
  printf("Hellow world \n");
  string o ;
  string q = "can you type any things with out space?";
  string w = "size your sentes is :" ;
  char  g = 72 ,  p = 73 ;
  cout << g << p << "\n";
  cout << "type your number \n" ;
  int x , y ;
  cin >> x ;
  cout << "type another number \n" ;
  cin >> y ;
  ++y;
  --x;
  cout << y <<"\n"<< x  <<"\n" ;
  cout << x + y << "\n" ;
  cout << q << "\n" ;
  cin >> o  ;
  cout << w << o.size() << "\n";
  cout << o ;
  return  0;
}
// Outputs 1 (true)
// Outputs 0 (false)

//int x = 5;
//int y = 3;
//cout << (x > y); // returns 1 (true) because 5 is greater than 3
//return 0;
//== 	 	x == y
//!= 	 	x != y
//> 	 	x > y
//< 	 	x < y
//>= 	 	x >= y
//<= 	 	x <= y
// && = and    || = or     ! = not
// for plus two str we can use + or x.append(y) but append is better
//string myString = "Hello";
//myString[0] = 'J';
//cout << myString;
// Outputs Jello instead of Hello


