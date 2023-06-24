#include <iostream>
#include <list>
using namespace std;

struct Node			// Represents a Vertex
{
	int val;		// Name or label of the vertex
	Node* next;		// Next neighbour in adjacency list
};

struct Edge			// Represents an edge
{
	int src, dest;	// For names of source vertex and destination vertex
};
class Graph
{
	int num_of_vertices;

	// This function adds a given destination vertex (dest) as neighbour 
	// to linked list of given source vertex (head)
	Node* getNode(int dest, Node* head)
	{
		Node* newNode = new Node;
		newNode->val = dest;
		newNode->next = head;
		return newNode;
	}

public:
	// This "head" is an array of pointers where each pointer points to a separate linked list
	// (it's simply like a 2D array!)
	Node** head;

	// Constructor for creating a graph. The parameters are self-explanatory
	Graph(Edge edges[], int num_of_edges, int num_of_vertices)
	{
		head = new Node*[num_of_vertices];				// Create our array of pointers (i.e. adjacency list)
														// i.e. for 5 vertices. There are 5 different "heads"
														// where each head pointing to a separate linked list (adjacency list)
		
		this->num_of_vertices = num_of_vertices;		// This line is self-explanatory
		for (int i = 0; i < num_of_vertices; i++)		// This loop initializes all our adjacency lists heads to 0 (null)
			head[i] = 0;


		for (int i = 0; i < num_of_edges; i++)			// This loop take one particular edge in each iteration and
														// based on that edge's source (src) and destination (dest),
														// it adds it to the relevant linked list
		{
			int src = edges[i].src;						// Gets source vertex of this particular edge
			int dest = edges[i].dest;					// Gets destination vertex of this particular edge

			Node* newNode = getNode(dest, head[src]);	// Create a new node as neighbour in linked list of the source vertex (head[src])
			head[src] = newNode;						// Update head so that any new neighbour will be added as a second node (i.e. to create a chain of nodes)

//			Node* newNode2 = getNode(src, head[dest]);	// Adding src->dest as well as dest->src
//			head[dest] = newNode2;						// Adding src->dest as well as dest->src
			/* The following two lines will only be used in case of undirected graph
			Node* newNode = getNode(src, head[dest]);	// Adding src->dest as well as dest->src
			head[dest] = newNode;						// Adding src->dest as well as dest->src
			*/
		}
	}

	~Graph()
	{
		for (int i = 0; i < num_of_vertices; i++)
		{
			delete[] head[i];						// Each head[i] is an array pointers so delete[] it 
		}

		delete[] head;								// Remember what we learned in OOP
													// about deleting 2D arrays???
	}

	void Printer(Node* x)							// This function takes a vertex as parameter
													// and prints all its neighbours (if any)
	{
		while (x != NULL)
		{
			cout << " -> " << x->val;
			x = x->next;
		}
	}
};

int main()
{
	Edge edges[] =
	{
		{0, 1}, {0, 4}, // Node 0 is connected to Node 1 and 4
		{1, 3}, {1, 2}, // Node 1 is connected to Node 3 and 2
		{2, 3},			// Node 2 is connected to Node 3
		{3, 0}, {3, 4}, // Node 3 is connected to Node 0 and 4
		{4, 1}			// Node 4 is connected to Node 1
	};

	int num_of_edges = sizeof(edges) / sizeof(edges[0]);	// Calculating # of elements in edges array
	int num_of_vertices = 5;								// # of vertices in our graph

	Graph g1(edges, num_of_edges, num_of_vertices);			// Create a graph

	// Printing our graph one vertex at a time in for loop
	for (int i = 0; i < num_of_vertices; i++)
	{
		cout << i;				// Display vertex name
		g1.Printer(g1.head[i]);	// Then display its neighbours
		cout << endl;
	}
}
