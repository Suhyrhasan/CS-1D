/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #16: Sort Performance
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 05/13/2020
 *****************************************************************************/
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stack>
#include <string>
using namespace std;
//USED FOR FORMATTING
const int COL_WIDTH = 10;

//Used for ArrayFill() to determine how to fill the array.
enum ArrayType
{
	ORDERED, REVERSED, RANDOMIZED
};

//Used by QuickSort() to decide which index to use as the pivot.
enum PivotIndex
{
	FIRST, MIDDLE, RANDOM
};

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
		int asNum,                    // IN - Assignment Number
		char asType)                   // IN - Assignment Type ('L' = Lab,
//                       'A' = Assignment)
{
	ostringstream output;
	output << left;
	output << "***************************************************************************\n";
	output << "*  PROGRAMMED BY : Suhyr Hasan\n";
	output << "*  " << setw(14) << "STUDENT IDs" << ": 1022520\n";
	output << "*  " << setw(14) << "CLASS"	     <<": CS1D - MW - 2:30pm - 4:50pm\n";
	output << "*  " ;

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
	output << "***************************************************************************\n";
	output << right;
	return output.str();
}
/*************************************************************************
 * FUNCTION ArrayFill
 * -----------------------------------------------------------------------
 * This fills arrays according to different paramaters.
 * -----------------------------------------------------------------------
 * INPUT -
 * 	arr      : The array to fill.
 * 	size     : The size of the array.
 * 	fillType : Whether the array elements should be ordered, reverse
 * 	           ordered, or randomized.
 *
 * OUTPUT -
 * 	arr      : The array will be filled when the function ends.
 *************************************************************************/
void ArrayFill(int* arr, int size, ArrayType fillType)
{
	switch(fillType)
	{
	case ORDERED:    //Ordered from 1-N.
		for (int index = 0; index < size; ++index)
		{
			arr[index] = index + 1;
		}
		break;
	case REVERSED:   //Reverse ordered from N-1.
		for (int index = size - 1; index >= 0; --index)
		{
			arr[index] = size - index;
		}
		break;
	case RANDOMIZED: //All elements are randomized.
		srand(time(NULL));
		for (int index = 0; index < size; ++index)
		{
			arr[index] = rand() % 30000;
		}
		break;
	}
}
/*************************************************************************
 * FUNCTION Partition
 * -----------------------------------------------------------------------
 * This function partitions a set of integers around a pivot. It is called
 * iteratively by the quick sort function. After it is called it guarantees
 * that every number in the range it was given which is lower than the
 * returned index is to the left of the index, and likewise for larger
 * numbers and the right of the index.
 * -----------------------------------------------------------------------
 * INPUT -
 * 	low   	  : The lowest index of the array to sort.
 * 	high  	  : The highest index of the array to sort.
 * 	arr   	  : The array to sort.
 * 	swaps 	  : The number of swaps used to sort the array.
 * 	pivotType : Whether to pivot on the first element, the middle element,
 * 	            or a random element.
 *
 * OUTPUT -
 * 	arr    : This is returned, having been sorted over the given range.
 * 	swaps  : This is returned, having been updated with the number of
 * 	         swaps used during this function.
 * 	hIndex : This is returned pointing to the index of the pivot. Every
 * 	         index (within the provided range) to the left of this has a
 * 	         number less than or equal to the pivot, and every index to the
 * 	         right has a number greater than or equal to the pivot.
 *************************************************************************/
int Partition(int low, int high, int *arr, long long& swaps, PivotIndex pivotType)
{
	//VARIABLE DECLERATIONS
	int hIndex;//PROC & OUT - Stores the index of the higher number being
	//             sorted. Is returned pointing at the pivot.
	int lIndex;//PROC       - Stores the index of the lower number being
	//             sorted.
	int pivot; //PROC       - The value, not index, of the pivot.
	int temp;  //PROC       - Used to temporarily store values during swaps.

	//VARIABLE INITIALIZATIONS
	lIndex = low;
	hIndex = high;

	/*********************************************************************
	 * PROC - Set the pivot based on the pivot type.
	 *********************************************************************/
	switch(pivotType)
	{
	case FIRST:
		pivot = arr[low];
		break;

	case MIDDLE:
		pivot = arr[((high - low) / 2) + low];
		break;

	case RANDOM:
		srand(time(NULL));
		pivot = arr[(rand() % (high - low)) + low];
		break;
	}

	/*********************************************************************
	 * PROC - This loop will run as long as the index of the lower number
	 *        being sorted is lower than the index of the higher number
	 *        being sorted.
	 *********************************************************************/
	while(lIndex < hIndex)
	{
		/*****************************************************************
		 * PROC - If lIndex's number is less than the pivot it is already
		 *        sorted and lIndex goes up until it finds one that isn't.
		 *****************************************************************/
		while(arr[lIndex] < pivot)
		{
			lIndex++;
		}

		/*****************************************************************
		 * PROC - If hIndex's number is greater than the pivot it is
		 *        already sorted and hIndex goes up until it finds one
		 *        that isn't.
		 *****************************************************************/
		while(arr[hIndex] > pivot)
		{
			hIndex--;
		}

		/*****************************************************************
		 * PROC - If lIndex is less than hIndex and they have both found
		 *        unsorted numbers, then the numbers are swapped. The
		 *        higher number is now on the right of the pivot and the
		 *        lower number is now on its left.
		 *****************************************************************/
		if(lIndex < hIndex)
		{
			/*************************************************************
			 * PROC - If the two numbers are equal then they must be the
			 *        same value as the pivot. If this is the case then
			 *        hIndex simply decrements passed it and it is sorted
			 *        in a later call.
			 *
			 *        Otherwise, the swap proceeds as normal.
			 *************************************************************/
			if(arr[lIndex] == arr[hIndex])
			{
				hIndex--;
			}
			else
			{
				temp        = arr[lIndex];
				arr[lIndex] = arr[hIndex];
				arr[hIndex] = temp;
				++swaps;
			}
		}
	}

	return hIndex;
}

/*************************************************************************
 * FUNCTION QuickSort
 * -----------------------------------------------------------------------
 * This function is an iterative sorting function. It uses a pivot to
 * organize subsets of the array as being less than and greater than or
 * equal to the pivot. It then iterates over those subsections. This
 * continues until the array is sorted.
 * -----------------------------------------------------------------------
 * INPUT -
 * 	low   	  : The lowest index of the array to sort.
 * 	high  	  : The highest index of the array to sort.
 * 	arr   	  : The array to sort.
 * 	swaps 	  : The number of swaps used to sort the array.
 * 	pivotType : Whether to pivot on the first element, the middle element,
 * 	            or a random element.
 *
 * OUTPUT -
 * 	arr    : This is returned, having been sorted over the given range.
 * 	swaps  : This is returned, having been updated with the number of
 * 	         swaps used during this function.
 *************************************************************************/
void QuickSort (int low, int high, int *arr, long long& swapCount, PivotIndex pivotType)
{
	//VARIABLE DECLERATIONS
	stack<int> sortStack; //PROC - This stores the low-high index pairs
	//       that still need to be iterated over.
	int        pivotIndex;//PROC - Stores the index of the current pivot.

	/*********************************************************************
	 * PROC - High and low are pushed onto the stack as its initial values.
	 *********************************************************************/
	sortStack.push(low);
	sortStack.push(high);

	/*********************************************************************
	 * PROC - Since the stack stores the ranges of the array to be
	 *        iterated over, the function will loop until the stack is
	 *        empty indicating that all ranges of the array are sorted.
	 *********************************************************************/
	while (!sortStack.empty())
	{
		/*****************************************************************
		 * PROC - The range to iterate over is retrieved form the stack.
		 *****************************************************************/
		high = sortStack.top();
		sortStack.pop();

		low = sortStack.top();
		sortStack.pop();

		/*****************************************************************
		 * PROC - The range is partitioned and the index of the pivot is
		 *        returned.
		 *****************************************************************/
		pivotIndex = Partition(low, high, arr, swapCount, pivotType);

		/*****************************************************************
		 * PROC - If there are elements to the left of the pivot then
		 *        that range is added to the stack.
		 *****************************************************************/
		if (pivotIndex - 1 > low)
		{
			sortStack.push(low);
			sortStack.push(pivotIndex - 1);
		}

		/*****************************************************************
		 * PROC - If there are elements to the right of the pivot then
		 *        that range is added to the stack.
		 *****************************************************************/
		if (pivotIndex + 1 < high)
		{
			sortStack.push(pivotIndex + 1);
			sortStack.push(high);
		}
	}
}
/*************************************************************************
 * FUNCTION WordWrap
 * ______________________________________________________________________
 * This will read in a string and a margin to fit that string into. It
 * will parse through the string and create a version of it with new
 * line characters before words that don't fit in the margins. This new
 * string is returned to be output.
 * ______________________________________________________________________
 * PRE-CONDITIONS -
 * 	toWrap     : The string you want to be word wrapped.
 * 	lineLength : The width of the line you want the string to conform to.
 *
 * POST-CONDITIONS -
 * 	wrapped    : A version of the input string which has been word wrapped
 * 	             with new line characters.
 *************************************************************************/
string WordWrap(string toWrap,     //IN - The string to be word wrapped.
		int    lineLength) //IN - The width of the line to fit
//     your string into.
{
	//VARIABLE DECLERATIONS
	int    charCount;   //CALC - Iterates through the string.
	int    stringLength;//CALC - Total length of the string.
	string word;        //CALC - Temporarily stores words from your string.
	string line;        //CALC - Stores a line until it would exceed the
	//       the margin.
	string wrapped;     //OUT  - Final version of the word wrapped string.

	//VARIABLE INITIALIZATIONS
	stringLength = toWrap.length();
	word    = "";
	line    = "";
	wrapped = "";

	//Iterates through every character of the string
	for (charCount = 0; charCount < stringLength; charCount++)
	{
		//If this character is not a space then its added to the current
		//word.
		if (toWrap[charCount] != ' ')
		{
			word = word + toWrap[charCount];
		}
		else //If it is a space then the word has ended
		{
			//If the word can't fit on the current line without going
			//over the margin then add it to the final string with a new
			//line character and reset the line.
			if (line.length() + word.length() > lineLength)
			{
				wrapped = wrapped + line + '\n';
				line.clear();
			}
			//Update line with the word and add a space after. Then reset
			//word.
			line = line + word + ' ';
			word.clear();
		}
	}

	//This checks the last word, which won't be checked above because there
	//probably isn't a space at the end of your string.
	if (line.length() + word.length() > lineLength)
	{
		wrapped = wrapped + line + '\n';
		line.clear();
	}
	wrapped = wrapped + line + word;

	return wrapped;
}
/*************************************************************************
 * FUNCTION OutputQuickSort
 * -----------------------------------------------------------------------
 * This wraps the quick sort function with information to track its
 * performance and output the result to the console. It will keep track
 * of the time taken to run, the number of swaps done in the sort, the
 * first ten elements before the sort, and the first ten elements after.
 * These are output to the console when the sort is done in a formatted
 * chart.
 * -----------------------------------------------------------------------
 * INPUT -
 * 	low       : The lowest index of the array to sort.
 * 	high      : The highest index of the array to sort.
 * 	arr       : The array to sort.
 * 	pivotType : Whether the pivot should be the first element, the middle
 * 	            element, or a random element.
 *
 * OUTPUT -
 * 	arr             : This is returned, having been sorted.
 * 	operationsCount : Is output to the console, contains the number of
 * 	                  swaps done by the sort.
 * 	tv_nsex         : Is output to the console, contains the number of
 * 	                  nanoseconds taken by the sort.
 * 	temp            : Is output to the console, contains the first elements
 * 	                  of arr from before the sort.
 *************************************************************************/
void OutputQuickSort(int low, int high, int* arr, PivotIndex pivotType)
{
	//VARIABLE DECLERATIONS
	long long operationsCount;//OUT - Stores number of swaps.
	timespec  tS;             //OUT - Stores time elapsed.
	int       temp[10];       //OUT - Stores the first ten unsorted elements.

	//VARIABLE INITIIALIZATIONS
	operationsCount = 0;
	tS.tv_sec       = 0;
	tS.tv_nsec      = 0;

	//Store the first ten unsorted elements of arr in temp.
	for (int i = 0; i < 10; ++i)
	{
		temp[i] = arr[i];
	}

	//Output the size and pivot type of the array about to be sorted.
	cout << left;
	cout << setw(COL_WIDTH)
												 << high + 1
												 << setw(COL_WIDTH + 5)
												 << (pivotType == FIRST  ? "First" :
														 pivotType == MIDDLE ? "Middle":
																 "Random");

	//Start timing, run the sort, and end timing.
	clock_settime(CLOCK_PROCESS_CPUTIME_ID, &tS);

	QuickSort(low, high, arr, operationsCount, pivotType);

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tS);

	//Output the elapsed time and the number of swaps.
	cout << setw(COL_WIDTH + 5) << tS.tv_nsec
			<< setw(COL_WIDTH)     << operationsCount;

	//Output the first ten elements of the array before and after it
	//was sorted.
	cout << "UNSORTED: ";
	for (int i = 0; i < 10; ++i)
	{
		cout << temp[i];
		if (i != 9)
			cout << ", ";
	}
	cout << endl;

	cout << setw(50) << ' ' << "SORTED  : ";
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i];
		if (i != 9)
			cout << ", ";
	}
	cout << endl;

	cout << right;
}
/*************************************************************************
 * FUNCTION OutputChartHeader
 * -----------------------------------------------------------------------
 * Outputs a small formatted line of text to act as a 'header' for the
 * charts monitoring quick sort performance.
 * -----------------------------------------------------------------------
 * INPUT -
 * 	title : The title of chart.
 *
 * OUTPUT -
 * 	Sends to the console something that looks like this:
 * 	     title -
 * 	     Size(N)      Pivot Type      Time(ns)      Swaps
 *
 *************************************************************************/
void OutputChartHeader(string title)
{
	cout << left;
	cout << title << " -\n";
	cout << setw(COL_WIDTH)       << "Size(N)"
			<< setw(COL_WIDTH + 5)   << "Pivot Type"
			<< setw(COL_WIDTH + 5)   << "Time (ns)"
			<< setw(COL_WIDTH)       << "Swaps" << endl << endl;
	cout << right;
}

/******************************************************************************
 * Huffman Coding
 * ----------------------------------------------------------------------------
 * This program will print out the frequency table and the Huffman Code for
 * each letter of the Gettysburg address.Then it will encode the Gettysburg
 * address and print it. It will decode the compressed and encoded file that is
 * created and print out the compression ratio that was achieved.
 * ----------------------------------------------------------------------------
 *****************************************************************************/
int main()
{
	//VARIABLE DECLERATIONS
	int arr5K [50000]; //PROC & OUT - Stores 50000 integers.
	int arr10K[75000]; //PROC & OUT - Stores 75000 integers.

	/*********************************************************************
	 * OUT - Outputs the class header to the console.
	 *********************************************************************/
	// Output header to console
	std::cout << PrinterHeader("Sort Performance", 15, 'A');
	/*********************************************************************
	 * ORDERED ARRAYS
	 *********************************************************************/
	OutputChartHeader("ORDERED");
	//50000 Elements
	ArrayFill(arr5K, 50000, ORDERED);
	OutputQuickSort(0, 49999,  arr5K,  FIRST);

	ArrayFill(arr5K, 50000, ORDERED);
	OutputQuickSort(0, 49999,  arr5K,  MIDDLE);

	ArrayFill(arr5K, 5000, ORDERED);
	OutputQuickSort(0, 49999,  arr5K,  RANDOM);

	//75000 Elements
	ArrayFill(arr10K, 75000, ORDERED);
	OutputQuickSort(0, 76999,  arr10K, FIRST);

	ArrayFill(arr10K, 75000, ORDERED);
	OutputQuickSort(0, 76999,  arr10K, MIDDLE);

	ArrayFill(arr10K, 75000, ORDERED);
	OutputQuickSort(0, 76999,  arr10K, RANDOM);

	cout << endl << endl;


	/*********************************************************************
	 * REVERSE ORDERED ARRAYS
	 *********************************************************************/
	OutputChartHeader("REVERSE ORDERED");

	//5000 Elements
	ArrayFill(arr5K, 5000, REVERSED);
	OutputQuickSort(0, 4999,  arr5K,  FIRST);

	ArrayFill(arr5K, 5000, REVERSED);
	OutputQuickSort(0, 4999,  arr5K,  MIDDLE);

	ArrayFill(arr5K, 5000, REVERSED);
	OutputQuickSort(0, 4999,  arr5K,  RANDOM);

	//75000 Elements
	ArrayFill(arr10K, 75000, REVERSED);
	OutputQuickSort(0, 76999,  arr10K, FIRST);

	ArrayFill(arr10K, 75000, REVERSED);
	OutputQuickSort(0, 76999,  arr10K, MIDDLE);

	ArrayFill(arr10K, 75000, REVERSED);
	OutputQuickSort(0, 76999,  arr10K, RANDOM);
	cout << endl << endl;


	/*********************************************************************
	 * RANDOMIZED ARRAYS
	 *********************************************************************/
	OutputChartHeader("RANDOM NUMBERS");

	//50000 Elements
	ArrayFill(arr5K, 5000, RANDOMIZED);
	OutputQuickSort(0, 4999,  arr5K,  FIRST);

	ArrayFill(arr5K, 5000, RANDOMIZED);
	OutputQuickSort(0, 4999,  arr5K,  MIDDLE);

	ArrayFill(arr5K, 5000, RANDOMIZED);
	OutputQuickSort(0, 4999,  arr5K,  RANDOM);

	//75000 Elements
	ArrayFill(arr10K, 75000, RANDOMIZED);
	OutputQuickSort(0, 76999,  arr10K, FIRST);

	ArrayFill(arr10K, 75000, RANDOMIZED);
	OutputQuickSort(0, 76999,  arr10K, MIDDLE);

	ArrayFill(arr10K, 75000, RANDOMIZED);
	OutputQuickSort(0, 76999,  arr10K, RANDOM);
	cout << endl;

	/*********************************************************************
	 * OUTPUT - The results are analyzed and output to the console.
	 *********************************************************************/
	cout << WordWrap("Using the left most pivot is a bad idea because if"
			"the array was already sorted (not uncommon) then you "
			"run in the worst case, which is O(n^2). The best case "
			"is O(logn) which is a substantial improvement. On "
			"average there was little difference between a random "
			"pivot or the middle pivot, but when there was the "
			"middle pivot came out just slightly better so I "
			"suppose thats the strategy I would prefer.", 80);

	return 0;
}
