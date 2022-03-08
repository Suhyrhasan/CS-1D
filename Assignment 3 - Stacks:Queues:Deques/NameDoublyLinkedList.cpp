/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #3 : Stacks/Queues/Deques
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/03/2020
 *****************************************************************************/
#include "myheader.h"
#include "nameDoublyLinkedList.h"
/****************************************************************
 * SheepList();
 * Constructor; Initialize class attributes
 * Parameters: none
 * Return: none
 ***************************************************************/
nameDoublyLinkedList::nameDoublyLinkedList()
{
	head = NULL;
	rear = NULL;
}

/****************************************************************
 * ~SheepList();
 * Destructor; Clears the linked list
 * Parameters: none
 * Return: none
 ***************************************************************/
nameDoublyLinkedList::~nameDoublyLinkedList(){}
/******************************************************************************
 * FUNCTION PushName
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
void nameDoublyLinkedList::Push(string name) // IN & OUT - Name.
{
	// CREATE new info perPtr and ALLOCOTE memory
	nameNode* perPtr;
	perPtr = new nameNode();

	// CHECK if stack is full.
	if (!perPtr)
	{
		cout << "\nHeap Overflow";
		exit(1);
	}

	// INITIALIZE data
	perPtr->name = name;
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
void nameDoublyLinkedList::Pop()
{
	struct nameNode* perPtr = head;
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
 * FUNCTION DisplayMenu
 * ____________________________________________________________________________
 * This function will output the entire list and their MovieRecrmation
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	  This function will display the entire list formated.
 ******************************************************************************/
void nameDoublyLinkedList::Display()
{
	// If Statement- will make sure
	// to check if the stack if empty first.
	if(head == NULL)
	{
		cout << "Can" << '\'' << "t display an empty list\n";
	}
	else
	{
		struct nameNode* temp = head;
		while(temp!= NULL)
		{   // Displays the top element of the stack;
			cout << "Name:  " << temp -> name << endl;
			temp = temp-> next;
		}

	}
}
