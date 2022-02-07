# Experiment 6
## Aim : Write a C++ program to use scope resolution operator. Display the various values of the same variables declared at different scope levels.
### Step by Step Procedure of experiment
Step 1 - Include the required header files (iostream.h).

Step 2 - Create a base class 'A1' (Grand_parent) with the following class members as public members. 'a1' as data member and 'display1()' as member function.

Step 3 - Initialise the value of 'a1' by using default constructor and implement display1() function.

Step 4 - Create a class 'A2' (parent) derived from Grand_parent with the following class members as public members. 'a2' as data member and 'display2()' as member function.

Step 5 - Initialise the value of 'a2' by using default constructor and implement display2() function.

Step 6 - Create a class 'A3' (child) derived from parent with the following class members as public members. 'a3' as data member, 'display3()', 'max()' as member functions.

Step 7 - Define the function max() outside the class using scope resolution operator.

Step 8 - Initialise the value of i with 100.

Step 9 - In the main function, Initialise the value of i with 200.

Step 10 - Declare the child class object 'obj' and call the functions max() and display3().

Step 11 - Obtain different values of i using the scope resolution operator.

Step 12 - Stop the program.
