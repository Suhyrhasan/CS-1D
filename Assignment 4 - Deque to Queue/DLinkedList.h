/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #4 : Deque to Queue
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/10/2020
 *****************************************************************************/
#ifndef DLINKEDLIST_H_
#define DLINKEDLIST_H_
#include "myheader.h"
typedef string Elem;
/****************************************************************
 * DLinkedList
 * This class represents an stack list object.
 ***************************************************************/
class DLinkedList
{
public:
	/******************************
	 ** CONSTRUCTOR & DESTRUCTOR **
	 ******************************/

	/****************************************************************
	 * DLinkedList();
	 * Constructor; Initialize class attributes
	 * Parameters: none
	 * Return: none
	 ***************************************************************/
	DLinkedList();

	/****************************************************************
	 * ~DLinkedList();
	 * Destructor; Clears the linked list
	 * Parameters: none
	 * Return: none
	 ***************************************************************/
	~DLinkedList();

	/****************
	 ** MUTATORS **
	 ****************/

	/*******************************************************************
	 * void addBack(const Elem& e);
	 *
	 * Mutator; This method will create a Node, then add the Node in the
	 *          stack, by adding it to the end of the linked List
	 *------------------------------------------------------------------
	 * Parameter: const Elem& e  // IN - new node
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void addBack(const Elem& e);

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
	 * const Elem& Front() const;
	 *
	 * Accessor; This method will output the string at the top of
	 *           the stack
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: the head node
	 *******************************************************************/
	const Elem&Front()const;// Outputs the string at the top of the stack

protected:
	DNode *head; //pointing to the head
	DNode *rear; //node to point to the rear
};
/****************************************************************
 * DLinkedList();
 * Constructor; Initialize class attributes
 * Parameters: none
 * Return: none
 ***************************************************************/
DLinkedList::DLinkedList()
{
	head = NULL;
	rear = NULL;
}
/****************************************************************
 * ~DLinkedList();
 * Destructor; Clears Linked List
 * Parameters: none
 * Return: none
 ***************************************************************/
DLinkedList::~DLinkedList()
{
	while (!Empty())
	{
		delete head; // remove the head
		delete rear;// remove the rear
	}
}
/******************************************************************************
 * Method addBack : Class DLinkedList
 * ____________________________________________________________________________
 *  This method will create a Node, then add the Node in the stack, by adding
 *  it to the end of the linked List – returns nothing.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	                const Elem& e - New String Node
 *
 * POST-CONDITIONS
 * 	This function will create a Node, then add the Node in the stack, by adding
 *  it to the end of the linked List – returns nothing.
 ******************************************************************************/
void DLinkedList::addBack(const Elem& e)
{
	// CREATE new stringNode perPtr and ALLOCOTE memory
	DNode *perPtr= new DNode;
	perPtr->elem = e;
	// For first node
	if (head == NULL)
	{
		head = rear = perPtr;
	}
	else
	{
		// adds the new node
		rear ->next = perPtr;
		rear = perPtr;
	}
	cout << "Adding String: " << rear->elem << endl;
}
/******************************************************************************
 * Method removeFront : Class DLinkedList
 * ____________________________________________________________________________
 *  This method will remove the stringNode from the stack, and delete the
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
void DLinkedList::removeFront()
{
	// stores the head to be returned
	DNode *perPtr = head;; // CALC - node to be deleted
	// CHECK for queue underflow
	if (perPtr == NULL)
	{
		cout << "Can" << '\'' << "t DEQUEUE from an empty list!";
		cout << endl << endl;
	}
	else
	{
		cout << "DEQUEUEING"<<endl;
		cout << "String: " << perPtr ->elem << endl << endl;
		head = head ->next;
		perPtr->next = NULL;

		// RELEASE memory of front stringNode
		free(perPtr);
	}
}
/******************************************************************************
 * Method Empty : Class DLinkedList
 * ____________________________________________________________________________
 *  This method will check if stack is empty  – returns an integer
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	  This function will check if stack is empty  – returns an integer.
 ******************************************************************************/
bool DLinkedList::Empty() const
{
	//CONDITION to check for an empty list
	return head == NULL;
}
/******************************************************************************
 * Method Front : Class DLinkedList
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
const Elem&DLinkedList::Front()const
{
	DNode *perPtr = head;
	return(perPtr->elem); //returning front element
}
#endif /* DLINKEDLIST_H_ */
