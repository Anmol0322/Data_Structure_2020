#include<stdio.h>
#include<conio.h>
int prcd(char,char);
void main(){
char op1,op2;
int ans;
clrscr();
printf("Enter outside and inside operator: ");
scanf("%c %c",&op1,&op2);
ans=prcd(op1,op2);
printf("1 for Push and 0 for Pop: %d",ans);
getch();
}
int prcd(char op1,char op2){
if(op1=='$')
  return 0;
else if(op2=='$')
  return 1;
else if(op2=='*'|| op2=='/'||op2=='%')
  return 0;
else if(op1=='/'|| op1=='*'||op1=='%')
  return 1;
else if(op2=='+'|| op2=='-')
  return 0;
else
  return 1;
}
