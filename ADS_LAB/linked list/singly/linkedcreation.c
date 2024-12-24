#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head,*temp,*newnode;
void main(){
    int a,i;
    head=NULL;
    printf("How many nodes do you want:");
    scanf("%d",&a);
    for(i=0;i<a;i++){
        newnode=malloc(sizeof(struct node));
        printf("Enter Your data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
        }
        else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
    printf("\nElements Are:");
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}