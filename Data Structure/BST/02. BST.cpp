#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* left, *right;
};
struct Node* root;

class BST {
public:
	BST() {
		root = NULL;
	}
	~BST() {
		cout<<"Tree pointer deleted\n";
		freeNode(root);
	}
	void freeNode(Node* temp) {
		if(temp != NULL) {
			freeNode(temp->left);
			freeNode(temp->right);
			free (temp);
			//printf("%d\n",temp->data);
		}
	}
	Node* createNode(int x) {
		Node* n = new Node;
		n->data = x;
		n->left = n->right = NULL;
		return n;
	}
	void insert(int key) {
		if(root == NULL) root = createNode(key);
		else insert(root,key);
	}
	void insert(Node* temp, int key) {
		if(key <= temp->data) { //left
			if(temp->left == NULL) temp->left = createNode(key);
			else insert(temp->left, key);
		}
		else { //right
			if(temp->right == NULL) temp->right = createNode(key);
			else insert(temp->right, key);
		}
	}
	void inorder(Node* temp) {
		if(temp == NULL) return;
		inorder(temp->left);
		cout<<temp->data<<" ";
		inorder(temp->right);
	}
	Node* search(Node* r, int key) {
		if(r == NULL) return NULL;
		if(r->data == key) return r;
		else if(key < r->data) return search(r->left, key);
		else return search(r->right, key);
	}
};

int main() {
	BST b;

	int arr[] = {55,40,80,34,28,38,60,90};
	for(int x: arr) b.insert(x);

	b.inorder(root); cout<<endl;

	if(b.search(root,34)) cout<<"found"<<endl;
	else cout<<"not found"<<endl;
	if(b.search(root,35)) cout<<"found"<<endl;
	else cout<<"not found"<<endl;
	return 0;
}