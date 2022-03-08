/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #3 : Stacks/Queues/Deques
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/03/2020
 *****************************************************************************/
#include "myheader.h"
#include "nameSingleLinkedList.h"
/****************************************************************
 * SheepList();
 * Constructor; Initialize class attributes
 * Parameters: none
 * Return: none
 ***************************************************************/
nameSingleLinkedList::nameSingleLinkedList()
{
	head = NULL;
}

/****************************************************************
 * ~SheepList();
 * Destructor; Clears the linked list
 * Parameters: none
 * Return: none
 ***************************************************************/
nameSingleLinkedList::~nameSingleLinkedList(){}
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
void nameSingleLinkedList::Push(string name) // IN & OUT - Name.
{
	// CREATE new info perPtr and ALLOCOTE memory
	nameNode* perPtr;
	perPtr = new nameNode();

	if (perPtr == NULL)
	{
		head = perPtr;
	}
	// INITIALIZE data
	perPtr->name = name;

	perPtr->next = head;
	head = perPtr;
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
void nameSingleLinkedList::Pop()
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
void nameSingleLinkedList::Display()
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
