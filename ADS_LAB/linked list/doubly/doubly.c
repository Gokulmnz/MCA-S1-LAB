#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL,*temp,*tail=NULL,*newnode;

void main(){
    int n,i;
    printf("how many nodes you want to insert:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=malloc(sizeof(struct node));
        printf("enter your data:");
        scanf("%d",&newnode->data);
        newnode->next=newnode->prev=NULL;
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
    printf("Elements are:");
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


