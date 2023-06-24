#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct tree{
	tree *left;
	tree *right;
	int data;
	tree(int val){
		this->data = val;
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
	cout << root->data << " ";
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
	inorderArray(root->left,arr,(i*2)+1,idx,n);
	arr[i] = root;
	inorderArray(root->right,arr,i*2+2,idx,n); 
}
void bubbleSort(tree **array,int n){
  for (int step = 0; step < n; ++step) {
    for (int i = 0; i < n - step - 1; ++i) {
      if (array[i]->data > array[i + 1]->data) {
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
	return root;
}
tree *fixTree(tree **arr, int n){
	int i = 0;
	tree* root = solve(arr,i,n-1);
	return root;
	
}
void funn(tree *root){
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return;
	if(root->left == NULL && root->right != NULL){
		if(root->data > root->right->data){
			swap(root->data,root->right->data);
			funn(root->right);
		}
	}
	if(root->right == NULL && root->left != NULL){
		if(root->data < root->left->data){
			swap(root->data,root->left->data);
			funn(root->left);
		}
	}
	if(root->left != NULL && root->right != NULL){
		if(root->data > root->right->data){
			swap(root->data,root->right->data);
		}
			if(root->data < root->left->data){
			swap(root->data,root->left->data);
		}
			funn(root->left);
			funn(root->right);
	}	
}
// void BSTtoHeapWithoutExtraSpace(tree* root) {
//
//        if(root == NULL) return;
//
//        if(root->left == NULL && root->right == NULL) return;
//
//        
//        if(root->left == NULL && root->right != NULL) {
//
//            if(root->data < root->right->data) {
//                swap(root->data, root->right->data);
//                BSTtoHeapWithoutExtraSpace(root->right);
//            }
//            return;
//
//        }
//        if(root->left != NULL && root->right == NULL) {
//
//            if(root->data < root->left->data) {
//
//                swap(root->data, root->left->data);
//
//                BSTtoHeapWithoutExtraSpace(root->left);
//
//            }
//
//            return;
//
//        }
//
//        
//
//        if(root->left != NULL && root->right != NULL) {
//
//            if(root->data < root->left->data || root->data < root->right->data) {
//
//                if(root->left->data < root->right->data) {
//
//                    swap(root->data, root->right->data);
//
//                }
//
//                else {
//
//                    swap(root->data, root->left->data);
//
//                }
//
//            }
//
//            if(root->left->data > root->right->data) {
//
//                swap(root->right->data, root->left->data);
//
//            }
//
//            func(root->right);
//
//            func(root->left);
//
//            return;
//
//        }
//
//    }
    void _inorder(tree *root,vector<int> &arr){
        if(root == NULL)
            return;
        
        _inorder(root->left,arr);
        arr.push_back(root->data);
        _inorder(root->right,arr);
    }
    void createHeap(tree *root,vector<int>arr,int &s){
        if(root == NULL)
            return;
         createHeap(root->left,arr,s);
          createHeap(root->right,arr,s);
          root->data = arr[s++];
    }
    void convertToMaxHeapWithExtraSpace(tree* root)
    {
        // Your code goes here
        vector<int> arr;
        _inorder(root,arr);
        int s = 0;
         createHeap(root,arr,s);
    } 
//	void maxHeapToBST(tree *root){
//		if(root == NULL || (root->left == NULL && root->right == NULL))
//			return;
//		if(root->left != NULL && root->right == NULL){
//			if(root->data)
//		}
//	}
int _countNodes(tree *tree){
      if(tree == NULL)
        return 0;
    return 1+_countNodes(tree->left) + _countNodes(tree->right);
  }
  bool _isCBT(tree *root,int i , int n){
  	if(root == NULL)
  		return true;
      if(i > n)
        return false;
    return _isCBT(root->left,i*2+1,n) && is_CBT(root->right,i*2+2);

  }
//   bool _isMaxHeap()
    bool _isHeap(struct tree* tree) {
        // code here
        if(tree == NULL || (tree->left == NULL && tree->right == NULL))
            return true;
        if(tree->left == NULL && tree->right != NULL){
            return tree->data > tree->right->data;
        }
        else if(tree->right == NULL && tree->left != NULL){
            return tree->data > tree->left->data;
        }
        else{
            bool left = _isHeap(tree->left);
            bool right = _isHeap(tree->right);
            bool flag = tree->data > tree->left->data && tree->data > tree->right->data;
            return flag && left && right;
        }
    }
        bool isHeap(struct tree* tree) {
            if(_isCBT(tree,0,_countNodes(tree))){
                cout << "here";
                if(_isHeap(tree))
                    return true;
                else 
                    return false;
            }else{
                return false;
            }
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
//	tree **arr = new tree*[n];		
//	int i = 0;
//	inorderArray(t2,arr,0,i,n);
//	bubbleSort(arr,n);
//	tree *final_root = fixTree(arr, n);
//	cout << "inorder to confirm" << endl;
//	inorderPrint(final_root);	
	for(int i=0;i<n;i++)
	funn(t1);
//	func(t1);
//	isHeap(t1);
	inorderPrint(t1);
}
