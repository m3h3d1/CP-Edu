#include<stdio.h>
#include<stdlib.h>
#define MAX 30

typedef struct pqueue{
	int data[MAX];
	int rear,front;
} pqueue;

void initialize(pqueue *p){
	p->rear=-1;
	p->front=-1;
}
int full(pqueue *p){
	return (p->rear+1)%MAX==p->front;
}
int empty(pqueue *p){
	return p->rear==-1;
}
void enqueue(pqueue *p, int x){
	int i;
	if(full(p)) printf("\nOverflow");
	else{
		if(empty(p)){
			p->rear=p->front=0;
			p->data[0]=x;
		}
		else{
			i=p->rear;
			while(x>p->data[i]){
				p->data[(i+1)%MAX]=p->data[i];
				i=(i-1+MAX)%MAX;
				if((i+1)%MAX==p->front) break;
			}

			//insert x
			i=(i+1)%MAX;
			p->data[i]=x;

			//re-adjust rear
			p->rear=(p->rear+1)%MAX;
		}
	}	
}
int dequeue(pqueue *p){
	int x;
	if(empty(p)) printf("\nUnderflow..");
	else{
		x=p->data[p->front];
		if(p->rear==p->front) //delete the last element
			initialize(p);
		else
			p->front=(p->front+1)%MAX;
	}
	return x;
}
void print(pqueue *p){
	int i,x;
	if(empty(p))
		printf("\nQueue is empty..");
	else{
		i=p->front;
		while(i!=p->rear){
			x=p->data[i];
			printf("%d ",x);
			i=(i+1)%MAX;
		}

		//prints the last element
		x=p->data[i];
		printf("%d\n",x);
	}
}

int main(){
	int x,op,n,i;
	pqueue q;
	initialize(&q);
	do{
		printf("\n1. Create\n2. Insert\n3. Delete\n4. Print\n5. Exit");
		printf("\nEnter Choice: ");
		scanf("%d",&op);
		switch(op){
			case 1: printf("\nEnter number of elements: ");
					scanf("%d",&n);
					initialize(&q);
					printf("\nEnter the data: ");
					for(i=0;i<n;i++){
						scanf("%d",&x);
						if(full(&q)){
							printf("\nQueue is full..");
							exit(0);
						}
						enqueue(&q,x);

					}
					break;
			case 2: printf("\nEnter the element to be inserted: ");
					scanf("%d",&x);
					if(full(&q)){
						printf("\nQueue is full");
						exit(0);
					}
					enqueue(&q,x);
					break;
			case 3: if(empty(&q)){
						printf("\nQueue is empty..");
						exit(0);
					}
					x=dequeue(&q);
					printf("\nDeleted element=%d",x);
					break;
			case 4: print(&q);
					break;
			default:break;
		}
	} while(op!=5);
}