#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>

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

int getNthNode(Node *start)
{
	int num;
	printf("\nEnter the position");
	scanf("%d",&num);
	int count=0;
	Node *curr = start;
	while(curr->next!=NULL)
	{
		if(count==num)
			return curr->data;
		count++;
		curr = curr->next;
	}
	assert(0);
}

int main()
{
	start = create_ll(start);
	int x;
	x  = getNthNode(start);
	printf("%d",x);
	return 0;
}
