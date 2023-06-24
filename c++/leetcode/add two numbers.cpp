#include<iostream>
#include<math.h>
using namespace std;

template < class T >
// create structure
class Node
{
  public: T data;
	Node *next;
};
template < class T > class LinkedList
{
	public: Node < T > *head; // head node
	LinkedList < T > ()
	{
		head = NULL;
	}
	// Insert node at end of linked list
	void insert(T value)
	{
		// Create dynamic node
		Node < T > *node = new Node < T > ;
		if (node == NULL)
		{
			cout << "Memory overflow\n";
		}
		else
		{
			node->data = value;
			node->next = NULL;
			if (head == NULL)
			{
				// Base condition
				head = node;
			}
			else
			{
				Node < T > *temp = head;
				while (temp->next != NULL)
				{
					temp = temp->next;
				}
				// Add newly node at last
				temp->next = node;
			}
		}
	}
	// Display all node value in linked list
	void display()
	{
		if (head == NULL)
		{
			cout << "Empty linked list";
		}
		else
		{
			Node < T > *temp = head;
			cout << "\nLinked List : ";
			while (temp != NULL)
			{
				// Print node value
				cout << temp->data << " ";
				temp = temp->next;
			}
		}
	}
};
template <class T>
int reverseSum(LinkedList <T>*list){
	Node <T> *temp  = list->head;
	int i = 0;
     int n = 0;
//	Node <int> *temp = list.head;
	while(temp){
		 int a =  temp->data * pow(10,i);
		  n += a;
		i++;
		temp = temp->next;
	}
	return n;
	
}
template <class T>
Node<T> * addTwoNumbers(LinkedList <T>* l1, LinkedList <T>* l2) {
        int n = reverseSum(l1);
        int m = reverseSum(l2);
        int sum = m + n;
        LinkedList <T>*temp = new LinkedList<T>;
        while(sum > 0){
        	temp->insert(sum % 10);
        	sum = sum / 10;
		}
		return temp->head;
    }
int main(){
	LinkedList <int> list;
//	list.insert(1);
//	list.insert(2);
//	list.insert(3);
	list.insert(2);
	list.insert(4);
//	list.insert(6);
//	list.insert(6);
	list.insert(3);
	LinkedList<int> lst;
	lst.insert(5);
	lst.insert(6);
	lst.insert(4);
	Node <int> *temp = addTwoNumbers(&list,&lst);
	while(temp){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << reverseSum(&list) << endl;

}
