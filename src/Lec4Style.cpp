//--------------------------tabs----------------------------
/* use linux command grep -P "\t" *.cpp | wc -l to check for tabs in the code
   if returns 0, there are no tabs in cpp source files
   if returns any number other than 0, source code includes many lines with tabs and
     will result in a style deduction
*/
//--------------------------booleans--------------------------
/*
Most bool type variables should be named starting with "do" or "is",
    or something else that implies boolean-ness
Use the c++ literal values true and false
    -isLate = false, clear and easy to read
Dont use "==true" or "==false"
    use "if (isLate)" over "if(isLate == true)"
    use "if (!doRunSimulation)" over "if (doRunSimulation == false)"
*/
//-------------------------identifier naming----------------------
/*
Naming identifiers is incredibly important
    - functions, variables, constants
example: "performSimulation" is named with a verb and therefore is a function
    the name clearly indicates the purpose of the function is to perform the simulation
Consider searchability when naming identifiers
*/
//----------------------disallowing magic numbers------------------
/*
Literal values that shows up in the code are considerend "magic numbers"
Use of vertical whitespace can improve readability
*/
//---------------------indentation consistency----------------------
/*
recommand using exactly two spaces for indentation
*/
//----------------consistant whitespace around operators
/*
always include one space on each side of every binary operator
*/