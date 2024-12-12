#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*head,*temp,*newnode;


void push(){
    newnode=malloc(sizeof(struct node));
    printf("enter your data:");
    scanf("%d",&newnode->data);
    if(head==NULL){
        head=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}

void pop(){
    if(head==NULL){
        printf("stack underflow");
   }
   else{
        temp=head;
        head=temp->next;
        printf("the popped element is %d",temp->data);
        free(temp);
   }
}

void peek(){
    if(head==NULL){
        printf("underflow");
    }
    else{
        printf("top element is %d",head->data);
    }
}

void display(){
    if(head==NULL){
        printf("underflow");
    } 
    else{
        temp=head;
        printf("the elements are:");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");   
    }
}

void main(){
    int ch=1,op;
    head=NULL;
    while(ch){
        printf("specify which operation you want to perform:\n 1.Push\n 2.Pop\n 3.Peek \n 4.Display \n5.stop\n");
        scanf("%d",&op);
        switch(op){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            case 5:
            ch=0;
            break;
            default:
            printf("selection cheyyan ariyille poi vaazha vekk!");
        }
    }
    
}