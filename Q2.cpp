#include<iostream>
#include <string>
using namespace std;
//a function to return a string comprising of small letters to be compared
string convertToSmall(string input){
    string s = "";
    for(int i=0;i<input.length();i++){
        s += tolower(input[i]);
    }
    return s;
}
// node class that contains our string
class Node{
    public:
    string data;
    Node* next,*prev;
    Node(){
        next = prev = NULL;
    }
    Node(string s){
        data = s;
        next = prev = NULL;
    }
};
// a doubly linked list to contain all the data
class DoublyLinkedList{
    private:
        Node* nodes;
        Node* head;
    public:
        DoublyLinkedList(){
            nodes = head = NULL;
        }
        //a function to insert our string nodes to the list
        void insertNode(string s){
            nodes = new Node(s);
            if(head == NULL){
                head = nodes;
            }else{
                Node* temp = head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = nodes;
                nodes->prev = temp;
            }
        }
        // a function to remove duplicates from the linked list
        void removeDuplicates(){
            Node* temp = head;
            while(temp!=NULL){
                Node* temp2 = temp->next;
                while(temp2!=NULL){
                    if(temp->data == temp2->data){
                        Node* temp3 = temp2;
                        // delete if strings match
                        if(temp2->next == NULL){
                            temp2->prev->next = NULL;
                            temp2 = temp2->next;
                            delete temp3;
                            temp3 = NULL;
                            continue;
                        }else{
                            temp2->prev->next = temp2->next;
                            temp2->next->prev = temp2->prev;
                            temp2 = temp2->next;
                            delete temp3;
                            temp3 = NULL;
                            continue;
                        }
                    }
                    temp2 = temp2->next;
                }
                temp = temp->next;
            }
        }
        // a function to sort the duplicate proof linked list
        void sort(){
            Node* temp = head;
            while(temp!=NULL){
                Node* temp2 = temp;
                while(temp2 != NULL){
                    if(convertToSmall(temp->data) > convertToSmall(temp2->data)){
                        string s = temp->data;
                        temp->data = temp2->data;
                        temp2->data = s;
                    }
                    temp2 = temp2->next;
                }
                temp = temp->next;
            }
        }
        //a function to traverse the linked list
        void traverse(){
            Node*temp = head;
            while(temp!= NULL){
                cout<<temp->data<<endl;
                temp = temp->next;
            }
        }
};

int main(){
    DoublyLinkedList DLL;
    //get the whole input as string
    string input;
    getline(cin,input);
    // divide the whole string on basis of spaces and push the string values into the Doubly linked list
    for(int i=0;i<input.length();i++){
        string s = "";
        if(input[i]!=' '){
            while(i<input.length() && input[i]!=' '){
                s += input[i];
                i++;
            }
            i--;
            DLL.insertNode(s);
        }
    }
    //call remove duplicates
    DLL.removeDuplicates(); 
    // call sort   
    DLL.sort();
    //traverse
    DLL.traverse();
    return 0;
}