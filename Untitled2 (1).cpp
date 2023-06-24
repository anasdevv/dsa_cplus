#include<iostream>
using namespace std;
struct TreeNode { 
	int key;
	TreeNode *left;
	TreeNode *right; 
	TreeNode(int key) {
	this->key = key;
	left = NULL;
	right = NULL;
	}
};
class BinaryTree{
	TreeNode *root;
	TreeNode *insert(int val,TreeNode *root){
		if(root == NULL){
			return new TreeNode(val);
		}
		if(val > root->key)
			root->right = insert(val,root->right);
		if(val < root->key)
			root->left = insert(val,root->left);
		return root;
	}
	void print(TreeNode *root){
		if(root == NULL)
			return;
		print(root->left);
		cout << root->key << " ";
		print(root->right);	
	}
	void print2(TreeNode *root){
		if(root == NULL)
			return;
		cout << root->key << " ";
		print2(root->left);
		print2(root->right);
	}
	public:
		BinaryTree(int key){
			TreeNode *temp = new TreeNode(key);
			root = temp;
		}
		void addNode(int val){
			insert(val,root);
		}
		void inorder(){
			print(root);
		}
		void preorder(){
			print2(root);
		}
		
};
int main(){
	BinaryTree tree(10);
	tree.addNode(5);
	tree.addNode(7);
	tree.addNode(15);
	tree.addNode(20);
	tree.addNode(1);
	tree.inorder();
}
