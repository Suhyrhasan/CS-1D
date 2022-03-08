/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #7 : Hashing Algorithms
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 03/04/2020
 *****************************************************************************/
#ifndef HASHMAP_H_
#define HASHMAP_H_
#include "MyHeader.h"
#define TABLE_SIZE 29 // Hash table size
#define PRIME 13 // Used in second hash function.
struct hashTable
{
	string value;
	int key;
};
/****************************************************************
 * HashMap
 * This class has all the attributes and methods for HashMap.
 ***************************************************************/
class HashMap
{
public:
	/****************************************************************
	 * HashMap();
	 * Default Constructor; Initialize class attributes
	 * Parameters: none
	 * Return: none
	 ***************************************************************/
	HashMap();

	/****************
	 ** MUTATORS **
	 ****************/

	/*******************************************************************
	 * void insertDouble(int key, string value);
	 *
	 * Mutator; This method will insert key into hash table using a
	 *          double hashing algorithm.
	 *------------------------------------------------------------------
	 * Parameter: int key - new key & string value - new value
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void insertDouble(int key, string value);

	/*******************************************************************
	 * void insertQuad(int key, string value);
	 *
	 *
	 * Mutator; This method will insert key into hash table using a
	 *          quadratic hashing algorithm.
	 *------------------------------------------------------------------
	 * Parameter:  int key - new key & string value - new value
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void insertQuad(int key, string value);

	/*******************************************************************
	 * void Delete(int key);
	 *
	 * Mutator; This method will delete value at key in hash table.
	 *------------------------------------------------------------------
	 * Parameter: int key - a key
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void Delete(int key);

	/***************
	 ** ACCESSORS **
	 ***************/

	/*******************************************************************
	 * bool isFull();
	 *
	 * Accessor; This method will check if hash table is full
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: boolean expression
	 *******************************************************************/
	bool isFull();

	/*******************************************************************
	 * int firstHash(int aKey);
	 *
	 * Accessor; This method will calculate first hash.
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: int hashedKey - first hash
	 *******************************************************************/
	int firstHash(int aKey);

	/*******************************************************************
	 * int secondHash(Key aKey);
	 *
	 * Accessor; This method will calculate second hash.
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: int hashedKey - second hash
	 *******************************************************************/
	int secondHash(int aKey);

	/*******************************************************************
	 * void Print();
	 *
	 * Accessor; This method will print the hash table.
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void Print();

private:
	hashTable *table;
	int currentSize;
};

/****************************************************************
 * hashMap()
 * Default Constructor; Initialize class attributes
 * Parameters: none
 * Return: none
 ****************************************************************/
HashMap::HashMap()
{
	currentSize = 0;
	table = new hashTable[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		table[i].value = "";
		table[i].key = 0;
	}
}
/******************************************************************************
 * Method Insert: Class HashMap
 * ____________________________________________________________________________
 * This method will insert key into hash table using a double hashing algorithm
 *  - returns nothing.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	                Key newKey     - new key
 * 	                Value newValue - new value
 * POST-CONDITIONS
 * This function will insert key into hash table using a double hashing algorithm
 *  - returns nothing.
 ******************************************************************************/
void HashMap::insertDouble(int key, string value)
{
	if (isFull())
		return;

	int index = firstHash(key);

	if (table[index].value != "" && table[index].key != key)
	{
		int index2 = secondHash(key);
		int i = 1;
		while (1)
		{
			int newIndex = (index + i * index2) % TABLE_SIZE;

			if (table[newIndex].value == "")
			{
				table[newIndex].value = value;
				table[newIndex].key = key;
				break;
			}
			i++;
		}
	}else{
		table[index].value = value;
		table[index].key = key;
	}
	currentSize++;
}
/******************************************************************************
 * Method insertQuad: Class HashMap
 * ____________________________________________________________________________
 *  This method will insert key into hash table using a quadratic hashing
 *  algorithm - returns nothing.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *	                int key      - new key
 *	                string Value - new value
 * POST-CONDITIONS
 * 	This function will insert key into hash table using a quadratic hashing
 *  algorithm - returns nothing.
 ******************************************************************************/
void HashMap::insertQuad(int key, string value)
{

	if (isFull())
		return;

	int index = firstHash(key);

	if (table[index].value != "" && table[index].key != key)
	{
		int i = 1;
		while (true)
		{
			// get newIndex
			int newIndex = (key + i * i) % TABLE_SIZE;

			// if no collision occurs, store the key
			if (table[newIndex].value == "")
			{
				table[newIndex].value = value;
				table[newIndex].key = key;
				break;
			}
			i++;
		}
	}else{
		table[index].value = value;
		table[index].key = key;
	}
	currentSize++;
}
/******************************************************************************
 * Method Delete : Class HashMap
 * ____________________________________________________________________________
 *  This method will delete value at key in hash table - returns nothing.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *                 int key - a key
 * POST-CONDITIONS
 * 	  This function will delete value at key in hash table - returns nothing.
 ******************************************************************************/
void HashMap::Delete(int key)
{
	table[firstHash(key)].value = "";
}
/******************************************************************************
 * Method isFull : Class HaspMap
 * ____________________________________________________________________________
 *  This method will check hash table is full - return a boolean expression.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	This function will check hash table is full - return a boolean expression.
 ******************************************************************************/
bool HashMap::isFull()
{
	// if hash size reaches maximum size
	return (currentSize == TABLE_SIZE);
}
/******************************************************************************
 * Method firstHash : Class HashMap
 * ____________________________________________________________________________
 *  This method will calculate and return first hash.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *	                int Key - a key
 * POST-CONDITIONS
 * 	  This function will calculate and return first hash.
 ******************************************************************************/
int HashMap::firstHash(int key)
{
	return (key % TABLE_SIZE);
}
/******************************************************************************
 * Method secondHash : Class HashMap
 * ____________________________________________________________________________
 *  This method will calculate and return second hash.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               int key - a key
 * POST-CONDITIONS
 * 	  This function will calculate and return second hash.
 ******************************************************************************/
int HashMap::secondHash(int key)
{
	return (PRIME - (key % PRIME));
}
/******************************************************************************
 * Method Print : Class HashMap
 * ____________________________________________________________________________
 *  This method will print out the hash table.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	This function will print out the hash table.
 ******************************************************************************/
void HashMap::Print()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (table[i].value != "")
		{
			cout << "Index: "<< right << setw(2) << i << ' ' << left;
			cout << " Key: " <<  table[i].key;
			cout << " Value: ";
			cout << table[i].value << endl;
		}else{
			cout << "Index: " << right << setw(2) << i << ' ';
			cout << " EMPTY\n";
		}
	}
}
#endif /* HASHMAP_H_ */
