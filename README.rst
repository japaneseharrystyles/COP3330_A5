//////////////////////////////////////////////////////////
            COP 3330 -- PROJECT 5 -- MyString CLASS
//////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////
                      project description
//////////////////////////////////////////////////////////

Create a user-defined MyString class to facilitate creation of
flexible string objects with intuitive operator syntax. Our custom
string objects should consist of a dynamically allocated character
array, to allow easy resizing. Since we are working in dynamic memory,
our class should provide measures against memory leak, etc.


//////////////////////////////////////////////////////////
                      completion status
//////////////////////////////////////////////////////////

1.) Data                        [private]
        
2.) Standard Constructors       [public]

3.) Automatics                  [public]

4.) I/O Functions               [friend]

5.) Comparison Operators        [friend]

6.) Concatenation Operators     [public]

7.) Bracket Operators           [public]

8.) Standard Accessors          [public]

9.) Substring Functions         [public]

10.) Insert Function            [public]
 
11.) indexOF Function           [public]

//////////////////////////////////////////////////////////
                         BUGLIST 
//////////////////////////////////////////////////////////

1.) I am starting with a static array.
My member array is declared as follows:

char sArray[100];

My default constructor has an empty definition,
but for some reason, when I attempt to call the
default constuctor from the main function, I am
encountering an error for:

undefined reference to Mystring::~MyString

The function compiled successfully after defining
the deconstructor in our .cpp file, even though the
definition was empty. I believe this is because when
we decalre a deconstructor in our header file, we
essential discard the built in class object deconstructor

2.) I have defined the three constructor functions and
overloaded the insertion operator << so that I can test
the runtime accuracy of my constructor. 

The int type conversion constructor was the most difficult
but during runtime, my default constructor is the one
that is giving me bad output. My member data within an
object that was instantiated with the default constructor
is printing "1" to the screen. I assume this has to do with
attempting to cout an empty character array.

 
