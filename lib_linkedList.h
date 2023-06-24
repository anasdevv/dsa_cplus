#include <iostream>
using namespace std;

// NODE Class with template NodeType
template <class NodeType>
struct Node
{
public:
    NodeType object;
    Node *next;
    Node *prev;
    Node(NodeType &obj)
    {
        object.set(obj);
        next = NULL;
        prev = NULL;
    }
    Node()
    {

        next = NULL;
        prev = NULL;
    }
    ~Node()
    {
    }
};

// Doubly LinkedList Class with Template 'Type'
template <class Type>
class DoublyLinkedList
{
    Node<Type> *head;
    Node<Type> *tail;

public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void push(Type &obj) //	Push function
    {
        Node<Type> *newNode = new Node<Type>(obj);

        if (!head)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void pop() //  Pop function
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = NULL;
    }

    void enQueue(Type &obj) //  Enqueue Function
    {
        Node<Type> *newNode = new Node<Type>(obj);
        if (!head)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void deQueue() //  Dequeue Function same as pop
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = NULL;
    }
    Type lastNode() //  returns TOP/EndNode
    {
        return tail->object;
    }
    Type firstNode() // returns StartNode
    {
        return head->object;
    }
    void displayList() // Prints LinkedList
    {

        Node<Type> *curr = head;

        while (curr)
        {
            curr->object.print();
            cout << " <-> ";
            curr = curr->next;
        }
        cout << "NULL" << endl
             << endl;
    }
    ~DoublyLinkedList()
    {
    }
};