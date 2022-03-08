/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #5 : Binary Trees
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 02/19/2020
 *****************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <list>
#include <queue>
#include <math.h>
#include<vector>
#define COUNT 19
using namespace std;
typedef struct BST
{
	int data;
	struct BST *left, *right;
} node;
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
	output << "*****************************************************\n";
	output << "*  PROGRAMMED BY : Suhyr Hasan \n";
	output << "*  " << setw(14) << "STUDENT IDs" << ": 1022520 \n";
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
	output << "*****************************************************\n";
	output << right;
	return output.str();
}
/****************************************************************
 * BinaryTree();
 * Constructor; Initialize class attributes
 * Parameters: none
 * Return: none
 ***************************************************************/
class BinaryTree
{
public:
	/******************************************************************************
	 * Method insert : Class BinaryTree
	 * ____________________________________________________________________________
	 *  This method will read in and store the new node  – returns nothing.
	 *
	 * PRE-CONDITIONS
	 * 	  The following parameters need to have a defined value prior to calling
	 * 	  the function:
	 * 	               node *root     - root node
	 * 	               node *new_node - new node
	 *
	 * POST-CONDITIONS
	 * 	This function will read in and store the new node  – returns nothing.
	 ******************************************************************************/
	void insert(node *root, node *new_node)
	{
		if (new_node->data < root->data)
		{
			if (root->left == NULL)
				root->left = new_node;
			else
				insert(root->left, new_node);
		}
		if (new_node->data > root->data)
		{
			if (root->right == NULL)
				root->right = new_node;
			else
				insert(root->right, new_node);
		}
	}
	/******************************************************************************
	 * Method inorder : Class BinaryTree
	 * ____________________________________________________________________________
	 *  This method will output in-order traversal of binary tree
	 *  – returns nothing.
	 *
	 * PRE-CONDITIONS
	 * 	  The following parameters need to have a defined value prior to calling
	 * 	  the function:
	 * 	               node *temp  - temp node
	 *
	 * POST-CONDITIONS
	 * 	This function will output in-order traversal of binary tree
	 *  – returns nothing.
	 ******************************************************************************/
	void inorder(node *temp)
	{
		if(temp != NULL)
		{
			inorder(temp->left);
			cout<<temp->data<<"->";
			inorder(temp->right);
		}
	}
	/******************************************************************************
	 * Method preorder : Class BinaryTree
	 * ____________________________________________________________________________
	 *  This method will output pre-order traversal of binary tree
	 *  – returns nothing.
	 *
	 * PRE-CONDITIONS
	 * 	  The following parameters need to have a defined value prior to calling
	 * 	  the function:
	 * 	               node *temp  - temp node
	 *
	 * POST-CONDITIONS
	 * 	This function will output pre-order traversal of binary tree
	 *  – returns nothing.
	 ******************************************************************************/
	void preorder(node *temp)
	{
		if(temp!=NULL)
		{
			cout<<temp->data<<"->";
			preorder(temp->left);
			preorder(temp->right);
		}
	}
	/******************************************************************************
	 * Method postorder : Class BinaryTree
	 * ____________________________________________________________________________
	 *  This method will output post-order traversal of binary tree
	 *  – returns nothing.
	 *
	 * PRE-CONDITIONS
	 * 	  The following parameters need to have a defined value prior to calling
	 * 	  the function:
	 * 	               node *temp  - temp node
	 *
	 * POST-CONDITIONS
	 * 	This function will output post-order traversal of binary tree
	 *  – returns nothing.
	 ******************************************************************************/
	void postorder(node *temp)
	{
		if(temp!=NULL)
		{
			postorder(temp->left);
			postorder(temp->right);
			cout<<temp->data<<"->";
		}
	}
	/******************************************************************************
	 * Method get_node : Class BinaryTree
	 * ____________________________________________________________________________
	 *  This method will read in and create a new node  – returns temp.
	 *
	 * PRE-CONDITIONS
	 * 	  The following parameters need to have a defined value prior to calling
	 * 	  the function:
	 *
	 *
	 * POST-CONDITIONS
	 * 	This function will read in and create a new node  – returns temp.
	 ******************************************************************************/
	node *get_node()
	{
		node *temp;
		temp = (node *) malloc(sizeof(node));
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	/******************************************************************************
	 * Method printLevelOrder : Class BinaryTree
	 * ____________________________________________________________________________
	 *  This method will do level order traversal line by line Iterative method to
	 *  do level order traversal line by line – returns nothing.
	 *
	 * PRE-CONDITIONS
	 * 	  The following parameters need to have a defined value prior to calling
	 * 	  the function:
	 * 	                node* root - root
	 *
	 * POST-CONDITIONS
	 * 	This function will do level order traversal line by line Iterative method to
	 *  do level order traversal line by line – returns nothing.
	 ******************************************************************************/
	void printLevelOrder(node *root)
	{
		// Base Case
		if (root == NULL) return;
		// Create an empty queue for level order tarversal
		queue<node *> q;
		// Enqueue Root and initialize height
		q.push(root);
		while (q.empty() == false)
		{
			// nodeCount (queue size) indicates number
			// of nodes at current lelvel.
			int nodeCount = q.size();
			// Dequeue all nodes of current level and
			// Enqueue all nodes of next level
			while (nodeCount > 0)
			{
				node *node = q.front();
				cout << node->data << " ";
				q.pop();
				if (node->left != NULL)
					q.push(node->left);
				if (node->right != NULL)
					q.push(node->right);
				nodeCount--;
			}
			cout << endl;
		}
	}
	/******************************************************************************
	 * Method BreadthFirstTraversal : Class BinaryTree
	 * ____________________________________________________________________________
	 *  This method will output breadth-first traversal of binary tree
	 *  – returns nothing.
	 *
	 * PRE-CONDITIONS
	 * 	  The following parameters need to have a defined value prior to calling
	 * 	  the function:
	 *            node* root - root
	 *
	 * POST-CONDITIONS
	 * 	This function will output breadth-first traversal of binary tree
	 *  – returns nothing.
	 ******************************************************************************/
	void BreadthFirstTraversal(node* root)
	{
		queue<node*> q;
		if (!root)
		{
			return;
		}
		for(q.push(root);!q.empty(); q.pop())
		{
			const node * const temp_node = q.front();
			cout<<temp_node->data << " ";
			if(temp_node->left)
			{
				q.push(temp_node->left);
			}
			if (temp_node->right)
			{
				q.push(temp_node->right);
			}
		}
	}
};  // END OF BinaryTree CLASS
/**********************************************************************************
 * Binary Trees
 * --------------------------------------------------------------------------------
 * This program will implement a binary tree using an (array, vector or linked list)
 * and store a certain number of elements using the properties of a binary search
 * tree. Then it will perform the in-order, post-order, pre-order, breadth-first
 * traversals. In addition to the traversals, the program will print out the binary
 * tree by level and how the parent-child relationship for all the nodes of the tree.
 * --------------------------------------------------------------------------------
 * INPUT
 *
 * OUTPUT:
 *********************************************************************************/
int main()
{
	// Outputs Heading
	cout << PrinterHeader("Binary Trees", 5 , 'A');
	// Output description of the program
	cout << "\n This program will implement a binary tree using an (array, vector\n"
			" or linked list) and store a certain number of elements using the\n"
			" properties of a binary search tree. Then it will perform the in\n"
			" order,post-order, pre-order, breadth-first traversals. In addition\n"
			" to the traversals, the program will print out the binary tree by\n"
			" level and how the parent-child relationship for all the nodes of\n"
			" the tree.\n";
	BinaryTree obj;
	/****************************************************************************
	 * Part One - This program will create and initialize an array to store in
	 *            as a new node.
	 ****************************************************************************/
	node *new_node, *root;
	node *get_node();
	root = NULL;
	int search[COUNT] = {44,17,32,48,50,62,78,88};
	int item[COUNT];
	int index;
	for (index=0;index<COUNT;index++)
	{
		item[index] = search[index];
		new_node = obj.get_node();
		new_node->data=item[index];
		if (root == NULL)
			root = new_node;
		else
			obj.insert(root, new_node);
	}
	/****************************************************************************
	 * Part Two - This program will output in-order traversal of binary tree.
	 ****************************************************************************/
	cout << "\n\nIn-order traversal of binary tree is \n";
	obj.inorder(root);
	/****************************************************************************
	 * Part Three - This program will output post-order traversal of binary tree.
	 ****************************************************************************/
	cout << "\n\nPost-order traversal of binary tree is \n";
	obj.postorder(root);
	/****************************************************************************
	 * Part Four - This program will output pre-order traversal of binary tree.
	 ****************************************************************************/
	cout << "\n\nPre-order traversal of binary tree is \n";
	obj.preorder(root);
	/****************************************************************************
	 * Part Five - This program will output breadth-first traversal of binary tree
	 ****************************************************************************/
	cout << "\n\nBreadth-first traversal of binary tree is \n";
	obj.BreadthFirstTraversal(root);
	/****************************************************************************
	 * Part Five - This program will output a drawing of the Draw the binary
	 *             search tree (level, relations )
	 ****************************************************************************/
	cout<<"\n\nDraw the binary search tree (level ,relations )\n";
	obj.printLevelOrder(root);
	return 0;
}
