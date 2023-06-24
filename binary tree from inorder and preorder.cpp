#include<iostream>
using namespace std;
struct treeNode{
	int val;
	treeNode *left;
	treeNode *right;
	treeNode(int val){
		this->val = val;
		left = right = NULL;
	}
	treeNode(){
		left = right = NULL;
	}
};
treeNode *solve(int pre[],int &it , int end){
	if(it >= end)
		return NULL;
	int element = pre[it++];
	treeNode *root = new treeNode(element);
	root->left = solve(pre,it,end);
	root->right = solve(pre,it,end);
	return root;	

}
treeNode * treeFromPreorder(int pre[],int n){
	int i = 0;
	treeNode *root = solve(pre,i,n);
	return root;
}
void preorder(treeNode *root){
	if(root == NULL)
		return;
	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);	
	
}
int findPos(int arr[],int n , int ele){
	for(int i = 0 ; i < n ; i++){
		if(arr[i] == ele)
			return i;
	}
	return -1;
}
treeNode *solve2(int postArr[],int &it ,int inArr[],int inStart,int inEnd,int inSize){
	if(inStart > inEnd || it < 0)
		return NULL;
	int element = postArr[it--];
	int inPos = findPos(inArr , inSize,element);
	treeNode *root = new treeNode(element);
	root->right = solve2(postArr,it,inArr,inPos+1,inEnd,inSize);
	root->left = solve2(postArr,it,inArr,inStart,inPos-1,inSize);
	return root;		
}
treeNode * treeFromInorderAndPreorder(int postArr[],int n,int inArr[],int m){
	int i = n-1;
	treeNode *root = solve2(postArr,i,inArr,0,m-1,m);
	return root;
}
int main(){
	int preArr[5] = {3,9,20,15,7};
	int inArr[5] = {9,3,15,20,7};
	int postArr[5] = {9,15,7,20,3};
	treeNode *root = treeFromPreorder(preArr,5);
	preorder(root);
	cout << endl;
	treeNode *root2 = treeFromInorderAndPreorder(postArr,5,inArr,5);
	preorder(root2);
	cout << endl;
}
