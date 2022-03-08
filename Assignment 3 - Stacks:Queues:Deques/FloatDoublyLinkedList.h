/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #3 : Stacks/Queues/Deques
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/03/2020
 *****************************************************************************/
#ifndef FLOATDOUBLYLINKEDLIST_H_
#define FLOATDOUBLYLINKEDLIST_H_
#include "myheader.h"

class floatDoublyLinkedList
{
public:
	/******************************
	 ** CONSTRUCTOR & DESTRUCTOR **
	 ******************************/

	/****************************************************************
	 * floatSingleLinkedList();
	 * Constructor; Initialize class attributes
	 * Parameters: none
	 * Return: none
	 ***************************************************************/
	floatDoublyLinkedList();

	/****************************************************************
	 * ~nameSingleLinkedList();
	 * Destructor; Clears the linked list
	 * Parameters: none
	 * Return: none
	 ***************************************************************/
	~floatDoublyLinkedList();

	/****************
	 ** MUTATORS **
	 ****************/

	/******************************************************************************
	 * FUNCTION Push
	 * ____________________________________________________________________________
	 * This function will add an element data in the stack
	 *
	 * PRE-CONDITIONS
	 * 	  The following parameters need to have a defined value prior to calling
	 * 	  the function:
	 * 	               newName   = string name
	 * POST-CONDITIONS
	 * 	  This function will not return anything
	 ******************************************************************************/
	void Push(float Float);

	/***************
	 ** ACCESSORS **
	 ***************/

	/******************************************************************************
	 * FUNCTION Pop
	 * ____________________________________________________________________________
	 * This function will remove the top element from the stack
	 *
	 * PRE-CONDITIONS
	 * 	  The following parameters need to have a defined value prior to calling
	 * 	  the function:
	 *
	 * POST-CONDITIONS
	 * 	  This function will output the top element's information.
	 ******************************************************************************/
	void Pop();

	/******************************************************************************
	 * FUNCTION Display
	 * ____________________________________________________________________________
	 * This function will output the entire list
	 * PRE-CONDITIONS
	 * 	  The following parameters need to have a defined value prior to calling
	 * 	  the function:
	 *
	 * POST-CONDITIONS
	 * 	  This function will display the entire list formated.
	 ******************************************************************************/
	void Display(); // Output sheep objects in table

private:
	struct floatNode
	{
		float Float;     // store names
		floatNode *next; // linked list next pointer
	};
	floatNode *head;	// head of the list
	floatNode *rear;	// end of the list
};
#endif /* FLOATDOUBLYLINKEDLIST_H_ */
