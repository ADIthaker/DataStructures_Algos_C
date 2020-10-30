#include <stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node*start  = NULL;
struct node* create(struct node * start){
	struct node* newnode,*temp;
	printf("enter  value for node\n");
	printf("-1 to quit\n");
	int val;
	scanf("%d",&val);
	while(val !=-1){
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = val;
		if(start==NULL){
			newnode->next = NULL;
			start = newnode;
		}
		else{
			temp=start;
			while(temp->next!=NULL){
			temp = temp->next;
			}
			temp->next = newnode;
			newnode->next = NULL;
		}
		printf("enter value to be added\t");
		scanf("%d",&val);
	}
	return start;
}
struct node * display(struct node * start){
	struct node *temp;
	temp = start;
	while(temp !=NULL){
		printf("%d \t ",temp->data);
		temp = temp->next;
	}
	return start;
}
struct node * insert_before(struct node* start){
	struct node *newnode,*ptr,*preptr;
	ptr=start;
	preptr = start;
	int val,before;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("enter value to be added\n");
	scanf("%d",&val);
	newnode->data = val;
	printf("enter value before which the value is to be added");
	scanf("%d",&before);
	if(before == start->data){
	newnode->data = val;
	newnode->next = start;
	start=newnode;
	return start;
	}
	while(ptr->data != before){
		preptr =  ptr;
		ptr = ptr->next;
	}
	preptr->next = newnode;
	newnode->next = ptr;
	return start;
}
int find_middle(struct node*start){
	struct node* fast = start;
	struct node* slow = start;
	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow->data;
}
struct node * insert_after(struct node * start){
	struct node *newnode,*preptr,*ptr;
	struct node *end;
	ptr=start;
	while(ptr->next !=NULL){
		ptr = ptr->next;
	}
	end = ptr;
	int val,after;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("enter value to be added\n");
	scanf("%d",&val);
	newnode->data = val;
	printf("enter value after which the value is to be added");
	scanf("%d",&after);
	if(after==end->data){
	end->next = newnode;
	newnode ->next = NULL;
	return start;
	}
	ptr = start;
	preptr = ptr;
	while(preptr->data !=after){
		preptr = ptr;
		ptr = ptr->next;
	}
	preptr->next = newnode;
	newnode->next = ptr;
	return start;
}
struct node *delete_beg(struct node* start){
	struct node* temp;
	temp = start;
	start = start->next;
	free(temp);
	return start;
}

struct node *delete_node(struct node* start){
	struct node *temp,*pre;
	int val;
	temp=  start;
	printf("enter the value to be deleted\n");
	scanf("%d",&val);
	if(temp->data == val){
		start = delete_beg(start);
		return start;
	}
		while(temp != NULL && temp->data !=val){
			pre = temp;
			temp = temp->next;
		}if(temp==NULL){
		printf("element dosent exist in the list\n");
		return start;
		}
		pre->next  = temp->next;
		free(temp);	
	return start;
}
int main(){
	int option; 
	do{
		printf("\nenter option from the menu for the operation \n");
		printf("1:Create linked list\n");
		printf("2:Display linked list\n");
		printf("3:Insert before a value\n");
		printf("4:Insert after a value\n");
		printf("5:Delete node by value\n");
		printf("6:Find middle \n");
		printf("-1 to quit\n");
		scanf("%d",&option);
		switch(option){
		case 1: start = create(start);
		break;
		case 2: start = display(start);
		break;
		case 3 : start = insert_before(start);
		break;
		case 4 : start = insert_after(start);
		break;
		case 5: start = delete_node(start);
		break;
		case 6: 
		printf("Mid value is %d\n", find_middle(start));
        break;
        default:
        printf("Not an option \n");
		}
	}while(option!=-1);
	return 0;
}
