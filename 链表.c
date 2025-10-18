#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct STUDENT
{
	char name[20];
	char sex[10];
	int age;
	struct STUDENT *next;
}STUDENT;					
//创建一个用于存放数据的结构体，在其中定义指向下一个节点的指针 

STUDENT *createNODE (char* name,char* sex,int x)
{
	STUDENT *p=malloc(sizeof(STUDENT));
	strcpy(p->name,name);
	strcpy(p->sex,sex);
	p->age =x;
	p->next =NULL;
	return p;
} 
//一个创建新节点的函数 

void addbefore(STUDENT **head,char *name,char*sex,int x)
{
	STUDENT *new=createNODE(name,sex,x);
	new->next =*head;	//将新节点的指针指向原来的首节点 
	*head=new;	//将头指针指向新节点
}
//头插法插入一个节点  

void append(STUDENT*head,char *name,char*sex,int x)
{
	STUDENT *new=createNODE(name, sex, x);
	
	STUDENT *address=head;
	while(address->next !=NULL)
	{
		address=address->next;
	}	//遍历所有节点，循环结束时address即为最后一个节点 
	
	address->next=new;
}
//尾插法插入一个节点 

void insert(STUDENT *head,char*nameins,char *name,char*sex,int x)
{
	STUDENT *new=createNODE(name,sex,x);
	STUDENT *address=head;
	int flag=0; 
	while(address!=NULL)
	{
		if(strcmp(address->name,nameins)==0)
		{
			new->next=address->next;	//先用新节点的next指向目标节点后一节点的首地址防止链表断裂 
			address->next=new;
			flag=1;
			break;
		}
		else
		{
			address=address->next;	//遍历链表 
		}
	}
	if(flag==1)printf("插入成功\n");
	else printf("插入失败\n");
}
//在链表中间插入一个节点 

void delete(STUDENT **head,char *namedel)
{
	STUDENT *prev=*head;
	STUDENT *address=prev->next;
	int flag=0;
	if(strcmp(prev->name,namedel)==0)	//判断要删除的节点是不是第一个节点 
	{
		*head=prev->next;
		free(prev);
		flag=1;
	}
	else while(address!=NULL)
	{
		if(strcmp(address->name,namedel)==0)	
		{
			prev->next=address->next;
			free(address);
			flag=1;
			break;
		}
		else 
		{
			prev=prev->next;
			address=prev->next;
		}	//遍历链表 
	}
	if(flag==1)printf("删除成功\n");
	else printf("未找到要删除的节点\n");
}
//删除一个节点 

STUDENT *query(STUDENT *head,char *nameq)
{
	STUDENT *address=head;
	while(address!=NULL)
	{
		if(strcmp(address->name,nameq)==0)
		{
			return address;
		}
		else address=address->next;
	}
	return NULL;
}
//查找一个节点 

void print(STUDENT *head)
{
	STUDENT *address=head;
	while(address!=NULL)
	{
		printf("%s %s %d\n",address->name,address->sex,address->age);
		address=address->next; 
	 } 
}
//遍历输出一个链表 

void destory(STUDENT *head)
{
	STUDENT *p1=head;
	STUDENT *p2;
	while(p1!=NULL)
	{
		p2=p1->next;
		free(p1);
		p1=p2;
	}
	printf("销毁完成\n");
}
//销毁链表 

int main()
{
	STUDENT *head=NULL;		//初始化链表头 
	head=createNODE("Jack","male",18);
	addbefore(&head, "Lily", "female", 20);
	append(head,"Tom", "male", 19) ;
	insert(head,"Jack","Peter","male",17);
	delete (&head,"Jack"); 
	STUDENT *info=query(head,"Peter");
	if(info!=NULL)printf("学生信息%s %s %d",info->name,info->sex,info->age);
	else printf("未找到");
	print(head);
	destory(head); 
}

