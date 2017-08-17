#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>

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

bool searchitr(Node *start)
{
	printf("\nEnter the search key  >  ");
	int x;
	scanf("%d",&x);
	Node *curr = start;
	while(curr->next!=NULL)
	{
		if(curr->data==x)
			return true;
		curr = curr->next;
	}
	return false;
}
int main()
{
	start = create_ll(start);
	bool x;
	x  = searchitr(start);
	if(x==true){
		printf("\nValue is present");
		
	}
	else{
		printf("\nValue is not present");
	}
	return 0;
}
