#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
node *top=NULL;

void push(int value )
{
	struct node *newnode;
	newnode=malloc(sizeof(struct node));
	newnode->data=value;
	if (top==NULL)
	{
		newnode->next=NULL;
	} else {
		newnode->next=top;
	}
	top=newnode;
	printf("node is inserted");
}

int pop()
{
	if (top==NULL)
	{
		printf("\n stack is underflow");
	} else {
		struct node *temp=top;
		int temp_data=top->data;
		top=top->next;
		free(temp);
		return temp_data;
	}
}

void display()
{
	if (top==NULL)
	{
		printf("\nstack is underflow");
		
	} else {
		printf("\nstack is ");
		struct node *temp=top;
		while(temp->next!=NULL)
		{
			printf("%d -->",temp->data);
			temp=temp->next;0
		}
	}
}

int main()
{
	int choice,value;
	while(1)
	{
		printf("PUSH\nPOP\nDISPLAY\n");
		printf("enter ur chocie :");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("enter the value :");
				scanf("%d",&value);
				push(value);
				break;
				
				case 2:
					printf("popped element ");
					break;
					
					case 3:display();
					break;
					
					case 4:
						exit(0);
						break;
						
						default:
							printf("\ninvalid choice");
		}
		
		
	}
}
