/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #3 : Stacks/Queues/Deques
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/03/2020
 *****************************************************************************/
#ifndef FLOATSINGLELINKEDLIST_H_
#define FLOATSINGLELINKEDLIST_H_
#include "myheader.h"
/****************************************************************
 * class SheepList
 * This class represents an sheep object. It manages a linked
 * list
 ***************************************************************/
class floatSingleLinkedList
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
	floatSingleLinkedList();

	/****************************************************************
	 * ~nameSingleLinkedList();
	 * Destructor; Clears the linked list
	 * Parameters: none
	 * Return: none
	 ***************************************************************/
	~floatSingleLinkedList();

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
	void Push(float Float);

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
	struct floatNode
	{
		float Float;    // store names
		floatNode *next; // linked list next pointer
	};
	floatNode *head;	// head of the list
};
#endif /* FLOATSINGLELINKEDLIST_H_ */
