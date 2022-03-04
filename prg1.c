#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
int top=-1,stack[MAXSIZE];
void push(int);
int pop();
void display();
void push(int val)
{
 if(top==MAXSIZE-1)
{
 printf("Stack is full");
 exit(0);
}
top=top+1;
stack[top]=val;
}


       

int pop()
{
int ele;
if(top==-1)
{
 printf("Stack is empty");
 exit(0);
}
printf("poped %d",stack[top]);
ele = stack[top--];
return ele;
}

void display()
{
 int i;
 if(top==-1)
 {
   printf("\n ...stack is empty...");
    exit(0);
  }
  
   printf("\n stack is:\n");
for(i=top;i>=0;i--)
printf("%d\t",stack[i]);
}



void main()
{
int ch,item ;
while(1)
{
                                                                                                                                                                                                                                                                                                              printf("\n 1.push\n \n 2.pop\n \n3.display\n \n4.Exit\n");
printf("Enter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter element to inserted:");
       scanf("%d",&item);
       push(item);
       break;
case 2:pop();
       break;
case 3:display();
       break;
case 4 :exit(0);
                                                            
default:printf("Wrong choice");
         exit(0);
}
}
 
}
