/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #6 : Priority Queues
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/26/2020
 *****************************************************************************/
#ifndef CLOCKTYPE_H_
#define CLOCKTYPE_H_
#include "myheader.h"
/****************************************************************
 * clockType
 * This class represents an time object.
 ***************************************************************/
class clockType
{
public:
	friend std::ostream& operator << (std::ostream& out, const clockType* x);
	friend std::ostream& operator << (std::ostream& out, const clockType x);
	/******************************
	 ** CONSTRUCTOR & DESTRUCTOR **
	 ******************************/
	/****************************************************************
	 * clockType(int hour, int minute);
	 * Parameterized Constructor; Initialize class attributes
	 * Parameters: none
	 * Return: none
	 ***************************************************************/
	clockType(int hour, int minute);
	/****************
	 ** MUTATORS **
	 ****************/
	/*******************************************************************
	 * void addMin(int newMin);
	 *
	 * Mutator; This method will read in a new minute
	 *------------------------------------------------------------------
	 * Parameter: int newMin - New Minute
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void addMin(int newMinute);

	/***************
	 ** ACCESSORS **
	 ***************/
	/*******************************************************************
	 * int getHours() const;
	 *
	 * Accessor; This method will return the number of hours
	 *-----------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: int hours - number of hours
	 *******************************************************************/
	int getHours() const;
	/*******************************************************************
	 * int getMin() const;
	 *
	 * Accessor; This method will return the number of minutes
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: int minutes - number of minutes
	 *******************************************************************/
	int getMinutes() const;

private:
	//private members
	int hours;
	int minutes;
};
/****************************************************************
 * clockType(int hour, int minute)
 * Parameterized Constructor; Initialize class attributes
 * Parameters: none
 * Return: none
 ***************************************************************/
clockType::clockType(int hour, int minute)
{
	hours = hour;
	minutes = minute;
}
/******************************************************************************
 * Method addMin : Class clockType
 * ____________________________________________________________________________
 *  This method will add a new minute
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	  This function will not return anything
 ******************************************************************************/
void clockType::addMin(int newMinute)
{
	minutes += newMinute;
	//if more than one hr
	if (minutes > 60)
	{
		hours++;
		minutes -= 60;
	}
	if (hours > 12)
	{
		hours = hours - 12;
	}
}
/******************************************************************************
 * Method getHours : Class clockType
 * ____________________________________________________________________________
 *  This method will get number hours.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	  This function will return number hours.
 ******************************************************************************/
int clockType::getHours() const
{
	return hours;
}
/******************************************************************************
 * Method getMinutes : Class clockType
 * ____________________________________________________________________________
 *  This method will get number of minutes.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	  This function will return number of minutes.
 ******************************************************************************/
int clockType::getMinutes() const
{
	return minutes;
}
#endif /* CLOCKTYPE_H_ */
