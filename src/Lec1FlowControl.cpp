#include <iostream> //Req'd for cout(out put to screen)
#include <iomanip>
using namespace std; //to avoid typing it over and over again


//Program Header
//Programmer:
//Date: 
//Purpose: 


/*
Typed language: enforces rules regarding how data types are used and manipulated within the code
static typing: variables is known at compile-time, variables must be declared with a type nefore they can be used, compiler checks for types
Dynamic typing: type of variable is known at runtime. variables do not need to be declared with a type. the interpreter checks the types as the program runs
strong typing: types are strickly enforced, meaning that implicit types conversions are limited or non-existent. 
                operations between different types will result in an error
weak typing: allows more implicit type conversions
explicit typing: the programmer must explicitly declare the types of variables, examples include java and c++
implicit typing: the language infers the types of variables based on their values and context: python and javascript
*/

int main(){
    // std::cout << "I like pizza" << std::endl;
    // std::cout << "Pizza is good" << '\n';
    /*---------------------------------variables-------------------------------
        identifier: name of variables, constant, user-defined functions
        must start with letter or underscore
        contains only letters, digits, or underscore
    */
    /*
    Variable names are any valid c++ identifier,
    the type of variable describes what kind of data it holds
    values of variables can change throughout a program, types of variabls can not
    */
    //all variables must have a name and a type, give variable a type and sets aside memory
    int counter; //declares an integer variable called counter
    float average; //declares a float called average
    char grade; //declares a character to represent a grade

    //initialization-setting a variables value
    counter = 10;
    average = 88.25;
    grade = 'B';

    //initialization can be donw during declaration
    char modif = '+'; //modifer to be appended to a grade
    int sumOfValues = 0; //some of input values
    float initialBudget = 135.50; //initial budget for week

    //stype: variable names in lower case, except  

    /*------------------------------------constants------------------------------
        constants must have a name and a type
        The value of a constant must be initialized at declaration time
        The value is not allowed to change during program execution
    */
    const float PI = 3.1415926;
    const int NUM_SCORES = 12;
    const char BEST_GRADE = 'A';
    //style: constant names in ALL CAPS to differentiate from variables

    
    /* operators are used on variables and/or literals to compute a new value
        =            assignment operator
        +, -, *, /   add subtract, multiply, divide
        ==, !=       equality, inequality
        ++, --       increment, decrement
        +=, -=, *=, /=   add/asign, etc
        >, < >=, <=  greather than, less than, greater or equal, less or equal
        &&           logical AND, returns true when both operands are true
        ||           logical OR, returns true when >= 1 operand is true
        !            logical NOT, returns true when operand is fals
        %            modulus (integer remainder)
    */

    /*expressions: a sequence of tokens that can be evaluated to a value,
    expressions result in some value
    5     value: 5
    5+10  value: 15
    a<15  value: depends on the value of a
    (intvar >= 15 && intvar <+30)    value: depends on the value of intvar
    2*y -i/2   value: depends on values of i and y
    x = 17      value: 17
    */

    /*statement: a sequence of tokens (often terminated with a semicolon)
     that can be recognized by the compiler as a complete instruction
     A statement does not have a value
    x = 5;
    cout<< "Hello World!" << endl;
    a = 14.8 +fvar;
    i++;
    */

    //------------------------------------output to screen--------------------------
    // int x = 5; //dummy integer
    // char c = 'P';
    // cout << "welcome Home!" << endl;
    // cout << "int: " << x << " char: " << c << endl;
    //-------------------------------------user inputs------------------------------
    // int x;
    // char c;
    // cout << "Enter an int: ";
    // cin >> x;
    // cout << "Enter a char:";
    // cin >> c;
    // cout << "int: "<< x << " char: " << c << endl;

    //--------------------------------------Division in C++-------------------------
    /*
    C++ has 2 kinds of division
    integer division: performed with both operands are integers, result in an integer
    floating point division: performed when at least one operans is a floating point value, result in a floatiing point value
    */

    //---------------------------------------type casting---------------------------
    //a variable's type can be changed temporarily in a statement
    //type is only changed for the instance on which the cast is appllied
    //syntax: static_cast< newtype >(variable)
    // int val = 31;
    // cout << "1. Value is: " << val / 2 / 2  << endl;

    // cout << "2. Value is: ";
    // cout << static_cast<double>(val) /2 / 2.0 << endl;
    
    /* C-style type cast: used in older C programs
        syntax: (newtype)variable
    */ 
    //cout << (double)31 / 2 / 2.0 << endl;

    // ------------------------------------compound-statements---------------------
    /*syntax of many c++ constructs allows only on single statement to be used
        compound statements allow multiple statements to be combined into one statement
        multiple statements inclosed in {} result in a compound statement
        style: all code within a set of curly braces must be indented using a consistent number of spaces
        */
    // {
    //     x = 5;
    //     a = 14.8 + fvar;
    //     i++;
    // }

    // -----------------------------------if-else-statements----------------------
    // each statement can only be one single statement
    // could use compound statement to put multiple statements in the body of an if or else
    /*syntax:
        if (expression)
            statement
        else
            statement
    */
// EXAMPLE
//    int x = 5;
//    if (x == 4)
//    {
//     cout << "x is 4!" << endl;
//    }
//    else
//    {
//     cout << "x is not 4!" << endl;
//     cout << "it was: " << x << endl;
//    }
//----------------------------------nested if-else----------------------- 
// EXAMPLE
    // int x = 2;
    // if (x == 4)
    // {
    //     cout << "x is 4" << endl;
    // }
    // else if (x == 3)
    // {
    //     cout << "x is 3" << endl;
    // }
    // else
    // {
    //     cout << " x is neither 3 nor 4" << endl;
    // }

//---------------------------------"switch" statement--------------------
/*
Unlike most other c++ control structures, the statements can contain multiple statements 
without the use of a compound statement
switch (discreteExpression)
{
    case value1:
        statement (s)
    case value2:
        statement (s)
    ...
    default:
        statement (s)    
}
discrete expression: expression that results in discrete values, integers, characters,
enumerated types. Not floats, doubles, etc
use of "break" keyword prevents this unwanted behavior
default case if optional, is used when no other case matches the expressions value

When the case is matched, the program continues to execute all subsequent statements until
it encounters a break; or reaches the end of the switch block
*/
// EXAMPLE
// int x;
// int i;

// cout << "Enter a value: ";
// cin >> x;
// switch (x)
// {
//     case 3:
//         cout << "3" << endl;
//         break;
//     case 4:
//         cout << "4" << endl;
//     case 5:
//         cout << "5" << endl;
//         break;
//     default:
//         cout << "other" << endl;
    
// }
// -----------------------------while loop---------------------
/*
Used to iterate until a condition is no longer met
While loop syntax
    while (expression)
        statement
The statement should modify the values in expression to be sure the expression
is eventually 0 to prevent infinite loops
The statement can only be one single statement
Could use a compound statement to put multiple statements in the body of a while loop
*/
// EXAMPLE
// int num = 1; //loop condition value
// int fact = 1; //Factorial
//     while (num <= 5)
//     {
//         fact *= num;
//         num++; //dont forget to modify num
//     }
//     cout << "5 factorial is: " << fact << endl;
// ------------------------------do-while loop------------------
/*
Used to interate until a condition is no longer met
Loop body always executed at least once
Do-while loop syntax
    do 
        statement
    while (expression);
The statement should modify the values in expression to be sure the expression is eventually
0 to prevent infinite loops
The statement can only be one single statement
Could use a compound statement to put multiple statements in the body of a do-while loop
*/
// EXAMPLE
// int num = 1; //loop condition value
// int fact = 1; //Factorial
//     do
//     {
//         fact *= num;
//         num++;
//     }
//     while (num <=5);
//         cout << "5 factorial is: " << fact << endl;
// --------------------------for loop-------------------------
/*
Used to iterate until a condition is no longer met
Usually used for count-controlled loops
Initialization, expression, and update are part of for loop
For loop syntax
    for (initialization; expression; update)
        statement
The update should modify the values in expression to be sure the expression is eventually 0
to prevent infinite loops
The statement can only be one single statement
Could used a compound statement to put multiple statements in the body of a for loop
*/
// EXAMPLE
// int num; //loop condition value
// int fact = 1; //Factorial

// for (num = 1; num <= 5; num++)
// {
//     fact *= num;
// }
// cout << "5 factorial is: " << fact << endl;
// --------------------------output formatting-------------------
/*
To specify fixed format (as opposed to scientific notation):
    cout.setf(ios::fixed);
To specify floating point numbers should always contain a decimal point character when output
    cout.setf(ios::showpoint);
To specify number of digits after the decimal point to be output:
    cout.precision(integerValue)
    cout.precision(4);
To specify justification:
    cout.setf(ios::left);
    cout.setf(ios::right);    
*/
// EXAMPLE
// double dVal = 1.0 / 3.0;
// double dVal2 = 1;
// cout << "1. dVal is: " << dVal << endl;
// cout << "1. dVal2 is: " << dVal2 << endl;
// cout.setf(ios::fixed);
// cout.setf(ios::showpoint);
// cout.precision(2);
// cout << "2. dVal is: " << dVal << endl;
// cout << "2. dVal2 is: " << dVal2 << endl;
// ------------------------outout format manupulators------------
/*
Modifying formats can be done via inline manipulators as well
Must #include <iomanip>
To set precision with manipulator:
    cout << setprecision(intValue);
Note: change in precision is permanent
To set width (number of characters output) with manipulator:
    cout << setw(intValue);
Note: change in width is for the immediately following value ONLY!!!
*/
// EXAMPLE
double dVal = 1.0 / 3.0;
double dVal2 = 1;
cout << "1. dVal is: " << dVal << endl;
cout << "1. dVal2 is: " << dVal2 << endl;
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
cout << "2. dVal is: " << dVal << endl;
cout << "2. dVal2 is: " << dVal2 << endl;
cout.setf(ios::left);
cout << "3. dVal is: " << setprecision(4) << dVal << endl;
cout << "3. dVal2 is: " << setw(8) << dVal2 << endl;
cout.setf(ios::right);
cout << "4. dVal is: " << dVal << endl;
cout << "4. dVal2 is: " << setw(8) << dVal2 << endl;
    return 0;
}