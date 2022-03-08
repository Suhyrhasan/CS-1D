/******************************************************************************
 * AUTHOR	   : Suhyr Hasan and Carissa Happeny
 * STUDENT ID  : 1022520 and 1123318
 * Lab # 3     : PrefixAverages
 * CLASS 	   : CS1D
 * SECTION 	   : MW 2:30p - 4:50p
 * DUE DATE	   : 01/27/2020
 *****************************************************************************/
#include<chrono>
#include<string>
#include<iomanip>
#include<cstdlib>
#include <stdlib.h>
#include<sstream>
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::chrono;// using namespace std::chrono
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
 * POST-CONDITIONS
 * 	  This function will output the class heading.
 ******************************************************************************/
string PrinterHeader(string asName,    // IN - Assignment Name
		int asNum,                    // IN - Assignment Number
		char asType)                   // IN - Assignment Type ('L' = Lab,
//                       'A' = Assignment)
{
	ostringstream output;
	output << left;
	output << "*****************************************************\n";
	output << "*  PROGRAMMED BY : Suhyr Hasan and Carissa Happeny\n";
	output << "*  " << setw(14) << "STUDENT IDs" << ": 1022520 and 1123318\n";
	output << "*  " << setw(14) << "CLASS" << ": CS1D - MW - 2:30pm - 4:50pm\n";
	output << "*  ";
	// PROCESSING - This will adjust setws and format appropriately based
	//              based on if this is a lab 'L' or assignment.
	if (toupper(asType) == 'L')
	{
		output << "LAB #" << setw(9);
	}
	else
	{
		output << "ASSIGNMENT #" << setw(2);
	}
	output << asNum << ": " << asName << endl;
	output << "*****************************************************\n";
	output << right;
	return output.str();
}

/******************************************************************************
 * FUNCTION prefixAverages1
 * ____________________________________________________________________________
 * This function will computes the prefix average in quadratic time.
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	                int X - array
 * 	                int n - array size
 * POST-CONDITIONS
 * 	  This function will return the prefix average.
 ******************************************************************************/
double* prefixAverages1(double* X, int n)
{
	int a;
	double* A = new double[n];
	for (int i = 0; i <= n - 1; i++)
	{
		a = 0;
		for (int j = 0; j <= i; j++)
		{
			a = a + X[j];
		}
		A[i] = (double)a / (i + 1);
	}
	return A;
}

/******************************************************************************
 * FUNCTION prefixAverages2
 * ____________________________________________________________________________
 * This function will compute the prefix average in linear time by keeping
 * a running sum.
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	                int X - array
 * 	                int n - array size
 * POST-CONDITIONS
 * 	  This function will return the prefix average.
 ******************************************************************************/
double* prefixAverages2(double* X, int n)
{
	int s = 0;
	double* A = new double[n];
	for (int i = 0; i <= n - 1; i++)
	{
		s = s + X[i];
		A[i] = (double)s / (i + 1);
	}
	return A;
}



/******************************************************************************
 * PrefixAverages
 * ----------------------------------------------------------------------------
 * This program implements prefixAverages1 and prefixAverages2 and perform an
 * experimental analysis of their running time using multiple array sizes.
 * ----------------------------------------------------------------------------
 * Input:
 *        A[10] - First Array
 *        B[10] - Second Array
 *
 * Output:
 *        duration  - the running time for prefixAverages1 using A[10]
 *        duration2 - the running time for prefixAverages2 using A[10]
 *        duration3 - the running time for prefixAverages1 using B[10]
 *        duration4 - the running time for prefixAverages2 using B[10]
 *****************************************************************************/
int main()
{
	// Output header to console
	cout << PrinterHeader("PrefixAverages", 3, 'L');
	cout << "\nThis program implements prefixAverages1 and prefixAverages2\n";
	cout << "and perform an experimental analysis of their running time \n";
	cout << "using multiple array sizes.\n";

	/* initialize random seed: */
	srand(time(NULL));
	double X[]; // CALC & OUT
	/*************************************************************************
	 * The program will use a random number generator to generate 15 integers
	 * between 1 and 99. Then the program will sort the random numbers and
	 * store it in a vector
	 *************************************************************************/
	for (int i = 0; i < 1; i++)
	{
		X(rand() % 1000);
	}

	int runtime = 100000;
	const int n = 10000000;
	int run = runtime;
	int run2 = runtime;
	double A[n];
	int nA = 0;
	double B[];
	int nB = 0;
	for (int i = 0; i <= n ; i++)
	{
		A[i] = i;
		B[i] = i;
	}

	/***********************************************************************
	 * Using the functions prefixaverage1() and prefixaverage2(),the program
	 * will compute the prefix average in quadratic time and in linear time
	 * of the first array. Then the program will measure the time used to
	 * execute each method and then display the resulting time (in seconds)
	 * for each method.
	 **********************************************************************/
	cout << "\n1st Array : ";
	for(int i = 0; i<10; i++)
	{
		cout << A[i] << ' ';
	}
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	while (runtime > 0)
	{
		prefixAverages1(A, nA);
		runtime--;
	}

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>
	(t2 - t1).count();
	cout << fixed << "\nIt took the program " << setprecision(10);
	cout << duration * (.000001) / run << " seconds to run prefixAverages1()\n";

	runtime = run;
	high_resolution_clock::time_point t3 = high_resolution_clock::now();
	while (runtime > 0)
	{
		prefixAverages2(A, nA);
		runtime--;
	}

	high_resolution_clock::time_point t4 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds> (t4 - t3).count();

	cout << fixed <<"It took the program " << setprecision(10);
	cout << (duration2 * (.000001)) / run << " seconds to run prefixAverages2()\n";
	/***********************************************************************
	 * Using the functions prefixaverage1() and prefixaverage2(),the program
	 * will compute the prefix average in quadratic time and in linear time
	 * of the second array. Then the program will measure the time used to
	 * execute each method and then display the resulting time (in seconds)
	 * for each method.
	 **********************************************************************/
	runtime = run2;
	//	int B[10] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
	//	int nB = 10;
	cout << "\n2nd Array : ";
	for(int i = 0; i<10; i++)
	{
		cout << B[i] << ' ';
	}
	high_resolution_clock::time_point t5 = high_resolution_clock::now();

	while (runtime > 0)
	{
		prefixAverages1(B, nB);
		runtime--;
	}

	high_resolution_clock::time_point t6 = high_resolution_clock::now();
	auto duration3 = duration_cast<microseconds>
	(t6 - t5).count();
	cout << fixed << "\nIt took the program " << setprecision(10);
	cout << duration3 * (.000001) / run2 << " seconds to run prefixAverages1()\n";

	runtime = run2;
	high_resolution_clock::time_point t7 = high_resolution_clock::now();
	while (runtime > 0)
	{
		prefixAverages2(B, nB);
		runtime--;
	}

	high_resolution_clock::time_point t8 = high_resolution_clock::now();
	auto duration4 = duration_cast<microseconds> (t8 - t7).count();

	cout << fixed <<"It took the program " << setprecision(10);
	cout << (duration4 * (.000001)) / run2 << " seconds to run prefixAverages2()\n";
	return 0;
}
