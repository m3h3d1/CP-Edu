#include<iostream>
using namespace std;

class node {
public:
	int value;
	node *next;
};

class list {
private:
	node *head,*tail;
public:
	list();
	~list();
	void pushback(int val);
	void display();
	void pushfront(int val);
	void insertt(int pos,int val);
	void popback();
	void popfront();
	void deletee(int pos);
};
list::list() {
	head=NULL;
	tail=NULL;
}
list::~list() {
	// node* cur=NULL;
	// node* next=head;
	// while(next!=NULL) {
	// 	cur=next;
	// 	next=next->next;
	// 	delete cur;
	// }
	cout<<"List Deleted\n";
}

void list::pushback(int val) {
	node *cur=new node;
	cur->value=val;
	cur->next=NULL;
	if(head==NULL) {
		head=cur;
		tail=cur;
	}
	else {
		tail->next=cur;
		tail=cur;
	}
}

void list::display() {
	node *cur=new node;
	cur=head;
	while(cur != NULL) {
		cout<<cur->value<<" ";
		cur=cur->next;
	}
	cout<<'\n';
}

void list::pushfront(int val) {
	node *cur=new node;
	cur->value=val;
	cur->next=head;
	head=cur;
}

void list::insertt(int pos,int val) {
	node *pre=new node;
	node *cur=new node;
	node *temp=new node;
	cur=head;
	for(int i=1;i<pos;++i) { //1 based index
		pre=cur;
		cur=cur->next;
	}
	temp->value=val;
	pre->next=temp;
	temp->next=cur;
}

void list::popback() {
	node *pre=new node;
	node *cur=new node;
	cur = head;
	while(cur->next != NULL) {
		pre=cur;
		cur=cur->next;
	}
	tail=pre;
	pre->next=NULL;
	delete cur;
}

void list::popfront() {
	node *cur=new node;
	cur=head;
	head=head->next;
	delete cur;
}

void list::deletee(int pos) {
	node *pre=new node;
	node *cur=new node;
	cur=head;
	for(int i=1;i<pos;++i) {
		pre=cur;
		cur=cur->next;
	}
	pre->next=cur->next;
}

int main() {
	list *a=new list();
	a->pushback(25);
	a->pushback(50);
	a->pushback(90);
	a->pushback(40);
	a->display();

	a->pushfront(10);
	a->pushfront(20);
	a->display();

	a->insertt(5,60);
	a->display();

	a->popback();
	a->display();

	a->popfront();
	a->display();

	a->deletee(4);
	a->display();

	delete a;
	return 0;
}