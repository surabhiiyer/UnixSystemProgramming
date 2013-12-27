#include<stdio.h>
#include<stdlib.h>
struct student
{
char name[10];
int cet,pu,X;
int reg_no;
struct student *next;
};
void enter(struct student **);
void disp(struct student **,int);
int main()
{
int *n,count=0,reg,c;
int ch;
//printf("enter the max number of students\n");
//n=(int *)malloc(sizeof(n));
struct student *head;
head=(struct student *)malloc(sizeof(struct student));
do
{
printf("enter the choice\n1:to enter\n2:display\n");
scanf("%d",&c);
switch(c)
{
case 1:
count++;
printf("count::%d\n",count);
if(count<4)
enter(&head);
else
printf("Maximun students reached\n");
break;
case 2:
printf("enter the register number to display\n");
scanf("%d",&reg);
disp(&head,reg);
default:printf("Enter the correct choice\n");
}
printf("do you want to continue\n1-yes\n2-no\n");
scanf("%d",&ch);
}while(ch==1);
return 0;
}
void enter(struct student **h)
{
struct student *p,*q;
p=(struct student *)malloc(sizeof(struct student));
printf("enter the details of the student\n");
printf("Enter the register number\n");
scanf("%d",&p->reg_no);
printf("enter the name\n");
scanf("%s",p->name);
printf("Enter the cet rank ,pu marks and Xth marks\n");
scanf("%d%d%d",&p->cet,&p->pu,&p->X);
if(*h==NULL)
{
*h=p;
p->next=NULL;
}
else
{
for(q=*h;q->next!=NULL;q=q->next);
q->next=p;
p->next=NULL;
}
printf("%s\n",p->name);
}
void disp(struct student **h,int a)
{
struct student *p;
p=*h;
printf("In line 77\n");
while(p->next!=NULL)
{
printf("%s",p->name);
}
}

