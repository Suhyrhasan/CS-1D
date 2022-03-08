/******************************************************************************
 * AUTHOR		 : Suhyr Hasan and Tanner Cordero, and Danin Namiranian
 * STUDENT ID 	 : 1022520, 1084772, and 1081970
 * Assignment #11: DFS and BFS Directed Edges
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 04/15/2020
 *****************************************************************************/
#include "Graphs.h"
#include "MyHeader.h"
/******************************************************************************
 * DFS and BFS Directed Edges
 * ----------------------------------------------------------------------------
 * This program will allow the programmer to create a directed graph. It should
 * traverse the graph in a depth first search and then a breadth first search.
 * ----------------------------------------------------------------------------
 * INPUT:
 *         intAr	: the array of numbers holding city keys
 * 		   stringAr : the array of names that will be input for the heap
 * 		             (in form of an array)
 * OUTPUT:
 *        myGraph   : the graph variable to insert/output
 *****************************************************************************/
int main()
{
	// Output header to console
	cout << PrinterHeader("DFS and BFS Directed Edges", 11, 'A');
	// Output description of the program
	cout << "\nThis program will show the implementation of a directed\n"
			"graph and traversals breadth first and depth first. This\n"
			"will demonstrate knowledge of graphs and functions that\n"
			"enable the graph ADT\n\n";
	Graph graph;
	/*****************************************************************************
	 * First - This program will use 2 numbers from their indices in cityArray
	 *****************************************************************************/
//	myGraph.addEdge(0, 2, 12);
//	myGraph.addEdge(0, 3, 9);
//	myGraph.addEdge(1, 0, 7);
//	myGraph.addEdge(1, 2, 6);
//	myGraph.addEdge(2, 5, 11);
//	myGraph.addEdge(3, 1, 1);
//	myGraph.addEdge(3, 4, 10);
//	myGraph.addEdge(4, 5, 4);
//	myGraph.addEdge(4, 2, 5);
//	myGraph.addEdge(5, 6, 8);
//	myGraph.addEdge(6, 4, 2);
//	myGraph.addEdge(6, 3, 3);
	graph.addEdge(0, 1, 7); //LA TO DENVER
		graph.addEdge(1, 0, 7); //DENVER TO LA

		graph.addEdge(2, 0, 12); //SEATTLE TO DENVER
		graph.addEdge(0, 2, 12); //DENVER TO SEATTLE

		graph.addEdge(3, 0, 9); //DENVER TO CHICAGO
		graph.addEdge(0, 3, 9); //CHICAGO TO DENVER

		graph.addEdge(1, 3, 1); //LA TO DENVER
		graph.addEdge(3, 1, 1); //DENVER TO LA

		graph.addEdge(2, 1, 6); //SEATTLE TO SF
		graph.addEdge(1, 2, 6); //SF TO SEATTLE

		graph.addEdge(2, 4, 5); //HOUSTON TO DALLAS
		graph.addEdge(4, 2, 5); //DALLAS TO HOUSTON

		graph.addEdge(2, 5, 11); //DALLAS TO KANSAS CITY
		graph.addEdge(5, 2, 11); //KANSAS TO DALLAS

		graph.addEdge(3, 4, 10); //DENVER TO SF
		graph.addEdge(4, 3, 10); //SF TO DENVER

		graph.addEdge(3, 6, 3); //DENVER TO SF
		graph.addEdge(6, 3, 3); //SF TO DENVER

		graph.addEdge(4, 6, 2); //HOUSTON TO ATLANTA
		graph.addEdge(6, 4, 2); //ATLANTA TO HOUSTON

		graph.addEdge(4, 5, 4); //DALLAS TO KANSAS CITY
		graph.addEdge(5, 4, 4); //KANSAS TO DALLAS

		graph.addEdge(5, 6, 8); //DALLAS TO KANSAS CITY
		graph.addEdge(6, 5, 8); //KANSAS TO DALLAS

	/*****************************************************************************
	 * Second - This program will output everything in a matrix formation
	 *****************************************************************************/
	graph.outputAll();
	/*****************************************************************************
	 * Third - This program will output everything in the DFS formation
	 *****************************************************************************/
	//Output everything in the DFS formation
	cout << "\nImplementing DFS... starting at Denver\n";
	graph.DFS(0,0);
	/*****************************************************************************
	 * Fourth - This program will output everything in the BFS formation
	 *****************************************************************************/
	cout << "\nImplementing BFS... starting at Denver\n";
	graph.BFS(0,0);
	return 0;
}
