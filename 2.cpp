#include<iostream>
#include<math.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp = new ListNode;
        int sum1 =0 , sum2 =0;
        temp = l1;
        int i = 0;
        while(temp){
           sum1 += (temp->val * pow(10,i));
            temp = temp->next;
            i++;
        }
        delete temp;
        temp = NULL;
        temp = l2;
        while(temp){
          sum2 += (temp->val * pow(10,i));
            temp = temp->next;
            i++;
        }
        ListNode *res = new ListNode;
        res->val = sum1+sum2;
         cout << "res" << res->val << endl;
        cout << "sum1" << res->val << endl;
        cout << "sum2" << res->val << endl;
        return 0;
        return res;
    }
int main(){
	ListNode *l1 = new ListNode;
	l1->val = 2;
	ListNode *temp = new ListNode;
	temp = l1;
	 l1->next = new ListNode(4,l1->next);
	l1->next = new ListNode(3,l1->next);
	l1->next = new ListNode(5,l1->next);
	l1->next = new ListNode(6,l1->next);
//	l1->next = new ListNode(5,l1->next);
	
	ListNode *l2 = new ListNode;
	l2->val = 5;
	l2->next = new ListNode;
	l2 = l2->next;
	l2->val = 4;
	l2->next = new ListNode;
	l2 = l2->next;
	l2->val = 3;
	
	
	ListNode *tempp;
	tempp = temp;
	while(tempp){
		cout << " " << tempp->val ;
		tempp = tempp->next;
	}
	return 0;
}
