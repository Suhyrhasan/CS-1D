/******************************************************************************
 * AUTHOR		 : Suhyr Hasan and Tanner Cordero, and Danin Namiranian
 * STUDENT ID 	 : 1022520, 1084772, and 1081970
 * Assignment #12: Dijkstra and MST
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 04/22/2020
 *****************************************************************************/
#include "Graphs.h"
#include "MyHeader.h"
/******************************************************************************
 * Function buildGraph
 * ____________________________________________________________________________
 * This function will initializes the graph with the distance between two
 * vertices.
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               Graph& graph - The graph that's being initialized
 * POST-CONDITIONS
 * 	  This function will initializes the graph with the distance between two
 *    vertices.
 ******************************************************************************/
void buildGraph(Graph& graph)
{

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
}
/******************************************************************************
 * Dijkstra and MST
 * ----------------------------------------------------------------------------
 * This program will implement Dijkstra’s to find the shortest distance from
 * Dallas to the cities on the map below and identify paths and the
 * corresponding distance. Then the will determine the MST and the identify
 * edges and total mileage.
 * ----------------------------------------------------------------------------
 * INPUT:
 *
 * OUTPUT:
 *        Dijkstra's - Path to every city from Dallas & associated mileage.
 *	      MST - Edges & Total Mileage
 *****************************************************************************/
int main()
{
	// Output header to console
	cout << PrinterHeader("DFS and BFS Directed Edges", 11, 'A');
	// Output description of the program
	cout << "\nThis program will implement Dijkstra’s to find the shortest distance\n"
			"from Dallas to the cities on the map below and identify paths and\n"
			"the corresponding distance.Then the program will determine the MST\n"
			"and identify edges and total mileage\n";
	Graph graph(7);
	/*********************************************************************************
	 * First - This program will implement Dijkstra’s to find the shortest distance
	 *         from Dallas to the cities on the map below and identify paths and
	 *         the corresponding distance.
	 *********************************************************************************/
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "  Building graphs and performing DIJKSTRA'S \n"
			"       shortest distance from DALLAS  ";
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++"
			"+++++++++++++++++++++++++++\n";
	buildGraph(graph);
	graph.shortestPath(0);
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++"
			"+++++++++++++++++++++++++++\n";
	/*********************************************************************************
	 * Second - This program will determine the MST (identify edges and total mileage)
	 *********************************************************************************/
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "  Finding minimum spanning tree using PRIM \n"
			"          printing out edges of MST        ";
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++"
			"++++++++++++++++++++++++++++\n";
	graph.primMST();
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++"
			"++++++++++++++++++++++++++++\n";

	return 0;
}
