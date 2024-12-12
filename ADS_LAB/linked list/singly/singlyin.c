#include<stdio.h>
#include<stdlib.h>
int count=0;
struct node{
    int data;
    struct node *next;
}*temp,*head,*newnode;
void creation(){
    newnode = malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    count++;
}
void display(){
    if(head==NULL){
        printf("List is empty");
    }   
    else{
        temp=head;
        printf("Elements are:");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    printf("\nCount=%d",count);
}
void insertbeg(){
    creation();
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
    display();
}
void insertend(){
    if(head==NULL){
        insertbeg();
    }
    else{
        creation();
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        display();
    }
}
void insertpos(){
    int pos;
    printf("Enter the position:");
    scanf("%d",&pos);
    if(pos>0 && pos<=count+1){
        if(pos==1){
            insertbeg();
        }
        else if(pos==count+1){
            insertend();
        }
        else{
            creation();
            temp=head;
            for(int i=1;i<pos-1;i++){
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
            display();
        }
    }
    else{
        printf("\nInvalid position");
    }    
}
void main(){
    int choice,ch=1;
    while(ch){
        printf("\n1.Beginning\n2.End\n3.At specific position\n4.Stop\nEnter the operation:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            insertbeg();
            break;
            case 2:
            insertend();
            break;
            case 3:
            insertpos();
            break;
            case 4:
            ch=0;
            break;
            default:
            printf("Invalid choice");
            break;
        }
    }
}