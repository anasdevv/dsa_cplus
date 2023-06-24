#include<iostream>
using namespace std;
//a node class containing the task name,time and quota for the task
class Node{
    public:
    string task;
    int time;
    int quota;
    Node* prev,*next;
    Node(){
        prev=next=NULL;
    }
    Node(string t,int tm,int q){
        task = t;
        time = tm;
        quota = q;
        prev=next=NULL;
    }
};
// a circular linked list to maintain the tasks
class CicrularLinkedList{
    private:
        Node* nodes;
        Node* head;
        int nodeCount;
    public:
        CicrularLinkedList(){
            nodes = NULL;
            nodeCount = 0;
            head = NULL;
        }
        // a function to insert tasks into the linked list
        void insertNode(string task,int time,int quota){
            nodes = new Node(task,time,quota);
            if(head == NULL){
                head = nodes;
                nodes->next = head;
                nodes->prev = head;
            }else{
                Node* temp = head;
                while(temp->next != head){
                    temp = temp->next;
                }
                temp->next = head->prev = nodes;
                nodes->next = head;
                nodes->prev = temp;
            }
            nodeCount++;
        }
        //a function to delete required nodes once their time period is over
        void deleteNode(Node* toBeDeleted){
            Node* temp = toBeDeleted;
            nodeCount--;
            if(toBeDeleted == head){
                head->prev->next = head->next;
                head = head->next;
                head->prev = toBeDeleted->prev;
                delete temp;
                temp = NULL;
                return;
            }else if(toBeDeleted == head && toBeDeleted->next == head){
                delete temp;
                temp = NULL;
                return;
            }
            toBeDeleted->prev->next = toBeDeleted->next;
            toBeDeleted->next->prev = toBeDeleted->prev;
            delete temp;
            temp = NULL;
        }
        //a function prints the tasks and calculates the time they are going to be run for
        void tinyProcess(){
            Node*temp = head;
            while(nodeCount!=0){
                if(temp->time == 0){
                    temp = temp->next;
                    deleteNode(temp->prev);
                    continue;
                }
                cout<<temp->task<<endl;
                temp->time -= temp->quota;
                temp = temp->next;
            }
        }
};
int main(){
    CicrularLinkedList CLL;
    int testCases,time,quota;
    string task;
    //get all test cases for the tasks
    cin>>testCases;
    for(int i=0;i<testCases;i++){
        cin>>task>>time>>quota;
        CLL.insertNode(task,time,quota);
    }
    // process the tasks
    CLL.tinyProcess();
    return 0;
}