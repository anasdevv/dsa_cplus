#include <iostream>
using namespace std;
template<class T> 
class Set /* binary search tree */
{
private:
	struct treeNode
	{
		treeNode* left;
		treeNode* right;
		T data;
		treeNode(){
			left = right = NULL;
		}
	};
	treeNode* root;
public:
	int i;
	Set(){
		root = NULL;
		i = 0;
	}
	bool isEmpty() const {
	 return (root==NULL); 
	 }
	void print();
	void inorder(treeNode*);
	void insert(T);
	void remove(T);
	bool search(T);
	~Set(){
		delete root;
	}
	int noOfElements();
	int countNodes(treeNode *root);
};
template <class T>
int Set<T>::noOfElements(){
	return i;
}
template <class T>
void Set<T>::insert(T val)
{
	treeNode* temp = new treeNode;
	treeNode* parent;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	parent = NULL;
	if(isEmpty()) {
		root = temp;
		i++;
		return;
		}
	else{
		treeNode* current;
		current = root;
		// Find the Node's parent
		while(current){
			parent = current;
			if(temp->data == current->data)  /* if value is greater we will insert it on right or if it is smaller we will insert it on left*/
				return;
			if(temp->data > current->data) 
				 current = current->right;
			else
				 current = current->left;
		}

		if(temp->data < parent->data)
			parent->left = temp;
		else
			parent->right = temp;
		i++;	
	}
}
template <class T>
bool Set<T>::search(T val)
{
	bool found = false;
	if(isEmpty()){
		cout<<" This Tree is empty! "<<endl;
		return false;
	}
	treeNode* current;
	treeNode* parent;
	current = root;
	parent = NULL;
	while(current != NULL){
		if(current->data == val){
			found = true;
			break;
		}
		else{
			parent = current;
			if(val >current->data) /* if value is greater we will search right or if it is smaller we will search it on left*/
				 current = current->right;
			else 
				current = current->left;
		}
	}
	if(!found){
		cout<<" Data not found! "<<endl;
	}
	else{
		cout<<" Data found! "<<endl;
	}

	return found;
}

template <class T>
void Set<T>::remove(T val){
	bool found = false;
	if(isEmpty()){
		cout<<" This Tree is empty! "<<endl;
		return;
	}
	treeNode* current;
	treeNode* parent;
	current = root;
	parent = NULL;
	i--;
	while(current != NULL){
		if(current->data == val){
			found = true;
			break;
		}
		else{
			parent = current;
			if(val > current->data) 
				current = current->right;
			else
				 current = current->left;
		}
	}
	if(!found){
		cout<<" Data not found! "<<endl;
		i++;
		return;
	}

	// Node with single child
	if((current->left == NULL && current->right != NULL)|| (current->left != NULL
		&& current->right == NULL)){
		if(current->left == NULL && current->right != NULL){			
			if(parent->left == current){
				parent->left = current->right;
				delete current;
			}
			else{
				parent->right = current->right;
				delete current;
			}
		}
		else {  // only left child
			if(parent->left == current){
				parent->left = current->left;
				delete current;
			}
			else{
				parent->right = current->left;
				delete current;
			}
		}
		return;
	}

	//We're looking at a leaf node
	if( current->left == NULL && current->right == NULL){
		if (parent == NULL){
			delete current;
		}
		 else
			if(parent->left == current) 
				parent->left = NULL;
			else 
				parent->right = NULL;
		delete current;
			return;
	}


	//Node with 2 children
	// replace node with smallest value in right subtree because the smallest right value will be greater then largest left value
	if (current->left != NULL && current->right != NULL){
		treeNode* temp2;
		temp2 = current->right;
		if((temp2->left == NULL) && (temp2->right == NULL)){
			current = temp2;
			delete temp2;
			current->right = NULL;
		}
		else {                                                          
			if((current->right)->left != NULL){
				treeNode* leftCur;
				treeNode* leftCurP;
				leftCurP = current->right;
				leftCurP = (current->right)->left;
				while(leftCur->left != NULL){
					leftCurP = leftCur;
					leftCur = leftCur->left;
				}
				current->data = leftCur->data;
				delete leftCur;
				leftCurP->left = NULL;
			}
			else{
				treeNode* temp3;
				temp3 = current->right;
				current->data = temp3->data;
				current->right = temp3->right;
				delete temp3;
			}

		}
		return;
	}

}
template<class T>
void Set<T>::print()
{
	inorder(root);
}
template<class T>
void Set<T>::inorder(treeNode* p)
{
	if(p != NULL)
	{
		if(p->left) inorder(p->left);
		cout<<" "<<p->data<<" ";
		if(p->right) inorder(p->right);
	}
	else return;
}
template <class T>
Set<T> * createSet(){
	Set <T>*temp = new Set<T>;
	return temp;
}
int main(){
	Set<int> b;
//	 = {1,2,3,4,5};
	b.insert(1);
	b.insert(4);
	b.insert(5);
	b.insert(1);
	b.insert(2);
	b.insert(7);
	b.insert(8);
	b.insert(10);
	b.print();

//	after removing 5
	cout << "\nNumber Of Elements : " << b.noOfElements() << endl;
	cout << "\nAfter removing : 5" << endl;
	b.remove(5);
	b.print();
	cout << "\n\n";
	cout << "Number Of Elements : " << b.noOfElements() << endl;
	// dynamically created set
	cout << "\n\ndynamically created set" << endl;
	Set <int>*p;
	p = createSet<int>();
	p->insert(5);
	p->insert(7);
	p->insert(1);
	cout << "Number Of Elements : " << p->noOfElements() << endl;
	p->print();
	return 0;
	
}
