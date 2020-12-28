#include<stdio.h>
#include<conio.h>

struct Queue{
int arr[5];
int front,rear;
};

void insert(struct Queue *, int);
int del(struct Queue *);

void main()
{
  struct Queue Q;
  int i,x;
  Q.front=0;
  Q.rear=-1;
  clrscr();

  for(i=1;i<=6;i++)
  {
    printf("Enter element: ");
    scanf("%d",&x);
    insert(&Q,x);
  }
  for(i=1;i<=6;i++)
  {
    x=del(&Q);
    if(x!=-1){
      printf("\nDeleted element: %d",x);
    }
  }
  getch();
}

void insert(struct Queue *p, int x)
{
  if(p->rear==4)
  {
    printf("\nQueue Overflow!!!\n");
    return;
  }
  p->rear=p->rear+1;
  p->arr[p->rear]=x;
}

int del(struct Queue *p)
{
  int x;
  if(p->front>p->rear)
  {
    printf("\n\nQueue Underflow!!!");
    return -1;
  }
  x=p->arr[p->front];
  p->front=p->front+1;
  return x;
}
