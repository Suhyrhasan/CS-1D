/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #3 : Stacks/Queues/Deques
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/03/2020
 *****************************************************************************/
#include "myheader.h"
#include "nameQueuesList.h"
#include "floatQueuesList.h"
#include "nameSingleLinkedList.h"
#include "floatSingleLinkedList.h"
#include "nameDoublyLinkedList.h"
#include "floatDoublyLinkedList.h"
/**********************************************************************************
 * Stacks/Queues/Deques
 * --------------------------------------------------------------------------------
 * First this program Initialize stringStack and floatStack and print (top of stack
 * to bottom) the stacks using the STL <stack> with the above data.
 *
 * Second the program will reinitialize floatStack and stringStack then delete
 * Jordyn and 200.12 from the above stacks (will delete others) using the STL
 * <stack> and print (top of stack to bottom) the remaining elements in the stacks.
 *
 * Third this program will initialize floatStack and stringStack and print (top of
 * stack to bottom) the stacks using a singly linked list using the above data.
 *
 * Forth this program will delete Jordyn and 200.12 from the above stacks (you
 * will need to delete others) and print (top of stack to bottom) the remaining
 * elements in the stacks.
 *
 * Fifth this program will implement and print the queues using either a circular
 * array or a linked list using the above data.
 *
 * Sixth this program will delete JoAnn and 200.12 from the above queues (will need
 * to delete others) and print the remaining elements in the queues.
 *
 * Seven this program will implement and print the deques using a linked list using
 * the above data (using push front).
 *
 * Eight this program will delete JoAnn (pop front) and 200.12 (pop back) from the
 * deques list (will need to delete others) and print the
 * remaining elements in the deques.
 *
 * Ninth this program willimplement the Parentheses Algorithm without using the
 * STL). Test your algorithm with the following mathematical
 * statements.
 *********************************************************************************/
int main()
{
	// Outputs Heading
	cout << PrinterHeader("Stacks/Queues/Deques", 3 , 'A');
	// Output description of the program

	cout << "\nThis program will follow 9 steps.\n\n";
	/****************************************************************************
	 * Part A - Initialize stringStack and floatStack and print (top of stack to
	 *          bottom) the stacks using the STL <stack> with the above data.
	 ****************************************************************************/
	cout << "Part A:\n";
	stack<string> stringStack; // Empty string stack
	stack<float> floatStack;   // Empty float stack
	// Initialize an empty string & float stack
	initializeStack(stringStack,floatStack);
	// Printing content of string stack
	while (!stringStack.empty())
	{
		cout << "Name:  " << stringStack.top() << '\n';
		stringStack.pop();
	}
	cout << '\n';
	while (!floatStack.empty())
	{
		cout << "Float: "<< floatStack.top() << '\n';
		floatStack.pop();
	}
	cout << '\n';
	/****************************************************************************
	 * Part B - Initialize floatStack and stringStack then delete Jordyn and
	 *          200.12 from the above stacks (will delete others) using the
	 *          STL <stack> and print (top of stack to bottom) the remaining
	 *          elements in the stacks.
	 ****************************************************************************/
	cout << "Part B:\n";
	// Initialize an empty string & float stack
	initializeStack(stringStack,floatStack);
	// Popping content of string stack
	while (stringStack.top() != "Jennifer")
	{
		stringStack.pop();
	}
	// Printing content of string stack
	while (!stringStack.empty())
	{
		cout << "Name:  " << stringStack.top() << '\n';
		stringStack.pop();
	}
	cout << '\n';
	// Popping content of float stack
	for(int i = 0; i <= 2; i++)
	{
		floatStack.pop();
	}
	// Printing content of float stack
	while (!floatStack.empty())
	{
		cout << "Float: "<< floatStack.top() << '\n';
		floatStack.pop();
	}
	cout << '\n';
	/**************************************************************************
	 * Part C - Initialize floatStack and stringStack and print (top of stack
	 *          to bottom) the stacks using a singly linked list using the
	 *          above data.
	 **************************************************************************/
	cout << "Part C:\n";
	nameSingleLinkedList nameSingle;
	nameSingle.Push("Mark");
	nameSingle.Push("Alan");
	nameSingle.Push("Jennifer");
	nameSingle.Push("Jordyn");
	nameSingle.Push("Eric");
	nameSingle.Push("JoAnn");
	nameSingle.Push("Bryan");
	nameSingle.Display();
	cout << '\n';

	floatSingleLinkedList floatSingle;
	floatSingle.Push(2019.1);
	floatSingle.Push(44.44);
	floatSingle.Push(888.55);
	floatSingle.Push(200.12);
	floatSingle.Push(123.123);
	floatSingle.Push(8.445);
	floatSingle.Display();
	cout << '\n';
	/**************************************************************************
	 * Part D - Will delete Jordyn and 200.12 from the above stacks (you will
	 *          need to delete others) and print (top of stack to bottom) the
	 *          remaining elements in the stacks.
	 **************************************************************************/
	cout << "Part D:\n";
	// Popping content of string stack
	for(int i = 0; i <= 3; i++)
	{
		nameSingle.Pop();
	}
	nameSingle.Display();
	cout << '\n';
	// Popping content of float stack
	for(int i = 0; i <= 2; i++)
	{
		floatSingle.Pop();
	}
	floatSingle.Display();
	cout << '\n';
	/**************************************************************************
	 * Part E - Will implement and print the queues using either a circular
	 *          array or a linked list using the above data.
	 **************************************************************************/
	cout << "Part E:\n";
	nameDoublyLinkedList nameDoubly;
	nameDoubly.Push("Mark");
	nameDoubly.Push("Alan");
	nameDoubly.Push("Jennifer");
	nameDoubly.Push("Jordyn");
	nameDoubly.Push("Eric");
	nameDoubly.Push("JoAnn");
	nameDoubly.Push("Bryan");
	nameDoubly.Display();
	cout << '\n';
	floatDoublyLinkedList floatDoubly;
	floatDoubly.Push(2019.1);
	floatDoubly.Push(44.44);
	floatDoubly.Push(888.55);
	floatDoubly.Push(200.12);
	floatDoubly.Push(123.123);
	floatDoubly.Push(8.445);
	floatDoubly.Display();
	cout << '\n';
	/**************************************************************************
	 * Part F - Will delete JoAnn and 200.12 from the above queues (will need
	 *          to delete others) and print the remaining elements in the
	 *          queues. Do not use the STL.
	 **************************************************************************/
	cout << "Part F:\n";
	// Popping content of string stack
	for(int i = 0; i <= 1; i++)
	{
		nameDoubly.Pop();
	}
	nameDoubly.Display();
	cout << '\n';
	// Popping content of float stack
	for(int i = 0; i <= 2; i++)
	{
		floatDoubly.Pop();
	}
	floatDoubly.Display();
	cout << '\n';
	/**************************************************************************
	 * Part G - Will Implement and print the deques using a linked list using
	 *          the above data (using push front).
	 **************************************************************************/
	cout << "Part G:\n";
	nameQueuesList nameQueue;
	nameQueue.Enqueue("Mark");
	nameQueue.Enqueue("Alan");
	nameQueue.Enqueue("Jennifer");
	nameQueue.Enqueue("Jordyn");
	nameQueue.Enqueue("Eric");
	nameQueue.Enqueue("JoAnn");
	nameQueue.Enqueue("Bryan");
	nameQueue.Display();
	cout << '\n';
	floatQueuesList floatQueue;
	floatQueue.Enqueue(2019.1);
	floatQueue.Enqueue(44.44);
	floatQueue.Enqueue(888.55);
	floatQueue.Enqueue(200.12);
	floatQueue.Enqueue(123.123);
	floatQueue.Enqueue(8.445);
	floatQueue.Display();
	cout << '\n';
	/**************************************************************************
	 * Part H - Will delete JoAnn (pop front) and 200.12 (pop back) from the
	 *          deques list (will need to delete others) and print the
	 *          remaining elements in the deques.
	 **************************************************************************/
	cout << "Part H:\n";
	// Popping content of string stack
	for(int i = 0; i <= 1; i++)
	{
		nameQueue.Dequeue();
	}
	nameQueue.Display();
	cout << '\n';

	// Popping content of float stack
	for(int i = 0; i <= 2; i++)
	{
		floatQueue.Dequeue();
	}
	floatQueue.Display();
	cout << '\n';
	/**************************************************************************
	 * Part I - Will implement the Parentheses Algorithm without using the
	 *          STL). Test your algorithm with the following mathematical
	 *          statements.
	 **************************************************************************/
	cout << "Part I: \n";
	ifstream inFile;
	inFile.open("Parentheses.txt");
	string expression;
	while(!inFile.eof())
	{
		getline(inFile, expression);
		inFile>>expression;
		cout << expression;
		if(AreParanthesesBalanced(expression))
			cout<<" is Balanced\n";
		else
			cout<<" is Not Balanced\n";
	}

	return 0;
}
