#include<cstdio>
#include<cstdlib>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

class Queue
{
    Node* Front;
    Node* Rear;
public:
    Queue();
    void Push(int x);
    void Pop();
    void Peek();
    void Display();
    bool Empty();
};

Queue::Queue()
{
    Front=NULL;
    Rear=NULL;
}

void Queue::Push(int x)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=x;
    temp->next=NULL;
    if(Front==NULL)
    {
        Front=Rear=temp;
    }
    else
    {
        Rear->next=temp;
        Rear=temp;
    }
}

bool Queue::Empty()
{
    return (Front==NULL);
}

void Queue::Pop()
{
    if(Front==NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    Node* temp=Front;
    Front=Front->next;
    printf("%d is popped from the queue\n",temp->data);
    free(temp);
}

void Queue::Peek()
{
    if(Front==NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Item at top of the queue is %d\n",Front->data);
}

void Queue::Display()
{
    Node* temp=Front;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    Queue Q;
    Q.Push(16);
    Q.Push(18);
    Q.Push(11);
    Q.Push(30);
    Q.Push(50);
    Q.Display();
    while(!Q.Empty())
    {
        Q.Peek();
        Q.Pop();
    }
    return 0;
}