
/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #6 : Priority Queues
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/26/2020
 *****************************************************************************/
#define SIZE 7
#include "PatientType.h"
#include "myheader.h"
#include "clockType.h"
#include "PriorityQueue.h"
/**********************************************************************************
 * Priority Queues
 * --------------------------------------------------------------------------------
 * This program will test both priority queues with the following data assuming
 * that the priority queue is built at noon and Doctor DoGood is the only doctor
 * on duty. Each patient requires 25 minutes of care. The patient who waited the
 * longest has the highest priority unless there is a life-threatening scenario.
 * Determine the order in which the patients will be treated. You will need to
 * create a timer. In the end the program will output the time each appointment
 * starts and ends.
 *
 * Part One - Develop software or use the author’s priority queue ADT to
 * implement a priority queue based on a heap.
 *
 * Part Two - Use the STL priority_queue.

 * --------------------------------------------------------------------------------
 *********************************************************************************/
int main()
{
	// Outputs Heading
	cout << PrinterHeader("Priority Queues", 6 , 'A');

	// Output description of the program
	cout << "\nThis program will test both priority queues with the following data\n"
			" assuming that the priority queue is built at noon and Doctor DoGood\n"
			"is the only doctor on duty. Each patient requires 25 minutes of care.\n"
			"The patient who waited the longest has the highest priority unless\n"
			"there is a life-threatening scenario. Determine the order in which the\n"
			"patients will be treated. You will need to create a timer. In the end\n"
			"the program will output the time each appointment starts and ends.\n\n";
	/****************************************************************************
	 * Part One - This program will create and intizalize name and priorities
	 *            clocktype, emergency patientType, and the two Priority Queues
	 ****************************************************************************/
	string names[SIZE] = {"Bob Bleeding", "Frank Feelingbad", "Cathy Coughing",
			"Paula Pain", "Alice Ailment", "Irene Ill","Tom Temperature"};
	int priorities[SIZE] = {5, 3, 2, 4, 7, 1, 6};
	//time object
	clockType *time;
	//for emergency customer
	patientType emergency;
	//time for emergency customer
	clockType interruptTimeB(0, 0);
	clockType interruptTimeE(0, 0);
	bool interrupt = false; //if there is an emergency

	priority_queue<patientType> Q;//stl
	PriorityQueue<patientType> QTwo;//custom

	//insert people into queue
	for (int i = 0; i < SIZE; i++)
	{
		Q.push(patientType(names[i], priorities[i]));
		QTwo.Enqueue(patientType(names[i], priorities[i]));
	}

	//set the time to noon
	time = new clockType(12, 0);

	/****************************************************************************
	 * Part Two - This program will develop software or use the author’s priority
	 * queue ADT to implement a priority queue based on a heap.
	 ****************************************************************************/
	cout << setw(44) << "" << "EMERGENCY ROOM -> USING THE STL" << endl;

	for (int i = 0; i < 120; i++)
		cout << '=';
	cout << endl;

	cout << "Name: " << setw(46)<< "Wait Time (Hours): " << setw(20) << "Start: "
			<< setw(25) << "End: " << endl;

	for (int i = 0; i < 120; i++)
		cout << '-';
	cout << endl;

	//start serving the patients
	for (int i = 0; i < SIZE; i++)
	{
		cout << setw(39) << left << Q.top().getName() << setw(25) << Q.top().getPriority()
																							<< setw(25) << time;

		for (int i = 0; i < 25; i++)
		{
			//if the time is 1:14
			//Sam Sneezing" emergency
			if (time->getMinutes() == 14 && time->getHours() == 1)
			{
				interrupt = true; //theres an emergency
				Q.push(patientType("Sam Sneezing", (Q.top().getPriority() + 1))); //add Sam Sneezing to queue
				interruptTimeB = *time;//interrupt begin time
				time->addMin(25);//add time
				interruptTimeE = *time;//get the end for the interrupt
				emergency = Q.top();//store emergency patient
				Q.pop();//remove from queue
			}

			//if time is 3:01
			//sid sickley emergency
			if (time->getMinutes() == 01 && time->getHours() == 3)
			{
				interrupt = true; //there's an emergency
				Q.push(patientType("Sid Sickley", (Q.top().getPriority() + 1)));//add sid sickley to the queue
				interruptTimeB = *time;//begin time for emergency
				time->addMin(25);//increment the time
				interruptTimeE = *time;//get the end of the interrupt
				emergency = Q.top();//store emergency patient
				Q.pop();//remove from queue
			}

			time->addMin(1);//increment the minute for  each time in loop

		}

		cout << time<< endl << endl;

		Q.pop();

		if (interrupt)
		{
			cout << setw(30) << left << emergency.getName() << setw(34) << "<<LIFE THREATNING>>"
					<< setw(25) << interruptTimeB << interruptTimeE << endl << endl;
			interrupt = false;
		}
	}

	time = new clockType(12, 0);
	/****************************************************************************
	 * Part Two - This program will use the STL priority_queue.
	 ****************************************************************************/
	cout << setw(37) << "" << "EMERGENCY ROOM -> USING CUSTOM PRIORITY QUEUE" << endl;

	for (int i = 0; i < 120; i++)
		cout << '=';
	cout << endl;

	cout << "Name: " << setw(25) << " "<< "Wait Time (Hours): " << setw(15)<< " " << "Start: "
				<< setw(20) << " "<< "End: " << endl;

	for (int i = 0; i < 120; i++)
		cout << '-';
	cout << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << setw(39) << left << QTwo.Front().getName() << setw(25) << QTwo.Front().getPriority()
													<< setw(25) << time;

		for (int i = 0; i < 25; i++)
		{

			if (time->getMinutes() == 14 && time->getHours() == 1)
			{
				interrupt = true;
				QTwo.Enqueue(patientType("Sam Sneezing", (QTwo.Front().getPriority() + 1)));
				interruptTimeB = *time;
				time->addMin(25);
				interruptTimeE = *time;
				emergency = QTwo.Front();
				QTwo.Dequeue();
			}
			if (time->getMinutes() == 01 && time->getHours() == 3)
			{
				interrupt = true;
				QTwo.Enqueue(patientType("Sid Sickley", (QTwo.Front().getPriority() + 1)));
				interruptTimeB = *time;
				time->addMin(25);
				interruptTimeE = *time;
				emergency = QTwo.Front();
				QTwo.Dequeue();
			}

			time->addMin(1);
		}
		cout << time << endl << endl;

		QTwo.Dequeue();

		if (interrupt)
		{
			cout << setw(30) << left << emergency.getName() << setw(34) << "<<LIFE THREATNING>>"
					<< setw(25) << interruptTimeB << interruptTimeE << endl << endl;
			interrupt = false;
		}
	}
	return 0;
}

bool operator< (const patientType& x, const patientType& y)
{
	return x.getPriority() < y.getPriority();
}

bool operator> (const patientType& x, const patientType& y)
{
	return x.getPriority() > y.getPriority();
}


std::ostream& operator << (std::ostream& out, const clockType* x)
{
	string output = "";

	if (x->getHours() < 10)
		output += "0";

	output += to_string(x->getHours()) + ": ";

	if (x->getMinutes() < 10)
		output += "0";

	output += to_string(x->getMinutes()) + " PM";

	out << output;

	return out;
}

std::ostream& operator << (std::ostream& out, const clockType x)
{

	string output = "";

	if (x.getHours() < 10)
		output += "0";

	output += to_string(x.getHours()) + ": ";

	if (x.getMinutes() < 10)
		output += "0";

	output += to_string(x.getMinutes()) + " PM";

	out << output;

	return out;
}
