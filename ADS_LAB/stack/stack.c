#include <stdio.h>
#include <stdlib.h>

#define max 5
int a[max],top=-1,b,i;
void push(){
    if(top==max-1){
        printf("Overflow");
    }
    else{
        top++;
        printf("Enter Your data:");
        scanf("%d",&a[top]);
    }
}
void pop(){
    if(top==-1){
        printf("Empty");
    }
    else{
        b=a[top];
        top--;
        printf("Popped element is:%d",b);
    }
}
void peek(){
    if(top==-1){
        printf("Underflow");
    }
    else{
        printf("Top element :%d",a[top]);
    }
}
void display(){
    if(top==-1){
        printf("Underflow");
    }
    else{
        printf("Elements in the stack:");
        for(i=top;i>=0;i--){
            printf("%d ",a[i]);
        }
    }
}
void main(){
    int ch=1,c;
    while(ch){
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Stop\n");
        scanf("%d",&c);
        switch(c){
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
            printf("Invalid Entry");
            break;
        }
    }

}
