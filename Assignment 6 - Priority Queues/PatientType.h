/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #6 : Priority Queues
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/26/2020
 *****************************************************************************/
#ifndef PATIENTTYPE_H_
#define PATIENTTYPE_H_
#include "myheader.h"
/****************************************************************
 * patientType
 * This class represents an queue list object.
 ***************************************************************/
class patientType
{
public:
	/******************************
	 ** CONSTRUCTOR & DESTRUCTOR **
	 ******************************/

	/****************************************************************
	 * Patient();
	 * Constructor; Initialize class attributes
	 * Parameters: none
	 * Return: none
	 ***************************************************************/
	patientType();
	/****************************************************************
	 * patientType(std::string newName, int newTime);
	 * Parameterized Constructor; Initialize class attributes
	 * Parameters: none
	 * Return: none
	 ***************************************************************/
	patientType(std::string newName, int newTime);

	/****************
	 ** MUTATORS **
	 ****************/
	/*******************************************************************
	 * void setName(std::string newName);
	 *
	 * Mutator; This method will set patient name.
	 *------------------------------------------------------------------
	 * Parameter: string newName - New Name
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void setName(std::string newName);
	/*******************************************************************
	 * void setPriority(int newTime);
	 *
	 * Mutator; This method will set priority time.
	 *------------------------------------------------------------------
	 * Parameter: int newTime - New Time
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void setPriority(int newTime);
	/***************
	 ** ACCESSORS **
	 ***************/

	/*******************************************************************
	 * std::string getName() const;
	 *
	 * Accessor; This method will return patient name.
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: string Name - Patient Name
	 *******************************************************************/
	std::string getName() const;
	/*******************************************************************
	 * int getPriority() const;
	 *
	 * Accessor; This method will return priority time.
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: int priority - Priority Time
	 *******************************************************************/
	int getPriority() const;
private:
	//private members
	std::string name;
	int priority;
};
/****************************************************************
 * Patient()
 * Constructor; Initialize class attributes
 * Parameters: none
 * Return: none
 ***************************************************************/
patientType::patientType()
{
	name = "";
	priority = 0;
}
/****************************************************************
 * Patient(std::string newName, int newTime)
 * Parameterized Constructor; Initialize class attributes
 * Parameters: none
 * Return: none
 ***************************************************************/
patientType::patientType(std::string newName, int newTime)
{
	name = newName;
	priority = newTime;
}
/******************************************************************************
 * Method setName : Class patientType
 * ____________________________________________________________________________
 *  This method will set patient name.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               string newName - New Name
 * POST-CONDITIONS
 * 	  This function will set patient name.
 ******************************************************************************/
void patientType::setName(std::string newName)
{
	name = newName;
}
/******************************************************************************
 * Method  setPriority : Class patientType
 * ____________________________________________________________________________
 *  This method will set priority time.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               int newTime - New Time
 * POST-CONDITIONS
 * 	  This function will set priority time.
 ******************************************************************************/
void patientType::setPriority(int newTime)
{
	priority = newTime;
}
/******************************************************************************
 * Method getName : Class patientType
 * ____________________________________________________________________________
 *  This method will return patient name.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	  This function will return patient name.
 ******************************************************************************/
std::string patientType::getName() const
{
	return name;
}
/******************************************************************************
 * Method getPriority : Class patientType
 * ____________________________________________________________________________
 *  This method will return priority time.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	  This function will return priority time.
 ******************************************************************************/
int patientType::getPriority() const
{
	return priority;
}

#endif /* PATIENTTYPE_H_ */
