#include "mystring.h"

/////////////////////////////////
//        CONSTRUCTORS         //
/////////////////////////////////

MyString::MyString () {
  size = 1;
  dArray = new char[size];
  dArray[0] = '\0';
}

////////////////////////////////////////////////////////////

MyString::MyString (const char* c) {
    
  size = 0;
  while (c[size] != '\0')
    size ++;

  dArray = new char[size];
  
  for (int i = 0; i < size; i++)
    dArray[i] = c[i];
}

////////////////////////////////////////////////////////////

MyString::MyString (int n) {
  
  size = 0;
  int hold = n;
  
  while (n) {
    n /= 10;
    size++;}

  n = hold;
  
  dArray = new char[size];
  
  for (int i = size - 1; i > -1; i--){
    dArray[i] = (n % 10) + '0';
    n /= 10;}  
}

/////////////////////////////////
//          AUTOMATICS         //
/////////////////////////////////

MyString::~MyString() {
  delete [] dArray;
}

////////////////////////////////////////////////////////////

MyString::MyString (const MyString& ms) {
    
  size = ms.size;
  dArray = new char[size];
  for (int i = 0; i < ms.size; i++)
    dArray[i] = ms.dArray[i];
}

////////////////////////////////////////////////////////////

MyString& MyString::operator = (const MyString& ms) {
  if (this != &ms)
    this->size = ms.size;
    for (int i = 0; i < size; i++)
      this->dArray[i] = ms.dArray[i];
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

////////////////////////////////////////////////////////////

istream& operator >> (istream& is, MyString& ms) {

  if (ms.dArray[0] != '\0'){
    delete [] ms.dArray;
    ms.size = 1;
    ms.dArray = new char[ms.size];
    ms.dArray[0] = '\0';}

  char buffChar;
  int count = 0;

  while (is.peek() == ' ')
    is.ignore();

  while (is.get(buffChar)){
    
    if (buffChar == ' '){
      is.putback(buffChar);
      break;}

    if (++count == ms.size){
      char* temp = new char[ms.size++];
      strcpy(temp, ms.dArray);
      delete [] ms.dArray;
      ms.dArray = temp;
    }
    
    ms.dArray[count - 1] = buffChar;
    ms.dArray[count] = '\0';
  }

  return is;
}

////////////////////////////////////////////////////////////

istream& getline (istream& is, MyString& ms , char delim) {

  if (ms.dArray[0] != '\0'){
    delete [] ms.dArray;
    ms.size = 1;
    ms.dArray = new char[ms.size];
    ms.dArray[0] = '\0';}

  char buffChar;
  int count = 0;

  while (is.get(buffChar)){
    
    if (buffChar == delim)
      break;

    if (++count == ms.size){
      char* temp = new char[ms.size++];
      strcpy(temp, ms.dArray);
      delete [] ms.dArray;
      ms.dArray = temp;
    }
    
    ms.dArray[count - 1] = buffChar;
    ms.dArray[count] = '\0';
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

////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////

bool operator <=(const MyString& ms1, const MyString& ms2) {
if (ms1 < ms2 || ms1 == ms2)
  return true;
else
  return false;
}

////////////////////////////////////////////////////////////

bool operator >=(const MyString& ms1, const MyString& ms2) {
if (ms1 > ms2 || ms1 == ms2)
  return true;
else
  return false;
}

////////////////////////////////////////////////////////////

bool operator ==(const MyString& ms1, const MyString& ms2) {

  if (ms1.size != ms2.size)
    return false;
  
  for (int i = 0; i < ms1.size; i++)
    if (ms1.dArray[i] != ms2.dArray[i])
      return false;
  
  return true;
}

////////////////////////////////////////////////////////////

bool operator !=(const MyString& ms1, const MyString& ms2) {

  return !(ms1 == ms2);
}

/////////////////////////////////
//   CONCATENATION FUNCTIONS   //
/////////////////////////////////

MyString MyString::operator+ (const MyString& ms) const {
  
  MyString sum;
  sum.size = size + ms.size;
  delete [] sum.dArray;
  sum.dArray = new char[sum.size];
  
  for (int i = 0; i < size; i++)
    sum.dArray[i] = dArray[i];
  
  for (int j = size; j < sum.size; j++)
    sum.dArray[j] = ms.dArray[j - size];
  
  return sum;
}

////////////////////////////////////////////////////////////

MyString& MyString::operator+=(const MyString& ms) {
  
  char* tempArray = new char[this->size];
  strcpy(tempArray, dArray);
  int tempSize = size;
  
  size += ms.size;
  delete [] dArray;
  this->dArray = new char[size];
  
  for (int i = 0; i < tempSize; i++)
    dArray[i] = tempArray[i];
  for (int j = tempSize; j < size; j++)
    dArray[j] = ms.dArray[j - tempSize];
  delete [] tempArray; 
  return *this;
}

/////////////////////////////////
//      BRACKET OPERATORS      //
/////////////////////////////////

char& MyString::operator[] (unsigned int index) {
  
  if (index < size)
    return dArray[index];
  
  else{
    int tempSize = size;
    char* tempArray = new char[tempSize];
    strcpy(tempArray, dArray);
    
    delete [] dArray;
    size = index + 1;
    dArray = new char[size];
    
    for (int i = 0; i < tempSize; i++)
      dArray[i] = tempArray[i];
    
    for (int j = tempSize; j < index; j++)
      dArray[j] = ' ';
    
    delete [] tempArray;
    
    return dArray[index];
  }
} 

////////////////////////////////////////////////////////////

const char& MyString::operator[] (unsigned int index) const {
  
  if (index < size)
    return dArray[index];
  
  else
    return '\0';
}

/////////////////////////////////
//      STANDARD ACCESSORS     //
/////////////////////////////////

int MyString::getLength() const {
return size;
}
const char* MyString::getCString() const {
return dArray;
}

/////////////////////////////////
//     SUBSTRING FUNCTIONS     //
/////////////////////////////////

MyString MyString::substring(unsigned int index, unsigned int length) const {
  
  MyString sub;
  sub.size = length; 
  delete [] sub.dArray;
  sub.dArray = new char[sub.size];
  
  int take = length;
  if (length > size - index)
    take = size - index;
  
  for (int i = 0; i < take; i++)
    sub.dArray[i] = dArray[i + index];
  
  return sub;
}  

////////////////////////////////////////////////////////////

MyString MyString::substring(unsigned int index) const {
  
  MyString sub;
  sub.size = size - index; 
  delete [] sub.dArray;
  sub.dArray = new char[sub.size];
  
  for (int i = 0; i < sub.size; i++)
    sub.dArray[i] = dArray[i + index];
  
  return sub; 
}

/////////////////////////////////
//        INSERT FUNCTION      //
/////////////////////////////////

MyString& MyString::insert (unsigned int index, const MyString& s) {
  
  char* temp1 = new char[index];
  char* temp2 = new char[size - index];

  for (int i = 0; i < index; i++)
    temp1[i] = dArray[i];
  for (int j = index; j < size; j++)
    temp2[j - index] = dArray[j];
  
  delete [] dArray;
  size += s.size;
  dArray = new char[size];
  
  for (int i = 0; i < index; i++)
    dArray[i] = temp1[i];
  for (int j = 0; j < s.size; j++)
    dArray[j + index] = s.dArray[j] ;
  for (int k = 0; k < size - s.size - index; k++)
    dArray[k + index + s.size] = temp2[k];

  delete [] temp1;
  delete [] temp2;

  return *this; 
}

int MyString::indexOf(const MyString& s) const {

  const int notFound = -1;
  int indexFound = 0;
 
  if (s.size > size) 
    return notFound;

  for (int i = 0; i < size; i++){
    int j = 0;
    
    if (dArray[i] == s.dArray[j]){
      indexFound = i;
      
      while (dArray[i] == s.dArray[j] && j < s.size){
        i++;
        j++;}
      
      if (j == s.size)
        return i;
    } 
  } 
  return notFound;
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



