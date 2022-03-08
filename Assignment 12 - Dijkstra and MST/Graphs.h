/******************************************************************************
 * AUTHOR		 : Suhyr Hasan and Tanner Cordero, and Danin Namiranian
 * STUDENT ID 	 : 1022520, 1084772, and 1081970
 * Assignment #12: Dijkstra and MST
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 04/22/2020
 *****************************************************************************/
#ifndef GRAPHS_H_
#define GRAPHS_H_
#include "myheader.h"
typedef std::pair<int, int> Pair;
/****************************************************************
 * Graph
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
	Graph(int V);
	/****************
	 ** MUTATORS **
	 ****************/
	/*******************************************************************
	 * void addEdge(int u, int v, int w);
	 *
	 * Mutator; This method will Adds a new edge to the graph and a new
	 *          vertex if a vertex with value "u" does not yet exist.
	 *------------------------------------------------------------------
	 * Parameter: int u, int v, int w
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void addEdge(int u, int v, int w);
	/***************
	 ** ACCESSORS **
	 ***************/
	/*******************************************************************
	 * void shortestPath(int s);
	 *
	 * Accessor; This method will determine the shortest path from the
	 * starting vertex "s" and all other vertices in the graph.
	 *------------------------------------------------------------------
	 * Parameters: int s
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void shortestPath(int s);
	/*******************************************************************
	 * void primMST();
	 *
	 * Accessor; This method will determine the minimum spanning tree
	 *           of the graph using Prim-Jarnik's Algorithm.
	 *------------------------------------------------------------------
	 * Parameters: none
	 *------------------------------------------------------------------
	 * Return: none
	 *******************************************************************/
	void primMST();
	void outputAll();
private:
	int V;
	std::list <std::pair<int, int>>* adj;
	string AIR_PORTS[7] = { "A", "B","C", "D","E", "F", "H"};
};
/****************************************************************
 * Graph(int V)
 * Default Constructor; Initialize class attributes
 * Parameters: none
 * Return: none
 ****************************************************************/
Graph::Graph(int V)
{
	this->V = V;
	adj = new std::list<Pair>[V];
}
/******************************************************************************
 * Method addEdge: Class Graph
 * ____________________________________________________________________________
 * This method will add a new edge to the graph and a new vertex if a vertex
 * with value "u" does not yet exist - returns nothing.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	              int u - Starting city must be defined.
 * 	              int v - Ending city must be defined.
 * 	              int w - Distance between the cities must be defined.
 * POST-CONDITIONS
 *    This function will add a new edge to the graph and a new vertex if a
 *    vertex with value "u" does not yet exist - returns nothing.
 ******************************************************************************/
void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(std::make_pair(v, w));
	adj[v].push_back(std::make_pair(v, w));
}
/******************************************************************************
 * MethodshortestPath : Class Graph
 * ____________________________________________________________________________
 *  This method will determine the shortest path from the starting vertex "s"
 *  and all other vertices in the graph - returns nothing.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 * 	               int s - Starting city "s" must be defined.
 * POST-CONDITIONS
 * 	  This function will determine the shortest path from the starting vertex
 * 	  "s" and all other vertices in the graph - returns nothing.
 ******************************************************************************/
void Graph::shortestPath(int s)
{
	priority_queue< Pair, vector<Pair>, greater<Pair>> pq;
	vector<int> dist(V, INT_MAX);
	pq.push(make_pair(0, s));
	dist[s] = 0;
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			int weight = (*i).second;
			if (dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	for (int i = 0; i < V; i++)
	{
		cout << "Vertex: " << AIR_PORTS[i]<< " ----> Distance: " << dist[i];
		cout << endl << endl;
	}
}
/******************************************************************************
 * Method primMST : Class Graph
 * ____________________________________________________________________________
 *  This method will determine the minimum spanning tree of the graph using
 *  Prim-Jarnik's Algorithm - returns nothing.
 *
 * PRE-CONDITIONS
 * 	  The following parameters need to have a defined value prior to calling
 * 	  the function:
 *
 * POST-CONDITIONS
 * 	  This function will determine the minimum spanning tree of the graph using
 *    Prim-Jarnik's Algorithm - returns nothing.
 ******************************************************************************/
void Graph::primMST()
{
	int totalDist = 0;
	priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
	int src = 0;
	vector<int> key(V, INT_MAX);
	vector<int> parent(V, -1);
	vector<bool> intMST(V, false);
	vector<int> distances(V);
	pq.push(make_pair(0, src));
	key[src] = 0;
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		intMST[u] = true;
		for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			int weight = (*i).second;
			if (intMST[v] == false && key[v] > weight)
			{
				key[v] = weight;
				pq.push(make_pair(key[v], v));
				parent[v] = u;
				distances[v] = weight;
			}
		}
	}
	for (int i = 1; i < V; ++i)
		cout << AIR_PORTS[parent[i]] << " ----> "
		<< AIR_PORTS[i] << " DISTANCE: " << distances[i] << endl << endl;
	for (int i = 1; i < V; ++i)
		totalDist += distances[i];
	cout << "TOTAL DISTANCE: " << totalDist << endl;
}
#endif /* GRAPHS_H_ */
