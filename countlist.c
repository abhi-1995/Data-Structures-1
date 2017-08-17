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

int count(Node *start)
{
	if(start == NULL)
	{
		return 0;
	}
	else{
		return 1+count(start->next);
	}
}
int main()
{
	start = create_ll(start);
	int x;
	x  = count(start);
	printf("The number of nodes in the list is %d",x);
	return 0;
}
