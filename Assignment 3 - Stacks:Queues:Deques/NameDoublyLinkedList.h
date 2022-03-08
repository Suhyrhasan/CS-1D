/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #3 : Stacks/Queues/Deques
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/03/2020
 *****************************************************************************/
#ifndef NAMEDOUBLYLINKEDLIST_H_
#define NAMEDOUBLYLINKEDLIST_H_
#include "myheader.h"
class nameDoublyLinkedList
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
	nameDoublyLinkedList();

	/****************************************************************
	 * ~nameSingleLinkedList();
	 * Destructor; Clears the linked list
	 * Parameters: none
	 * Return: none
	 ***************************************************************/
	~nameDoublyLinkedList();

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
	void Push(string name);

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
	void Pop();

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
		nameNode *prev; // linked list prev pointer
	};
	nameNode *head;	// head of the list
	nameNode *rear;	// end of the list
};
#endif /* NAMEDOUBLYLINKEDLIST_H_ */
