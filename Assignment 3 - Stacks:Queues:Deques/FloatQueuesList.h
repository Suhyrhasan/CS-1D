/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #3 : Stacks/Queues/Deques
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/03/2020
 *****************************************************************************/
#ifndef FLOATQUEUESLIST_H_
#define FLOATQUEUESLIST_H_
#include "myheader.h"
/****************************************************************
 * class SheepList
 * This class represents an sheep object. It manages a linked
 * list
 ***************************************************************/
class floatQueuesList
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
	floatQueuesList();

	/****************************************************************
	 * ~nameSingleLinkedList();
	 * Destructor; Clears the linked list
	 * Parameters: none
	 * Return: none
	 ***************************************************************/
	~floatQueuesList();

	/****************
	 ** MUTATORS **
	 ****************/

	/*******************************************************************
	 * void Push(string name);
	 *
	 * Mutator; This method will add a new name to the end of the list
	 *------------------------------------------------------------------
	 * Parameter: newName (string)  // IN - New String Name
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void Enqueue(float Float);

	/***************
	 ** ACCESSORS **
	 ***************/

	/*******************************************************************
	 * 	Sheep FindSheep(string sheepName) const;
	 *
	 * Accessor; This method will delete the top node in the stack
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void Dequeue();

	/*******************************************************************
	 * void DisplayStack() const;
	 *
	 * Accessor; This method will output the entire linked list
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void Display(); // Output sheep objects in table

private:
	struct floatNode
	{
		float Float;     // store names
		floatNode *next; // linked list next pointer
		floatNode *prev; // linked list prev pointer
	};
	floatNode *head;	// head of the list
	floatNode *rear;	// end of the list
};

#endif /* FLOATQUEUESLIST_H_ */
