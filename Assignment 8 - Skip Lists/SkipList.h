/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #8 : Skip Lists
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 03/25/2020
 *****************************************************************************/
#ifndef SKIPLIST_H_
#define SKIPLIST_H_
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <limits>
/****************************************************************
 *  SkipList
 * This class has all the attributes and methods for SkipList.
 ***************************************************************/
class SkipList
{
public:
	/****************************************************************
	 * SkipList(float newProbability = 0.5f, int newMaxLevel = 16)
	 * Default Constructor; Initialize class attributes
	 * Parameters: none
	 * Return: none
	 ***************************************************************/
	SkipList(float newProbability = 0.5f, int newMaxLevel = 16){
		probability = newProbability;
		maxLevel = newMaxLevel;
		currentSize = 0;

		srand(time(0));

		int headKey = numeric_limits<int>::min();
		head = new Node(headKey, "head", maxLevel);

		int tailKey = numeric_limits<int>::max();
		tail = new Node(tailKey, "tail", maxLevel);

		fill(head->next.begin(), head->next.end(), tail);}
	/****************************************************************
	 * ~SkipList()
	 * Destructor; Clears Linked List
	 * Parameters: none
	 * Return: none
	 ***************************************************************/
	~SkipList(){
		Node* node = head;
		while (node->next[0])
		{
			Node* temp = node;
			node = node->next[0];
			delete temp;
		}
		delete node;}

	/****************
	 ** MUTATORS **
	 ****************/

	/******************************************************************************
	 * Method Insert: Class SkipList
	 * ____________________________________________________________________________
	 * This method will insert given key in skip list  - returns nothing.
	 *
	 * PRE-CONDITIONS
	 * 	  The following parameters need to have a defined value prior to calling
	 * 	  the function:
	 * 	                searchKey - new key
	 * 	                newValue  - new value
	 * POST-CONDITIONS
	 * This function will insert given key in skip list  - returns nothing.
	 ******************************************************************************/
	void insert(int searchKey, const string& newValue)
	{
		vector<Node*> prevNodes = getPreviousNodes(searchKey);

		int newNodeLevel = randomLevel();
		Node* newNode = makeNode(searchKey, newValue, newNodeLevel);

		for (int i = 0; i < newNodeLevel; ++i)
		{
			newNode->next[i] = prevNodes[i]->next[i];
			prevNodes[i]->next[i] = newNode;
		}

		currentSize++;
	}
	/***************
	 ** ACCESSORS **
	 ***************/
	/******************************************************************************
	 * Method Find : Class SkipList
	 * ____________________________________________________________________________
	 *  This method will fine for element in skip list - returns nothing.
	 *
	 * PRE-CONDITIONS
	 * 	  The following parameters need to have a defined value prior to calling
	 * 	  the function:
	 * 	               searchKey - given key
	 * POST-CONDITIONS
	 * 	This function will fine for element in skip list - returns nothing.
	 ******************************************************************************/
	string* find(int searchKey) const
	{
		string* result = nullptr;
		if (auto node = lower_bound(searchKey))
		{
			if (node->key == searchKey && node != tail)
			{
				result = &(node->value);
			}
		}
		return result;
	}
	/******************************************************************************
	 * Method Erase : Class SkipList
	 * ____________________________________________________________________________
	 *  This method will  - returns nothing.
	 *
	 * PRE-CONDITIONS
	 * 	  The following parameters need to have a defined value prior to calling
	 * 	  the function:
	 * 	               searchKey -
	 *
	 * POST-CONDITIONS
	 * 	This function will  - returns nothing.
	 ******************************************************************************/
	void erase(int searchKey)
	{
		vector<Node*> prevNodes = getPreviousNodes(searchKey);
		Node* node = prevNodes[0]->next[0];
		if (node->key != searchKey || node == tail)
		{
			return;
		}
		for (size_t i = 0; i < nodeLevel(node); ++i)
		{
			prevNodes[i]->next[i] = node->next[i];
		}
		delete node;
		currentSize--;
	}
	/******************************************************************************
	 * Method empty : Class SkipList
	 * ____________________________________________________________________________
	 *  This method will check if list is empty - return a boolean expression.
	 *
	 * PRE-CONDITIONS
	 * 	  The following parameters need to have a defined value prior to calling
	 * 	  the function:
	 *
	 * POST-CONDITIONS
	 * 	  This function will check if list is empty - return a boolean expression.
	 ******************************************************************************/
	bool empty() const{return (currentSize == 0);}
	/******************************************************************************
	 * Method size : Class SkipList
	 * ____________________________________________________________________________
	 *  This method will check the size list  - return an integer.
	 *
	 * PRE-CONDITIONS
	 * 	  The following parameters need to have a defined value prior to calling
	 * 	  the function:
	 *
	 * POST-CONDITIONS
	 * 	  This function will check the size list  - return an integer.
	 ******************************************************************************/
	int size() const{return currentSize;}
	/******************************************************************************
	 * Method printLevels : Class SkipList
	 * ____________________________________________________________________________
	 *  This method will print the number of levels.
	 *
	 * PRE-CONDITIONS
	 * 	  The following parameters need to have a defined value prior to calling
	 * 	  the function:
	 *
	 * POST-CONDITIONS
	 * 	This function will print the number of levels.
	 ******************************************************************************/
	void printLevels() const
	{
		cout << "\n----------\n";

		Node* list;
		for (int i = maxLevel - 1; i >= 0; i--)
		{
			list = head->next[i];

			cout << "level: " << setw(10) << i << '\n';

			while (list != tail)
			{
				cout << string(10, ' ') << "value: " << setw(30) << list->value
						<< "key: " << setw(10) << list->key;

				list = list->next[i];


				cout << "\n";
			}
		}
		cout << "\n----------\n";
	}
	/******************************************************************************
	 * Method Print : Class SkipList
	 * ____________________________________________________________________________
	 *  This method will print out the table.
	 *
	 * PRE-CONDITIONS
	 * 	  The following parameters need to have a defined value prior to calling
	 * 	  the function:
	 *
	 * POST-CONDITIONS
	 * 	This function will print out the table.
	 ******************************************************************************/
	void print() const
	{
		Node* list = head->next[0];
		cout << "\n----------\n";
		cout << left;
		while (list != tail)
		{
			cout << "value: " << setw(20) << list->value
					<< "key: " << setw(10) << list->key
					<< "level: " << setw(10) << nodeLevel(list);
			for (int i = 0; i < nodeLevel(list); i++)
			{
				cout << "[]";
			}
			list = list->next[0];
			cout << "\n";
		}
		cout << "\n----------\n";
	}
private:
	struct Node
	{
		int key;
		string value;

		vector<Node*> next;

		Node(int k, const string& v, int level) :
			key(k), value(v), next(level, nullptr)
		{
		}
	};

	Node* head;
	Node* tail;
	int currentSize;
	float probability;
	int maxLevel;
	/*******************************************************************
	 * int randomLevel() const;
	 *
	 * Accessor; This method will use random to create a new level.
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: a newLevel int
	 *******************************************************************/
	int randomLevel() const
	{
		int newLevel = 1;
		while(((double)rand()/RAND_MAX) < probability&&(newLevel < maxLevel))
		{newLevel++;}
		return newLevel;
	}
	/*******************************************************************
	 * static int nodeLevel(const Node* v);
	 *
	 * Accessor; This method will return the node level.
	 *------------------------------------------------------------------
	 * Parameters: const Node* v
	 *------------------------------------------------------------------
	 * Return: a node level
	 *******************************************************************/
	static int nodeLevel(const Node* v){return v->next.size();}
	/*******************************************************************
	 * static int nodeLevel(const Node* v);
	 *
	 * Accessor; This method will create a new node.
	 *------------------------------------------------------------------
	 * Parameters: int key, string val, int level
	 *------------------------------------------------------------------
	 * Return: a new node
	 *******************************************************************/
	static Node* makeNode(int key, string val, int level)
	{
		return new Node(key, val, level);
	}
	/*******************************************************************
	 * 	Node* lower_bound(int searchKey) const;
	 *
	 * Accessor; This method will
	 *------------------------------------------------------------------
	 * Parameters: int searchKey
	 *------------------------------------------------------------------
	 * Return:
	 *******************************************************************/
	Node* lower_bound(int searchKey) const
	{
		Node* node = head;

		for (unsigned int i = nodeLevel(head); i-- > 0;)
		{
			while (node->next[i]->key < searchKey)
			{
				node = node->next[i];
			}
		}
		return node->next[0];
	}
	/*******************************************************************
	 * vector<SkipList::Node*> getPreviousNodes(int searchKey) const;
	 *
	 * Accessor; This method will get the previous node
	 *------------------------------------------------------------------
	 * Parameters: int searchKey
	 *------------------------------------------------------------------
	 * Return: the result
	 *******************************************************************/
	vector<SkipList::Node*> getPreviousNodes(int searchKey) const{
		vector<Node*> result(nodeLevel(head), nullptr);
		Node* node = head;

		for (unsigned int i = nodeLevel(head); i-- > 0;)
		{
			while (node->next[i]->key < searchKey)
			{
				node = node->next[i];
			}
			result[i] = node;
		}
		return result;}
};
#endif /* SKIPLIST_H_ */
