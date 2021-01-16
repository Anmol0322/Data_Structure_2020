#include<stdio.h>
#include<string.h>

struct Stack
{
	int data;
	struct Stack *next;
};

void push(struct Stack **,int);
int pop(struct Stack **);

void main()
{
	struct Stack *tos=NULL;
	int x;
	clrscr();
	push(&tos,10);
	push(&tos,20);
	push(&tos,30);
	push(&tos,40);
	push(&tos,50);
	x=pop(&tos);
	printf("%d\n",x);
	x=pop(&tos);
	printf("%d\n",x);
	x=pop(&tos);
	printf("%d\n",x);
	x=pop(&tos);
	printf("%d\n",x);
	x=pop(&tos);
	printf("%d\n",x);
	getch();
}

void push(struct Stack **ptos,int x)
{
	struct Stack *p;
	p=(struct Stack *)malloc(sizeof(struct Stack));
	if(p==NULL)
	{
		printf("Stack Overflow\n");
		return;
	}
	p->data=x;
	p->next=*ptos;
	*ptos=p;
}

int pop(struct Stack **ptos)
{
	struct Stack *temp;
	int data;
	if(*ptos==NULL)
	{
		printf("Stack Underflow\n");
		return -1;
	}
	temp=*ptos;
	data=temp->data;
	*ptos=(*ptos)->next;
	free(temp);
	return data;
}
