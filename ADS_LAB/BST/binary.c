#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
}*root=NULL,*temp,*newnode;

void insertion(){
    newnode=malloc(sizeof(struct node));
    printf("Enter the value to be inserted:");
    scanf("%d",&newnode->data);
    newnode->right=NULL;
    newnode->left=NULL;
    if(root==NULL){
        root=newnode;
    }
    else if(newnode->data>root->data){
        temp=root;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        if(newnode->data>temp->data){
            temp->right=newnode;
        }
        else{
            temp->left=newnode;
        }
    }
    else{
        temp=root;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        if(newnode->data<temp->data){
            temp->left=newnode;
        }
        else{
            temp->right=newnode;
        }
    }
}
int printlist(root){
    if(root==NULL){
        return;
    }
    printlist(root->left);
    printf("%d ",root->data);
    printlist(root->right);
}
void main(){
    int choice,ch=1;
    while(ch){
        printf("\n1.Insertion\n2.Print\n3.Stop");
        printf("\nSelect your operation:");
        scanf("%d",&ch);
        switch(choice){
            case 1:
            insertion();
            break;
            case 2:
            printlist();
            case 3:
            ch=0;
            break;
            default:
            printf("Invalid choice");
            break;
        }
    }
}