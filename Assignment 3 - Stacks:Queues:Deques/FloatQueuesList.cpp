/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #3 : Stacks/Queues/Deques
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/03/2020
 *****************************************************************************/
#include "myheader.h"
#include "floatQueuesList.h"

floatQueuesList::floatQueuesList()
{
	head = NULL;
	rear = NULL;
}

floatQueuesList::~floatQueuesList(){}
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
void floatQueuesList::Enqueue(float Float) // IN & OUT - Name.
{
	// CREATE new info perPtr and ALLOCOTE memory
	floatNode* perPtr;
	perPtr = new floatNode();

	// INITIALIZE data
	perPtr->Float = Float;
	if(rear == NULL)
	{
		head = rear = perPtr;
	} else {
		perPtr -> prev = rear;
		rear->next = perPtr;
		rear = perPtr;
		perPtr = NULL;
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
void floatQueuesList::Dequeue()
{
	// CHECK for stack underflow
	if (rear == NULL)
	{
		cout << "\nCan" << '\'' << "t POP from an empty stack!" << endl;
	}
	else
	{
		rear = rear -> prev;
		rear-> next = NULL;
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
void floatQueuesList::Display()
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
