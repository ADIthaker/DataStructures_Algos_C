#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node* start=NULL;

void display(struct node* );
struct node* insert_beg(struct node* ,int );
struct node* delete_beg(struct node* );
struct node* insert_end(struct node* ,int );
struct node* delete_end(struct node* );
struct node* insert_at(struct node* , int , int );
struct node* delete_at(struct node* ,int );
int main ()
{
    start = insert_beg(start,2);
    start = insert_beg(start,4);
    start = insert_beg(start,6);
    start = insert_end(start,12);
    start = insert_at(start,1,1);
    start = delete_beg(start);
    start = delete_at(start,2);
    display(start);
    return 0;
}
struct node* insert_beg(struct node*start,int val)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    if(start==NULL){
        start = new_node;
        new_node->next = new_node;
        return start;
    }
    new_node->next = start;
    struct node* temp = start;
    while((temp->next!=start)){
        temp = temp->next;
    }
    temp->next = new_node;
    start = new_node;
    return start;
}
struct node* insert_end(struct node*start ,int val ){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data= val;
    if(start==NULL){
        return insert_beg(start,val);
    }
    struct node* curr = start;
    while(curr->next!=curr && curr->next!=start){
        curr = curr->next;
    }
    new_node->next = curr->next;
    curr->next= new_node;
    return start;
}
struct node* insert_at(struct node* start, int val, int index){
    if(index==0){
        return insert_beg(start,val);
    }
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    struct node* curr  = start;
    int cnt=0;
    while(curr->next!=curr && curr->next!=start){
        if(cnt==index-1){
            break;
        }
        curr = curr->next;
        cnt++;
    }
    new_node->next = curr->next;
    curr->next = new_node;
    return start;
}
struct node* delete_beg(struct node* start){
    if(start==NULL){
        printf("EMPTY QUEUE\n");
        return start;
    }
    struct node* curr  =  start;
    struct node* temp = start;
    while(curr->next!=curr && curr->next!=start){
        curr = curr->next;
    }
    curr->next = temp->next;
    start = temp->next;
    free(temp);
    return start;
}
struct node* delete_end(struct node* start){
    if(start==NULL){
        printf("EMPTY QUEUE\n");
        return start;
    }
    struct node* curr = start;
    
    while(curr->next!=curr && curr->next->next!=start){
        curr = curr->next;
    }
    struct node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
    return start;
}
struct node* delete_at(struct node* start,int index){
if(index==0){
        return delete_beg(start);
    }
    struct node* curr  = start;
    int cnt=0;
    while(curr->next!=curr && curr->next!=start){
        if(cnt==index-1){
            break;
        }
        curr = curr->next;
        cnt++;
    }
    struct node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
    return start;
}
void display(struct node*start)
{
    struct node* temp = start;
    while(temp->next!=start){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d ",temp->data);
    return;
}