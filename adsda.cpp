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
        temp = right;
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
