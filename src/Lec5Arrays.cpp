#include <iostream> //Req'd for cout(out put to screen)
#include <iomanip>
#include <cmath> // required, even if you happen to use an IDE that allows you get away without it
using namespace std; //to avoid typing it over and over again

// write a program to input 3 ints and output each value and their sum

// int main(){
// int i0, i1, i2;
// int sum;

// cout << "Enter int #1: ";
// cin >> i0;
// cout << "Enter int #2: ";
// cin >> i1;
// cout << "Enter int #3: ";
// cin >> i2;

// cout.setf(ios::right);
// cout << " " << setw(4) << i0 << endl;
// cout << "+ " << setw(4) << i1 << endl;
// cout << "+ " << setw(4) << i2 << endl;
// cout << "--------" << endl;

// sum = i0 + i1 + i2;
// cout << " " << setw(4) << sum << endl;
// }
// when number of int for user to provide gets too large, the above code is no longer good
//---------------------------intro to arrays--------------------------
/*
Array: a list of variables, all of the same data type that can be accessed vis a common name
the length of an array (the number of elements in the list) can be of any fixed length
Syntax for declaring an array:
    -dataType arrayName[arrayLength];
        -dataType: Any available data type (int, float, user-defined types, etc)
        -arrayName: The name of the array
        -arrayLength: The number of elements that can be accessed via this array
Example:
    -int quizGrades[10];
        -declares an array of 10 integer elements, with the name "quizGrades"
Individual elements of the array are accessed by "indexing"
    -to index into an array, used square brackets
    -in C/C++ array indices start at 0, and end at (length-1)
If an int variable requires 4 bytes of memory, then the declaration:
    -int quizGrades[10];
    -sets aside 40 bytes (10 ints at 4 bytes each) of memory
    -elements can be accessed using the following:
        -quizGrades[0], quizGrades[1]
*/
//-----------------------arrays stored in memory------------------------
/*
Array elements are always stored in contiguous memory locations
    -this is what makes arrays so powerful
    -any individual element can be accessed very quickly
        -knowledge of the element size and the memory address of the first element 
            is all that is needed to determine the location of any element
        -elementAddress = ArrayStartAddress + (Index * sizeOfArrayElement(bytes of memory))
*/
//--------------------using an array for the sum program--------------------
// the sum program can be rewritten using a single array
// int main(){
// const int ARRAY_LENGTH = 5;
// int i;
// int valsToSum[ARRAY_LENGTH];
// int sum = 0;
// for (i = 0; i < ARRAY_LENGTH; i++)
// {
//     cout << "Enter int #" << i+1 << ": ";
//     cin >> valsToSum[i];
// }
// cout.setf(ios::right);
// cout << " " << setw(4) << valsToSum[0] << endl;

// for (i = 1; i < ARRAY_LENGTH; i++)
// {
//     cout << "+ " << setw(4) << valsToSum[i] << endl;
// }
// cout << "--------" << endl;

// for (i = 0; i < ARRAY_LENGTH; i++)
// {
//  sum += valsToSum[i];
// }
// cout << " " << setw(4) << sum << endl;
// }
//-------------------------------Array bounds------------------------------
/*
C/C++ does not do any bounds checking for you
    -Assumption is that programmer knows what he/she is doing
    -Formula for computing element address is used, even if index value is
        out-of-bounds for the array
*/
// example: this does not give any compil-time warnings or errors, nor does it give any 
//          run-time errors
// int main()
// {
//     int i;
//     int ary[4]; // initialize an array of size 4
//     int var = 0;
//     for (i = 1; i <= 4; i++)
//     {
//         cout << "Enter int #" << i << ": ";
//         cin >> ary[i];
//     }    
//     cout << "Var: " << var << endl;
//     return 0;
// }
//---------------------more on array bounds-------------------------
/*
Why doesn't C/C++ do tange checking for you?
    -Efficiency
        -Arrays are used a lot in programming
        -If every time an array was indexed, the computer had to do array bound checking,
            things would be very slow
Segmentation fault: index is off far enough such that the memory address computed
    does not belong to the program
*/
//--------------------segmentation faults-----------------------
/*
Segmentation fulats occur when your program tries to access a memory location that
    does not belong to your program
A seg fault is considered to be a "crash" of the program
Just because the program didn't seg fault, does not mean there were no bounds problems
*/
//EXAMPLE
// int main()

// {
//     int ary[4];
//     ary[0] = 10;
//     cout << "Set ary[0]" << endl;
//     ary[3] = 20;
//     cout << "Set ary[3]" << endl;
//     ary[9] = 30;
//     cout << "Set ary[9]" << endl;
//     ary[185] = 40;
//     cout << "Set ary[185]" << endl;
//     ary[600] = 50;
//     cout << "Set ary[600]" << endl;
//     ary[900] = 60;
//     cout << "Set ary[900]" << endl;
//     return (0);
// }
//--------------initializing array values----------------------
/*
array values can be initialized at the time they are declared
    -Assigned to comma-separated list of values enclosed in curly braces
    -If array length is unspecified, it is assumed to be exact size to fit initial values
        int oddary[5] = {1, 3, 5, 7, 9}; // These two are
        int addary2[] = {1, 3, 5, 7, 9}; // equivalent
    -If length is specified, but not enough initial valus are provided, extra
     values are initialized to zero
        int zeroAry[100] = {0}; // 100 zeros
        int careful[100] = {100}; // 100 followed by 99 zeros
    -Use a loop to assign all elements to a specific value
        int aryOf100s[100]; // uninitialized
        for (i=0; i<100; i++)
        {
            aryOf100s[i] = 100; // all elements assign to 100
        }
*/
//---------------array elements as function parameters---------------
/*
Given the following array declaration:
    -int ary[5];
    -Indexing into the array results in an int
    -This int can be used anywhere an int can be used
*/
// void printInt (int val)
// {
//     cout << "Int is: " << val << endl;
// }
// int main()
// {
//     int iary[5] = {3, 5, 7, 9, 11};

//     printInt(iary[3]);
//     printInt(iary[4]);
//     return 0;
// }
//----------------whole array as function parameters---------------
/*
Entire array can be passed into a function
*/
// int sumAry(
//     int num, //# of elems in ary
//     int ary[] //array of vals to sum
//     )
// {
//     int sum = 0;
//     int i;

//     for (i = 0; i < num; i++)
//     {
//         sum += ary[i];
//     }
//     return sum;
// }
// int main()
// {
//     int iary[5] = {3, 5, 7, 9, 11};
//     int x;

//     x = sumAry(5, iary);
//     cout << "Sum: " << x << endl;

//     return 0;
// }
//----------------array passed by reference----------------------
/*
Arrays are passed by reference by default
    -No special syntax(no '&') is requried to pass arrays by reference
Why?
    -pass-by-value implied a copy is made
    -is arrays were passed-by-value, every element of the entire array
     would have to be copied
       *For large arrays especially, this would be ectremely slow
       *Also uses a lot of memory to duplicate the array
Changing contents of an array inside a function changes the array as stored
 in the calling function as well
*/
// void sumArys(int num, int a[], int b[], int c[])
// {
//     int i;
//     for (i = 0; i < num; i++)
//     {
//         c[i] = a[i] + b[i];
//     }
// }
// int main()
// {
//     int i;
//     int iary1[5] = {3, 5, 7, 9, 11};
//     int iary2[5] = {2, 4, 6, 8, 10};
//     int iary3[5]; // uninitialized

//     sumArys(5, iary1, iary2, iary3);
    
//     for (i = 0; i < 5; i++)
//     {
//         cout << "iary3[" << i << "]: " << iary3[i] << endl;
//     }
//     return 0;
// }
// changing "c" array in sumArys changes "iary3" in main, since arrays are
// pass by reference by default
/*
If you want to prevent array contents from changing in a function,
use keyword "const"
    -Results in array being passed by "constant reference"
    -Array is still passed by reference - no inefficient copy is made
    -Keyword const prevents contents from being modified in the function
Why bother?
    -To protect yourslef from making mistakes
    -What would output of previous program if sumArys was as follows:
*/
// void sumArys(int num, const int a[], const int b[], int c[])
// {
//     int i;
//     for (i = 0; i < num; i++)
//     {
//         // c[i] = a[i] + b[i];
//         a[i] = b[i] + c[i];
//     }
// }
// int main()
// {
//     int i;
//     int iary1[5] = {3, 5, 7, 9, 11};
//     int iary2[5] = {2, 4, 6, 8, 10};
//     int iary3[5]; // uninitialized

//     sumArys(5, iary1, iary2, iary3);
    
//     for (i = 0; i < 5; i++)
//     {
//         cout << "iary3[" << i << "]: " << iary3[i] << endl;
//     }
//     return 0;
// }
// above code provides a compile-time error, preventing problems resulting from this mistake
//---------------using variables as array sizes-------------------------
/*
Array sizes must be specified as CONSTANTS!
    -Named constants: NUM_QUIZZES, TOTAL_STUDENTS
    -Literal Values: 10, 62, etc
Array sizes van not be a variable
The following program should ot compile!
General rule: declare all variables at begining of function
    -prevents any possibility of below program from being written
*/
//This is an invalid program
// int main()
// {
//     int num;

//     cout << "Enter length of array: ";
//     cin >> num;
//     int iary[num]; // num is not constant!
//     cout << "Final array is: " << iary[1] << endl;
//     return 0;
// }
//----------------problem: segmentation fault------------------------
// int main(void)
// {
//     const int SIZE = 5;
//     int i;
//     int iary[SIZE] = {2, 4, 6, 8, 10};

//     while (i < SIZE)
//     {
//         cout << iary[i] << endl;
//         i++;
//     }
//     return 0;
// }
// reason: i is not initialized, it can contain any garbage value, the loop
// could access memory outside of the array's bounds, leading to segmentaiton fault
//-------------------another problem: never ending while loop---------------------------
// int main(void)
// {
//     const int SIZE = 5;
//     int i = 0; // initialize to 0 this time
//     int iary[SIZE] = {2, 4, 6, 8, 10};

//     while (i < SIZE)
//     {
//         // cout << iary[i] << endl;
//         iary[i]++; // the value of first element of the array has been imcremented
//                     // from 2 to 3 each loop
//         cout << iary[i] << endl;
//         i++;
//     }
//     return 0;
// }
/*
reason: iary[i]++ increments the value of array element at index i
i is never been incremented, it stays at 0 and the while loop
consition is therefore always true
*/
//--------------------two-dimensional arrays------------------------
/*
Arrays are not limited to one dimension
2-D array is often called a matrix (with rows and columns)
Syntax for a 2-D array is similar to a 1-D
    -dataType arrayName[numRows][numCols];
While there are 2 dimensions, each element must still be of the same data type
To declare a 6x6 matrix (6 rows, 6 columns)
    -int matrix[6][6];
If ints are stored in 4 bytes, then the above declaration sets aside
    6*6*4 = 144 bytes of memory
A 2-D array is really just a 1-D array, where each individual
    element is itself a 1-D array
Initialization of 1-D array was a comma separates list of values
    enclosed in curly braces
2-D array initialization is an initializatino of a 1-D array of 1-D array
As with all arrays, 2-D arrays are stored contiguously in memory
    -Row 2's elements are stored immediately following the last element from row 1
As with 1-D arrays, any element's address can be computed very quickly
    -elemAddre = staringAddre + (#Columns*Rowindex)*elementSize + ColumnIndex*ElementSize
*/
// Individual elements can be assigned using two sets of brackets
// int main()
// {
// int i;
// int j;
// int matrix[6][6];
// for (i = 0; i < 6; i++)
// {
//     for (j = 0; j < 6; j++)
//     {
//         matrix[i][j] = (i + 1) * (j + 1);
//         cout << matrix[i][j] << endl;
//     }
// }
//     return 0;
// }
//---------------use single element anywhere variable  of that type can be used---------
// void printInt(int i)
// {
//     cout << "Int is: " << i << endl;
// }

// int main()
// {
//     int matrix[3][2] = {{2, 4}, {6, 8}, {10, 12}};

//     printInt(matrix[1][0]);
//     printInt(matrix[2][1]);

//     return 0;
// }
//---------------------Using rows of 2-D arrays-----------------
//Since a 2-D array is a 1-D array of 1-D arrays, each row can be used
// in a 1-D array
// int sumAry(
//     int num, //# of elems in ary
//     const int ary[] //array of vals to sum, row in this case
// )
// {
// int sum = 0;
// int i;
//     for (i = 0; i < num; i++)
//     {
//         sum += ary[i];
//     }
//     return sum;
// }
// int main()
// {
//     int matr[3][5] = {{3, 5, 7, 9, 11},
//                       {2, 4, 6, 8, 10},
//                       {1, 2, 3, 4, 5}};
//     int x;

//     x = sumAry(5, matr[0]);
//     cout << "Row1 Sum: " << x << endl;
//     x = sumAry(5, matr[1]);
//     cout << "Row2 Sum: " << x << endl;

//     return 0;
// }
//-----------------whole 2-D arrays as parameters----------------
/*
When passing a 2-D array as a parameter, function must know the number of columns
    -Recall this is required in order to compute address of an element
    -First dimension can be left unspecified, second dimension cannot
*/
// void printAry(int rows,
//               const char ary[][2])
// {
//     int i;
//     int j;
//     for (i = 0; i < rows; i++)
//     {
//         for (j = 0; j < 2; j++)
//         {
//             cout << ary[i][j] << " ";
//         }
//         cout << endl;
//     }
// }
// int main()
// {
//     char matrix[3][2] = {{'a', 'b'},
//                         {'c', 'd'},
//                         {'e', 'f'}};
//     printAry(3, matrix);
//     return 0;
// }
//-----------------3-D arrays-------------------------
/*
C++ arrays can have as many dimensions as necessary
1-D array: list of values
2-D array: matrix of values, consisting of rows and columns
3-D array: cube of values, consisting of rows, columns and layers
    -in other words, a 3-D array is a 1-D array of matrices
*/