#include<iostream>
using namespace std;
class TreeNode { 
	public:	
	int key;
	string name;
	TreeNode *left;
	TreeNode *right; 
	TreeNode(int key, string name) {
	this->key = key;
	this->name = name;
	left = NULL;
	right = NULL;
	}
};
bool solve(TreeNode *root,int min,int max){
	if(root == NULL)
		return true;
	if(root->key < max && root->key > min){
		bool left = solve(root->left , min,root->key);
		bool right = solve(root->right,root->key,max);
		return left && right;
	}else
		return false;
}
bool isBST(TreeNode *root){
	return solve(root,-999999,999999);
}
int main(){
	TreeNode *root = new TreeNode(10,"abc");
	root->left = new TreeNode(5,"abcc");
	root->right = new TreeNode(9,"abcde");
	cout << isBST(root) << endl;
}
