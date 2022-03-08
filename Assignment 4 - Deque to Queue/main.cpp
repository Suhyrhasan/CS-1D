/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #4 : Deque to Queue
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/10/2020
 *****************************************************************************/
#include "myheader.h"
#include "Queue.h"
/**********************************************************************************
 * Deque to Queue
 * --------------------------------------------------------------------------------
 * This program will test all the member functions (Enqueue(), Dequeue(), Empty(),
 * Front(), and Size() of the queue class.
 *
 * Part One - This program will create and initialize strings then using the
 *            function, Enqueue(), it will create a Node, then add the Node in
 *            the stack, by adding to the front of the linked List
 *            – returns nothing.
 *
 * Part Two - Using the function,Dequeue(), the program will output the
 *            stringNode in the top of the stack, and then remove the
 *            stringNode from the stack, and delete the stringNode
 *            – returns nothing.
 *
 * Part Three: Using the function, Empty(), the program will check if
 *             the stack is empty – returns an integer.
 *
 * Part Four: Using the functions, Front(), the program will output the
 *            stringNode at the top of the stack – returns nothing.
 *
 * Part Five: Using the function, Size(), the program will return the
 *            number of strings in the stack – returns stackCount.
 * --------------------------------------------------------------------------------
 *********************************************************************************/
int main()
{
	// Outputs Heading
	cout << PrinterHeader("Deque to Queue", 4 , 'A');

	// Output description of the program
	cout << "\nThis program will create and test all the member functions\n"
			"(Enqueue(), Dequeue(), Empty(), Front(), and Size() of the\n"
			"queue class.\n\n";

	queueList queue; // CALC - list of strings

	/****************************************************************************
	 * Part One - This program will create and initialize strings then using the
	 *            function, Enqueue(), it will create a Node, then add the Node
	 *            in the stack, by adding to the front of the linked List
	 *            – returns nothing.
	 ****************************************************************************/
	cout << "Part One - Enqueue()\n";
	string string1 = "A man, a plan, a canal, Panama";
	string string2 = "Was it a car or a cat I saw?";
	string string3 = "Sit on a potato pan, Otis";
	string string4 = "No lemon, no melon";
	queue.Enqueue(string1);
	queue.Enqueue(string2);
	queue.Enqueue(string3);
	queue.Enqueue(string4);
	cout << endl;
	/***********************************************************************
	 * Part Two - Using the function, Dequeue(), the program will output
	 *            the stringNode in the top of the stack, and then remove
	 *            the stringNode from the stack, and delete the stringNode
	 *            – returns nothing.
	 ***********************************************************************/
	cout << "Part Two - Dequeue()\n";
	queue.Dequeue();
	/***********************************************************************
	 * Part Three: Using the function, Empty(), the program will check if
	 *            the stack is empty – returns a boolean.
	 ***********************************************************************/
	cout << "Part Three - Empty()\n";
	if(queue.Empty())
	{
		cout<<"Yes, the QUEUE is empty."<<endl<<endl;
	}
	else
	{
		cout<<"The QUEUE is NOT empty!"<<endl<<endl;
	}
	/***********************************************************************
	 * Part Four: Using the functions,Front(), the program will output the
	 *            stringNode at the top of the stack – returns head node.
	 ***********************************************************************/
	cout << "Part Four - Front()\n";
	if (!queue.Empty())
	{   // Displays the front element on the list's information
		cout<<"The first string in the queue is:"<<endl;
		cout << "String: " << queue.Front() << endl<< endl;
	}
	else
		cout <<"No string in FRONT, the queue is empty!!" << endl <<endl;
	/***********************************************************************
	 * Part Five: Using the function, Size(), the program will return the
	 *            number of strings in the stack – returns stackCount.
	 ***********************************************************************/
	cout << "Part Five - Size()\n";
	if(queue.Size() > 1)
	{
		cout << "There are " << queue.Size() << " people on the queue. ";
		cout <<endl<< endl;
	}
	else if(queue.Size() == 1)
	{
		cout << "There is one person on the queue."<<endl<< endl;
	}
	else if(queue.Size() < 0)
	{
		cout << "Nobody is on the queue!"<<endl<< endl;
	}
	return 0;
}
