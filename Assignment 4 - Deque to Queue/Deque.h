/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #4 : Deque to Queue
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/10/2020
 *****************************************************************************/
#ifndef DEQUE_H_
#define DEQUE_H_
#include "myheader.h"
#include "DLinkedList.h"
typedef string Elem;
/****************************************************************
 * dequeList
 * This class  has all the attributes and methods for dequeList.
 ***************************************************************/
class dequeList
{
public:
	/******************************
	 ** CONSTRUCTOR & DESTRUCTOR **
	 ******************************/

	/****************************************************************
	 * dequeList();
	 * Constructor; Initialize class attributes
	 * Parameters: none
	 * Return: none
	 ***************************************************************/
	dequeList();

	/****************
	 ** MUTATORS **
	 ****************/
	/*******************************************************************
	 * void insertBack(const Elem& e);
	 *
	 * Mutator; This method will create a Node, then add the Node in the
	 *          stack, by adding it to the end of the linked List
	 *------------------------------------------------------------------
	 * Parameter: const Elem& e  // IN - new node
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void insertBack(const Elem& e);

	/*******************************************************************
	 * void removeFront();
	 *
	 * Mutator; This method will remove the stringNode from the stack,
	 *          and delete the stringNode
	 *------------------------------------------------------------------
	 * Parameter: none
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void removeFront(); //deletes the stringNode in the front of the stack

	/***************
	 ** ACCESSORS **
	 ***************/

	/****************************************************************
	 * bool Empty() const;
	 *
	 * Accessor; This method will check if stack is empty
	 * --------------------------------------------------------------
	 * Parameters: none
	 * --------------------------------------------------------------
	 * Return: a boolean expression
	 *******************************************************************/
	bool Empty() const; // check if stack is empty

	/*******************************************************************
	 * 	int Size() const;
	 *
	 * Accessor; This method will return the number of strings
	 *           in the stack
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: Total number of strings in the stack
	 *******************************************************************/
	int Size() const;

	/*******************************************************************
	 * const Elem& Front() const;
	 *
	 * Accessor; This method will return the string at the top of
	 *           the stack
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	const Elem& Front() const;// ouputs the string at the top of the stack
private:
	DLinkedList D;  // Variable to wrap around doubly linked list
	int stackCount; //Counter to keep track of size of the list
};
/****************************************************************
 * dequeList();
 * Constructor; Initialize class attributes
 * Parameters: none
 * Return: none
 ***************************************************************/
dequeList::dequeList()
:D(), stackCount(0){}

/******************************************************************************
 * Method insertBack : Class DequeList
 * ____________________________________________________________________________
 *  This method will create a Node, then add the Node in the stack, by adding
 *  it to the end of the linked List – returns nothing.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	                const Elem& e - New Node
 *
 * POST-CONDITIONS
 * 	This function will create a Node, then add the Node in the stack, by adding
 *  it to the end of the linked List – returns nothing.
 ******************************************************************************/
void dequeList::insertBack(const Elem& e)
{
	D.addBack(e); //calling add function
	stackCount++; //incrementing n
}
/******************************************************************************
 * Method removeFront : Class DequeList
 * ____________________________________________________________________________
 *  This method will remove the Node from the stack, and delete the
 *  stringNode – returns nothing.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	 This function will remove the stringNode from the stack, and delete the
 * 	 stringNode – returns nothing
 ******************************************************************************/
void dequeList::removeFront()
{
	D.removeFront(); //calling remove function
	stackCount--; //decrement
}
/******************************************************************************
 * Method Empty : Class DequeList
 * ____________________________________________________________________________
 *  This method will check if stack is empty  – returns a boolean expression
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	This function will check if stack is empty  – returns a boolean expression
 ******************************************************************************/
bool dequeList::Empty() const
{
	return D.Empty(); //calling empty function
}
/******************************************************************************
 * Method Size : Class DequeList
 * ____________________________________________________________________________
 *  This method will return the number of strings in the stack.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	  This function will return the number of strings in the stack.
 ******************************************************************************/
int dequeList::Size() const
{
	return stackCount; //returning size of queue
}
/******************************************************************************
 * Method Front : Class DequeList
 * ____________________________________________________________________________
 *  This method will return the stringNode at the top of the stack.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	  This function will return the stringNode at the top of the stack.
 ******************************************************************************/
const Elem& dequeList::Front() const
{
	return D.Front(); //return front elem
}

#endif /* DEQUE_H_ */
