
#include<stdio.h>
#include<ctype.h>
char postfix[30];
float stack[30];
int top=-1;
void push(float symbol)
{
  stack[top++]=symbol;
 }
float pop()               
{
float x;
x=stack[top--];
return x;
}

void main()
{
int i=0;
char op1,op2;
printf("Enter postfix expression:");
scanf("%s",postfix);
while((symbol=postfix[i++])!='\0')
{
if(isalnum(postfix[i]))
{
push(postfix[i]-'0');
} 
else
{                                             
op2=pop();
op1=pop();
switch(postfix[i])
{
case '+':push(op1+op2);
         break;
case '-':push(op1-op2);
         break;
case '*':push(op1*op2);
         break;
case '/':push(op1/op2)
         break;
case '^':push(op1^op2);
          break;
default:printf("somthing wrong u entered");
}
}
}
printf("exp %s",stack[top]);
}


