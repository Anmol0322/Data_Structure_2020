/*
Circular Linked List:-
1. append() = insert element
2. display() = show elements
3. del_first() = deleting first element
4. del_last() = deleting last element
5. del_any() = deleting element that we want too
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void append(struct cnode **,int);
void display(struct cnode *);
void del_first(struct cnode **);
void del_last(struct cnode **);
void del_any(struct cnode **,int);
struct cnode
{
int data;
struct cnode *next;
};
void main()
{
struct cnode *start=NULL;
clrscr();
append(&start,10);
append(&start,20);
append(&start,30);
append(&start,40);
append(&start,50);
printf("Data is nodes...\n");
display(start);
printf("\nAfter deleting first node...\n");
del_first(&start);
display(start);
printf("\nAfter deleting last node...\n");
del_last(&start);
display(start);
printf("\nAfter deleting data 30...\n");
del_any(&start,30);
display(start);
getch();
}
void append(struct cnode **ps,int x)
{
struct cnode *p,*temp;
p=(struct cnode*)malloc(sizeof(struct cnode));
p->data=x;
if((*ps)->next==NULL)
{
*ps=p;
p->next=p;
return;
}
temp=*ps;
while(temp->next!=*ps)
{
temp=temp->next;
}
temp->next=p;
p->next=*ps;
}
void display(struct cnode *p)
{
struct cnode *temp;
if(p==NULL)
{
printf("List is empty");
return;
}
temp=p;
do
{
printf("%d\n",temp->data);
temp=temp->next;
}while(temp!=p);
}

void del_first(struct cnode **ps)
{
struct cnode *temp,*temp2;
if(*ps==NULL)
{
printf("List is empty");
return;
}
if((*ps)->next==*ps)
{
free(*ps);
*ps=NULL;
}
temp=(*ps)->next;
while(temp!=*ps)
{
temp2=temp;
temp=temp->next;
}
temp2->next=temp->next;
*ps=temp->next;
free(temp);
}
void del_last(struct cnode **ps)
{
struct cnode *temp,*temp2;
if(*ps==NULL)
{
printf("List is empty");
return;
}
if((*ps)->next==*ps)
{
free(*ps);
*ps=NULL;
}
temp=*ps;
while(temp->next!=*ps)
{
temp2=temp;
temp=temp->next;
}
free(temp);
temp2->next=*ps;
}
void del_any(struct cnode **ps,int x)
{
struct cnode *temp,*temp2;
if(*ps==NULL)
{
printf("List is empty");
return;
}
if((*ps)->data==x)
{
if((*ps)->next==*ps)
{
free(*ps);
*ps=NULL;
return;
}
temp=(*ps)->next;
while(temp!=*ps)
{
temp2=temp;
temp=temp->next;
}
temp2->next=temp->next;
*ps=temp->next;
free(temp);
return;
}
temp=*ps;
while(temp->data!=x)
{
temp2=temp;
temp=temp->next;
}
temp2->next=temp->next;
free(temp);
}

