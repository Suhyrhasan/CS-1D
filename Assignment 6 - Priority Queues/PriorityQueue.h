/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #6 : Priority Queues
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/26/2020
 *****************************************************************************/
#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_
#include "myheader.h"
#include "Queue.h"
/****************************************************************
 * PriorityQueue
 * This wrapped class represents a priority queue list.
 ***************************************************************/
template <class Type> class PriorityQueue
{
public:
	/****************
	 ** MUTATORS **
	 ****************/

	/*******************************************************************
	 * void Enqueue(const Type &x);
	 *
	 * Mutator; This method will inserts an element into the queue.
	 *------------------------------------------------------------------
	 * Parameter: const Type &x - New Element
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void Enqueue(const Type &x); //inserts element
	/*******************************************************************
	 * void Dequeue();
	 *
	 * Mutator; This method will remove top element.
	 *------------------------------------------------------------------
	 * Parameter: none
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void Dequeue();//removes top element

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
	 * Accessor; This method will get the front element
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: front element
	 *******************************************************************/
	Type Front();//gets the front element

	/*******************************************************************
	 * int Size() const;
	 *
	 * Accessor; This method will return the size of the queue
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: int size of queue
	 *******************************************************************/
	int Size() const; //returns the size

private:
	Queue<Type> Q; //Variable to wrap around dequeue
};
/******************************************************************************
 * Method Enqueue: Class PriorityQueue
 * ____________________________________________________________________________
 *  This method will inserts an element into the queue.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               const Type &x - New Element
 *
 * POST-CONDITIONS
 * 	  This function will inserts an element into the queue.
 ******************************************************************************/
template <class Type>
void PriorityQueue<Type>::Enqueue(const Type &x)
{
	Q.Push(x);
}
/******************************************************************************
 * Method Dequeue: Class PriorityQueue
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
void PriorityQueue<Type>::Dequeue()
{
	Q.Pop();
}
/******************************************************************************
 * Method isEmpty : Class PriorityQueue
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
bool PriorityQueue<Type>::isEmpty()
{
	return Q.isEmpty();
}
/******************************************************************************
 * Method Front : Class PriorityQueue
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
Type PriorityQueue<Type>::Front()
{
	return Q.Front();
}
/******************************************************************************
 * Method Size : Class PriorityQueue
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
int PriorityQueue<Type>::Size() const
{
	return Q.Size();
}
#endif /* PRIORITYQUEUE_H_ */
