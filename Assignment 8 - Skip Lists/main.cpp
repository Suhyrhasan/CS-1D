/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #8 : Skip Lists
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 03/25/2020
 *****************************************************************************/
#include "MyHeader.h"
#include "SkipList.h"
/******************************************************************************
 * Dictionary - Skip List
 * ----------------------------------------------------------------------------
 * This program will develop software to implement a dictionary using a skip
 * list. Then it will identify the output of pseudo random number generator that
 * was used (true or false).
 * ----------------------------------------------------------------------------
 *****************************************************************************/

int main()
{
	// Output header to console
	cout << PrinterHeader("Dictionary - Skip List", 8, 'A');
	// Output description of the program
	cout << "\nThis program will develop software to implement a dictionary\n"
			"using a skip list. Then it will identify the output of pseudo\n"
			"random number generator that was used (true or false).\n\n";

	SkipList skipList(.6f, 16);

	cout << "Inserting: 18, 41, 22, 44" << endl;
	skipList.insert(18, "San Clamente");
	skipList.insert(41, "Mission Viejo");
	skipList.insert(22, "Laguna Niguel");
	skipList.insert(44, "Irvine");

	//skipList.print();

	//DELETE KEY 18
	cout << "Erasing 18" << endl;
	skipList.erase(18);

	//skipList.print();

	cout << "Inserting: 58, 32, 49" << endl;
	skipList.insert(58, "Lake Forest");
	skipList.insert(32, "San Diego");
	skipList.insert(49, "Anaheim");

	//skipList.print();

	//DELETE KEY 58
	cout << "Erasing 58" << endl;
	skipList.erase(58);

	//skipList.print();

	cout << "Inserting: 31, 17, 72, 41" << endl;
	skipList.insert(31, "Los Angeles");
	skipList.insert(17, "Orange");
	skipList.insert(72, "Palms Springs");
	skipList.insert(41, "Riverside");

	//skipList.print();

	//DELETE KEY 49
	cout << "Erasing 49" << endl;
	skipList.erase(49);

	//skipList.print();
	cout << "Inserting: 19, 60, 35, 103, 11, 18, 22, 49" << endl;
	skipList.insert(888, "Mark Zuckerberg");
	skipList.insert(888, "Bob Iger");
	skipList.insert(123, "Mark Zuckerberg");
	skipList.insert(555, "Bill Gates ");
	skipList.insert(444, "Bob Iger");
//	skipList.insert(19, "Brea");
//	skipList.insert(60, "Santa Ana");
//	skipList.insert(35, "Tustin");
//	skipList.insert(103, "Oceanside");
//	skipList.insert(11, "La Jolla");
//	skipList.insert(18, "Del Mar");
//	skipList.insert(22, "Aliso Viejo");
//	skipList.insert(49, "Laguna Beach");

	//skipList.print();

	//DELETE KEY 41
	cout << "Erasing 41" << endl;
	skipList.erase(41);

	//skipList.print();

	cout << "Inserting: 42, 49, 99, 29, 88, 41, 62" << endl;
	skipList.insert(42, "Vista");
	skipList.insert(49, "San Diego");
	skipList.insert(99, "San Juan");
	skipList.insert(29, "Dana Point");
	skipList.insert(88, "El Segundo");
	skipList.insert(41, "San Clemente");
	skipList.insert(62, "Laguna Hills");

	skipList.print();

	skipList.printLevels();

	std::cout << "Find value by key 41\nResulting value: " << *skipList.find(41) << endl << endl;

	cout << "Calling size() method\nResulting value: " << skipList.size() << endl << endl;
	return 0;
}
