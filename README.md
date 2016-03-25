# SuperNumber
Super number C++ class for infinite numbers

#Coplien
This class is coplien for a usage as easy as a basic type.
It's able to make operations on infinite numbers. Really useful when basic types capacity is limited.

#Usage
This class is really useful in mathematics programs.
For example it's impossible for a 'long' type to calculate factorial of 100.
Use it as a basic numeric type

#Features
Following specifics functions are implemented:

    -   Construction on std::string(mathematics expression as "3+2"), int, unsigned int, long, unsigned long
    -   Every operators +, -, *, %, /, ==, !=, <, >, <=, >=, =, +=, -=, /=, %=, *=, ++(pre, post), --(pre, post)
    -   toNegative, toPositive, isNegative, isPositive
    -   getNumber: returns a string cause of types limitations
    -   Basic types conversion (CAN THROW LOGIC EXCEPTION IF NUMBER DOES NOT FIT)
    -   SwapValues with another SuperNumber
    -   evalExpr for arithmetic evaluation
    -   factorial and pow which are the both functions that grow really fast in high values

Because construction can be made with int, unsigned int, long, unsigned long, all of the following features are available on those types

#DEVELOPPEMENT CURRENTLY IN PROCESS
The code is currently in development