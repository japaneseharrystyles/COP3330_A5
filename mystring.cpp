#include "mystring.h"

/////////////////////////////////
//        CONSTRUCTORS         //
/////////////////////////////////

MyString::MyString () {
}

// conversion constructors //

MyString::MyString (const char* c) {
  strcpy(sArray, c);
}

MyString::MyString (int n) {
  int digits = 0;
  int hold = n;
  while (n) {
    n /= 10;
    digits++;
  }
  n = hold;
  for (int i = digits - 1; i > -1; i--){
    sArray[i] = (n % 10) + '0';
    n /= 10;
  }  
}

/////////////////////////////////
//          AUTOMATICS         //
/////////////////////////////////

MyString::~MyString() {
}

MyString::MyString (const MyString& ms) {
  for (int i = 0; i < strlen(ms.sArray); i++)
    sArray[i] = ms.sArray[i];
}

MyString& MyString::operator = (const MyString& ms) {
  if (this != &ms)
    for (int i = 0; i < strlen(ms.sArray); i++)
      sArray[i] = ms.sArray[i];
  return *this;
}
/////////////////////////////////
//        I/O OPERATORS        //
/////////////////////////////////

ostream& operator << (ostream& os, const MyString& ms) {
  if (strlen(ms.sArray) != 0)
    for (int i = 0; i < strlen(ms.sArray); i++)
      os << ms.sArray[i];
  return os;
}

istream& operator >> (istream& is, MyString& ms) {
  int i = 0;
  while (is == " ")
    is.ignore();
  while (is != " "){
    is >> ms.sArray[i];
    i++;
  }
  return is;
}
