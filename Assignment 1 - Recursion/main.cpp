/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #1 : Recursion
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 01/22/2020
 *****************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <sstream>
using namespace std;
/******************************************************************************
 * FUNCTION PrinterHeader
 * ____________________________________________________________________________
 * This function receives an assignment name, type and number then
 * 		outputs the appropriate class heading. asType is defaulted to Lab
 * 		as there are more labs than Assignments.
 * 		==> returns nothing - This will output the class heading.
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	  			  asName : Assignment Name
 * 	  			  asNum  : Assignment Number
 *				  asType : Assignment Type ==> THIS SHOULD CONTAIN:
 *				  							   'L' for Labs
 *				  							   'A' for Assignments
 *
 * POST-CONDITIONS
 * 	  This function will output the class heading.
 ******************************************************************************/
string PrinterHeader(string asName,    // IN - Assignment Name
		int asNum ,                    // IN - Assignment Number
		char asType)                   // IN - Assignment Type ('L' = Lab,
//                       'A' = Assignment)
{
	ostringstream output;
	output << left;
	output << "*****************************************************\n";
	output << "*  PROGRAMMED BY : Suhyr Hasan \n";
	output << "*  " << setw(14) << "STUDENT IDs" << ": 1022520 \n";
	output << "*  " << setw(14) << "CLASS"	     <<": CS1D - MW - 2:30pm - 4:50pm\n";
	output << "*  " ;

	// PROCESSING - This will adjust setws and format appropriately based
	//              based on if this is a lab 'L' or assignment.

	if(toupper(asType) == 'L')
	{
		output << "LAB #" << setw(9);
	}
	else
	{
		output << "ASSIGNMENT #" << setw(2);
	}
	output<< asNum << ": " << asName << endl;
	output << "*****************************************************\n";
	output << right;
	return output.str();
}

/******************************************************************************
 * Function editString
 * ____________________________________________________________________________
 * This function will read in a string and remove all spaces and punctuations.
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               string string - a phrase
 *
 * POST-CONDITIONS
 * 	  This function return the new string.
 ******************************************************************************/
string editString(string string)
{

	string.erase(remove(string.begin(), string.end(), ' '), string.end());
	for (int i =0 , length = string.size(); i<length; i++)
	{
		if(ispunct(string[i]))
		{
			string.erase(i--,1);
			length = string.size();
		}
	}
	// string without punctuations and whitespaces
	return string;
}
/******************************************************************************
 * Function isPalindrome
 * ____________________________________________________________________________
 * This recursive function that takes a string as an argument and returns a
 * TRUE if the string is a palindrome otherwise FALSE is returned.
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               const string message - a phrase
 *
 * POST-CONDITIONS
 * 	  This function will return TRUE if the string is a palindrome otherwise
 * 	  FALSE is returned.
 ******************************************************************************/
bool isPalindrome(const string message, size_t i = 0)
{
	if (i >= message.size() / 2)
		return true;
	if (tolower(message[i]) != tolower(message[message.size() - i - 1]))
		return false;
	return isPalindrome(message, i + 1);
}
/******************************************************************************
 * Recursion
 * ----------------------------------------------------------------------------
 * This program will use a recursive function that takes a string as an
 * argument and returns a TRUE if the string is a palindrome otherwise FALSE
 * is returned. A palindrome is a string that reads the same forward and
 * backward (dad, mom, radar).The recursive function will ignore whitespaces,
 * capital letters (case insensitive), and punctuation.
 * ----------------------------------------------------------------------------
 *****************************************************************************/
int main()
{
	cout << PrinterHeader("Recursive", 1, 'A');
	cout << "\nThis program will use a recursive function that takes\n"
			<< "a string as an argument and returns a TRUE if the\n"
			<< "string is a palindrome otherwise FALSE is returned.\n\n";
	vector<string> strings =
	{
			"A man a plan a canal Panama",
			"The rain in Spain",
			"No lemon, no melon",
			"radar",
			"CS1D",
			"Was it a cat I saw?",
			"Racecar",
			"Saddleback",
			"dad",
	};
	/****************************************************************************
	 * Using the function, editString(), the program will read in a string,
	 * remove any whitespaces and punctuations , and then return a new string.
	 * Afterwards the program will use the function, isPalindrome(), and take the
	 * new string as an argument and returns a TRUE if the string is a palindrome
	 * otherwise FALSE is returned. In the end the program will output the string
	 * and whether it is a palindrome or not.
	 ****************************************************************************/
	for(int i = 0; i < 8; i++)
	{
		string message = strings[i];
		cout << setw(33) << right << message << " : ";
		message = editString(message);
		if (!isPalindrome(message))
		{
			cout << "FALSE.\n";
		}else{
			cout << "TRUE.\n";
		}
	}
	return 0;
}
