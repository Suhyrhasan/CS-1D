/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #2 : Big Oh
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 01/27/2020
 *****************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <sstream>
using namespace std;
/******************************************************************************
 * FUNCTION PrinterHeader
 * ____________________________________________________________________________
 * This function receives an assignment name, type and number then
 * 		outputs the appropriate class heading. asType is defaulted to Lab
 * 		as there are more labs than Assignments.
 * 		==> returns nothing - This will output the class heading.
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	  			  asName : Assignment Name
 * 	  			  asNum  : Assignment Number
 *				  asType : Assignment Type ==> THIS SHOULD CONTAIN:
 *				  							   'L' for Labs
 *				  							   'A' for Assignments
 *
 * POST-CONDITIONS
 * 	  This function will output the class heading.
 ******************************************************************************/
string PrinterHeader(string asName,    // IN - Assignment Name
		int asNum ,                    // IN - Assignment Number
		char asType)                   // IN - Assignment Type ('L' = Lab,
//                       'A' = Assignment)
{
	ostringstream output;
	output << left;
	output << "*****************************************************\n";
	output << "*  PROGRAMMED BY : Suhyr Hasan \n";
	output << "*  " << setw(14) << "STUDENT IDs" << ": 1022520 \n";
	output << "*  " << setw(14) << "CLASS"	     <<": CS1D - MW - 2:30pm - 4:50pm\n";
	output << "*  " ;

	// PROCESSING - This will adjust setws and format appropriately based
	//              based on if this is a lab 'L' or assignment.

	if(toupper(asType) == 'L')
	{
		output << "LAB #" << setw(9);
	}
	else
	{
		output << "ASSIGNMENT #" << setw(2);
	}
	output<< asNum << ": " << asName << endl;
	output << "*****************************************************\n";
	output << right;
	return output.str();
}

/******************************************************************************
 * Function O(N^2)
 * ____________________________________________________________________________
 * This function will
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	  This function
 ******************************************************************************/
int sum(int A[], const int n)
{
	int s = A[0];
	int t = s;
	for(int i = 1; i < n -1; i++)
	{
		s = s + A[i];
		t = t + s;
	}
	return t;
}

/******************************************************************************
 * Big Oh
 * ----------------------------------------------------------------------------
 * This program will
 * ----------------------------------------------------------------------------
 *****************************************************************************/
int main()
{
	cout << PrinterHeader("Big Oh", 2, 'A');
	cout << "\nThis program will .\n\n";
	//int A[MAX]={0};
		int B[MAX]={0};
		//initialize the array
		for(int i=0; i< MAX; i++)
		{
			//intialize two arrays with zero
			A[i]= i+1;
			B[i]= i+1;
		}
	/****************************************************************************
	 *
	 ****************************************************************************/

	return 0;
}
