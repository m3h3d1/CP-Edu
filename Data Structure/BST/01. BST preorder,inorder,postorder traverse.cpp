#include<iostream>
using namespace std;
struct Node {
	int data;
	struct Node *left, *right;
};
struct Node *root;

void insert(int val) {
	struct Node *newnode = new Node;
	newnode->data = val;
	newnode->left = newnode->right = NULL;
	if(root == NULL) {
		root = newnode;
	} else {
		struct Node *temp = root;
		while(1) {
			if(newnode->data <= temp->data) {
				//left
				if(temp->left == NULL) {
					temp->left = newnode;
					break;
				} else {
					temp = temp->left;
				}
			} else {
				//right
				if(temp->right == NULL) {
					temp->right = newnode;
					break;
				} else {
					temp = temp->right;
				}
			}
		}
	}
}
void preorder(struct Node *r) {
	//root left right
	if(r == NULL) return;
	cout<<r->data<<" "; //print root
	preorder(r->left); //left subtree visit
	preorder(r->right); //right subtree visit
}
void inorder(struct Node *r) {
	//left root right
	if(r == NULL) return;
	inorder(r->left);
	cout<<r->data<<" ";
	inorder(r->right);
}
void postorder(struct Node *r) {
	//left right root
	if(r == NULL) return;
	postorder(r->left);
	postorder(r->right);
	cout<<r->data<<" ";
}
int main() {
	root = NULL;
	insert(55);
	insert(40);
	insert(80);
	insert(34);
	insert(28);
	insert(38);
	insert(60);
	insert(90);

	cout<<"preorder:  "; preorder(root); cout<<endl;
	cout<<"inorder:   "; inorder(root); cout<<endl;
	cout<<"postorder: "; postorder(root); cout<<endl;
	return 0;
}

/*
             55
            /  \
           40  80
          /   /  \
         34  60  90
        /  \
       28  38
*/