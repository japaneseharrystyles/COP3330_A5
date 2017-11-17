#include "mystring.h"

int main () {

  const char* cstring = "apple";

  MyString d;
  MyString c(cstring);
  MyString i(12345);
  MyString copy(i);
  MyString in;

  cout << "MyString d: " << d << endl;
  cout << "MyString c: " << c << endl;
  cout << "MyString i: " << i << endl;
  cout << "MyString copy: " << copy << endl;

  d = "zebra";
  cout << "MyString d: " << d << endl;
  
  //cout << "Input a string: ";
  //cin >> in;
  cout << "MyString in: " << in << endl;
  cout << "Comparing MyString d: " << d << " to MyString c: " << c << endl;
  bool compare =  d < c;
  cout << compare;
};
