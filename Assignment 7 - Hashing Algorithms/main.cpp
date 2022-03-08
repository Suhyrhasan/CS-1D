/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #7 : Hashing Algorithms
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 03/04/2020
 *****************************************************************************/
#include "myheader.h"
#include "HashMap.h"
/******************************************************************************
 * Hashing Algorithms
 * ----------------------------------------------------------------------------
 * This program will take the given key value pairs and stores them inside
 * a hash map using either double hashing or quadratic probing. The hash
 * buckets are vector based.
 * ----------------------------------------------------------------------------
 *****************************************************************************/
int main()
{
	// Output header to console
	cout << PrinterHeader("Hashing Algorithms", 7, 'A');
	// Output description of the program
	cout << "\nThis program will take the given key value pairs and\n"
			<< "stores them inside a hash map using either double hashing\n"
			<< "or quadratic hashing.\n";
	/****************************************************************************
	 * Part One - This program will create a map using the double hashing
	 *  algorithm where:
	 *                  h(k) = k mod 29
	 *                  h’(k) = 13 - k mod 13
	 *                  N = 29 (size of the array)
	 *  Then it will output the final map including the keys and values.
	 ****************************************************************************/
	HashMap doubleHash;
	cout << "\n***************************\n";
	cout << "  Hash Map Double Hashing  ";
	cout << "\n***************************\n";
	doubleHash.insertDouble(18, "San Clemente");
	doubleHash.insertDouble(41, "Mission Viejo");
	doubleHash.insertDouble(22, "Laguna Niguel");
	doubleHash.insertDouble(44, "Irvine");

	doubleHash.Delete(44);

	doubleHash.insertDouble(58, "Lake Forest");
	doubleHash.insertDouble(32, "San Diego");
	doubleHash.insertDouble(49, "Anaheim");

	doubleHash.Delete(58);

	doubleHash.insertDouble(31, "Los Angeles");
	doubleHash.insertDouble(17, "Orange");
	doubleHash.insertDouble(72, "Palms Springs");
	doubleHash.insertDouble(41, "Riverside");

	doubleHash.Delete(49);

	doubleHash.insertDouble(19, "Brea");
	doubleHash.insertDouble(60, "Santa Ana");
	doubleHash.insertDouble(35, "Tustin");
	doubleHash.insertDouble(103, "Oceanside");
	doubleHash.insertDouble(11, "La Jolla");
	doubleHash.insertDouble(18, "Del Mar");
	doubleHash.insertDouble(22, "Aliso Viejo");
	doubleHash.insertDouble(49, "Laguna Beach");

	doubleHash.Delete(41);

	doubleHash.insertDouble(42, "Vista");
	doubleHash.insertDouble(49, "San Diego");
	doubleHash.insertDouble(99, "San Juan");
	doubleHash.insertDouble(29, "Dana Point");
	doubleHash.insertDouble(88, "El Segundo");
	doubleHash.insertDouble(41, "San Clemente");
	doubleHash.insertDouble(62, "Laguna Hills");

	doubleHash.Print();

	/****************************************************************************
	 * Part Two - This program will create a map using the quadratic hashing
	 *            algorithm where:
	 *                            h(k) = k mod 29
	 *  Then it will output the final map including the keys and values.
	 ****************************************************************************/
	HashMap quadHash;
	cout << "\n******************************\n";
	cout << "  Hash Map Quadratic Hashing  ";
	cout << "\n******************************\n";
	quadHash.insertQuad(888, "Mark Zuckerberg");
	quadHash.insertQuad(888, "Bob Iger");
	quadHash.insertQuad(123, "Mark Zuckerberg");
	quadHash.insertQuad(555, "Bill Gates ");
	quadHash.insertQuad(444, "Bob Iger");
//
//	quadHash.Delete(18);
//
//	quadHash.insertQuad(58, "Lake Forest");
//	quadHash.insertQuad(32, "San Diego");
//	quadHash.insertQuad(49, "Anaheim");
//
//
//	quadHash.Delete(58);
//
//	quadHash.insertQuad(31, "Los Angeles");
//	quadHash.insertQuad(17, "Orange");
//	quadHash.insertQuad(72, "Palms Springs");
//	quadHash.insertQuad(41, "Riverside");
//
//	quadHash.Delete(49);
//
//	quadHash.insertQuad(19, "Brea");
//	quadHash.insertQuad(60, "Santa Ana");
//	quadHash.insertQuad(35, "Tustin");
//	quadHash.insertQuad(103, "Oceanside");
//	quadHash.insertQuad(11, "La Jolla");
//	quadHash.insertQuad(18, "Del Mar");
//	quadHash.insertQuad(22, "Aliso Viejo");
//	quadHash.insertQuad(49, "Laguna Beach");
//
//	quadHash.Delete(41);
//
//	quadHash.insertQuad(42, "Vista");
//	quadHash.insertQuad(49, "San Diego");
//	quadHash.insertQuad(99, "San Juan");
//	quadHash.insertQuad(29, "Dana Point");
//	quadHash.insertQuad(88, "El Segundo");
//	quadHash.insertQuad(41, "San Clemente");
//	quadHash.insertQuad(62, "Laguna Hills");

	quadHash.Print();
	return 0;
}
