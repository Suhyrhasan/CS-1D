/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #3 : Stacks/Queues/Deques
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/03/2020
 *****************************************************************************/
#include "myheader.h"
#include "floatDoublyLinkedList.h"

floatDoublyLinkedList::floatDoublyLinkedList()
{
	head = NULL;
	rear = NULL;
}
floatDoublyLinkedList::~floatDoublyLinkedList(){}
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
void floatDoublyLinkedList::Push(float Float) // IN & OUT - Name.
{
	// CREATE new info perPtr and ALLOCOTE memory
	floatNode* perPtr;
	perPtr = new floatNode();

	// CHECK if stack is full.
	if (!perPtr)
	{
		cout << "\nHeap Overflow";
		exit(1);
	}
	// INITIALIZE data
	perPtr->Float = Float;
	if(head == NULL)
	{
		head = rear = perPtr;
	} else {
		perPtr->next = head;
		head = perPtr;
		rear->next = NULL;
	}
}
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
void floatDoublyLinkedList::Pop()
{
	struct floatNode* perPtr = head;
	// CHECK for stack underflow
	if (head == NULL) {
		cout << "\nCan" << '\'' << "t POP from an empty stack!" << endl;

	}
	else {
		head = head-> next;
		perPtr-> next = NULL;
		// RELEASE memory of top info
		free(perPtr);
	}
}
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
void floatDoublyLinkedList::Display()
{
	// If Statement- will make sure
	// to check if the stack if empty first.
	if(head == NULL)
	{
		cout << "Can" << '\'' << "t display an empty list\n";
	}
	else
	{
		struct floatNode* temp = head;
		while(temp!= NULL)
		{   // Displays the top element of the stack;
			cout << "Float: " << temp -> Float << endl;
			temp = temp-> next;
		}
	}
}
