#include "mystring.h"

int main () {

  const char* cstring = "Zebra";

  MyString s1("Apple");
  MyString s2(cstring);
  MyString s3("apple");
  MyString s4("zebra");


  cout << "-------------------------------\n";
  MyString x = "applE", y = "apple";
  cout << "x = " << x << '\n';
  cout << "y = " << y << '\n';

   if (x < y)		cout << "x < y is true\n";
   if (x > y)		cout << "x > y is true\n";
   if (x <= y)		cout << "x <= y is true\n";
   if (x >= y)		cout << "x >= y is true\n";
   if (x == y)		cout << "x == y is true\n";
   if (x != y)		cout << "x != y is true\n";

  /*
  cout << "s1: " << s1 << " < s2: " << s2 << endl;
  bool compare =  s2 < s1;
  cout << compare << endl;
  
  cout << "s1: " << s1 << " < s2: " << s2 << endl;
  bool compare =  s2 < s1;
  cout << compare << endl;
  
  cout << "s1: " << s1 << " > s2: " << s2 << endl;
  compare =  s2 > s1;
  cout << compare << endl;

  cout << "s1: " << s1 << " == s2: " << s2 << endl;
  compare =  s2 == s1;
  cout << compare << endl;
  */
};
