#include<iostream>
using namespace std;
// A node class to hold the value,expression and exponent of the polynomial
// it also has a flag to determine if the variable was used for addition or not
class Node{
    public:
        int value;
        char expression;
        int exponent;
        bool flag;
        Node* next;
        Node(){
            flag = 0;
            next = NULL;
        }
        Node(int val,char exp,int expo){
            flag = 0;
            value = val;
            expression = exp;
            exponent = expo;
            next = NULL;
        }
};
//linked list to hold the polynomials
class LinkedList{
    private:
        Node *nodes;
        Node *head;
        int nodeCount;
    public:
        LinkedList(){
            nodeCount = 0;
            nodes = head = NULL;
        }
        Node* getHead(){
            return head;
        }
        int getNodeCount(){
            return nodeCount;
        }
        //add nodes to the end of the linked list
        void insertNode(int v,char c,int i){
            nodes = new Node(v,c,i);
            nodeCount++;
            if(head == NULL){
                head = nodes;
            }else{
                Node* temp = head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = nodes;
            }
        }
        //a function to sort the polynomials by their exponents
        void sortByExponent(){
            Node* temp = head;
            while(temp != NULL){
                Node*temp2 = temp;
                while(temp2!=NULL){
                    if(temp->exponent>temp2->exponent){
                        int val = temp->value;
                        temp->value = temp2->value;
                        temp2->value = val;
                        int tmp = temp2->exponent;
                        temp2->exponent = temp->exponent;
                        temp->exponent = tmp;
                        char tmpp = temp2->expression;
                        temp2->expression = temp->expression;
                        temp->expression = tmpp;
                    }
                    temp2= temp2->next;
                }
                temp = temp->next;
            }
        }
        //a function to sort the polynomials by their expressions
        void sortByExpression(){
            Node* temp = head;
            while(temp != NULL){
                Node*temp2 = temp;
                while(temp2!=NULL){
                    if(temp->expression>temp2->expression){
                        int val = temp->value;
                        temp->value = temp2->value;
                        temp2->value = val;
                        int tmpp = temp2->exponent;
                        temp2->exponent = temp->exponent;
                        temp->exponent = tmpp;
                        char tmp = temp2->expression;
                        temp2->expression = temp->expression;
                        temp->expression = tmp;
                    }
                    temp2= temp2->next;
                }
                temp = temp->next;
            }
        }
        //a function to traverse through the whole linked list printing the polynomials
        void traverse(){
            cout<<nodeCount<<endl;
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->value<<" "<<temp->expression<<" "<<temp->exponent<<endl;
                temp = temp->next;
            }
        }
};
//a function that adds and returns a resultant linked list
LinkedList calculateResult(LinkedList P1,LinkedList P2){
    LinkedList result;
    Node* temp1 = P1.getHead();
    int nc=0;
    while(temp1 != NULL){
        char exp = temp1->expression;
        int expo = temp1->exponent;
        int val = temp1->value;
        Node* temp2 = P2.getHead();
        while(temp2!= NULL){
            //if exponenet and exxpression match then add the polynomails and push them into resultant
            if(temp2->expression == exp && temp2->exponent == expo && temp2->flag == 0){
                val += temp2->value;
                temp2->flag = 1;
                temp1->flag =1;
                nc++;
            }
            temp2 = temp2->next;
        }
        //if there was no addition,it means that the expression is different than the whole other polynomial so directly push it
        if(temp1->flag==0){
            temp1->flag = 1;
            result.insertNode(temp1->value,temp1->expression,temp1->exponent);
            temp1= temp1->next;
            continue;
        }
        //else simply push the node into resultant
        result.insertNode(val,exp,expo);
        temp1 = temp1->next;
    }
    Node* temp2 = P2.getHead();
    //if there was any node in polynomial 2 left, then push it into result
    while(temp2!= NULL){
        if(temp2->flag == 0){
            result.insertNode(temp2->value,temp2->expression,temp2->exponent);
            temp2->flag = 1;
        }
        temp2 = temp2->next;
    }
    return result;
}
int main(){
    LinkedList polynomial1,polynomial2;
    int testCases1,testCases2,val,expo;
    char exp;
    //get first polynomial
    cin>>testCases1;
    for(int i=0;i<testCases1;i++){
        cin>>val>>exp>>expo;
        polynomial1.insertNode(val,exp,expo);
    }
    //get second polynomial
    cin>>testCases2;
    for(int i=0;i<testCases2;i++){
        cin>>val>>exp>>expo;
        polynomial2.insertNode(val,exp,expo);
    }
    // calculate resultant polynomial
    LinkedList resultant = calculateResult(polynomial1,polynomial2);
    resultant.sortByExponent();
    resultant.sortByExpression();
    resultant.traverse();
    return 0;
}