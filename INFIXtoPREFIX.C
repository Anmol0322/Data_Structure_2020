#include<stdio.h>
#include<conio.h>
#include<ctype.h>

struct Stack{
char arr[10];
int tos;
};

void push(struct Stack *, char);
char pop(struct Stack *);

int isoprnd(char);

int isempty(struct Stack);

int prcd(char, char);

void convert(char [], char[]);

void main(){
char infix[15],prefix[15];
clrscr();
printf("Enter an infix exp: ");
scanf("%s",&infix);
convert(prefix,infix);
printf("Prefix exp is %s",prefix);
getch();
}

void convert(char prefix[], char infix[]){
struct Stack S;
int i, j=0;
char ch;
int ans;
S.tos=-1;

for(i=strlen(infix)-1;i>='\0';i--){
  ch=infix[i];

  if(isoprnd(ch)==1){
    prefix[j]=ch;
    j++;
  }
  else if(ch==')'){
  push(&S,ch);
  }
  else if(ch=='('){
    while(S.arr[S.tos]!=')'){
      prefix[j]=pop(&S);
     j++;
    }
  pop(&S);
  }
  else{
    while(isempty(S)==0){
      ans=prcd(ch,S.arr[S.tos]);
      if(ans==1)
	break;
      prefix[j]=pop(&S);
      j++;
    }
    push(&S,ch);
  }
}

while(isempty(S)==0){
  prefix[j]=pop(&S);
  j++;
}
prefix[j]='\0';
strrev(prefix);
return;
}

void push(struct Stack *p, char ch){
  if(p->tos==9){
    printf("\nStack Overflow...\n");
    return;
  }
  p->tos=p->tos+1;
  p->arr[p->tos]=ch;
}

char pop(struct Stack *p){
  char ch;
  if(p->tos==-1){
    printf("\nStack Underflow...\n");
    return 0;
  }
  ch=p->arr[p->tos];
  p->tos=p->tos-1;
  return ch;
}

int isoprnd(char ch){
if(isalpha(ch)==0 && isdigit(ch)==0)
  return 0;
return 1;
}

int isempty(struct Stack S)
{
  return (S.tos==-1);
}

int prcd(char op1,char op2)
{
if(op1==op2)
  return 1;
else if(op1=='$')
  return 1;
else if(op2=='$')
  return 0;
else if(op1=='*'|| op1=='/'||op1=='%')
  return 1;
else if(op2=='/'|| op2=='*'||op2=='%')
  return 0;
else if(op1=='+'|| op1=='-')
  return 1;
else
  return 0;
}


