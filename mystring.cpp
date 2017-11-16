#include "mystring.h"

MyString::MyString () {
}


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

MyString::~MyString() {
}

ostream& operator << (ostream& os, const MyString& ms) {
  for (int i = 0; i < strlen(ms.sArray); i++)
    os << ms.sArray[i];
  return os;
}
