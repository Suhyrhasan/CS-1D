/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #4 : Deque to Queue
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/10/2020
 *****************************************************************************/
#ifndef MYHEADER_H_
#define MYHEADER_H_
#include <string>
#include <iomanip>
#include <sstream>
#include <iostream>
using namespace std;
typedef string Elem;
struct DNode
{
	Elem elem; //element of the list
	DNode*prev; //pointer to previous node
	DNode* next; //pointer to next node
};
string PrinterHeader(string asName, int asNum , char asType);
/**************************************************************************
 * Function PrinterHeader - This function receives an assignment name, type
 * 						    and number then outputs the appropriate class
 * 						    heading. asType is defaulted to Lab as there
 * 						    are more labs than Assignments. ==> returns
 * 						    nothing - This will output the class heading.
 *************************************************************************/
#endif /* MYHEADER_H_ */
