#include<iostream>
using namespace std;
struct tree{
	tree *left;
	tree *right;
	int val;
	tree(int val){
		this->val = val;
		left = right = NULL;
	}
	tree(){
		left = right = NULL;
	}
};
void inorderPrint(tree *root){
	if(root == NULL)
		return;
	inorderPrint(root->left);
	cout << root->val << " ";
	inorderPrint(root->right);
}
int countNode(tree *root){
	if(root == NULL)
		return 0;
	return 1 + countNode(root->left) + countNode(root->right);
}
void swap(tree *a, tree *b) {
  tree t = *a;
  *a = *b;
  *b = t;
}
void inorderArray(tree *root,tree *arr[] , int i ,int &idx, int n){
	if(i >= n)
		return;
	inorder(root->left,arr,(i*2)+1,idx,n);
	arr[i] = root;
	inorder(root->right,arr,i*2+2,idx,n); 
}
void bubbleSort(tree **array,int n){
  for (int step = 0; step < n; ++step) {
    for (int i = 0; i < n - step - 1; ++i) {
      if (array[i]->val > array[i + 1]->val) {
      	swap(array[i],array[i+1]);
      }
    }
  }
}
tree *solve(tree **arr,int i , int n){
	if(i > n)
		return NULL;
	int mid = (i + n) / 2;
	tree *root = arr[mid];
	root->left = solve(arr,i,mid-1);
	root->right = solve(arr,mid+1,n);
}
tree *fixTree(tree **arr, int n){
	int i = 0;
	tree* root = solve(arr,i,n-1);
	return root;
}
int main(){
	tree *t1 = new tree(50);
	tree *t2 = t1;
	t1->left = new tree(40);
	t1->right = new tree(45);
	t1->left->left = new tree(35);
	t1->left->right = new tree(31);
	t1->right->left = new tree(41);
	t1->right->right = new tree(43);
	int n = countNode(t1);
	tree **arr = new tree*[n];		
	int i = 0;
	inorderArray(t2,arr,0,i,n);
	bubbleSort(arr,n);
	for(int i = 0 ; i < n ; i++)
		cout << arr[i]->val << " ";
	tree *final_root = fixTree(arr, n);
	cout << "inorder to confirm" << endl;
	inorderPrint(final_root);	
}
