#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL,*temp,*newnode,*tail=NULL;
int count=0;
void printlist(){
    if(head==NULL){
        printf("List is empty\n");
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
void del_beg(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else if(head==tail){
        free(head);
        head=tail=NULL;
        count--;
        printlist();
    }
    else{
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
        count--;
        printlist();
    }
}
void del_end(){
    if(head==NULL){
        printf("List is empty\n");
    }
    else if(head==tail){
        del_beg();
    }
    else{
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        free(temp);
        count--;
        printlist();
    }
}
void del_any(){
    int pos,i;
    if(head==NULL){
        printlist();
    }
    else{
        printf("Which position do you want to delete:");
        scanf("%d",&pos);
        if(pos>0 && pos<=count){
            if(pos==1){
                del_beg();
            }
            else if(pos==count){
                del_end();
            }
            else{
                temp=head;
                i=1;
                while(i<pos){
                    temp=temp->next;
                    i++;
                }
                temp->next->prev=temp->prev;
                temp->prev->next=temp->next;
                free(temp);
                count--;
                printlist();
            }
        }
        else{
            printf("Invalid position\n");
        }
    }
}
void main(){
    int n,j,ch=1,c;
    printf("How many nodes you want:");
    scanf("%d",&n);
    for(j=0;j<n;j++){
        newnode=malloc(sizeof(struct node));
        printf("Enter data for node:");
        scanf("%d",&newnode->data);
        newnode->next=newnode->prev=NULL;
        count++;
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
    printlist();
    while(ch){
        printf("\n1.Beginning\n2.Anywhere\n3.End\n4.Display\n5.Stop\n");
        printf("Which deletion operation you want:");
        scanf("%d",&c);
        switch(c){
            case 1:del_beg();break;
            case 2:del_any();break;
            case 3:del_end();break;
            case 4:printlist();break;
            case 5:ch=0;break;
            default:printf("Invalid choice");break;
        }
    }
}