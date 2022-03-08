/******************************************************************************
 * AUTHOR		 : Suhyr Hasan and Tanner Cordero, and Danin Namiranian
 * STUDENT ID 	 : 1022520, 1084772, and 1081970
 * Assignment #11: DFS and BFS Directed Edges
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 04/15/2020
 *****************************************************************************/
#ifndef GRAPHS_H_
#define GRAPHS_H_
#include "myheader.h"
//Distance object in the multidimensional array
struct DistObject
{
	int distance;
	bool visited;
	bool crossed;
};
struct CurrCity
{
	string city;
	int index;
	int distance;
};
/****************************************************************
 *  Graph
 * This class has all the attributes and methods for Graph.
 ***************************************************************/
class Graph
{
public:
	/****************************************************************
	 * Graph();
	 * Default Constructor; Initialize class attributes
	 * Parameters: none
	 * Return: none
	 ***************************************************************/
	Graph();
	/****************************************************************
	 * ~Graph();
	 * Destructor; Clears Linked List
	 * Parameters: none
	 * Return: none
	 ***************************************************************/
	~Graph();
	/****************
	 ** MUTATORS **
	 ****************/
	/*******************************************************************
	 * void addEdge(int num1, int num2, int dist);
	 *
	 * Mutator; This method will add an edge to graph
	 *------------------------------------------------------------------
	 * Parameter: int num1, int num2, int dist
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void addEdge(int num1, int num2, int dist);
	/*******************************************************************
	 * void DFS(int Xcoordinate, int Ycoordinate);
	 *
	 * Mutator; This method will DFS trav of the vert from V.
	 *------------------------------------------------------------------
	 * Parameter: int Xcoordinate, int Ycoordinate
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void DFS(int Xcoordinate, int Ycoordinate);
	/*******************************************************************
	 * void BFS(int xCd, int yCd);
	 *
	 * Mutator; This method will BFS traversal of vertices
	 *------------------------------------------------------------------
	 * Parameter: int xCd, int yCd
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void BFS(int xCd, int yCd);
	/***************
	 ** ACCESSORS **
	 ***************/
	/*******************************************************************
	 * bool isCrossEdge(int xCd);
	 *
	 * Accessor; This method will
	 *------------------------------------------------------------------
	 * Parameters: int xCd
	 *------------------------------------------------------------------
	 * Return: a boolean expression
	 *******************************************************************/
	bool isCrossEdge(int xCd);
	/*******************************************************************
	 * void outputAll();
	 *
	 * Accessor; This method will output as simple distance matrix
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void outputAll();
private:
	int numberOfNodes;// number of nodes
	int smallest;
	int crossX;
	int backEdge;
	int listVisited[12];
	vector<int> cVisited;
	queue<int>listCrossed;
	int number;
	int iter;
	int totalDistance; // Total distance traveled
	DistObject myArray[12][12];	// Adjacency Matrix
	DistObject copy[12][12];
	string cityArray[12]; // Corresponding names
	void BFSUtil(int xCd, int yCd);
	void DFSUtil(int Xcoordinate, int Ycoordinate); // A function used by DFS
	void PrintAdjEdges(int xCd);
};
/****************************************************************
 * Graph()
 * Default Constructor; Initialize class attributes
 * Parameters: none
 * Return: none
 ****************************************************************/
Graph::Graph()
{
	smallest = 10000;
	totalDistance = 0;
	number = 0;
	crossX = 0;
	iter = 0;
	numberOfNodes = 7;
	backEdge = crossX;
	//Initialize the City Array parallel to the graph
	cityArray[0] = "A";
	cityArray[1] = "B";
	cityArray[2] = "C";
	cityArray[3] = "D";
	cityArray[4] = "E";
	cityArray[5] = "F";
	cityArray[6] = "H";
	for(int i=0; i<numberOfNodes; i++)    //This loops on the rows.
	{
		for(int j=0; j<numberOfNodes; j++) //This loops on the columns
		{
			myArray[i][j].distance = -1;
			myArray[i][j].visited = false;
			myArray[i][j].crossed = false;
		}
	}
	cVisited.push_back(0);
}
/****************************************************************
 * ~Graph();
 * Destructor; Clears Linked List
 * Parameters: none
 * Return: none
 ***************************************************************/
Graph::~Graph(){}
/******************************************************************************
 * Method addEdge: Class Graph
 * ____________________________________________________________________________
 * This method will create a new edge in the list - returns nothing.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	              int num1 - first number
 * 	              int num2 - second number
 * 	              int dist - total distance
 * POST-CONDITIONS
 * This function will create a new edge in the list - returns nothing.
 ******************************************************************************/
void Graph::addEdge(int num1, int num2, int dist)
{
	myArray[num1][num2].distance = dist;
}
/******************************************************************************
 * Method DFS : Class Graph
 * ____________________________________________________________________________
 *  This method will DFS traversal of the vertices reachable from v using
 *  recursive DFSUtil() - returns nothing.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               int Xcoordinate - x coordinate
 * 	               int Ycoordinate - y coordinate
 * POST-CONDITIONS
 * 	  This function will DFS traversal of the vertices reachable from v using
 *    recursive DFSUtil() - returns nothing.
 ******************************************************************************/
void Graph::DFS(int Xcoordinate, int Ycoordinate)
{
	// Call the recursive helper function to print DFS traversal
	DFSUtil(Xcoordinate, Ycoordinate);
	cout << "Total mileage gone: " << totalDistance << endl;
}
/******************************************************************************
 * Method BFS : Class Graph
 * ____________________________________________________________________________
 *  This method will BFS traversal of vertices - returns nothing.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               int xCd - x coordinate
 * 	               int yCd - y coordinate
 * POST-CONDITIONS
 * 	  This function will BFS traversal of vertices - returns nothing.
 ******************************************************************************/
void Graph::BFS(int xCd, int yCd)
{
	totalDistance = 0;
	number = 1;
	cVisited.clear();
	for(int i=0; i<numberOfNodes; i++)    //This loops on the rows.
	{
		listVisited[i] = 4;

		for(int j=0; j<numberOfNodes; j++) //This loops on the columns
		{
			myArray[i][j].visited = false;
			copy[i][j] = myArray[i][j];
		}
	}
	for(int row = 0; row < 7; row++)
	{
		copy[row][crossX].crossed = true;
		copy[row][crossX].visited = true;
	}
	BFSUtil(xCd, yCd);
	cout << "Total distance traveled: " << totalDistance << endl;
}
/******************************************************************************
 * Method isCrossEdge: Class Graph
 * ____________________________________________________________________________
 *  This method will  - returns a boolean expression.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               int xCd - x coordinate
 * POST-CONDITIONS
 * 	  This function will  - returns a boolean expression.
 ******************************************************************************/
bool Graph::isCrossEdge(int xCd)
{
	for(int col = 0; col < 7; col++)
	{
		if(col == listCrossed.front())
		{
			if(copy[xCd][col].distance != -1)
				return true;
		}
	}
	return false;
}
/******************************************************************************
 * Method BFSUtil : Class Graph
 * ____________________________________________________________________________
 *  This method will check if it was visited, recurs for all vertices
 *  - returns nothing.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               int xCd - x coordinate
 * 	               int yCd - y coordinate
 *
 * POST-CONDITIONS
 * 	  This function will check if it was visited, recurs for all vertices
 *    - returns nothing.
 ******************************************************************************/
void Graph::BFSUtil(int xCd, int yCd)
{
	smallest = 10000;	  //Number to compare against
	bool possible = false;//Whether it is possible to visit a city

	//Go through the row
	for(int i = 0; i < 7; i++)
	{
		//If the node is not visited, distance exists, and it is smaller
		if(copy[xCd][i].crossed == false &&
				copy[xCd][i].distance > -1)
		{
			possible = true;
		}
	}
	//If all the cities have been visited
	if(number == 7)
	{
		//Return to the main
		return;
	}
	else if(!possible && listCrossed.empty())
	{
		listCrossed.push(backEdge);
		if(cityArray[xCd] != cityArray[listCrossed.front()])
		{
			cout << "\nBack Edge: ";
			//Output the node crossed
			cout << endl << cityArray[xCd] << " " << flush;
			cout << "-->"<< cityArray[listCrossed.front()] << " " << flush << endl;
			BFSUtil(listCrossed.front(), 0);
		}
	}else{
		PrintAdjEdges(xCd);
		if(cityArray[xCd] != cityArray[listCrossed.front()])
		{
			if(isCrossEdge(xCd))
				cout << "\nCross Edge: ";
			else
				cout << "\nForward Edge: ";
			//Output the node crossed
			cout << endl << cityArray[xCd] << " " << flush;
			cout << "-->"<< cityArray[listCrossed.front()] << " " << flush
					<< endl;
		}
		crossX = listCrossed.front();
		backEdge = crossX;
		for(int row = 0; row < 7; row++)
		{
			copy[row][crossX].crossed = true;
		}
		listCrossed.pop();
		BFSUtil(crossX, 0);
	}
}
/******************************************************************************
 * Method DFSUtil : Class Graph
 * ____________________________________________________________________________
 *  This method will check if it was visited, recurs for all vertices
 *  - returns nothing.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               int Xcoordinate - x coordinate
 * 	               int Ycoordinate - y coordinate
 * POST-CONDITIONS
 * 	  This function will check if it was visited, recurs for all vertices
 *    - returns nothing.
 ******************************************************************************/
void Graph::DFSUtil(int Xcoordinate, int Ycoordinate)
{
	smallest = 10000;			//Number to compare against
	int tempX;					//The temporary X variable
	bool possible = false;		//Whether it is possible to visit a city
	int tempY;					//The temporary Y variable
	//Go through the first column
	for(int i = 0; i < 7; i++)
	{
		//If the node is not visited, distance exists, and it is smaller
		if(myArray[Xcoordinate][i].visited == false &&
				myArray[Xcoordinate][i].distance > -1 &&
				myArray[Xcoordinate][i].distance < smallest)
		{
			//make smallest the new distance
			smallest = myArray[Xcoordinate][i].distance;
			tempX = Xcoordinate;
			tempY = i;
			possible = true;
		}
	}
	//If all the cities have been visited
	if(number == 6)
	{
		//Return to the main
		return;
	}
	//If it is not possible to visit, backtrack
	else if(!possible)
	{
		cout << "Back Edge: " << cityArray[listVisited[iter-1]] << endl;
		iter = iter - 1;
		DFSUtil(listVisited[iter], 0);
	}
	//Otherwise, mark the paths as visited, as well add up the
	//total distance and output
	else
	{
		cout << "Discovery edge: ";
		//Add up the distances
		totalDistance = totalDistance + smallest;
		//Output the node visited
		cout << setw(15) << left << cityArray[tempX];
		cout << setw(5)  << "--->";
		cout << setw(15) << left << cityArray[tempY];
		myArray[tempX][tempY].visited = true;
		myArray[tempY][tempX].visited = true;
		cVisited.push_back(tempY);
		// Mark the current city as visited for all rows in the matrix
		for(unsigned int col = 0; col < cVisited.size(); col++)
		{
			for(int row = 0; row < 7; row++)
			{
				if(myArray[row][cVisited[col]].distance != -1)
				{
					myArray[row][cVisited[col]].visited = true;
				}
			}
		}
		//Place into the list visited the number corresponding to the city
		listVisited[number] = tempY;
		number++;
		iter++;
		//Output the distance for the trip
		cout << setw(10) << left << myArray[tempX][tempY].distance;
		cout << endl << flush;
		//Recursively call the function again, this time using
		//The next city in the trip
		DFSUtil(tempY,0);
	}
}
/******************************************************************************
 * Method PrintAdjEdges : Class Graph
 * ____________________________________________________________________________
 *  This method will output the node visited and the distance for the trip
 *  - returns nothing.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               int xCd - x coordinate
 * POST-CONDITIONS
 * 	  This function will output the node visited and the distance for the trip
 *    - returns nothing.
 ******************************************************************************/
void Graph::PrintAdjEdges(int xCd)
{
	unsigned int indexCurrent;
	int indexCheck;
	CurrCity tempLargerCheck;
	string tempStringLarger;
	vector<CurrCity> currVisit;
	for(int i = 0; i < 7; i++)
	{
		CurrCity n;

		if(copy[xCd][i].visited == false && copy[xCd][i].distance != -1)
		{
			n.city = cityArray[i];
			n.index = i;
			n.distance = copy[xCd][i].distance;

			currVisit.push_back(n);
			number++;
		}
	}
	//sort the soon to be discovered cities in vector
	for(indexCurrent = 0;indexCurrent < currVisit.size();indexCurrent++)
	{
		indexCheck = indexCurrent;

		while(indexCheck>0
				&& currVisit[indexCheck].distance
				< currVisit[indexCheck - 1].distance)
		{
			tempLargerCheck = currVisit[indexCheck];
			currVisit[indexCheck]= currVisit[indexCheck - 1];
			currVisit[indexCheck - 1] = tempLargerCheck;
			indexCheck--;
		}
	}
	for(unsigned int i = 0; i < currVisit.size(); i++)
	{
		cout << "Discovery edge: ";
		//Add up the distances
		totalDistance = totalDistance + currVisit[i].distance;

		listCrossed.push(currVisit[i].index);

		//Output the node visited
		cout << setw(15) << left << cityArray[xCd] << " " << flush;
		cout << setw(5)  << "-->";
		cout << setw(15) << left<< currVisit[i].city << " " << flush;

		//Output the distance for the trip
		cout << setw(10) << left << currVisit[i].distance << " " << flush;
		cout << endl << flush;

		cVisited.push_back(currVisit[i].index);
	}
	// Mark the current city as visited for all rows in the matrix
	for(unsigned int col = 0; col < cVisited.size(); col++)
	{
		for(int row = 0; row < 7; row++)
		{
			copy[row][cVisited[col]].visited = true;
		}
	}
}
/******************************************************************************
 * Method outputAll : Class Graph
 * ____________________________________________________________________________
 *  This method will output all numbers in a matrix fashion.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	This function will output all numbers in a matrix fashion.
 ******************************************************************************/
void Graph::outputAll()
{
	cout << "This is the adjacency matrix: " << endl;
	cout << "\t";
	for(int index = 0; index < 7; index++)
	{
		cout << left;
		cout << setw(14) << cityArray[index];
	}
	cout << endl;
	for(int i=0; i<7; i++)    //This loops on the rows.
	{
		cout << setw(14) << cityArray[i];
		for(int j=0; j<7; j++) //This loops on the columns
		{
			if(myArray[i][j].distance == -1)
			{
				cout << setw(14) << "-";
			}
			else
			{
				cout << setw(14) << myArray[i][j].distance;
			}
		}
		cout << endl;
	}
}
#endif /* GRAPHS_H_ */
