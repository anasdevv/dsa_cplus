#include<iostream>
#include<stack>
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
	TreeNode *delNode(TreeNode *root,int val){
		if(root == NULL)
			return NULL;
		else if(val > root->key){
			root->right = delNode(root->right , val); 
		}
		else if(val < root->key){
			root->left = delNode(root->left,val);
		}
		// node to be deleted is found
		else{
			if(root->left && root->right){
				TreeNode *temp = maxNode(root->left);
				root->key = temp->key;
				root->left = delNode(root->left,root->key);
			}else{
				TreeNode *temp = root;
				if(root->left == NULL){
					root = root->right;
				}
				else if(root->right == NULL){
					root = root->right;
				}
				delete temp;
			}
		}
		return root;
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
		void iterativePreorder(){
			stack<TreeNode*> st;
			st.push(root);
			while(!st.empty()){
				TreeNode *temp = st.top();
				cout << temp->key << " ";
				st.pop();
				if(temp->right)
					st.push(temp->right);
				if(temp->left)
					st.push(temp->left);
			}
		}
		TreeNode *maxNode(TreeNode *root){
			if(root->right == NULL)
				return root;
			return maxNode(root->right);
		}
		deleteNode(int val){
			root = delNode(root,val);
		}
		void delRange(int start,int end){
			for(int i = start ; i <= end ; i++){
				deleteNode(i);
			}
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
	cout << endl;
	tree.preorder();
	cout << endl;
//	tree.deleteNode(10);
	tree.delRange(10,15);
	tree.iterativePreorder();
	
}
