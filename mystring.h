#include <iostream>
using namespace std;

class MyString
{
  /* 4. I/O Functions */
  friend ostream& operator<< (ostream& , const MyString& );
  friend istream& operator>> (istream& , MyString& );
  friend istream& getline (istream& , MyString& , char delim = '\n');

  /* 5. Comparison Operators */
  friend bool operator< (const MyString& , const MyString& );
  friend bool operator> (const MyString& , const MyString& );
  friend bool operator<=(const MyString& , const MyString& );
  friend bool operator>=(const MyString& , const MyString& );
  friend bool operator==(const MyString& , const MyString& );
  friend bool operator!=(const MyString& , const MyString& );

public:
  /* 2. Standard Constructors */
  MyString();                // empty string
  MyString(const char* );    // conversion from c-string
  MyString(int );            // conversion from int
  
  /* 3. Automatics */
  ~MyString();                            // destructor
  MyString(const MyString& );             // copy constructor
  MyString& operator=(const MyString& );  // assignment operator

  /* 6. Concatenation Operators */
  MyString operator+ (const MyString& ) const;  // concatenation
  MyString& operator+=(const MyString& );       // concatenation/assignment

  /* 7. Bracket Operators */
  char& operator[] (unsigned int index);              // returns L-value
  const char& operator[] (unsigned int index) const;  // read-only
  
  /* 8. Standard Accessors */
  int getLength() const;            // return string length
  const char* getCString() const;   // return c-string equivalent

  /* 9. Substring Functions */
  MyString substring(unsigned int , unsigned int ) const;
  MyString substring(unsigned int ) const;

  /* 10. Insert Function */
  MyString& insert(unsigned int index, const MyString& s);

  /* 11. indexOf Function */
  int indexOf(const MyString& s) const;

private:
  /* 1. Data */
  // declare your member data and helper functions here
  char sArray[100];
};

