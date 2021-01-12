/*
Linear Linked List:-
1. append() = insert element
2. display() = show elements
3. searchnode() = tells the node number where the data is stored
4. del_first() = deleting first element
5. del_last() = deleting last element
6. del_any() = deleting element that we want too
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *next;
};

void display(struct node *);
void append(struct node **,int);
int searchnode(struct node *, int x);
void del_first(struct node **);
void del_last(struct node **);
void del_any(struct node **,int);

void main()
{
struct node *start = NULL;
int search;
clrscr();
append(&start,10);
append(&start,20);
append(&start,30);
append(&start,40);
append(&start,50);
display(start);
search=searchnode(start,40);
printf("\n\nAt data 40, the node is: %d\n",search);
del_first(&start);
printf("\nAfter deletion of first node...");
display(start);
del_last(&start);
printf("\n\nAfter deletion of last node...");
display(start);
del_any(&start,30);
printf("\n\nAfter deleting data 30...");
display(start);
getch();
}

void append(struct node **ps,int x)
{
struct node *p,*temp;
p=(struct node *)malloc(sizeof(struct node));
p->data=x;
p->next=NULL;
if(*ps==NULL)
{
  *ps=p;
  return;
}
temp=*ps;
while(temp->next!=NULL)
{
  temp=temp->next;
}
temp->next=p;
}

void display(struct node *p)
{
if(p==NULL)
{
  printf("List is empty");
  return;
}
while(p!=NULL)
{
  printf("\n%d",p->data);
  p=p->next;
}
}

int searchnode(struct node *p,int x)
{
int pos=0;
if(p==NULL)
{
  printf("The list is empty.");
  return pos;
}
while(p!=NULL)
{
  pos++;
  if(p->data==x)
    return pos;
  p=p->next;
}
return -1;
}

void del_first(struct node **ps)
{
struct node *temp;
if(*ps==NULL)
{
  printf("The list is empty.");
  return;
}
temp=*ps;
*ps=(*ps)->next;
free(temp);
}

void del_last(struct node **ps)
{
struct node *lastnode,*secondlastnode;
if(*ps==NULL)
{
	printf("The list is empty.");
	return;
}
lastnode = *ps;
while(lastnode->next != NULL)
{
    secondlastnode = lastnode;
    lastnode = lastnode->next;
}
secondlastnode->next = NULL;
free(lastnode);
}
void del_any(struct node **ps,int x)
{
struct node *temp,*prev;
if(*ps==NULL)
{
printf("List is empty");
return;
}
temp=*ps;
if((*ps)->data==x)
{
*ps=temp->next;
free(temp);
return;
}
while(temp!=NULL && temp->data!=x)
{
prev=temp;
temp=temp->next;
}
if(temp==NULL)
{
printf("List is empty");
}
else
{
prev->next = temp->next;
free(temp);
}
}
