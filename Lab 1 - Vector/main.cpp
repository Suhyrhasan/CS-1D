/******************************************************************************
 * AUTHOR	   : Suhyr Hasan Logan Blakeborough
 * STUDENT ID  : 1022520 and 1124436
 * Lab # 1     : Vector
 * CLASS 	   : CS1D
 * SECTION 	   : MW 2:30p - 4:50p
 * DUE DATE	   : 01/13/2020
 *****************************************************************************/
#include "myheader.h"
/******************************************************************************
 * Vector
 * ----------------------------------------------------------------------------
 * This program will a random number generator to generate 15 three-digit
 * integers. Then it will store the random numbers in a vector. Afterward the
 * the program will sort the random numbers and then reverse the digits of the
 * random numbers. Afterwards the program will store the reversed digits into
 * another vector.Then the program will find the sum the digits of the random
 * numbers and store the sums in another vector. In the end the program will
 * print all three vectors.
 * ----------------------------------------------------------------------------
 *****************************************************************************/
int main()
{
	// Output header to console
	cout << PrinterHeader("Vector", 1, 'L');

	/* initialize random seed: */
	srand(time(NULL));

	vector <int> myVector;    // CALC & OUT
	vector <int> myRevVector; // CALC & OUT
	vector <int> sumVector;   // CALC & OUT
	/*************************************************************************
	 * The program will use a random number generator to generate 15 integers
	 * between 1 and 99. Then the program will sort the random numbers and
	 * store it in a vector
	 *************************************************************************/
	for (int i = 0; i < 15; i++)
	{
		myVector.push_back(rand() % 1000);
	}
	/***********************************************************************
	 * The program will sort the random numbers and store it in in a vector.
	 ***********************************************************************/
	std::sort(myVector.begin(), myVector.end());
	cout << "\nSorted random numbers:\n";
	for (int i = 0; i < 15; i++)
	{
		if (myVector[i] < 100)
		{
			std::cout << left << std::setfill('0') << setw(3)<< myVector[i];
			cout << right<< endl;
		}else
			cout << myVector[i] << endl;
	}
	cout << endl;
	/***********************************************************************
	 * The program will reverse the digits and then store the random
	 * numbers in a new vector.
	 ***********************************************************************/
	cout << "Sorted random numbers but the digits are reversed:\n";
	for (int i = 0; i < 15; i++)
	{
		myRevVector.push_back(myVector[i]);
		if (myRevVector[i] < 10)
		{
			myRevVector[i] *= 10;
			cout << myRevVector[i] << endl;
		}
		else if (myRevVector[i] < 100)
		{
			int temp = 0;
			while(myRevVector[i]> 0)
			{
				temp = temp *10 + myRevVector[i]%10;
				myRevVector[i] = myRevVector[i]/10;
			}
			if (temp < 100)
			{
				std::cout << std::setfill('0') << setw(3)<< temp << endl;
			}
		}
		else
		{
			int temp = 0 ;
			while(myRevVector[i]> 0)
			{
				temp = temp *10 + myRevVector[i]%10;
				myRevVector[i] = myRevVector[i]/10;
			}
			if (temp < 100)
			{
				std::cout << std::setfill('0') << setw(3)<< temp << endl;
			}
			else
			{
				cout << temp << endl;
			}
		}
	}
	cout << endl;
	/************************************************************************
	 * The program will find the sum of the digits of the random numbers and
	 * store it in a a new vector.Then program will print all three vectors.
	 *************************************************************************/
	cout << "The Sum of the digits of the random numbers:\n";
	for (int i = 0; i < 15; i++)
	{
		int sum = 0;
		sumVector.push_back(myVector[i]);
		while(sumVector[i] > 0)
		{
			sum = sum + sumVector[i]%10;
			sumVector[i] = sumVector[i]/10;
		}
		sumVector[i] = sum;

		cout << "The sum of the digits of ";
		if (myVector[i] < 100)
		{
			std::cout << left << std::setfill('0') << setw(3)<< myVector[i];
			cout << right;
		}else
			cout << myVector[i];
		cout << " is " << sumVector[i] << endl;
	}

	return 0;
}
