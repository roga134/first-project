#include <iostream>
using namespace std;

int main() {
  char a = 65 , b = 66 , c = 67 , d = 68 ;
  cout << a  ;
  cout << b  ;
  cout << c  ;
  cout << d  ;
  int x , y;
  cout << "type your number \n" ;
  cin >> x ;
  cout << "type another number \n" ;
  cin >> y ;
  ++y;
  --x;
  cout << y << x  <<"\n" ;
  cout << x + y << "\n" ;
  return  0;
}
