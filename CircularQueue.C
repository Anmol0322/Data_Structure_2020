#include<stdio.h>
#include<conio.h>
void insert(struct CQueue *, int);
int del(struct CQueue *);
struct CQueue
{
int arr[5];
int front,rear;
};
void main()
{
struct CQueue Q;
int i,x,ch;
char choice;
Q.front=Q.rear=-1;
clrscr();
printf("Options: \n1. Insert\n2. Delete\n3. Quit");
do
{
printf("\n\nChoose:");
scanf("%d",&ch);
if(ch==1)
{
  printf("\nEnter element:");
  scanf("%d",&x);
  insert(&Q,x);
}
else if(ch==2)
{
  x=del(&Q);
  if(x!=-1)
    printf("\nRemoved element: %d\n",x);
}
else if(ch==3)
  exit(0);
else
  printf("\nYou entered wrong option.");

fflush(stdin);
printf("\nDo you want to continue(Y/N): ");
scanf("%c",&choice);

}while(choice=='Y'||choice=='y');
printf("\nThankyou!!!");
getch();
}

void insert(struct CQueue *q,int x)
{
if((q->rear+1)%5==q->front)
{
  printf("\nQueue Overflow!\n");
  return;
}
q->rear=(q->rear+1)%5;
q->arr[q->rear]=x;
if(q->front==-1)
 q->front=0;
}
int del(struct CQueue *q)
{
int x;
if(q->front==-1)
{
  printf("\nQueue Underflow\n");
  return -1;
}
x=q->arr[q->front];
if(q->front==q->rear)
  q->front=q->rear=-1;
else
  q->front=(q->front+1)%5;
return x;
}

