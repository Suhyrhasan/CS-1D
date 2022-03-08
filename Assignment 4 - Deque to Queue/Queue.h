/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #4 : Deque to Queue
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/10/2020
 *****************************************************************************/
#ifndef QUEUE_H_
#define QUEUE_H_
#include "myheader.h"
#include "Deque.h"
typedef string Elem;
/****************************************************************
 * queueList
 * We will make a queue version of a stack ADT and then we will
 * use the members of this class to perform actions in the main
 * program.
 ***************************************************************/
class queueList
{
public:
	/******************************
	 ** CONSTRUCTOR & DESTRUCTOR **
	 ******************************/

	/****************************************************************
	 * queueList();
	 * Constructor; Initialize class attributes
	 * Parameters: none
	 * Return: none
	 ***************************************************************/
	queueList();

	/****************
	 ** MUTATORS **
	 ****************/

	/*******************************************************************
	 * void Enqueue(const Elem& e);
	 *
	 * Mutator; This method will create a Node, then add the Node in the
	 *          stack, by adding it to the end of the linked List
	 *------------------------------------------------------------------
	 * Parameter: const Elem& e  // IN - new node
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void Enqueue(const Elem& e);


	/*******************************************************************
	 * void Dequeue();
	 *
	 * Mutator; This method will remove the Node from the head of the
	 *          the stack, and then delete the Node
	 *------------------------------------------------------------------
	 * Parameter: none
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void Dequeue(); //deletes the stringNode in the end of the stack


	/***************
	 ** ACCESSORS **
	 ***************/

	/****************************************************************
	 * bool Empty();
	 *
	 * Accessor; This method will check if stack is empty
	 * --------------------------------------------------------------
	 * Parameters: none
	 * --------------------------------------------------------------
	 * Return: a boolean expression
	 *******************************************************************/
	bool Empty(); // check if stack is empty

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
	 * Accessor; This method will output the string at the top of
	 *           the stack
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: head node
	 *******************************************************************/
	const Elem& Front() const; // ouputs the string at the top of the stack

private:
	dequeList Q; //Variable to wrap around dequeue
};
/****************************************************************
 * queueList();
 * Constructor; Initialize class attributes
 * Parameters: none
 * Return: none
 ***************************************************************/
queueList::queueList()
: Q(){}

/******************************************************************************
 * Method Enqueue : Class QueueList
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
void queueList::Enqueue(const Elem& e)
{
	Q.insertBack(e);
}
/******************************************************************************
 * Method Dequeue : Class QueueList
 * ____________________________________________________________________________
 *  This method will remove the Node from the stack, and then delete the
 *  Node – returns nothing.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	 This function will remove the stringNode from the stack, and delete the
 * 	 stringNode – returns nothing
 ******************************************************************************/
void queueList::Dequeue()
{
	Q.removeFront();
}
/******************************************************************************
 * Method Empty : Class QueueList
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
bool queueList::Empty()
{
	return Q.Empty();
}
/******************************************************************************
 * Method Size : Class queueList
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
int queueList::Size() const
{
	return Q.Size();
}
/******************************************************************************
 * Method Front : Class QueueList
 * ____________________________________________________________________________
 *  This method will return the Node at the top of the stack.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	  This function will return the Node at the top of the stack.
 ******************************************************************************/
const Elem& queueList::Front() const
{
	return Q.Front();
}

#endif /* QUEUE_H_ */
