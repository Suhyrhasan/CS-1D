/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #3 : Stacks/Queues/Deques
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/03/2020
 *****************************************************************************/
#ifndef MYHEADER_H_
#define MYHEADER_H_
#include <stack>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

string PrinterHeader(string asName, int asNum , char asType);
/**************************************************************************
 * Function PrinterHeader - This function receives an assignment name, type
 * 						    and number then outputs the appropriate class
 * 						    heading. asType is defaulted to Lab as there
 * 						    are more labs than Assignments. ==> returns
 * 						    nothing - This will output the class heading.
 *************************************************************************/
void initializeStack(stack<string>& stringStack,stack<float>& floatStack);
/**************************************************************************
 * Function initializeStack - This function will initialize an empty
 *                            string and float Stack.
 *************************************************************************/
bool ArePair(char opening,char closing);
/**************************************************************************
 * Function ArePair - This function will return a boolean expression
 *************************************************************************/
bool AreParanthesesBalanced(string exp);
/**************************************************************************
 * Function AreParanthesesBalanced - This function will return a boolean
 *************************************************************************/

#endif /* MYHEADER_H_ */
