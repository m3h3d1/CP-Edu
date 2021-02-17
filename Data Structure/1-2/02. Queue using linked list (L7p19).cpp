#include<iostream>
using namespace std;
struct Node {
	int data;
	struct Node *next;
} *front=NULL,*rear=NULL;

void insert(int val) {
	struct Node *newNode;
	newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=val;
	newNode->next=NULL;
	if(front==NULL) front=rear=newNode;
	else {
		rear->next=newNode;
		rear=newNode;
	}
	cout<<"\nInsertion is success!!!\n";
}
void delet() {
	if(front==NULL) cout<<"\nQueue is empty!!!\n";
	else {
		struct Node *temp=front;
		front=front->next;
		cout<<"\nDeleted element: "<<temp->data<<endl;
		free(temp);
	}
}
void display() {
	if(front==NULL) cout<<"\nQueue is empty!!!\n";
	else {
		struct Node *temp=front;
		while(temp->next!=NULL) {
			cout<<temp->data<<"--->";
			temp=temp->next;
		}
		cout<<temp->data<<"--->NULL\n";
	}
}

int main() {
	int choice,val;
	cout<<"\n:: Queue Implementation using Linked List ::\n";
	while(1) {
		cout<<"\n*****MENU*****\n";
		cout<<"1. Insert\n2. Delete\n3. Display\n4. Exit\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice) {
			case 1: cout<<"Enter the value to be inserted: ";
					cin>>val;
					insert(val);
					break;
			case 2: delet(); break;
			case 3: display(); break;
			case 4: exit(0);
			default:cout<<"Wrong selection!!! Please try again!!!\n";
		}
	}
	return 0;
}