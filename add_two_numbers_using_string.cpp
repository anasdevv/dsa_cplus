//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *temp = l1;
	string s1 = "" , s2 = "";
	unsigned long int x;
	while(temp){
		x = temp->val;
		s1 += to_string(x);
		temp = temp->next;
	}
	temp = l2;
	while(temp){
		x = temp->val;
		s2 += to_string(x);
		temp = temp->next;
	} 
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
   unsigned long int num1 = stoll(s1);
	unsigned long int num2 = stoll(s2);
	x = num1 + num2;
	s1 = to_string(x);
	reverse(s1.begin(),s1.end());
    ListNode *head = new ListNode;
        head->val = s1[0] - '0';
         temp = head;
	for(int i = 1 ; i < s1.length() ; i++){
		temp->next = new ListNode(s1[i] - '0');
        temp = temp->next;
	}
	return head;
    }
};
