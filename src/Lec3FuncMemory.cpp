#include <iostream> //Req'd for cout(out put to screen)
#include <iomanip>
#include <cmath> // required, even if you happen to use an IDE that allows you get away without it
using namespace std; //to avoid typing it over and over again
//-------------------------------pass-by-values-review-----------------------
/*
A value parameter in a function becomes a copy of the argument that
    is passed in
Changing the value of a value parameter:
    - Does changes the memory associated with the parameter
    - Does not change the memory associated with the argument passed in
*/
// EXAMPLE
// void valFunc (float val)
// {
//     val = 50;
// }
// int main ()
// {
//     int mainVal = 9;
//     valFunc(mainVal);
//     cout << "mainVal: " << mainVal << endl;
//     return 0; 
// }
//-------------------------------pass-by-reference-------------------------
/*
A reference parameter in a function "references" the same physical memory
    location as the argument passed in
Changing the value of a reference parameter:
    - Does not change the memory associated with the parameter
    - Does change the memory associated with the argument passed in
    - Therefore - argument's memory must not be constant or literal
*/
// void refFunc (int &val)
// {
//     val = 50;
// }
// int main ()
// {
//     int mainVal = 9;
//     refFunc(mainVal);
//     cout << "mainVal: " << mainVal << endl;
//     return 0;
// }
//----------------------------pre-existing-functions-----------------------
/*
C++ standard libraries contain many functions that you usually do not have
to write algorithms for yourself
Many math related functions in a standard math library
    -Must #include<cmath> to access these functions (and include the "using namespace std")
    - Once the library is #include'd, you may utilize functions from the library
Some available functions:
    - double sin(double x)
    - double cos(double x)
    - double pow(double base, double exponent)
    - double sqrt(double x)
*/
// EXAMPLE
// int main ()
// {
//     double checkVal;
//     double resultVal;

//     checkVal = 4;
//     resultVal = pow(checkVal, 3.0);
//     cout << checkVal << "^3 = " << resultVal << endl;

//     checkVal = 65;
//     resultVal = sqrt(checkVal);
//     cout << "sqrt of " << checkVal << " = " << resultVal << endl;

//     return 0;
// }
//----------------------default-parameters-to-functions-------------
/*
If a function's parameter is usually a known value, the parameter can be given
a "defulat value"
    -defulat parameters must be at the end of the parameter list
    - defulat valus specified in function prototype
    - argument is not required for default parameters
        - defulat value will be used if no argument is provided
*/
// EXAMPLE
// void print(int a, int b = 4) // 4 is default value of b
// {
//     cout << a << " " << b << endl;
// }
// int main()
// {
//     print(8, 16);
//     print(7);
//     // print(); // will not compile
//     return 0;
// }
//----------------------Types of languages-----------------------
/*
Machine Language- actually stored in memory
    -platform dependent
    -binary instructions only
    -1001001101010100
Assembly language- direct mapping to machine language
    -platform dependent
    -basic codes, each of which maps to a sequence of binary digits (bits)
    -ADD R1, IP
high-level language -easy to write, similar to english
    -platform independent
    -each plftform needs to be able to convert to machine language
*/
//---------------------------CREATING an executable with c++----------
/*
create c++ program with extension .cpp
pre-processor
    -"pastes" prototypes and definitions from include files
    -controlled via pre-processor directives that begin with "#"
    -results in c++ code that has been modified based on directives
compiler
    -converts c++ code into assembly and/or machine language
    -usually called "object code" with extension .o
    -Leaves "holes" in place of function calls from other libraries
Linker
    -fills holes from compiler with locations (addresses) of library functions
    -results in complete sequene of machine langauge
result: executable program
    -can be executed on the platform in which it was compiled and linked
    -sometimes, all steps are combined, so individual steps are transparent to user

*/
//---------------------------gloabl and static---------------------
/*
global constants and variables
    -declared outside the scope of any individual function
    -globals can be accessed from anywhere
    -memory is obtained at beginning of program, is freed up when the program is finished
static variables
    - declared within a function, using keyword "static" before data type
    -memory is obtained at the beginning of program, is freed up when the program is finished
    -can only be accessed from within the function it is declared
    -scope is within the function it is declared. lifetime is the entire program 
*/
// EXAMPLE
//Global variable to count total calls
// int numFuncCalls;
// void f1()
// {
//     //Allocated and initialized once
//     static int f1Calls = 0;
//     numFuncCalls++;
//     f1Calls++;
//     cout << "In f1: totalCalls: " << numFuncCalls << " f1 calls: " << f1Calls << endl;
// }
// void f2()
// {
//     //Allocated and initialized every
//     //time the f2 is called => local to f2
//     int f2Calls = 0;
//     numFuncCalls++;
//     f2Calls++;
//     cout << "In f2: totalCalls: " << numFuncCalls << " f2 calls: " << f2Calls << endl;
// }
// int main()
// {
//     //Initialization of global var
//     numFuncCalls = 0;
//     f1();
//     f2();
//     f1();
//     f2();
//     //numFuncCalls can be accessed from anywhere, since it is global
//     cout << "End of main: " << "totalCalls: " << numFuncCalls << endl;
//     //This will not compile! Scope of f1Calls is ONLY in f1 function
//     //cout << "f1 Calls: " << f1Calls;
//     return (0);
// }
//---------------------use of memory--------------------------
/*
Generic content of main memory:
    -memory reserved for operating system
    -compiled and linked c++ program (in binary form)
    - heap: the global and static data for your c++ program, data whose lifetime is the 
        entire program run
    -runtime stack: the local data for the individual functions in your c++ program;
        lifetime is while function is active
*/
//-----------------------activation records-----------------
/*
everytime a function is called, many pieces of information the function
    requires need to be stored in an "activation record" (AR)
As one function calls another, ARs stack up on top of each other
When a function ends, the AR on top of the stack is removed
    -includes the parameters and local variables
A possible version of an AR
    -return value
    -return address
    -dynamic link
    -parameters
    -local variables
*/
// EXAMPLE: memory trace
int calls; //Global var (ack!)
int inFunc(int val)
{
    int locIn;
    locIn = val + 50;
    calls++;
    return (locIn);
}
int outFunc(int p1)
{
    int locOut;
    locOut = inFunc(p1);
    locOut = inFunc(locOut);
    calls++;
    return (locOut);
}
int main()
{
    int mainVar;
    calls = 0;
    mainVar = outFunc(10);
    return (0);
}
