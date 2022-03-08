#include "NameQueuesList.h"
/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #3 : Stacks/Queues/Deques
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/03/2020
 *****************************************************************************/
#include "myheader.h"
#include "NameQueuesList.h"
nameQueuesList::nameQueuesList()
{
	head = NULL;
	rear = NULL;
}
nameQueuesList::~nameQueuesList(){}
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
void nameQueuesList::Enqueue(string name) // IN & OUT - Name.
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
void nameQueuesList::Dequeue()
{
	struct nameNode* perPtr = head;
	// CHECK for stack underflow
	if (head == NULL) {
		cout << "\nCan" << '\'' << "t POP from an empty stack!" << endl;
	}
	else
	{
		head = head-> next;
		perPtr-> next = NULL;
		if(head == NULL)
			rear = NULL;
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
void nameQueuesList::Display()
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
