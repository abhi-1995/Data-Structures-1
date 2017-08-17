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

Node *pairWiseSwap(Node *start)
{
	Node *temp = start;
	while(temp!=NULL && temp->next!=NULL)
	{
		swap(&temp->data,&temp->next->data);
		temp = temp->next->next;
	}
	return start;
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
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
int main()
{
	start = create_ll(start);
	printf("\nBefore swap");
	start = display(start);
	start = pairWiseSwap(start);
	printf("\nAfter swap");
	start = display(start);
	return 0;
}
