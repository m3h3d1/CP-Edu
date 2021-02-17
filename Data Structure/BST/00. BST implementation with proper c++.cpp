#include<iostream>
using namespace std;

class Node {
	int  key;
	Node* left, *right, *parent;
public:
	Node() {
		key=1;
		left = right = parent = NULL;
	};
	void setKey(int aKey) { key = aKey; };
	void setLeft(Node* aLeft) { left = aLeft; };
	void setRight(Node* aRight) { right = aRight; };
	void setParent(Node* aParent) { parent = aParent; };
	int Key() {return key; };
	Node* Left() { return left; };
	Node* Right() { return right; };
	Node* Parent() { return parent; };
};

class bstree {
	Node *root;
public:
	bstree();
	~bstree();
	Node* Root() { return root; };
	void addNode(int key);
	Node* findNode(int key, Node* parent);
	void preorder(Node* node);
	void inorder(Node* node);
	void postorder(Node* node);

	Node* deleteNode(Node* root, int key);
	Node* min(Node* node);
	Node* max(Node* node);
	Node* successor(int key, Node* parent);
	Node* predecessor(int key, Node* parent);
private:
	void addNode(int key, Node* leaf);
	void freeNode(Node* leaf);
};

//constructor
bstree::bstree() {
	root = NULL;
}

//destructor
bstree::~bstree() {
	cout<<"Tree pointer deleted\n";
	freeNode(root);
}

//free the node
void bstree::freeNode(Node* leaf) {
	if(leaf != NULL) {
		freeNode(leaf->Left());
		freeNode(leaf->Right());
		free(leaf);
	}
}

//add a node
void bstree::addNode(int key) {
	//no elements. add the root
	if(root == NULL) {
		Node* n = new Node();
		n->setKey(key);
		root = n;
	} else {
		addNode(key,root);
	}
}

//add a node (private)
void bstree::addNode(int key, Node* leaf) {
	if(key <= leaf->Key()) {
		if(leaf->Left() != NULL) {
			addNode(key, leaf->Left());
		} else {
			Node* n=new Node();
			n->setKey(key);
			n->setParent(leaf);
			leaf->setLeft(n);
		}
	} else {
		if(leaf->Right() != NULL) {
			addNode(key, leaf->Right());
		} else {
			Node* n=new Node();
			n->setKey(key);
			n->setParent(leaf);
			leaf->setRight(n);
		}
	}
}

//Print the tree from left, to root, to right sub-trees
void bstree::inorder(Node* node)
{
	if (node) //Print as long as node is not null
	{
		inorder(node->Left());
		cout << node->Key() << " ";
		inorder(node->Right());
	}
}

//print the BSTree
//root->left->right subtrees
void bstree::preorder(Node* node) {
	if(node) { //print as long as node is not NULL
		cout<<node->Key()<<" ";
		preorder(node->Left());
		preorder(node->Right());
	}
}

//Print the tree from left, to right, to root sub-trees
void bstree::postorder(Node* node)
{
	if (node) //Print as long as node is not null
	{
		postorder(node->Left());
		postorder(node->Right());
		cout << node->Key() << " ";
	}
}

// Find a node
Node* bstree::findNode(int key, Node* node) {
	if (node != nullptr) {
		if (key == node->Key()) return node; //Once key == Key() return node pointer
		if (key < node->Key()) return findNode(key, node->Left());//if key is less than Key() traverse left
		else return findNode(key, node->Right()); //if key is greater than Key() traverse right	
	}
	else return node; //return nullptr if tree Node is null
}

// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
Node* bstree::min(Node* node) {
    Node* tempNode = node;
    if(node == nullptr) tempNode = nullptr;
    else if (node->Left()) tempNode = min(node->Left());
    else tempNode = node;

    return tempNode;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
Node* bstree::max(Node* node)
{
    Node * tempNode = node;
    if(node == nullptr) tempNode = nullptr;
    else if(node->Right()) tempNode = max(node->Right());
    else tempNode = node;
 
    return tempNode;
}

// Find successor to a node
// Find the node, get the node with max value
// for the right sub-BSTree to get the successor
Node* bstree::successor(int key, Node *node) {
    Node* thisKey = findNode(key, node);
    if(thisKey) return max(thisKey->Right());

    return thisKey;
}

// Find predecessor to a node
// Find the node, get the node with max value
// for the left sub-BSTree to get the predecessor
Node* bstree::predecessor(int key, Node *node) {
    Node* thisKey = findNode(key, node);
    if(thisKey) return max(thisKey->Left());
    return thisKey; //Changed from nullptr to thisKey so that the proper value is returned
}

Node* bstree::deleteNode(Node* root,int key) {
    /* Given a binary search tree and a key, this function deletes the key
     and returns the new root */
    
    // base case
    if (root == nullptr) return root;
    
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->Key()) root->setLeft(deleteNode(root->Left(), key));

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->Key()) root->setRight(deleteNode(root->Right(), key));
    
    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->Left() == NULL) {
            Node *temp = root->Right();
            free(root);
            return temp;
        }
        else if (root->Right() == NULL) {
            Node *temp = root->Left();
            free(root);
            return temp;
        }
        
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node* temp = min(root->Right());
        
        // Copy the inorder successor's content to this node
        root->setKey(temp->Key());
        
        // Delete the inorder successor
        root->setRight(deleteNode(root->Right(), temp->Key()));
    }
    return root;
}

int main() {
	bstree* tree = new bstree();

	//add elements to the BST
	tree->addNode(55);
	tree->addNode(40);
	tree->addNode(80);
	tree->addNode(34);
	tree->addNode(28);
	tree->addNode(38);
	tree->addNode(60);
	tree->addNode(90);

	//preorder print
	cout<<"preorder print: \n";
	tree->preorder(tree->Root()); cout<<endl;
	//inorder print
	cout<<"\ninorder print: \n";
	tree->inorder(tree->Root()); cout<<endl;
	//postorder print
	cout<<"\npostorder print: \n";
	tree->postorder(tree->Root()); cout<<endl<<endl;
	
	//Allocate memory for a new Node
	Node* temp = new Node;

	int key = 100; //Key element used for member functions

	//Use temp node pointer for return node from the member function
	//if temp == nullptr, node not found; else found
	temp = tree->findNode(key, tree->Root());
	cout << "Node " << key;
	if (temp == NULL) cout <<"not found.\n";
	else cout << " found.\n";

	key = 34;
	temp = tree->findNode(key, tree->Root());
	cout << "Node " << key;
	if (temp == nullptr) cout << " not found.\n";
	else cout << " found.\n";

	temp = tree->min(tree->Root()); //Find minimum 
	cout << "Min = " << temp->Key() << endl; //Use temp node to display current Key, which is the minimum node
	temp = tree->max(tree->Root()); //Find maximum
	cout << "Max = " << temp->Key() << endl; //Use temp node to display current Key, which is the maximum node

	temp = tree->successor(key, tree->Root()); //Find successor
	if (temp != nullptr) //if temp is not nullptr, then a successor was found
		cout << "\nSuccessor to " << key << " = " << temp->Key() << endl; //Display successor node
	else
		cout << "No successor to " << key << endl; //If pointer is nullptr, then no successor exists

	temp = tree->predecessor(key, tree->Root()); //Find predecessor
	if (temp != nullptr) //if temp is not nullptr, then a predecessor was found
		cout << "Predecessor to " << key << " = " << temp->Key() << endl; //Display predecessor
	else
		cout << "No predecessor to " << key << endl; //If pointer is nullptr, then no predecessor exists

	//Delete a node from the tree
	cout << "\nDeleting 300\n";
	tree->deleteNode(tree->Root(), key);

	//Print preorder after deleting node 300
	cout << "\nPreorder print: \n";
	tree->preorder(tree->Root());
	cout << endl;

	//Print postorder after deleting node 300
	cout << "\nPostorder print: \n";
	tree->postorder(tree->Root());
	cout << endl;

	//Delete tree pointer
	cout << "\nDeleting entire tree pointer\n";
	delete tree;


	cin.get(); //Pause the program
	return 0;
}

/*
https://github.com/moorStef/BST-HW8/

               55
              /  \
             40  80
            /   /  \
           34  60  90
          /  \
         28  38
*/