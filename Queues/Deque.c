#include<stdio.h>
#include<conio.h>
#define MAX 5
int front=-1;
int rear=-1;
int deque[MAX];
void input_deque(void);
void output_deque(void);
void insert_left(void);
void insert_right(void);
int delete_left(void);
int delete_right(void);
void display(void);
int main()
{
    int option;
    do
    {
    printf("\n *****MAIN MENU*****");
    printf("\n 0.Quit");
    printf("\n 1.Input restricted deque");
    printf("\n 2.Output restricted deque");
    printf("\n Enter your option : ");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
            input_deque();
        break;
        case 2:
            output_deque();
        break;
    }
    }while(option!=0);
    return 0;
}
void input_deque()
{
    int option;
    do
    {
    printf("\n INPUT RESTRICTED DEQUE");
    printf("\n 1.Insert at right");
    printf("\n 2.Delete from left");
    printf("\n 3.Delete from right");
    printf("\n 4.Display");
    printf("\n 5.Quit");
    printf("\n Enter your option : ");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
            insert_right();
        break;
        case 2:
            delete_left();
        break;
        case 3:
            delete_right();
        break;
        case 4:
            display();
        break;
    }
    }while(option!=5);
}
void output_deque()
{
    int option;
    do
    {
        printf("\n OUTPUT RESTRICTED DEQUE");
        printf("\n 1.Insert at right");
        printf("\n 2.Insert at left");
        printf("\n 3.Delete from left");
        printf("\n 4.Display");
        printf("\n 5.Quit");
        printf("\n Enter your option : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                insert_right();
            break;
            case 2:
                insert_left();
            break;
            case 3:
                delete_left();
            break;
            case 4:
                display();
            break;
        }
    }while(option!=5);
}
void insert_right(){
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
        deque[0] = val;
        return;
    }
    else{
        rear = (rear+1)%MAX;
        deque[rear] = val;
    }
    return;
}
void insert_left()
{
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
        deque[0] = val;
        return;
    }
    else{
        if(front==0){
            front = MAX-1;
            deque[front] = val;
            return;
        }
        front = (front-1)%MAX;
        deque[front] = val;
    }


}

int delete_left(){
    if(front==-1 && rear==-1)
    {
        printf("EMPTY QUEUE \n");
        return -1 ;
    }
    if(front==rear){
        int val = deque[front];
        front = -1;
        rear = -1;
        return val;
    }
    int val = deque[front];
    front=(front+1)%MAX;
    return val;
    
}
void display(){
    if(front==-1 && rear==-1){
        printf("EMPTY QUEUE");
        return;
    }
    else{
        if(front<=rear)
        {
            for(int i=front;i<=rear;i++)
            printf("\t %d", deque[i]);
        }
        else
        {
            for(int i=front;i<MAX;i++)
            printf("\t %d", deque[i]);
            for(int i=0;i<=rear;i++)
            printf("\t %d", deque[i]);
        }
    } 
    printf("\nFRONT: %d \nREAR: %d",front,rear);
}
int delete_right(){
    if(front==-1 && rear==-1)
    {
        printf("EMPTY QUEUE \n");
        return -1 ;
    }
    if(front==rear){
        int val = deque[front];
        front = -1;
        rear = -1;
        return val;
    }
    int val = deque[rear];
    rear=(rear-1)%MAX;
    return val;
}