#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*head,*temp,*newnode,*prev;
int count=0,i;
void display(){
    if(head==NULL){
        printf("List is empty");
    }
    else{
        temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\nCount=%d",count);
    }
}
void del_beg(){
    if(head==NULL){
        display();
    }
    else{
        temp=head;
        head=temp->next;
        free(temp);
        count--;
        display();
    }
}
void del_end(){
    if(head==NULL){
        display();
    }
    else if(count==1){
        del_beg();
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
        count--;
        display();
    }
}
void del_pos(){
    if(head==NULL){
        display();
    }
    else{
        int pos;
        printf("Enter position to delete: ");
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
                    prev=temp;
                    temp=temp->next;
                    i++;
                }
                prev->next=temp->next;
                free(temp);
                count--;
                display();
            }
        }
        else{
            printf("Invalid position\n");
        }
    }
}
void main(){
    int choice,c=1,j,a;
    head=NULL;
    printf("How many nodes do you want:");
    scanf("%d",&a);
    for(j=0;j<a;j++){
        newnode=malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        count++;
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    display();
    while(c){
        printf("\n1.Beginning\n2.At a position\n3.End\n4.Display\n5.Stop");
        printf("Which operation do you want:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            del_beg();
            break;
            case 2:
            del_pos();
            break;
            case 3:
            del_end();
            break;
            case 4:
            display();
            break;
            case 5:
            c=0;
            break;
            default:
            printf("Invalid choice\n");
        }
        printf("\n");
    }

}
