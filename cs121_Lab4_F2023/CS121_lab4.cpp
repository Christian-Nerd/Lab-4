

///////////////////////////////////////////////////////////////////////////////
//
// File Name         : CS121_lab4.cpp
//
// This program determines a student's grade
// based on the average of three test scores.
//
// Programmer        : B.J. Streller  Trey Davis
//
// Date Written      : 9/26/23
//
// Date Last Revised : 10/9/23
//
///////////////////////////////////////////////////////////////////////////////




#include<iostream>										// need cin,cout,etc.
#include<iomanip>										// need setf,precision
using namespace std;



// prototype declarations

void    getTests ( int testArray[]);		//prompts for tests and validate
double  average ( int testArray[] );		//computes average
char    results ( double Average_Of_Tests, int testArray[]);//determines final grade
void    print (int testArray[], double ave, char letterGrade);//print results







///////////////////////////////////////////////////////////////////////////////



int  main( )
{

    int     tests[3];								// array to hold 3 tests
    double  Average_Of_Tests = 0.0;					// average of tests
    char    Grade;									// course grade

    for (int j = 0; j < 3; j++)
    {
        tests[j] = 0;
    }

    getTests( tests );							//function call to get tests
    Average_Of_Tests = average( tests );		//function call to compute average
    Grade = results( Average_Of_Tests, tests );	//function call to detrmine grade
    print( tests, Average_Of_Tests, Grade );	//function call to print tests

    return 0;

}


///////////////////////////////////////////////////////////////////////////////







///////////////////// greet function //////////////////////////////////////////
//
// Function name: getTests
//
// Purpose: prompt user for three test scores; validates entries;
//			prints any re-entered score
//
// Input parameters: an integer array to store tests
//
// Output parameters: an integer array to storing tests
//
// Return Value: none
//
///////////////////////////////////////////////////////////////////////////////


void getTests( int testArray[] )
{
    int testNumber = 1;		//counter to display test 1,test 2 and test 3
    int i = 0;	           //counter to loop through array
    
    cout << "Enter your 3 tests" << endl << endl;
    for (i; i < 3; i++) // Trey: Enters the 3 tests.
    {
        int test;
        cin >> test;
        testArray[i] = test;
        if (testArray[i] > 100 || testArray[i] < 0) 
        {
            cout << "Invalid input please input your test again ";
            --i;
        }
    }
    //use for loop to get tests and validate user input
    //use array testArray to store the tests

}




///////////////////// average function ////////////////////////////////////////
//
// Function name: average
//
// Purpose: calculates the average of the three tests that the user entered
//
// Input parameters: an integer array to store tests
//
// Output parameters: none
//
// Return Value: the average of tests
//
///////////////////////////////////////////////////////////////////////////////


double average ( int testArray[] )

{
    //local variable declarations

    double sum = 0.0,		// sum of the tests
           ave = 0.0;		// average of tests
    int testNumber = 0;
    for(int x = 0; x < 3; x++) 
    {
        sum += testArray[x];
    }
    //compute test average and return the average, ave
    ave = sum / 3;
    return ( ave );


}



//////////////////// results function ////////////////////////////////////////
//
// Function name: results
//
// Purpose: determines the course grade from Average_Of_Tests
//
// Input parameters: the test average and integer array to store tests
//
// Output parameters: none
//
// Return Value: a character indicating letter grade
//
///////////////////////////////////////////////////////////////////////////////



char  results ( double Average_Of_Tests,  int testArray[] )
{
    // local variable declaration
    char grd = ' ';					// course grade

    //computations to determin letter grade
    if (Average_Of_Tests > 90)
    {
        grd = 'A';
    }

    else if (Average_Of_Tests < 90 && Average_Of_Tests >= 80) 
    {
        grd = 'B';
    }

    else if (Average_Of_Tests < 80 && Average_Of_Tests >= 70) 
    {
        grd = 'C';
    }

    else if (Average_Of_Tests < 70 && Average_Of_Tests >= 60)
    {
        grd = 'D';
    }

    else if (Average_Of_Tests < 60)
    {
        grd = 'F';
    }

    return ( grd );

}




//////////////////// print function ////////////////////////////////////////
//
// Function name: print
//
// Purpose: prints data echo, test average (two decimal places)
// 			and the course grade
//
// Input parameters: the test average and integer array to store tests
//					 and the course grade
//
// Output parameters: none
//
// Return Value: none
//
///////////////////////////////////////////////////////////////////////////////

void print (int testArray[], double ave, char letterGrade )
{

    cout.setf(ios::fixed|ios::showpoint);			// show the decimal point
    cout << setprecision(2);						// show two decimal places

    cout << " \n You have entered the following three test grades : " // data echo
         << " \n " << testArray[0] << " for test 1, " << testArray[1] << " for"
         << " test 2, and " << testArray[2] << " for test 3, " << "\n\n ";

    cout << " The average of the three tests that you"               // print average
         << " entered is : "<< ave << "\n ";

    cout << " Your course grade is "<< letterGrade << "."<< "\n\n\n"; //print final grade

}





















