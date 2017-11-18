#include "mystring.h"

/////////////////////////////////
//        CONSTRUCTORS         //
/////////////////////////////////

MyString::MyString () {
  size = 1;
  dArray = new char[size];
  dArray[0] = '\0';
}

MyString::MyString (const char* c) {
  size = strlen(c);
  dArray = new char[size];
  strcpy(dArray, c);
}

MyString::MyString (int n) {
  size = 0;
  int hold = n;
  while (n) {
    n /= 10;
    size++;
  }
  n = hold;
  dArray = new char[size];
  for (int i = size - 1; i > -1; i--){
    dArray[i] = (n % 10) + '0';
    n /= 10;
  }  
}

/////////////////////////////////
//          AUTOMATICS         //
/////////////////////////////////

MyString::~MyString() {
  delete [] dArray;
}

MyString::MyString (const MyString& ms) {
    
  size = ms.size;
  dArray = new char[size];
  for (int i = 0; i < ms.size; i++)
    dArray[i] = ms.dArray[i];
}

MyString& MyString::operator = (const MyString& ms) {
  if (this != &ms)
    (*this).size = ms.size;
    for (int i = 0; i < size; i++)
      (*this).dArray[i] = ms.dArray[i];
  return *this;
}
/////////////////////////////////
//        I/O FUNCTIONS        //
/////////////////////////////////

ostream& operator << (ostream& os, const MyString& ms) {
  if (ms.size != 0)
    for (int i = 0; i < ms.size; i++)
      os << ms.dArray[i];
  return os;
}

istream& operator >> (istream& is, MyString& ms) {
  if (ms.dArray != '\0')
    delete [] ms.dArray;
    ms.size = 0;
  int i = 0;
  while (is.peek() != ' '){
    ms.dArray[i] = is.get();
    i++;
    ms.size++;
  }
  return is;
}

/////////////////////////////////
//    COMPARISON OPERATORS     //
/////////////////////////////////

bool operator < (const MyString& ms1 , const MyString& ms2) {
int cLength;
cLength = ms1.size < ms2.size ? ms1.size : ms2.size;
for (int i = 0; i < cLength; i++){
  if (ms1.dArray[i] < ms2.dArray[i])
    return true;
  if (ms1.dArray[i] > ms2.dArray[i])
    return false;
  i++;}
  return false;
}

bool operator > (const MyString& ms1, const MyString& ms2) {
int cLength;
cLength = ms1.size < ms2.size ? ms1.size : ms2.size;
for (int i = 0; i < cLength; i++){
  if (ms1.dArray[i] > ms2.dArray[i])
    return true;
  if (ms1.dArray[i] < ms2.dArray[i])
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
if (ms1.size != ms2.size)
  return false;
for (int i = 0; i < ms1.size; i++)
  if (ms1.dArray[i] != ms2.dArray[i])
    return false;
return true;
}

bool operator !=(const MyString& ms1, const MyString& ms2) {
return !(ms1 == ms2);
}

/////////////////////////////////
//   CONCATENATION FUNCTIONS   //
/////////////////////////////////

MyString MyString::operator+ (const MyString& ms) const {
  MyString sum;
  sum.size = this->size + ms.size;
  delete [] sum.dArray;
  sum.dArray = new char[sum.size];
  for (int i = 0; i < this->size; i++)
    sum.dArray[i] = this->dArray[i];
  for (int j = this->size; j < sum.size; j++)
    sum.dArray[j] = ms.dArray[j - this->size];
  return sum;
}

MyString& MyString::operator+=(const MyString& ms) {
  
  char* tempArray = new char[this->size];
  strcpy(tempArray, this->dArray);
  int tempSize = this->size;
  
  this->size += ms.size;
  delete [] this->dArray;
  this->dArray = new char[this->size];
  
  for (int i = 0; i < tempSize; i++)
    this->dArray[i] = tempArray[i];
  for (int j = tempSize; j < this->size; j++)
    this->dArray[j] = ms.dArray[j - tempSize];
  
  return *this;
}

/////////////////////////////////
//       HELPER FUNCTIONS      //
/////////////////////////////////

void MyString::info() const {
  cout << "This object's dynamic array is sized to: " << size << endl;
  cout << "The object's dynamic array stores: ";
  if (dArray)
    cout << *this << endl;
  else
    cout << "nothing!" << endl;  
} 
