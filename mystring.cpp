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
//        I/O FUNCTIONS        //
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

/////////////////////////////////
//    COMPARISON OPERATORS     //
/////////////////////////////////

bool operator < (const MyString& ms1 , const MyString& ms2) {
int cLength;
cLength = strlen(ms1.sArray) < strlen(ms2.sArray) ? strlen(ms1.sArray) : strlen(ms2.sArray);
for (int i = 0; i < cLength; i++){
  if (ms1.sArray[i] < ms2.sArray[i])
    return true;
  if (ms1.sArray[i] > ms2.sArray[i])
    return false;
  i++;}
  return false;
}

bool operator > (const MyString& ms1, const MyString& ms2) {
int cLength;
cLength = strlen(ms1.sArray) < strlen(ms2.sArray) ? strlen(ms1.sArray) : strlen(ms2.sArray);
for (int i = 0; i < cLength; i++){
  if (ms1.sArray[i] > ms2.sArray[i])
    return true;
  if (ms1.sArray[i] < ms2.sArray[i])
    return false;
  i++;}
  return false;
}

bool operator <=(const MyString& ms1, const MyString& ms2) {
if (ms1 < ms2 || ms1 == ms2)
  return true;
else
  return false;
}

bool operator >=(const MyString& ms1, const MyString& ms2) {
if (ms1 > ms2 || ms1 == ms2)
  return true;
else
  return false;
}

bool operator ==(const MyString& ms1, const MyString& ms2) {
if (strlen(ms1.sArray) != strlen(ms2.sArray))
  return false;
for (int i = 0; i < strlen(ms1.sArray); i++)
  if (ms1.sArray[i] != ms2.sArray[i])
    return false;
return true;
}

bool operator !=(const MyString& ms1, const MyString& ms2) {
return !(ms1 == ms2);
}
