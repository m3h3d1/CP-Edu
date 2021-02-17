#include <iostream>
using namespace std;
// Constants
#define max 20

// Functions
int menu();

// Stack functions
void enqueue();
void dequeue();
int front();
bool isFull();
bool isEmpty();

// Variables
int queue[max];
int frontElement = 0;
int rearElement = 0;

int main(int argc, const char * argv[]) {
    
    int choice;
    
    do {
        choice = menu();
        
        switch(choice) {
            case 1: enqueue();
                break;
            case 2: dequeue();
                break;
            case 3: front();
                break;
            case 4: isFull();
                break;
            case 5: isEmpty();
                break;
            case -1:
                choice = -1;
                break;
                
            default: printf("\nEnter a valid choice!!");
        }
    } while(choice != -1);
}

int menu() {
    int ch;
    printf("\nQueue");
    printf("\n1.Enqueue\n2.Dequeue\n3.Front element\n4.Is Full\n5.Is Empty\n6.Exit");
    printf("\nEnter your Choice:");
    scanf("%d",&ch);
    return ch;
}

void enqueue() {
    if(rearElement == max) {
        printf("\nOverflow");
        
    } else {
        int element;
        printf("\nEnter Element:");
        scanf("%d",&element);
        printf("\nElement(%d) has been pushed at %d", element, rearElement);
        queue[rearElement] = element;
        rearElement++;
    }
}

void dequeue() {
    if(rearElement == 0) {
        printf("Queue is empty.");
        
    } else {
        if(frontElement == rearElement)
        {
            frontElement = 0;
            rearElement = 0;
        }
        
        printf("Dequeued element is %d", queue[frontElement]);
        frontElement ++;
    }
}

int front() {
    printf("\nTop number is %d", queue[frontElement]);
    return queue[frontElement];
}

bool isFull() {
    if(rearElement == max -1) {
        printf("\n%d", true);
        return true;
        
    } else {
        printf("\n%d", false);
        return false;
    }
}

bool isEmpty() {
    if(rearElement == 0) {
        printf("\n%d", true);
        return true;
        
    } else {
        printf("\n%d", false);
        return false;
    }
}