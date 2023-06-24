#include<iostream>
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
int _countNodes(tree *tree){
      if(tree == NULL)
        return 0;
    return 1+_countNodes(tree->left) + _countNodes(tree->right);
  }
  bool _isCBT(tree *root,int i , int n){
      if(i > n)
        return false;
    return _isCBT(root->left,i*2+1,n);
    return _isCBT(root->right,i*2+2,n);
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
	isHeap(t1);

  }      
