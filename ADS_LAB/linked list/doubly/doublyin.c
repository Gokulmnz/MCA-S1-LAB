#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node *prev;
}*temp,*head=NULL,*tail=NULL,*newnode;
int count=0;
void creation(){
    newnode=malloc(sizeof(struct node));
    printf("Enter the data of the node:");
    scanf("%d",&newnode->data);
    newnode->next=newnode->prev=NULL;
    count++;
}
void printlist(){
    if(head==NULL){
        printf("List is empty");
    }
    else{
        temp=head;
        printf("Entered elements are:");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    printf("Count=%d",count);
}
void ins_beg(){
    creation();
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    printlist();
}
void ins_end(){
    if(head==NULL){
        ins_beg();
    }
    else{
        creation();
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
        printlist();
    }
}
void ins_any(){
    int pos,i;
    printf("Enter the position of the node:");
    scanf("%d",&pos);
    if(pos>0 && pos<=count+1){
        if(pos==1){
            ins_beg();
        }
        else if(pos==count+1){
            ins_end();
        }
        else{
            creation();
            temp=head;
            i=1;
            while(i<pos-1){
                temp=temp->next;
                i++;
            }
            newnode->next=temp->next;
            temp->next->prev=newnode;
            temp->next=newnode;
            newnode->prev=temp;
            printlist();
        }
    }
    else{
        printf("Invalid position");
    }
}
void main(){
    int choice,c=1;
    while(c){
        printf("\n1.Beginning\n2.Anywhere\n3.End\n4.Display\n5.Stop\n");
        printf("Which insertion operation do you want:");
        scanf("%d",&choice);
        switch(choice){
            case 1:ins_beg();break;
            case 2:ins_any();break;
            case 3:ins_end();break;
            case 4:printlist();break;
            case 5:c=0;break;
            default:printf("Invalid entry");break;
        }
    }
}