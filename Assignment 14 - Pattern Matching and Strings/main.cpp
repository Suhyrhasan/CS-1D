/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #14: Pattern Matching and Strings
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 04/29/2020
 *****************************************************************************/
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <limits.h>
#include <iostream>
using namespace std;
# define NO_OF_CHARS 256
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
/******************************************************************************
 * Function lcs
 * ____________________________________________________________________________
 * This function will return the length of LCS for X[0..m-1], Y[0..n-1].
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               X -
 * 	               Y -
 * 	               m -
 * 	               n -
 * POST-CONDITIONS
 * 	  This function will return the length of LCS for X[0..m-1], Y[0..n-1].
 ******************************************************************************/
void lcs( char *X, char *Y, int m, int n )
{
	int L[m+1][n+1];

	/* Following steps build L[m+1][n+1] in bottom up fashion. Note
	that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	for (int i=0; i<=m; i++)
	{
		for (int j=0; j<=n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i-1] == Y[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}

	// Following code is used to print LCS
	int index = L[m][n];

	// Create a character array to store the lcs string
	char lcs[index+1];
	lcs[index] = '\0'; // Set the terminating character

	// Start from the right-most-bottom-most corner and
	// one by one store characters in lcs[]
	int i = m, j = n;
	while (i > 0 && j > 0)
	{
		// If current character in X[] and Y are same, then
		// current character is part of LCS
		if (X[i-1] == Y[j-1])
		{
			lcs[index-1] = X[i-1]; // Put current character in result
			i--; j--; index--;	 // reduce values of i, j and index
		}

		// If not same, then find the larger of two and
		// go in the direction of larger value
		else if (L[i-1][j] > L[i][j-1])
			i--;
		else
			j--;
	}

	// Print the lcs
	cout << "LCS of " << X << " and " << Y << " is " << lcs;
}
/******************************************************************************
 * Function bruteforce
 * ____________________________________________________________________________
 * This function will
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               key  -
 * 	               text -
 *
 * POST-CONDITIONS
 * 	  This function will
 ******************************************************************************/
int bruteforce(string key, string text)
{
	bool verify = false;
	int count = 0;
	unsigned int i = 0;
	unsigned int a = 0;
	while(i < text.size() && !verify)
	{
		if(key[a] == text[i])
		{
			count ++;
			a++;
			unsigned int b = i;
			while(key[a] == text[b] && !verify)
			{
				if(a < key.size())
				{
					count ++;
					a++;
					b++;
				}
				else
				{
					verify = true;
					count ++;
				}
			}
		}
		else
		{
			a = 0;
			++i;
		}
	}
	return count;
}
/******************************************************************************
 * Function Max
 * ____________________________________________________________________________
 * This function will
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               a -
 * 	               b -
 * POST-CONDITIONS
 * 	  This function will
 ******************************************************************************/
static int Max(int a, int b)
{
	return a >= b ? a : b;
}
/******************************************************************************
 * Function BadCharHeuristic
 * ____________________________________________________________________________
 * This function will
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               str     -
 * 	               size    -
 * 	               badChar -
 * POST-CONDITIONS
 * 	  This function will
 ******************************************************************************/
static void BadCharHeuristic(string str, int size, int* badChar)
{
	int i;
	for (i = 0; i < 256; i++)
		badChar[i] = -1;

	for (i = 0; i < size; i++)
		badChar[(int)str[i]] = i;
}
/******************************************************************************
 * Function SearchString
 * ____________________________________________________________________________
 * This function will
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               str  -
 * 	               pat  -
 * POST-CONDITIONS
 * 	  This function will
 ******************************************************************************/
vector<int> SearchString(string str, string pat) {
	vector<int> retVal;
	int m = pat.length();
	int n = str.length();
	int count = 0;

	int* badChar = new int[256];

	BadCharHeuristic(pat, m, badChar);

	int s = 0;
	while (s <= (n - m))
	{
		int j = m - 1;

		while (j >= 0 && pat[j] == str[s + j])
			--j;

		if (j < 0)
		{
			count ++;
			retVal.push_back(s);
			s += (s + m < n) ? m - badChar[str[s + m]] : 1;
		}
		else
		{
			count ++;
			s += Max(1, j - badChar[str[s + j]]);
		}
	}

	cout << count + pat.size();
	delete[] badChar;

	return retVal;
}

/******************************************************************************
 * Function SearchString
 * ____________________________________________________________________________
 * This function will
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               str  -
 * 	               pat  -
 * POST-CONDITIONS
 * 	  This function will
 ******************************************************************************/
vector<int> computeFailFunction(string key){
	vector<int> F;
	F.push_back(0);
	int i = 1;
	int j = 0;
	while(i < key.size())
	{
		if(key[i] == key[j])
		{
			F.push_back(j+1);
			++i;
			++j;
		}
		else if(j > 0)
		{
			j = F[j-1];
		}
		else
		{
			F.push_back(0);
			++i;
		}
	}
	return F;
	}
/******************************************************************************
 * Function SearchString
 * ____________________________________________________________________________
 * This function will
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               str  -
 * 	               pat  -
 * POST-CONDITIONS
 * 	  This function will
 ******************************************************************************/
int KMP(string key, string text)
{
	int n = text.size();
	int m = key.size();
	int count = 0;
	std::vector<int> fail = computeFailFunction(key);
	int i = 0;					// text index
	int j = 0;					// pattern index
	while (i < n) {
		if (key[j] == text[i]) {
			if (j == m - 1)
			{
				cout << count + 1;
				return i - m + 1;			// found a match
			}
			i++;
			j++;
			++count;
		}
		else if (j > 0)
		{
			count ++;
			j = fail[j - 1];
		}
		else
		{
			count ++;
			i++;
		}
	}
	return -1;					// no match

}


/******************************************************************************
 * Pattern Matching and Strings
 * ----------------------------------------------------------------------------
 * This program will use
 * ----------------------------------------------------------------------------
 *  INPUT:
 *
 *  OUTPUT:
 *
 *****************************************************************************/
int main()
{
	// Output header to console
	cout << PrinterHeader("Pattern Matching and Strings", 14, 'A');
	// Output description of the program
	cout << "\nThis program will\n\n";
	/*****************************************************************************
	 * First - Construct the Longest Common Subsequence (LCS) matrix comparing the
	 *         strings �aaabcaadaabaaa� and �abcdba�. What is the LCS?
	 *****************************************************************************/
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "  Longest Common Subsequence (LCS) matrix";
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++"
			"+++++++++++++++++++++++++++++++++++++++++++++++++\n";
	string key = "axdcax";
	string text = "axaax";
	int L [7][6];
	int i;
	int j;
	int n =7;
	int m = 6;

	// initialize the first column to zero
	for (i = 0;i < n; i++)
	{
		L[i][0]=0;
	}
	// initialize the first rows to zero
	for (j = 1;j < m; j++)
	{
		L[0][j]=0;
	}
	for (i = 1;i <= n-1; i++)
	{
		for (j = 1;j <= m-1; j++) //
		{
			if (key[i - 1]==text[j - 1])
			{
				L[i][j]=L[i-1][j-1] + 1;
			}
			else
			{
				L[i][j]=max(L[i-1][j],L[i][j-1]);
			}
		}
	}
	// print the array
	i=j=0;
	while ( i < n )
	{
		cout << L[i][j];
		( j == m - 1 ) ? cout << '\n' : cout << '\t' ;
		( j == m - 1 ) ? i++,j=0 : j++;
	}
	char X[] = "axdcax";
	char Y[] = "axaax";
	int p = strlen(X);
	int q = strlen(Y);
	lcs(X, Y, p, q);
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++"
			"+++++++++++++++++++++++++++++++++++++++++++++++++\n";

	/*****************************************************************************
	 * Second - Draw a figure illustrating the comparisons done by the brute-force
	 *          pattern matching algorithm for the text �aaabcaadaabaaa� and
	 *          pattern �aabaaa�. Determine the number of comparisons needed.
	 *****************************************************************************/
	cout << "\n+++++++++++++++++++++++++\n";
	cout << "  Brute Force Algorithm  ";
	cout << "\n+++++++++++++++++++++++++\n";
	cout << "+++++++++++++++++++++++++++++++++++++++"
			"++++++++++++++++++++++++++++++++++++++\n";
	string txt = "aecdaexaecdaecdaeda";
	string ke = "aecdaed";
	cout << "Brute force algorithm performed on the text : " << txt
			<< endl << "With the key: " << ke << endl << "requires ";
	cout << bruteforce(ke, txt) << " comparisons";
	cout << "\n+++++++++++++++++++++++++++++++++++++++"
			"++++++++++++++++++++++++++++++++++++++\n";

	/*****************************************************************************
	 * Third - Draw a figure illustrating the comparisons done by the Boyer-Moore
	 *         (BM) matching algorithm for the text �aaabcaadaabaaa� and pattern
	 *         �aabaaa�. Determine the number of comparisons needed.
	 *****************************************************************************/
	cout << "\n+++++++++++++++++++++++++\n";
	cout << "  Boyer-Moore Algorithm   ";
	cout << "\n+++++++++++++++++++++++++\n";
	cout << "+++++++++++++++++++++++++++++++++++++++"
			"++++++++++++++++++++++++++++++++++++++\n";
	string tet = "aecdaexaecdaecdaeda";
	string ky = "aecdaed";
	cout << "Boyer-Moore algorithm performed on text: " << tet
			<< endl << "With the key: " << ky << endl << "requires ";
	SearchString(tet, ky);
	cout << " comparisons";
	cout << "\n+++++++++++++++++++++++++++++++++++++++"
			"++++++++++++++++++++++++++++++++++++++\n";

	/*****************************************************************************
	 * Fourth - Draw a figure illustrating the comparisons done by the Knuth-Morris
	 *          -Pratt (KMP) matching algorithm for the text �aaabcaadaabaaa� and
	 *          pattern �aabaaa�. Determine the number of comparisons needed.
	 *****************************************************************************/
	cout << "\n++++++++++++++++++++++++++++++++\n";
	cout << "  Knuth-Morris-Pratt Algorithm  ";
	cout << "\n++++++++++++++++++++++++++++++++\n";
	cout << "+++++++++++++++++++++++++++++++++++++++"
			"++++++++++++++++++++++++++++++++++++++\n";
	string t = "aecdaexaecdaecdaeda";
	string k = "aecdaed";
	cout << "Knuth-Morris-Pratt algorithm performed on text: " << t
			<< endl << "With the key: " << k << endl << "requires ";
	KMP(k, t);
	cout << " comparisons";
	cout << "\n+++++++++++++++++++++++++++++++++++++++"
			"++++++++++++++++++++++++++++++++++++++\n";
	return 0;
}
