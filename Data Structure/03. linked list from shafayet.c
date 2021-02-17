#include<stdio.h>
struct node{
    int roll;
    node *next;
};
node *root=NULL;
void append(int roll){
    if(root==NULL){ //If the list is empty
        root=new node(); //create new node in root
        root->roll=roll;
        root->next=NULL;
    }
    else{
        node *current_node=root; //make a copy of root node
        while(current_node->next!=NULL){ //Find the last node
            current_node=current_node->next; //go to next address
        }
        node *newnode=new node(); //go to next address
        newnode->roll=roll;
        newnode->next=NULL;
        current_node->next=newnode; //link the last node with new node
    }
}
void delete_node(int roll){
    node *current_node=root;
    node *previous_node=NULL;
    while(current_node->roll!=roll){ //Searching node
        previous_node=current_node; //Save the previous node
        current_node=current_node->next;
    }
    if(current_node==root){ //Delete root
        node *temp=root; //save root in temporary variable
        root=root->next; //move root forward
        delete(temp); //free memory
    }
    else{
        previous_node->next=current_node->next; //previous node points the current node's next node
        delete(current_node); //free current node
    }

}
void print(){
    node *current_node=root;
    while(current_node!=NULL){ //loop until you reach null
        printf("%d ",current_node->roll);
        current_node=current_node->next;
    }
    printf("\n");
}
int main(){
    long long a[5];
    append(1);
    append(2);
    append(6);
    print();
    delete_node(2);
    print();
    return 0;
}