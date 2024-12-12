#include <stdio.h>
#include <stdlib.h>

int a[100],front=-1,rear=-1,ch=1,max,c,i;
void enqueue(){
    if(front==-1 && rear==-1){
        front=rear=0;
        printf("enter your element:");
        scanf("%d",&a[rear]);
    }
    else if(rear==max-1){
        printf("overflow");
    }
    else{
        rear++;
        printf("enter your element:");
        scanf("%d",&a[rear]);
    }
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("underflow");
    }
    else if(front==rear){
        printf("dequeued element is %d",a[front]);
        front=-1,rear=-1;
    }
    else{
        printf("dequeued element is %d",a[front]);
        front++;
    }
}

void peek(){
    if(front==-1 && rear==-1){
        printf("underflow");
    }
    else{
        printf("the element is %d",a[rear]);
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("underflow");
    }
    else{
        printf("the elements are:");
        for(i=front;i<=rear;i++){
            printf("%d ",a[i]);
        }
    }printf("\n");
}   

void main(){
    
    printf("enter the size of array:");
    scanf("%d",&max);
    while(ch){
        printf("\nwhich operation you want to perform:");
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Stop.\n");
        scanf("%d",&c);
        switch(c){
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
            ch=0;
            break;
            default:
            printf("invalid choice");
            break;
        }
    }
}