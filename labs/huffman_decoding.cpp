#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct node {
	int freq;
    char data;
    node * left;
    node * right;
    
};
struct deref:public binary_function<node*, node*, bool> {
  	bool operator()(const node * a, const node * b)const {
        return a->freq > b->freq;
    }
};

typedef priority_queue<node *, vector<node*>, deref> spq;

node * huffman_tree(string s) {

    spq pq;
    vector<int>count(256,0);
  
    for(int i = 0; i < s.length(); i++ ) {
        count[s[i]]++;
    }
    
    for(int i=0; i < 256; i++) {
        
        node * n_node = new node;
        n_node->left = NULL;
        n_node->right = NULL;
        n_node->data = (char)i;
        n_node->freq = count[i];
      
        if( count[i] != 0 )
        	pq.push(n_node);
      
    }
    
    while( pq.size() != 1 ) {
      
        node * left = pq.top();
        pq.pop();
        node * right = pq.top();
        pq.pop();
        node * comb = new node;
        comb->freq = left->freq + right->freq;
        comb->data = '\0';
        comb->left = left;
        comb->right = right;
        pq.push(comb);
      
    }
    
    return pq.top();
    
}

void print_codes(node * root, string code, map<char, string>&mp) {
    
  	if(root == NULL)
        return;
    
  	if(root->data != '\0') {
        mp[root->data] = code;
    }
  
    print_codes(root->left, code+'0', mp);
    print_codes(root->right, code+'1', mp);
        
}

bool printLeaf(node *r){
    if(r == NULL)
        return false;
    if(r->left == NULL && r->right == NULL){
        cout << r->data;
        return true;
    }
    return false;
}
void decode_huff(node * root, string s) {
    node *temp = root;
    for(char c : s){
        if(c == '1')
            temp = temp->right;
        else
            temp = temp->left;
        if(printLeaf(temp))
            temp = root;    
    }
}
void inorder(node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout << root->freq << " " << root->data << endl;
	inorder(root->right);	
}
int main(){
	string s = "ABRACADABRA";
	node *tree = huffman_tree(s);
	string code = "";
    map<char, string>mp;  
    print_codes(tree, code, mp);    
    string binarycode;  
    for( int i = 0; i < s.length(); i++ ) {
        binarycode += mp[s[i]];
    }
    cout << binarycode << endl;
	decode_huff(tree,binarycode);
//	inorder(tree);
}
