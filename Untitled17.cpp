#include <iostream>
using namespace std;
struct node
{
  int val;
  node *next;
  node *prev;
  node(int val)
  {
    this->val = val;
    this->next = NULL;
    prev = NULL;
  }
  node()
  {
    next = NULL;
    prev = NULL;
  }
};
class List
{
  /* double link*/
  node *head;
  node *tail;

public:
  List()
  {
    head = NULL;
    tail = NULL;
  }
  List(int val)
  {
    node *temp = new node(val);
    this->head = temp;
    head->prev = NULL;
    tail = head;
    tail->prev = NULL;
    tail->next = NULL;
  }
  void addNode(int val)
  {
    node *temp = new node(val);
    if (head == NULL)
    {
      head = temp;
      tail = head;
      head->prev = NULL;
      head->next = NULL;
      tail->prev = NULL;
      tail->next = NULL;
      return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  }
  void deleteNode(int val)
  {
    //			if(head == addr)
    node *temp = head;
    if (head->val == val)
    {
      head = head->next;
      head->prev = NULL;
      delete temp;
      return;
    }
    while (temp != NULL)
    {
      if (temp->val == val)
      {
        break;
      }
      temp = temp->next;
    }
    temp->prev = temp->next;
    delete temp;
  }
  void printAll()
  {
    node *temp = head;
    while (temp != NULL)
    {
      cout << temp->val << " ";
      temp = temp->next;
    }
  }
  node *getHead()
  {
    return head;
  }
  void addNodes(int arr[], int n)
  {
    for (int i = 0; i < n; i++)
      this->addNode(arr[i]);
  }
  void reversePrint(){
  	node *temp = tail;
  	while(temp != NULL){
  		cout << temp->val << " ";
  		temp = temp->prev;
	  }
  }

  node *getTail(){
  	return tail;
  }
};
node *removeDup(node *head){
	while(head != NULL && head->next){
		node *temp = head->next;
		cout << "here" << endl;
		while(temp != NULL && temp->next){
			if(temp->val == head->val){
					head->next  = head->next->next;
					node *d = head;
//					delete d;
			}
			temp = temp->next;
		}
		head = head->next;
	}
}
node *findMid(node *head){
	node *fast = head->next;
	node *slow = head;
	while(fast && fast->next){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
node *merge(node *left,node *right){
	if(left == NULL)
		return right;
	if(right == NULL)
		return left;
	node *ans = new node(-1);
	node *temp = ans;
	while(left && right){
		if(left->val > right->val){
			temp->next = right;
			right = right->next;
		}
		else{
			temp->next = left;
			left = left->next;
		}
		temp = temp->next;

	}
	  while(left != NULL) {
        temp->next = left;
        temp = temp->next;
        left = left-> next;
    }
    
    while(right != NULL) {
        temp-> next = right;
        temp = temp->next;
        right = right->next;
    }
    
    ans = ans->next;
    return ans;
}
node * mergeSort(node *head){
	if(head == NULL || head->next == NULL)
		return head;
	node *left = head;
	node *mid = findMid(head);
	node *right = mid->next;
	mid->next = NULL;
	left = mergeSort(head);
	right = mergeSort(right);
	node *res = merge(left,right);
	return res;
	
}
int main()
{
  List L;
  int arr[] = {8,7,5,42,1,2,424};
  L.addNodes(arr, sizeof(arr)/sizeof(int));
  node *head = mergeSort(L.getHead());
  while(head){
  	cout << head->val << " ";
  	head = head->next;
  }
//  L.printAll();
//	L.reversePrint();
//	node *head = L.getHead();
//	node *tail = L.getTail();
//	tail->next = head->next;
//	head->next = NULL;
//	head->prev = tail->prev;
//	tail->prev = NULL;
//	tail->next->prev = tail;
//	head->prev->next = head;
//	while(tail->next){
//		cout << tail->val << " ";
//		tail = tail->next;
//	}
//	node *head = removeDup(L.getHead());
//	L.printAll();
}
