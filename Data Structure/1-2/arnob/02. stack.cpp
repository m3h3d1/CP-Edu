#include<cstdio>
#include<cstdlib>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* head;
public:
    Stack();
    void Push(int x);
    void Pop();
    void Peek();
    void Display();
    void Mid();
    bool Empty();
};

Stack::Stack() {
    head=NULL;
}

void Stack::Push(int x) {
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=x;
    temp->next=head;
    head=temp;
}

bool Stack::Empty() {
    return (head==NULL);
}

void Stack::Pop() {
    if(head==NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    Node* temp=head;
    head=head->next;
    printf("%d is popped from the stack\n",temp->data);
    free(temp);
}

void Stack::Peek() {
    if(head==NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Item at top of the stack is %d\n",head->data);
}

void Stack::Display() {
    Node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void Stack::Mid() {
    Node* temp1=head;
    Node* temp2=head;
    while(1)
    {
        if(temp2==NULL || temp2->next==NULL)
        {
            printf("Mid element is %d\n",temp1->data);
            return;
        }
        if(temp2->next!=NULL)
        {
            temp2=temp2->next->next;
        }
        temp1=temp1->next;
    }
}

int main() {
    Stack S;
    S.Push(16);
    S.Push(18);
    S.Push(11);
    S.Push(30);
    S.Push(50);
    S.Display();
    S.Mid();
    while(!S.Empty())
    {
        S.Peek();
        S.Pop();
    }
    return 0;
}