#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define SIZE  25
int stack[SIZE], top=-1;
int pop(){
    if(top == -1)
    {
        printf("stack underflow!\n");
        return -1;
    }
    else 
    {
        top--;
        return stack[top+1];
    }
}
int peek(){
    if(top == -1)
    {
        printf("empty stack!\n");
    } 
    else 
    {
        return stack[top];
    }
}
void push(int element){
    if(top+1>=SIZE)
    {
        printf("stack overflow!\n");
    } 
    else 
    {
        stack[top+1] = element;
        top++;
    }
}
void show(){
    if(top == -1){
        printf("empty stack!\n");
    }
    else 
    {
        for(int i=top;i>=0;i--)
            printf("%d\n",stack[i]);
    }
}

void main(){
    
    printf("Choose one of the operations to perform: \n");
    printf("-1. EXIT \n");
    printf("0. Push to the stack\n");
    printf("1. Pop from  the stack\n");
    printf("2. Peek into the stack\n");
    printf("3. Show the stack\n");
    int choice, num, run = 1;
    int k;
    while(run){
        printf("Enter a choice: ");
        scanf("%d", &choice);
        switch(choice){
            case -1:
                run = 0;
                break;
            case 0:
                printf("Enter element to be pushed to stack: ");
                scanf("%d", &num);
                push(num);
                break;
            case 1:
                k = pop();
                printf("removed %d\n", k);
                break;
            case 2:
                k = peek();
                printf("The element on top of the stack  %d\n", k);
                break;
            case 3:
                printf("Stack:\n");
                show();
                break;
            default:
                printf("Wrong Choice\n");
        }
    }
}