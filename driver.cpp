#include "mystring.h"

int main () {

  const char* cstring = "Tristen";

  MyString d;
  MyString c(cstring);
  MyString i(12345);
  MyString copy(i);

  cout << "MyString d: " << d << endl;
  cout << "MyString c: " << c << endl;
  cout << "MyString i: " << i << endl;
  cout << "MyString copy: " << copy << endl;

  d = copy;
  cout << "MyString d: " << d << endl;

};
