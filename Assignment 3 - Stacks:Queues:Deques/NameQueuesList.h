/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #3 : Stacks/Queues/Deques
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/03/2020
 *****************************************************************************/
#ifndef NAMEQUEUESLIST_H_
#define NAMEQUEUESLIST_H_

#include "myheader.h"
class nameQueuesList
{
public:
	/******************************
	 ** CONSTRUCTOR & DESTRUCTOR **
	 ******************************/

	/****************************************************************
	 * nameSingleLinkedList();
	 * Constructor; Initialize class attributes
	 * Parameters: none
	 * Return: none
	 ***************************************************************/
	nameQueuesList();

	/****************************************************************
	 * ~nameSingleLinkedList();
	 * Destructor; Clears the linked list
	 * Parameters: none
	 * Return: none
	 ***************************************************************/
	~nameQueuesList();

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
	void Enqueue(string name);

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
	struct nameNode
	{
		string name;    // store names
		nameNode *next; // linked list next pointer
	};
	nameNode *head;	// head of the list
	nameNode *rear;	// head of the list
};

#endif /* NAMEQUEUESLIST_H_ */
