/******************************************************************************
 * AUTHOR	   : Suhyr Hasan and Tanner Cordero
 * STUDENT ID  : 1022520 and
 * Lab # 2     : Test using GITHUB
 * CLASS 	   : CS1D
 * SECTION 	   : MW 2:30p - 4:50p
 * DUE DATE	   : 01/15/2020
 *****************************************************************************/
#include <iostream>
using namespace std;
int hello1Function(string name1);
int hello2Function(string name2);
/******************************************************************************
 * Test using GITHUB
 * ----------------------------------------------------------------------------
 * Hello World in C++
 * ----------------------------------------------------------------------------
 *****************************************************************************/
int main()
{
	string name1="Suhyr Hasan";
	hello1Function(name1);
	string name2="Tanner Cordero";
	hello2Function(name2);
	return 0;
}
/******************************************************************************
 * Function hello1Function
 * ____________________________________________________________________________
 * This function reads in a name1 and then outputs a string to the console.
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	                name1 : 1st name
 *
 * POST-CONDITIONS
 * 	  This function outputs a string.
 ******************************************************************************/
int hello1Function(string name1)
{
	cout << "hello World " << name1 << endl;
	return 0;
}

/******************************************************************************
 * Function hello2Function
 * ____________________________________________________________________________
 * This function reads in a name and then outputs a string to the console.
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	                name2 : 2nd name
 *
 * POST-CONDITIONS
 * 	  This function outputs a string.
 ******************************************************************************/
int hello2Function(string name2)
{
	cout << "hello World " << name2 << endl;
	return 0;
}
