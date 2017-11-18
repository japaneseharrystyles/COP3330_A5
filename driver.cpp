#include "mystring.h"

int main () {

//		Test 1  

cout << "Testing default constructor" << endl;

MyString d; 

d.info();

//		Test 2

cout << "Testing conversion constructor (char*)" << endl;

const char* cstar = "Tristen";

MyString c1(cstar);
MyString c2("Hi"); 

c1.info();
c2.info();

//		Test 3

cout << "Testing conversion constructor (int)" << endl;

int n = 123;

MyString n1(n);
MyString n2(54321);

n1.info();
n2.info();

//		Test 3

cout << "Testing copy constructor" << endl;

MyString copy(c1);

copy.info();

//		Test 4

cout << "Testing assignment operator" << endl;

MyString eq = c2;

eq.info();

eq = n2;

eq.info();

//		Test 5

cout << "Testing I/O functions" << endl;

cout << eq << n2 << endl;

//		Test 6

cout << "Testing comparison operators" << endl;

MyString x = "apply", y = "apply";

cout << "x = " << x << '\n';
cout << "y = " << y << '\n';

if (x < y)		cout << "x < y is true\n";
if (x > y)		cout << "x > y is true\n";
if (x <= y)		cout << "x <= y is true\n";
if (x >= y)		cout << "x >= y is true\n";
if (x == y)		cout << "x == y is true\n";
if (x != y)		cout << "x != y is true\n";
   
//		Test 7

cout << "Testing concatenation" << endl;

MyString sum;
sum = c2 + c1;
sum.info();

sum += n2;
sum.info();
}
