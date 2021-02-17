//create binary tree
//search in a binary search tree
//binary search tree te data insert kora
#include<iostream>
using namespace std;
struct node {
	int data;
	struct node *left,*right;
};

struct node* newNode(int data) {
	//node* node=new node;
	struct node* node=(struct node*) malloc(sizeof(struct node));
	node->data=data;
	node->left=node->right=NULL;
	return (node);
}

struct node* search(struct node* root,int key) {
	//base case: root is NULL or key is present at root
	if(root==NULL || root->data==key) return root;
	//Key is greater than root's key
	if(root->data<key) return search(root->right,key);
	//key is smaller than root's key
	return search(root->left,key);
}
int main() {
	struct node *root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);

	// struct node *x;
	// x=seach(x,3);
	return 0;
}