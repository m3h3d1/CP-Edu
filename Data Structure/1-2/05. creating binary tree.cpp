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

int main() {
	struct node *root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	return 0;
}