#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
	struct node* prev;
};

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
			newnode->prev = NULL;
			newnode->next = NULL;
			start = newnode;
		}
		else{
			temp=start;
			while(temp->next!=NULL){
			temp = temp->next;
			}
			temp->next = newnode;
			newnode->prev = temp;
			newnode->next = NULL;
		}
		printf("enter value to be added\t");
		scanf("%d",&val);
	}
	return start;
}
void display (struct node*start)
{	struct node*temp = start;
	while(temp!=NULL){
		printf(" %d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
struct node* insert_beg(struct node*start, int val){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = val;
	newnode->prev = NULL;
	newnode->next = NULL;
	start = newnode;
	return start;
}


struct node* insert(struct node*start){
	int val, key;
	printf("Enter the data you want to insert: ");
	scanf("%d",&val);
	printf("Enter the number you want to insert before: ");
	scanf("%d",&key);
	struct node* newnode,*temp,*before;
	if(start==NULL){
		return insert_beg(start,val);
	}
	temp = start;
	while(temp->data != key && temp!=NULL)
	{	
		
		temp = temp->next;
	}
	if(temp==NULL){
		printf("NO such node");
		return start;
	}
	before = temp->prev;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = val;
	newnode->prev = before;
	newnode->next = temp;
	before->next = newnode;
	temp->prev = newnode;
	return start;
}

int find_middle(struct node *start){
    struct node *end = start;
    while(end->next != NULL)
    	end = end->next; 
    while(start!=end){
        start = start->next;
        end = end->prev;
        if (end->prev==start){
            return start->data;
        }
    }
    return start->data;
}
int find_middle_without_prev(struct node*start){
	struct node* fast = start;
	struct node* slow = start;
	while(fast!=NULL && fast->next!=NULL){
		if(fast->next->next==NULL){
			return slow->data;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow->data;
}

struct node *delete_before(struct node*start){
	int  key;
	printf("Enter the number before which you want to delete: ");
	scanf("%d",&key);
	struct node*temp,*before,*after;
	temp = start;
	if(start==NULL){
		printf("list is empty");
		return start;
	}
	while(temp->data != key && temp!=NULL){
		temp = temp->next;
	}
	before = temp->prev;
	after = temp->next;
	before->next = after;
	after->prev = before;
	free(temp);
	return start;

}

int main(){
	struct node*start = NULL;
	int option = 1;
	int choice,val;
	while(option)
	{	printf("Choose one of the operations:\n");
    	printf("0. Exit Program\n");
    	printf("1. Create a doubly linked list\n");
    	printf("2. Display\n");
    	printf("3. Insert before element\n");
    	printf("4. Delete element\n");
    	printf("5. Find middle element\n");
		printf("Enter your choice :\n");
		scanf("%d",&choice);
		switch(choice){
			case 0: 
			printf("Exited\n");
			option = 0;
			break;
			case 1:
			start = create(start);
			break;
			case 2:
			printf("The list is:\n");
			display(start);
			break;
			case 3:
			start = insert(start);
			break;
			case 4:
			start = delete_before(start);
			break;
			case 5:
			printf("Mid value is %d\n", find_middle_without_prev(start));
               break;
			default:
			printf("Not an option :\n");
			break;
		}
			
		
	}
	return 0;
}