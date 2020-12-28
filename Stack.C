#include<stdio.h>
#include<conio.h>
void push(struct Stack *, int);
int pop(struct Stack *);

struct Stack{
int arr[5];
int tos;
};

void main(){
struct Stack S;
int i,x,choice;
char ch;
clrscr();
S.tos=-1;
printf("Select your choice:-\n1. Push\t2. Pop\t3. Quit");

do{
  printf("\n\nEnter choice: ");
  scanf("%d",&choice);

  if(choice==1){
    printf("\nEnter element to push: ");
    scanf("%d",&x);
    push(&S,x);
  }

  else if(choice==2){
    x=pop(&S);
    if(x!=0)
      printf("\nPopped element... %d",x);
      printf("\n");
  }
  else if(choice==3){
    break;
  }
  else{
    printf("\nYou gave wrong choice!!!\n");
    break;
  }
  fflush(stdin);
  printf("\nDo you want to continue(Y/N): ");
  scanf("%c",&ch);
}while(ch=='Y' || ch=='y');

printf("\nThankyou!");
getch();
}

void push(struct Stack *p, int x){
  if(p->tos==4){
    printf("\nStack Overflow...\n");
    return;
  }
  p->tos=p->tos+1;
  p->arr[p->tos]=x;
  printf("Successfully pushed: %d\n",x);
}

int pop(struct Stack *p){
  int x;
  if(p->tos==-1){
    printf("\nStack Underflow...\n");
    return 0;
  }
  x=p->arr[p->tos];
  p->tos=p->tos-1;
  return x;
}