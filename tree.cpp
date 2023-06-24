#include<iostream>
using namespace std;
struct TreeNode{
	TreeNode *left;
	TreeNode *right;
	int val;
	TreeNode(){
		left = right = NULL;
	}
	TreeNode(int val){
		this->val = val;
		left = right = NULL;
	}
};
TreeNode *findMax(TreeNode *root){
	if(root == NULL)
		return NULL;
	if(root->left == NULL && root->right == NULL)
		return root;
	return findMax(root->right);
}
class BST{
	TreeNode *root;
	TreeNode * insert(TreeNode *root , int val){
		if(root == NULL)
			return new TreeNode(val);
		if(root->val > val)
			root->left = insert(root->left,val);
		else if(root->val < val)
			root->right = insert(root->right , val);
		else
			return root;
		int bf = getBF(root);
		if(bf > 1){ /* left skewed */
			if( root->left->val > val ){
				return rightRotate(root);
			}
			else{
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}
		}
		if(bf < -1){ /* left skewed */
			if( root->right->val > root->val ){
				return leftRotate(root);
			}
			else{
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}
		}
	}
	void inorder(TreeNode *root){
		if(root == NULL)
			return;
		inorder(root->left);
		cout << root->val << " ";
		inorder(root->right);
	}
	TreeNode *leftRotate(TreeNode *root){
		TreeNode *x = root->right;
		TreeNode *y = x->left;
		x->left = root;
		root->right = y;
		return x;
	}
	TreeNode *rightRotate(TreeNode *root){
		TreeNode *x = root->left
		TreeNode *y = x->right;
		x->right = root;
		root->left = y;
		return x;
	}
	TreeNode * del(TreeNode *root,int val){
		TreeNode *temp;
		if(root == NULL)
			return root;
		else if(root->val < val)
			root->right = del(root->right,val);
		else if(root->val > val)
			root->left = del(root->left,val);
		//node to be deleted is found
		else{
			//both child case
			if(!root->left && !root->right){
				return NULL;
			}
			else if(root->left && root->right){
				temp = findMax(root->left);
				root->val = temp->val;
				root->left = del(root->left,root->val);
			}
			//either child exist
			else{
				temp = root;
				if(root->left == NULL)
					root = root->right;
				if(root->right == NULL)
					root = root->left;
			}
//			delete temp;
		}
		return root;
	}
	public:
		BST(){
			root = NULL;
		}
		void insert(int val){
			root = insert(root,val);
		}
		void inorder(){
			inorder(this->root);
		}
		void remove(int val){
			this->root = del(root,val);
		}
};
int main(){
	BST tree;
	int arr[5] = {6,2,1,3,4};
	for(int i = 0 ; i < 5 ; i++)
		tree.insert(arr[i]);
//	tree.remove();
	tree.inorder();
}
