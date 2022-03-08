/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #6 : Priority Queues
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/26/2020
 *****************************************************************************/
#ifndef QUEUE_H_
#define QUEUE_H_
#include "myheader.h"
#include <vector>
/****************************************************************
 * Queue
 * This class represents an queue list object.
 ***************************************************************/
template <class Type> class Queue
{
public:
	/****************
	 ** MUTATORS **
	 ****************/
	/*******************************************************************
	 * void Push(Type x);
	 *
	 * Mutator; This method will inserts an element into the queue
	 *------------------------------------------------------------------
	 * Parameter: Type x - New Element
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void Push(Type x); //inserts element

	/*******************************************************************
	 * void Pop();
	 *
	 * Mutator; This method will remove top element.
	 *------------------------------------------------------------------
	 * Parameter: none
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void Pop();//removes top element

	/***************
	 ** ACCESSORS **
	 ***************/

	/*******************************************************************
	 * bool isEmpty();
	 *
	 * Accessor; This method will check if the queue empty
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: boolean expression
	 *******************************************************************/
	bool isEmpty(); //checks if empty
	/*******************************************************************
	 * Type Front();
	 *
	 * Accessor; This method will get the front element.
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: front element
	 *******************************************************************/
	Type Front();

	/*******************************************************************
	 * int Size();
	 *
	 * Accessor; This method will return the size of the queue
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: int size of queue
	 *******************************************************************/
	int Size();

private:
	//private members
	std::vector<Type> queue;
	void queueDown(int x);
	void queueUp(int x);
};
/******************************************************************************
 * Method Push: Class Queue
 * ____________________________________________________________________________
 *  This method will inserts an element into the queue.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               Type x - New Element
 *
 * POST-CONDITIONS
 * 	  This function will inserts an element into the queue.
 ******************************************************************************/
template <class Type>
void Queue<Type>::Push(Type x)
{
	//insert the element at top
	queue.push_back(x);

	//get the index of the insert
	int index = Size() - 1;

	//restore the heap order
	queueUp(index);
}

/******************************************************************************
 * Method Pop: Class Queue
 * ____________________________________________________________________________
 *  This method will remove front element.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	  This function will remove front element.
 ******************************************************************************/
template <class Type>
void Queue<Type>::Pop()
{
	//deletes the element at top
	queue[0] = queue.back();
	queue.pop_back();

	queueDown(0);
}
/******************************************************************************
 * Method isEmpty : Class Queue
 * ____________________________________________________________________________
 *  This method will check if the queue empty
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	  This function will check if the queue empty
 ******************************************************************************/
template <class Type>
bool Queue<Type>::isEmpty()
{
	return Size() == 0;
}
/******************************************************************************
 * Method Front : Class Queue
 * ____________________________________________________________________________
 *  This method will get the front element
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	  This function will get the front element
 ******************************************************************************/
template <class Type>
Type Queue<Type>::Front()
{
	return queue.at(0);
}
/******************************************************************************
 * Method Size : Class Queue
 * ____________________________________________________________________________
 *  This method will return the size of the queue
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	  This function will return the size of the queue
 ******************************************************************************/
template <class Type>
int Queue<Type>::Size()
{
	return queue.size();
}
/******************************************************************************
 * Method queueUp: Class Queue
 * ____________________________________________________________________________
 *  This method will check the parent of the index then recursively swap the
 *  elements if the parent is greater.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	                int x - index
 * POST-CONDITIONS
 * 	  This function will check the parent of the index then recursively swap
 * 	  the elements if the parent is greater.
 ******************************************************************************/
template <class Type>
void Queue<Type>::queueUp(int x)
{
	//check the parent of the index
	int parent = (x - 1) / 2;

	//recursively swap the elements if the parent
	//is greater
	if (x && queue[parent] < queue[x])
	{
		swap(queue[x], queue[parent]);
		queueUp(parent);
	}
}
/******************************************************************************
 * Method queueDown: Class Queue
 * ____________________________________________________________________________
 *  This method will check if index is in bound and if element is greater or
 *  less. Then it will swap the elements if root isn't the index call the
 *  function recursively to bubbleDown.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               int x - index
 *
 * POST-CONDITIONS
 * 	  This function will check if index is in bound and if element is greater
 * 	  or less. Then it will swap the elements if root isn't the index call the
 *    function recursively to bubbleDown.
 ******************************************************************************/
template <class Type>
void Queue<Type>::queueDown(int x)
{
	//getLeft
	int left = (2 * x) + 1;
	//getRight
	int right = (2 * x) + 2;
	//max is index
	int max = x;

	//check if index is in bound and if element is greater
	if (left < Size() && queue[left] > queue[x])
		max = left;
	//check if index is in bound and if element is less
	if (right < Size() && queue[right] > queue[max])
		max = right;

	//swap the elements if root isn't the index
	//call the function recursively to bubbleDown
	if (max != x)
	{
		swap(queue[max], queue[x]);
		queueDown(max);
	}
}

#endif /* QUEUE_H_ */
