#include <iostream> //Req'd for cout(out put to screen)
#include <iomanip>
using namespace std; //to avoid typing it over and over again
/*
Functions: allows for modular programming
write the function once, call it many times
group similar things together
Parameters: allow values from calling function to be used within the function
May, or may not return a value to calling function
*/
/*
syntax:
return_type function_name (formal parameter list)
{
 function code ...
}
*/
/*
Function prototype declares a function
Provide user with information about the function
    - name of function, what values and types need to be passed in, 
        what type to expect the function to return
Here is a function prototype for a factorial function
    - int computeFactorial (int num);
    - this function is called "computeFactorial"
    - takes in one integer value from the calling function as a parameter
    - returns an integer value to the calling function
style: the function name must be descriptive of its purpose
style: the function name must be named with a verb
*/
/*
A function definition provides the implementation  of an algorithm
Here is a function definition for computing factorial of a number passed in by the user
*/
// function need to be declared first before it can be called
// int computeFactorial (int num) //Function header, takes on integer value and name it "num"
// {
//     int result = 1; // value to return
//     int i;

//         for (i=1; i<=num; i++) // initilization, condition (expression), update
//         {
//             result *= i;
//         }
//         return result; // Returns an integer, as expected
// }
// // A function is "called" when you want to use the algorithm that was implemented in the function
// int main ()
// {
//     int fact; // factorial result
//     int val = 5;

//     fact = computeFactorial(val); // function call!

//     cout << "Fact. of " << val << " is: " << fact << endl;

//     return 0;
// }
//--------------------------------multiple parameters-----------------
/*
often, multiple values from the calling function are needed
Any number of parameters can be passed in to a function
*/
// int addNums (int a, int b, int c) // pass in 3 different integer values
// {
//     int result;

//     result = a + b + c;

//     return result; // return sum
// }

// int main ()
// {
//     int num1 = 5;
//     int num2 = 3;
//     int result; // result of the function call

//     result = addNums(num1, 6, num2);

//     cout << "The result is: " << result << endl;

//     return 0;
// }
//-----------------------------overloading functions----------------
/*
Multiple functions can have the same name, but MUST have unique parameter list
Function signature:
    - function name and types and order of parameters in parameter list
    - functions must have a unique signature
Overloading: multiple functions with the same name
*/
// Not overloaded function
// int squareInt (int num); // square an int, and return the value
// float squareFloat(float num); // square a float, and return the value
// int drawSquare (int x, int y, int len, int wid); // draw a square on the screen

// overloaded function
// int square (int num); // square an int, and return the value
// float square (float num); // square a float, and return the value
// int square (int x, int y, int len, int wid); // draw a square on the screen

// overloading example
// int overloadSum (int a, int b, int c)
// {
//     cout << "(i i i) version" << endl;
//     return (a + b + c);
// }
// float overloadSum (float a, float b, float c)
// {
//     cout << "(f f f) version" << endl;
//     return (a + b + c);
// }
// float overloadSum (int a, float b, float c)
// {
//     cout << "i f f version" << endl;
//     return (a + b + c);
// }

// int main ()
// {
//     float ans;
//     float f1 = 6.4;
//     float f2 = 4.2;
//     int i1 = 4;
//     int i2 = 6;

//     ans = overloadSum(f1, f2, f2); // 2nd type
//     cout << ans << endl;

//     ans = overloadSum(i1, i2, i2); // 1st type
//     cout << ans << endl;

//     ans = overloadSum(i2, (float)i1, f1); // 3rd type
//     cout << ans << endl;

//     return 0;
// }
//----------------------some words on scope--------------
/*
Any variable declared in a function is "local" to that function
It only exists from the time it's declared until the end of the function
    -variables in different functions are unique variables, in unique addresses,
        with unique scopes
*/
//-----------------------------pass-by-value---------------------
/*
When a parameter is "passed-by-value" into a function, 
    a new variable is declared to store the parameter
The initial value of the parameter is copied from the value passed in from the calling function
When the parameter is changed, only the copy is changed
*/
//  EXAMPLE 1
// chnage Val() changes the value of the parameter within the function 
// int changeVal (int val) //val has a value of 19, which is a copy of num, at a different memory location
//     val = (val - 15) / 2; // the value in the same val memory location is changed
//     return val;
// }
// int main()
// {
//     int num = 19; // integer for test
//     int result; // result of changeVal

//     cout << "starting!" << endl;
//     result = changeVal(num);
//     cout << "result: " << result // result will be 2
//          << "num: " << num << endl; // num is still 19
//     return 0;
// }
/*
Any local variable defined within a frame will go out of scope once the program
exit that stack frame (an execution of a function). 
When a stack variable goes out of scope, its destructor is called
*/
//-----------------------------pass-by-reference------------------
/*
only avaliable in c++
unlike pass-by-value, parameter "references" the same memory location
Accomplished by including and '&' before the parameter name in function
    proototype and header
Changing the value of a reference parameter in a function changes the value of the variable
    in the calling function (since the same memory is referenced)
Argument in function call MUST be a variable
    cannot be a literal or a constant (since it could be changed)
Allows for multiple values to be "returned" from a function
*/
// EXAMPLE
// chnageRef() changes the value of the parameter in main as well
// int changeRef (int &val)
// {
//     val = (val - 15) / 2;
//     return val;
// }
// int main()
// {
//     int num = 19; // integer for test
//     int result; // result of changeRef

//     cout << "starting!" << endl;
//     result = changeRef(num); // changeRef will change the value at num's memory location
//     cout << "result: " << result // will be 2
//          << "num: " << num << endl; // will also be 2
//     return 0;
// }
// EXAMPLE multiple reference params
// void return type specified that the function does not return a value
// void swap (int  &a, int &b) // pass-by-reference!
// {
//     int temp;

//     temp = a; // will be destory once out of scope, since local variable
//     a = b; // n1 memory location becomes 10
//     b = temp; // n2 memory location becomes 5
// }
// int main()
// {
//     int n1 = 5;
//     int n2 = 10;

//     cout << "Before swap - n1: " << n1 << "n2: " << n2 << endl;
//     swap(n1, n2);
//     cout << "After swap -n1: " << n1 << "n2: " << n2 << endl;
//     return 0;
// }
//------------------------------advantages of modularity------------------
/*
Cleaner code;
    A call to a function called "computeFactorial() is compact and essentially 
        self-documenting
    A loop to compute the factorial would not be immediately clear
Breaks the program into smaller pieces
    Real world: write specifications and prototypes for needed functions, then
        distribute different functions to difference people
        parallel coding is faster
Easier testing
    How to test one, huge, monolithic, 30,000 line program?
    modular program can be tested module by module (function by function, in this case)
*/
//------------------------Modular testing - Driver programs----------------
/*
Driver programs allow you to test a newly written function
The purpose of a driver program is simply to call your function and out put some results to 
    check correctness
Most main programs in lectures so far have been driver programs-
    to demonstrate the use of other functions
Especially helpful when the function you are writing is buried deep in some milion line projetc
    If adding functionality to a simulation that takes 12 hours to run, you dont want to 
        want to have to run 50 test cases (25 days) using the entire simulation just to 
        test one function
*/
//---------------------------Modular testing - stubs-------------------------
/*
Stubs allow you to test a program that is unfinished
If waiting for someone else to finish an important function, you would still want to
    do some testing
Provide the function prototype and a "dummy" body
    stub does not return actual value that the function will, but allows you to call the function
    as if it were complete, for testig
This simply allows you to have the function defined in some way so when the function
    is ready, the stub is simply replaced with the actual function
*/