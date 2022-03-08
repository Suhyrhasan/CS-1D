/******************************************************************************
 * AUTHOR		 : Suhyr Hasan
 * STUDENT ID 	 : 1022520
 * Assignment #15: Huffman Coding
 * CLASS 		 : CS1D
 * SECTION 		 : MW 2:30p - 4:50p
 * DUE DATE		 : 05/13/2020
 *****************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
// Redefines the unsigned int type to uint.
typedef unsigned int uint;
const int BOUND = 76;
struct NodeType
{
	char data;              // Symbol
	int freq;               // Frequency of the symbol
	NodeType *left, *right; // Left and right children of the node.

	// Overloaded constructor.
	NodeType(char data, int freq)
	{
		this->data = data;
		this->freq = freq;
		left = NULL;
		right = NULL;
	}
};
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
 * POST-CONDITIONS
 * 	  This function will output the class heading.
 ******************************************************************************/
std::string PrinterHeader(std::string asName,    // IN - Assignment Name
		int asNum,                    // IN - Assignment Number
		char asType)                   // IN - Assignment Type ('L' = Lab,
//                       'A' = Assignment)
{
	std::ostringstream output;
	output << std::left;
	output << "*****************************************************\n";
	output << "*  PROGRAMMED BY : Suhyr Hasan \n";
	output << "*  " << std::setw(14) << "STUDENT IDs" << ": 1022520 \n";
	output << "*  " << std::setw(14) << "CLASS"	      <<": CS1D - MW - 2:30pm - 4:50pm\n";
	output << "*  ";

	// PROCESSING - This will adjust setws and format appropriately based
	//              based on if this is a lab 'L' or assignment.

	if (toupper(asType) == 'L')
	{
		output << "LAB #" << std::setw(9);
	}else{
		output << "ASSIGNMENT #" << std::setw(2);
	}
	output << asNum << ": " << asName << std::endl;
	output << "*****************************************************\n";
	output << std::right;
	return output.str();
}
/******************************************************************************
 * CLASS - Symbol
 * ----------------------------------------------------------------------------
 * This class defines an object representing a symbol in the Huffman Coding
 * Algorithm and holds its frequency and Huffman Code.
 *****************************************************************************/
class Symbol
{

public:
	/**************************************************************************
	 * Class Constructor
	 *************************************************************************/
	Symbol(){
		c = ' ';
		frequency = 0;
		code = "";
	}

	/**************************************************************************
	 * Class Overloaded Constructor
	 * ------------------------------------------------------------------------
	 * Sets the data members of the Symbol object to the values of declared at
	 * object instantiation.
	 *************************************************************************/
	Symbol(char symbol, int freq, string code){
		c = symbol;
		frequency = freq;
		this->code = code;
	}

	/**************************************************************************
	 * Class Destructor
	 *************************************************************************/
	~Symbol(){}

	/**************************************************************************
	 * setSymbol
	 * ------------------------------------------------------------------------
	 * Sets the symbol of the Symbol object.
	 * ------------------------------------------------------------------------
	 * PRE-CONDITION:
	 *     symbol - Symbol must be defined.
	 *
	 * POST-CONDITION:
	 * 	   Changes the symbol data member of the Symbol object.
	 *************************************************************************/
	void setSymbol(char symbol){c = symbol;}

	/**************************************************************************
	 * setFrequency
	 * ------------------------------------------------------------------------
	 * Sets the frequency of the Symbol object.
	 * ------------------------------------------------------------------------
	 * PRE-CONDITION:
	 *     frequency - Frequency must be defined.
	 *
	 * POST-CONDITION:
	 * 	   Changes the frequency data member of the Symbol object.
	 *************************************************************************/
	void setFrequency(int freq){frequency = freq;}

	/**************************************************************************
	 * setCode
	 * ------------------------------------------------------------------------
	 * Sets the code of the Symbol object.
	 * ------------------------------------------------------------------------
	 * PRE-CONDITION:
	 *     code - Code must be defined.
	 *
	 * POST-CONDITION:
	 * 	   Changes the code data member of the Symbol object.
	 *************************************************************************/
	void setCode(string code){this->code = code;}

	/**************************************************************************
	 * getSymbol
	 * ------------------------------------------------------------------------
	 * Returns the symbol of the Symbol object.
	 * ------------------------------------------------------------------------
	 * POST-CONDITION:
	 * 	   Symbol of the Symbol object is returned.
	 *************************************************************************/
	char getSymbol(){return c;}

	/**************************************************************************
	 * getFrequency
	 * ------------------------------------------------------------------------
	 * Returns the frequency of the Symbol object.
	 * ------------------------------------------------------------------------
	 * POST-CONDITION:
	 * 	   Frequency of the Symbol object is returned.
	 *************************************************************************/
	int getFrequency(){return frequency;}

	/**************************************************************************
	 * getCode
	 * ------------------------------------------------------------------------
	 * Returns the code of the Symbol object.
	 * ------------------------------------------------------------------------
	 * POST-CONDITION:
	 * 	   Code of the Symbol object is returned.
	 *************************************************************************/
	string getCode(){return code;}

	/**************************************************************************
	 * operator++
	 * ------------------------------------------------------------------------
	 * Overloads the postfix operator to increment the frequency data member of
	 * the Symbol object.
	 * ------------------------------------------------------------------------
	 * POST-CONDITION:
	 * 	   Frequency ofthe Symbol object is incremented by 1.
	 *************************************************************************/
	void operator++(int){frequency++;}
private:
	char c;        // Symbol
	int frequency; // Frequency of the symbol
	string code;   // Symbol Huffman code
};
/******************************************************************************
 * COMPARATOR CLASS - CompareFrequency
 * ----------------------------------------------------------------------------
 * This class is used to store the symbols in the Symbols vector in the priority
 * queue in ascending order.
 *****************************************************************************/
class CompareFrequency
{
public:
	bool operator()(NodeType *node, NodeType *otherNode)
	{
		return (node->freq > otherNode->freq);
	}
};

/******************************************************************************
 * CLASS - Huffman Tree
 * ----------------------------------------------------------------------------
 * This class defines a Huffman Tree that is capable of building an Encoding
 * Tree, generating the codes for the symbols in the Encoding Tree, encoding a
 * given text, and decoding the text.
 *****************************************************************************/
class HuffmanTree
{
public:
	/**************************************************************************
	 * Class Default constructor.
	 *************************************************************************/
	HuffmanTree(){}
	/**************************************************************************
	 * Class Destructor.
	 *************************************************************************/
	~HuffmanTree(){}
	/**************************************************************************
	 * void buildEncodingTree(vector<Symbol> &symbols);
	 * ------------------------------------------------------------------------
	 * Builds the encoding tree using the symbols stored in the Symbol vector
	 * and generates their Huffman Codes.
	 * ------------------------------------------------------------------------
	 * POST-CONDITION:
	 * 	   The Huffman Codes for each of the symbols will be stored.
	 *************************************************************************/
	void buildEncodingTree(vector<Symbol> &symbols)
	{
		//Declares the new node in the Encoding Tree that will become the parent of
		// the elements with the lowest frequency and its left and right children.
		NodeType *left, *right, *top;

		// Defines a priority queue storing the symbols.
		priority_queue<NodeType*, vector<NodeType*>, CompareFrequency> nodeQueue;

		// Stores the symbols in the priority queue in increasing order.
		for(uint i = 0; i < symbols.size(); i++)
		{
			nodeQueue.push(new NodeType(symbols[i].getSymbol(), symbols[i].getFrequency()));
		}

		// Makes the symbols with the lowest frequencies the children of top and
		// adds top back onto the queue.
		while(nodeQueue.size() != 1)
		{
			// Makes the node with the lowest frequency the left child of top.
			left = nodeQueue.top();
			nodeQueue.pop();

			// Makes the node with the next lowest frequency the right child of top.
			right = nodeQueue.top();
			nodeQueue.pop();

			// Creates a new node for top and makes its frequency the sum of its
			// children's frequencies and makes its left and right pointers point
			// to its left and right children.
			top = new NodeType('`', left->freq + right->freq);
			top->left = left;
			top->right = right;

			// Pushes top back onto the priority queue with its new frequency.
			nodeQueue.push(top);
		}

		// Generates the codes for all of the symbols in the Encoding Tree.
		generateCodes(nodeQueue.top(), "", symbols);
	}
	/**************************************************************************
	 * 	void generateCodes(NodeType* root, string code, vector<Symbol> &symbols);
	 * ------------------------------------------------------------------------
	 * Recursively generates the codes for each of the symbols in the symbol vector.
	 * ------------------------------------------------------------------------
	 * POST-CONDITION:
	 * 	   Stores the Huffman Code for each symbol.
	 *************************************************************************/
	void generateCodes(NodeType* root, string code, vector<Symbol> &symbols)
	{
		// Base Case - Breaks out of the recursive call if the left or right child
		//             from the previous call is NULL (bottom of tree was reached).
		if(!root)
		{
			return;
		}
		// Stores the code of the symbol.
		if(root->data != '`')
		{
			symbols[getSymbolIndex(root->data, symbols)].setCode(code);
		}
		// Adds a 0 to the current code when going left down the tree.
		generateCodes(root->left, code + "0", symbols);
		// Adds a 1 to the current code when going right down the tree.
		generateCodes(root->right, code + "1", symbols);
	}
private:
	/**************************************************************************
	 * void buildEncodingTree(vector<Symbol> &symbols);
	 * ------------------------------------------------------------------------
	 * Returns the index of the symbol being searched for.
	 * ------------------------------------------------------------------------
	 * POST-CONDITION:
	 * 	   symbol - Symbol to be searched for.
	 * 	   ssymbol - Symbol to be searched for.
	 *************************************************************************/
	uint getSymbolIndex(char symbol, vector<Symbol> symbols)
	{
		// Stores the index of the symbol being search for.
		uint i = 0;
		// Increments i until the symbol is found.
		while(symbol != symbols[i].getSymbol())
		{
			i++;
		}
		return i;
	}
};
vector<char> getText(string fileName){
	vector<char> text;
	char symbol;
	ifstream fin;
	fin.open(fileName.c_str());

	while(fin.get(symbol))
	{
		text.push_back(symbol);
	}
	return text;}
uint symbolExists(char symbol, vector<Symbol> symbols)
{
	uint i = 0;
	bool found = false;
	while(i < symbols.size() && !found)
	{
		if(symbols[i].getSymbol() == symbol)
		{
			found = true;
		}else{
			i++;
		}
	}
	return i;
}
vector<Symbol> getSymbolFrequencies(vector<char> text){
	vector<Symbol> symbols;
	for(uint i = 0; i < text.size(); i++)
	{
		uint symIndex = symbolExists(text[i], symbols);

		if(symIndex >= symbols.size())
		{
			Symbol temp(text[i], 1, "");

			symbols.push_back(temp);
		}else{
			symbols[symIndex]++;
		}
	}
	return symbols;}

vector<string> encodeText(vector<char> text, vector<Symbol> symbols){
	vector<string> encodedText;
	// Huffman code of the current character.
	string currCode;

	for(uint i = 0; i < text.size(); i++)
	{
		encodedText.push_back(symbols[symbolExists(text[i], symbols)].getCode());
	}
	return encodedText;}
vector<char> decodeText(vector<string> encodedText, vector<Symbol> symbols){
	vector<char> decodedText;

	for(uint i = 0; i < encodedText.size(); i++)
	{
		bool found = false;

		uint j = 0;

		while(j < symbols.size() && !found)
		{
			if(encodedText[i] == symbols[j].getCode())
			{
				found = true;
			}else{
				j++;
			}
		}
		decodedText.push_back(symbols[j].getSymbol());
	}
	return decodedText;}
/******************************************************************************
 * Huffman Coding
 * ----------------------------------------------------------------------------
 * This program will print out the frequency table and the Huffman Code for
 * each letter of the Gettysburg address.Then it will encode the Gettysburg
 * address and print it. It will decode the compressed and encoded file that is
 * created and print out the compression ratio that was achieved.
 * ----------------------------------------------------------------------------
 *****************************************************************************/
int main()
{
	// Output header to console
	// Output header to console
	cout << PrinterHeader("Huffman Coding", 15, 'A');
	// Output description of the program
	cout << "\nThis program will use huffman coding algorithm and read in the Gettysburg\n"
			"address.Print out the frequency table and the HuffmanCode for each letter of\n"
			"the Gettysburg address. Then the program will Encode the Gettysburg address\n"
			"and print the encoded Gettysburg address.Then decode your compressed file and\n"
			"print out the Gettysburg address and print out the compression ratio that was\n"
			"achieved.\n\n";
	cout << "**********\n"
			"* PART A *\n"
			"**********\n\n";
	/*****************************************************************************
	 * First - Read in the Gettysburg address from an input file.
	 *****************************************************************************/
	// Returns the text in the file.
	vector<char> text = getText("InFile.txt");
	/*****************************************************************************
	 * Second - Print out the frequency table and the Huffman Code for each letter
	 *          of the Gettysburg address.
	 *****************************************************************************/
	// Determines the frequency of each character in the text.
	vector<Symbol> symbols = getSymbolFrequencies(text);

	HuffmanTree huffTree;

	huffTree.buildEncodingTree(symbols);

	cout << "Printing the frequency table and Huffman Codes for the symbols.\n\n";

	// Prints the frequency table and code for each symbol in the text.
	cout << left
			<< setw(12) << "SYMBOL" << setw(15) << "FREQUENCY" << setw(12) << "CODE"
			<< endl
			<< setw(12) << "------" << setw(15) << "---------" << setw(12) << "----"
			<< endl;

	for(uint i = 0; i < symbols.size(); i++)
	{
		if(symbols[i].getSymbol() == ' ')
		{
			cout << setw(12) << " space";
		}
		else if(symbols[i].getSymbol() == '\n')
		{
			cout << setw(12) << "  \\n";
		}
		else
		{
			cout << "   " << setw(9) << symbols[i].getSymbol();
		}

		cout << "   " << setw(12) << symbols[i].getFrequency()<< symbols[i].getCode();
		cout << endl;
	}
	/*****************************************************************************
	 * Third - Encode the Gettysburg address and print the encoded Gettysburg
	 *         address.Then decode your compressed file and print out the
	 *         Gettysburg address and print out the compression ratio that was
	 *         achieved.
	 *****************************************************************************/
	cout << "\n**********\n"
			"* PART B *\n"
			"**********\n\n";
	cout << "Encoding Gettysburg Address...\n\n";
	vector<string> encodedText = encodeText(text, symbols);
	cout << "**********\n"
			"* PART C *\n"
			"**********\n\n";
	cout << "Printing the encoded Gettysberg Address...\n\n";
	uint i = 0;
	// Prints the encoded text while ensuring that the maximum length of any line
	// is no greater than the bound (76).
	while(i < encodedText.size())
	{
		string line;
		uint length = 0;
		// Adds the codes to the current line of the encoded text.
		while(length < BOUND && i < encodedText.size())
		{
			// Checks to see if adding the next code to the current line of text
			// will cause the length of the line to exceed the bound.
			if(length + encodedText[i].size() < BOUND)
			{
				// Adds the code to the current line.
				line += encodedText[i];

				// Accumulates length to store the new size of the line.
				length += encodedText[i].size();

				// Increments i to the next index in encodedText.
				i++;
			}else{
				// Assigns 100 to length to indicate that adding the next code
				// to the current line will exceed the bound.
				length = 100;
			}
		}
		// Prints the line of encoded text.
		cout << line << endl;
	}
	/*****************************************************************************
	 * Fourth - Decode your compressed file and print out the Gettysburg
	 *          address and print out the compression ratio that was achieved.
	 *****************************************************************************/
	cout << "\n**********\n"
			"* PART D *\n"
			"**********\n\n";
	cout << "Now decoding the encoded Gettysberg Address...\n\n";
	// Decodes the text and stores the decoded symbols in a vector of characters.
	vector<char> decodedText = decodeText(encodedText, symbols);
	uint j = 0;
	// Prints the decoded text while ensuring that the length of any line does
	// not exceed the bound.
	while(j < decodedText.size())
	{
		string line;
		uint length = 0;
		// Adds characters to the line until a newline is reached or a space is
		// reached and adding the word before the previous space has exceeded
		// the bound.
		while(length < BOUND && j < decodedText.size())
		{
			line += decodedText[j];

			// Checks if the last symbol added was a new line.
			if(decodedText[j] == '\n')
			{
				// Exits to signify that the paragraph ends here.
				length = 100;
			}else{
				// Increments length and continues the loop.
				length++;
			}

			// Increments j to the next symbol in the decodedText vector.
			j++;
		}
		// If last symbol in the line is not a newline or a punctuation mark,
		// checks if the last symbol is a space.
		if(line.back() != '\n' && line.back() != '.' && line.back() != '!')
		{
			// If the last symbol is not a space, removes the last symbol from
			// the line until it is a space since the bound was exceeded and the
			// entire word may not have been stored in the line.
			if(line.back() != ' ')
			{
				while(line.back() != ' ' && !line.empty())
				{
					line.pop_back();

					// Decrements j to start at the beginning of the word that
					// was just removed from the line in the next loop iteration.
					j--;
				}
			}
		}
		// Prints the line if it is not empty.
		if(!line.empty())
		{
			cout << line << endl;
		}
	}
	/*****************************************************************************
	 * Fifth - Print out the compression ratio that was achieved.
	 *****************************************************************************/
	cout << "\n**********\n"
			"* PART E *\n"
			"**********\n\n";
	double compressionRatio = 0.0;
	// Finds the compressed length of the text.
	for(uint i = 0; i < symbols.size(); i++)
	{
		compressionRatio += (symbols[i].getFrequency() * symbols[i].getCode().size());
	}
	// Divides by 8 to store the number of bytes in the compressed text.
	compressionRatio /= 8.0;
	// Divides the number of bytes by the number of symbols in the text to
	// get the compression ratio.
	compressionRatio /= double(text.size());
	// Prints the compression ratio to 2 decimal places.
	cout << fixed << setprecision(2)<< "Compression Ratio = "
			<< compressionRatio * 100 << "%";
	return 0;
}
