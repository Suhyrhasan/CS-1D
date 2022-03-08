/******************************************************************************
 * AUTHOR		 : Suhyr Hasan and Tanner Cordero, and Danin Namiranian
 * STUDENT ID 	 : 1022520, 1084772, and 1081970
 * Assignment #12: Dijkstra and MST
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 04/22/2020
 *****************************************************************************/
#ifndef MYHEADER_H_
#define MYHEADER_H_
#include <list>
#include <queue>
#include <vector>
#include <string>
#include <climits>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <functional>
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
		int asNum,                    // IN - Assignment Number
		char asType)                   // IN - Assignment Type ('L' = Lab,
//                       'A' = Assignment)
{
	ostringstream output;
	output << left;
	output << "***************************************************************************\n";
	output << "*  PROGRAMMED BY : Suhyr Hasan and Tanner Cordero, and Danin Namiranian\n";
	output << "*  " << setw(14) << "STUDENT IDs" << ": 1022520, 1084772, and 1081970 \n";
	output << "*  " << setw(14) << "CLASS"	     <<": CS1D - MW - 2:30pm - 4:50pm\n";
	output << "*  " ;

	// PROCESSING - This will adjust setws and format appropriately based
	//              based on if this is a lab 'L' or assignment.

	if (toupper(asType) == 'L')
	{
		output << "LAB #" << setw(9);
	}
	else
	{
		output << "ASSIGNMENT #" << setw(2);
	}
	output << asNum << ": " << asName << endl;
	output << "***************************************************************************\n";
	output << right;
	return output.str();
}
#endif /* MYHEADER_H_ */
