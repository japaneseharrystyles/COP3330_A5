#include "mystring.h"

int main () {

// 
cout << "Testing default constructor" << endl;
MyString d; 
d.info();
cout << "Testing conversion constructor (char*)" << endl;
const char* cstar = "Tristen";

MyString c1(cstar);
MyString c2("Hi"); 
c1.info();
c2.info();
}
