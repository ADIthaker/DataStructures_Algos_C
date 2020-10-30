#include<stdio.h>
#include<conio.h>
#define MAX 5
int front = -1;
int rear = -1;
int c_queue[MAX];
void enqueue(){
    int val;
    printf(" Enter the value: ");
    scanf("%d",&val);
    if((front==0 && rear==MAX-1) || (front==rear+1))
    {
        printf("QUEUE OVERFLOW\n");
        return ;
    }
    if(front==-1 && rear==-1){
        front=0;
        rear=0;
        c_queue[0] = val;
        return;
    }
    else{
        rear = (rear+1)%MAX;
        c_queue[rear] = val;
    }
    return;
}
int dequeue(){
    if(front==-1 && rear==-1)
    {
        printf("EMPTY QUEUE \n");
        return -1 ;
    }
    if(front==rear){
        int val = c_queue[front];
        front = -1;
        rear = -1;
        return val;
    }
    int val = c_queue[front];
    front=(front+1)%MAX;
    return val;
    
}
void display(){
    if(front==-1 && rear==-1){
        printf("EMPTY QUEUE");
        return;
    }
    else{
        if(front<rear)
        {
            for(int i=front;i<=rear;i++)
            printf("\t %d", c_queue[i]);
        }
        else
        {
            for(int i=front;i<MAX;i++)
            printf("\t %d", c_queue[i]);
            for(int i=0;i<=rear;i++)
            printf("\t %d", c_queue[i]);
        }
    } 
    printf("\nFRONT: %d \nREAR: %d",front,rear);
}
int main(){
    int option, val;
    do
    {
    printf("\n ***** MAIN MENU *****");
    printf("\n 0. EXIT");
    printf("\n 1. Insert an element");
    printf("\n 2. Delete an element");
    printf("\n 3. Display the queue");
    printf("\n Enter your option : ");
    scanf("%d", &option);
    switch(option)
    {
        case 1:
        enqueue();
        break;
        case 2:
        val = dequeue();
        if(val != -1)
            printf("\n The number deleted is : %d", val);
        break;
        case 3:
        display();
        break;
    }
    }while(option!=0);
}