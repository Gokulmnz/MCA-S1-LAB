#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*head,*temp,*newnode;
void printlist(){
    if(head==NULL){
        printf("Underflow");
    }
    else{
        temp=head;
        printf("Elements are:");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
void enqueue(){
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the element to be inserted: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        temp=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        temp=newnode;
    }
}
void dequeue(){
    if(head==NULL){
        printf("Underflow");
    }
    else{
        printf("Dequeued element is=%d",head->data);
        temp=head;
        head=head->next;
        free(temp);
    }  
}
void peek(){
    if(head==NULL){
        printf("Underflow");
    }
    else{
        printf("The top element is: %d",head->data);
    }
}
void display(){
    printlist();
}
void main(){
    int choice,c=1;
    head=NULL;
    while(c){
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Which operation do you want:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            case 5:
            c=0;
            break;
            default:
            printf("Invalid choice");
            break;
        }
    }
}