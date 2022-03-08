/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #3 : Stacks/Queues/Deques
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/03/2020
 *****************************************************************************/
#include "myheader.h"
/******************************************************************************
 * Function initializeStack
 * ____________________________________________________________________________
 * This function will initialize an empty string and float Stack.
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               stringStack - string stack
 * 	               floatStack  - float  stack
 *
 * POST-CONDITIONS
 * 	  This function return an initialized stack.
 ******************************************************************************/
void initializeStack(stack<string>& stringStack,stack<float>& floatStack)
{
	/****************************************
	 * INPUT - initialize empty string stack
	 ****************************************/
	stringStack.push("Mark");
	stringStack.push("Alan");
	stringStack.push("Jennifer");
	stringStack.push("Jordyn");
	stringStack.push("Eric");
	stringStack.push("JoAnn");
	stringStack.push("Bryan");
	/****************************************
	 * INPUT - initialize empty float stack
	 ****************************************/
	floatStack.push(2019.1);
	floatStack.push(44.44);
	floatStack.push(888.55);
	floatStack.push(200.12);
	floatStack.push(123.123);
	floatStack.push(8.445);
}
/******************************************************************************
 * Function ArePair
 * ____________________________________________________________________________
 * This function will
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	  This function
 ******************************************************************************/
bool ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')')
	{
		return true;
	}
	else if(opening == '{' && closing == '}')
	{
		return true;
	}
	else if(opening == '[' && closing == ']')
	{
		return true;
	}
	return false;
}
/******************************************************************************
 * Function AreParanthesesBalanced
 * ____________________________________________________________________________
 * This function will
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	  This function
 ******************************************************************************/
bool AreParanthesesBalanced(string exp)
{
	stack<char>  S;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
		{
			S.push(exp[i]);
		}
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(S.empty() || !ArePair(S.top(),exp[i]))
			{
				return false;
			}
			else
			{
				S.pop();
			}
		}
	}
	return S.empty() ? true:false;
}
