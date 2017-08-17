#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};
typedef struct node Node;
Node *start = NULL;

Node *create_ll(Node *start){
	Node *newnode, *ptr;
	int num;
	printf("\nEnter -1 to end.");
	printf("\nEnter the data : ");
	scanf("%d",&num);
	while(num!=-1)
	{
		newnode = (Node *)malloc(sizeof(Node));
		newnode->data = num;
		if(start==NULL)
		{
			newnode->next = NULL;
			start = newnode;
		}
		else
		{
			ptr = start;
			while(ptr->next!=NULL)
				ptr = ptr->next;
			ptr->next = newnode;
			newnode->next=NULL;
		}
		printf("Enter the data : ");
		scanf("%d",&num);
	}
	return start;
}

Node *display(Node *start){
	Node *ptr;
	ptr = start;
	while(ptr!=NULL)
	{
		printf("\t %d",ptr->data);
		ptr=ptr->next;
	}
	return start;
}

Node *insert_beg(Node *start)
{
	Node *newnode;
	int num;
	printf("Enter the data : ");
	scanf("%d",&num);
	newnode = (Node *)malloc(sizeof(Node));
	newnode->data = num;
	newnode->next=start;
	start = newnode;
	return start;
}

Node *insert_end(Node *start){
	Node *ptr, *newnode;
	int num;
	printf("Enter the data : ");
	scanf("%d",&num);
	newnode = (Node *)malloc(sizeof(Node));
	newnode->data = num;
	newnode->next = NULL;
	ptr = start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
	return start;
}

Node *delete_end(Node *start)
{
	Node *ptr,*preptr;
	ptr = start;
	while(ptr->next!=NULL)
	{
		preptr = ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
	free(ptr);
	return start;
}
int display1(){
	int c;
	printf("\nEnter 1 for create");
	printf("\nEnter 2 for display");
	printf("\nEnter 3 for insert and beg");
	printf("\nEnter 4 for insert at end");
	printf("\nEnter 5 for delete at end");
	printf("\nEnter 0 for exit");
	printf("\nEnter your choice : ");
	scanf("%d",&c);
	return c;
}
int main()
{
	int ch;
	while(1){
		ch = display1();
		switch(ch){
			case 1: start = create_ll(start);
					printf("Linked List created....");
					break;
			case 2: start = display(start);
					break;
			case 3: start = insert_beg(start);
					break;
			case 4: start = insert_end(start);
					break;
			case 5: start = delete_end(start);
					break;
			case 0: exit(0);
					break;
			default: printf("\nInvalid Choice.......");
					 
		}
	}
	return 0;
}
