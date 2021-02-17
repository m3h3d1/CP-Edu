#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class Queue {
    Node* Front, *Rear;
public:
    Queue();
    void Push(int x);
    void Pop();
    void Peek();
    void Display();
    bool Empty();
};
Queue::Queue() {
    Front=NULL;
    Rear=NULL;
}
void Queue::Push(int x) {
    Node* temp=new Node;
    temp->data=x;
    temp->next=NULL;
    if(Front==NULL) {
        Front=Rear=temp;
    }
    else {
        Rear->next=temp; //*
        Rear=temp; //*
    }
}
bool Queue::Empty() {
    return (Front==NULL);
}
void Queue::Pop() {
    if(Front==NULL) {
        cout<<"Queue is empty"<<endl;
        return;
    }
    Node* temp=Front;
    Front=Front->next; //*
    cout<<temp->data<<" is popped from the queue\n";
    free(temp);
}
void Queue::Peek() {
    if(Front==NULL) {
        cout<<"Queue is empty\n";
        return;
    }
    cout<<"Item at top of the queue is "<<Front->data<<endl;
}
void Queue::Display() {
    //write, if(front=null) print:queue is empty
    Node* temp=Front;
    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main() {
    Queue q;
    q.Push(16);
    q.Push(18);
    q.Push(11);
    q.Push(30);
    q.Push(60);
    q.Display();
    while(!q.Empty()) {
        q.Peek();
        q.Pop();
    }
    return 0;
}