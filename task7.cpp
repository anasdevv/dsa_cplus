#include <iostream>
using namespace std;
//task1
class Node
{

public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int d)
    {
        data = d;
        next = NULL;
    }

};

class SinglyLinkedList
{
public:
    Node *head;

    SinglyLinkedList()
    {
        head = NULL;
    }

    SinglyLinkedList(Node *n)
    {
        head = n;
    }

    //task2

    void appendNode(Node* n, int d){
        Node* nn = new Node();
        nn->data = d;
        if(head==NULL){
            head = nn;
        }
        else{
            Node* temp = head;

            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = nn;
        }
    }
    //task3
    void prependNode(int d){
        Node *nn = new Node();
        nn->data = d;
        nn->next = head;
        head = nn;
    }
    //task4
    void insertAfterNode(int d, int pos){
        Node* nn = new Node();
        nn->data = d;

        if(pos==0){
            nn->next = head;
            head = nn;
        }
        else{
            Node *p = head;
            while(pos>1){
                p = p->next; 
            }
            nn->next = p->next;
            p->next = nn;
        }
    }
    //task5
    void deleteNode(int pos){
        Node* t = head;
        Node* t2 = NULL;
        int len;

        if(head==NULL){
            cout<<"The list is empty"<<endl;
            return;
        }

        while(t != NULL){
            t = t->next;
            len++;
        }

        t2 = head;

        if(pos==1){
            head = head->next;
            delete t2;
            return;
        }

        while(pos>1){
            t2 = t;
            t = t->next;
            pos--;
        }

        t2->next = t->next;
        delete t;
    }
    //task6
    void UpdateNode(int d, int nd){
        Node* temp = new Node();
        temp = head;

        if (head==NULL){
            cout<<"List is Empty"<<endl;
            return;
        }

        while(temp->next!=NULL){
            if(temp->data == d){
                temp->data = nd;
                cout<<"Node is Updated with new data"<<endl;
                return;
            }
            temp = temp->next;
        }
        cout<<"Item does not exists in the list"<<endl;
    }

    void print(){
        Node* temp = head;

        if (head==NULL){
            cout<<"List is Empty"<<endl;
            return;
        }

        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    //task7
    void evenodd(Node* n){
        Node* evens = NULL;
        Node* evene = NULL;
        Node* odds = NULL;
        Node* odde = NULL;
        Node* temp = head;

        while(temp!=NULL){
            int v;
            v = temp->data;
            if(v%2==0){
                if(evens!=NULL){
                    evene->next = temp;
                    evene = evene->next;
                }
                else{
                    evens = temp;
                    evene = temp;
                }
            }
            else{
                if(odds!=NULL){
                    odde->next = temp;
                    odde = odde->next;
                }
                else{
                    odds = temp;
                    odde = temp;
                }
            }
            temp = temp->next;
        }

        if(odds==NULL||evens==NULL){
            if(odds=NULL){
                cout<<"all values are even"<<endl;
            }
            else{
                cout<<"all values are odd"<<endl;
            }
            return;
        }

        evene->next = odds;
        odde->next = NULL;
        head = evens;
    }
};

int main(){
    SinglyLinkedList l1 = NULL;

    l1.prependNode(17);
    l1.appendNode(l1.head,15);
    l1.appendNode(l1.head,8);
    l1.appendNode(l1.head,12);
    l1.appendNode(l1.head,10);
    l1.appendNode(l1.head,5);
    l1.appendNode(l1.head,4);
    l1.appendNode(l1.head,1);
    l1.appendNode(l1.head,7);
    l1.appendNode(l1.head,6);

    l1.print();
    
    cout<<endl;
    
    l1.evenodd(l1.head);

    cout<<"Modified List"<<endl;
    l1.print();
}