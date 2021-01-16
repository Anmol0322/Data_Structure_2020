#include<stdio.h>
#include<string.h>

struct Queue
{
	int data;
	struct Queue *next;
};

void insert(struct Queue **,struct Queue **,int);
int rem(struct Queue **,struct Queue **);

void main()
{
	struct Queue *front=NULL;
	struct Queue *rear=NULL;
	int x;
	clrscr();
	insert(&front,&rear,10);
	insert(&front,&rear,20);
	insert(&front,&rear,30);
	insert(&front,&rear,40);
	insert(&front,&rear,50);
	x=rem(&front,&rear);
	printf("%d\n",x);
	x=rem(&front,&rear);
	printf("%d\n",x);
	x=rem(&front,&rear);
	printf("%d\n",x);
	x=rem(&front,&rear);
	printf("%d\n",x);
	x=rem(&front,&rear);
	printf("%d\n",x);
	getch();
}

void insert(struct Queue **pf,struct Queue **pr,int x)
{
	struct Queue *p;
	p=(struct Queue *)malloc(sizeof(struct Queue));
	if(p==NULL)
	{
		printf("Stack Overflow\n");
		return;
	}
	p->data=x;
	p->next=NULL;
	if((*pf)==NULL)
		*pf=p;
	else
		(*pr)->next=p;
	*pr=p;
}

int rem(struct Queue **pf,struct Queue **pr)
{
	struct Queue *p;
	int x;
	if(*pf==NULL)
	{
		printf("Stack Underflow\n");
		return -1;
	}
	p=*pf;
	x=(*pf)->data;
	if((*pf)==*pr)
		*pf=*pr=NULL;
	else
		*pf=(*pf)->next;
	free(p);
	return x;
}
