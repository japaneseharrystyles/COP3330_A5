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

I'm NOT going to attempt to fix this, since the constructors
currently exist in an intermediate static state that will be
altered later on to DMA.

3.) My 3rd bug happened to solve my 2nd bug. 
I made the same mistake in my last assignment.

My assignment operator wouldn't work when attempting
to assign my empty MyString with a new MyString object
because it was a function.

CALL DEFAULT CONSTRUCTOR WITH:

MyString d;

NOT:

MyString d();

I actually ran the default constructor correctly 
and then changed it to the incorrect format after 
seeing it and thinking I was correcting it.

4.) My comparison operator was returning false true values.
I implemented the operator so that I iterated through a loop
until the end of the shorter MyString object, comparing
character by character, returning true if ms1.sArray[i]
was less than that of ms.sArray[i]. If this 'if statement'
failed, the loop moved on and checked the next character.
The loop SHOULD ONLY move on if the character ASCII values
were equal. Essentially, my function returned true if ANY
of the characters in the first string were less than ANY
of the corresponding characters in the second string.

5.) I defined a working 'less than' operator, and then
to create a 'greater than' operator, I pasted the same code
into the next definition block, and inverted '<'s to '>'s and 
'>'s to '<'s. This seemed to make sense, but my 'greater than'
function ALWAYS returned false.

DANGERS OF COPYPASTE

Inverting all the comparison operators resulted in a for loop

for (int i = 0; i > length; i++)

since 0 is less than length, my for loop was never used.

5.) I just made the attempted conversion to dynamic mem.
A LOT of seg faults, my program still leaks memory, but it 
compiles and produces accurate output. I'm using valgrind to 
locate instances of memory leak. 

6.) I found all the memory leaks and corrected them.
The difficult one was a dynamic tempArray being allocated
within a concatenation function. The reason I didn't check
this one, is because my last project, freeing this memory
cause a compilation error, so I concluded that I must not
be required to free memory that is allocated within the 
local scope of a function, but maybe I was attempting to
free a memory block that was already empty.

 
