#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int num;
	char name[15];
	char sex[5];
	int Chinese;
	int Maths;
	int English;
	struct node* pnext;

};
typedef struct node NODE;
typedef struct node* PNODE;

PNODE insertInfo(PNODE ptail)
{
	ptail->pnext = (PNODE)malloc(sizeof(NODE));
	if (ptail->pnext == NULL)
	{
		printf("内存分配失败,请重试！！！\n");
			return ptail;
	}
	ptail = ptail->pnext;
	ptail->pnext = NULL;
	printf("请输入学号：\n");
	scanf_s("%d",&(ptail->num));
	fflush(stdin);
	printf("请输入姓名:\n");
	scanf_s("%s",(ptail->name),15);
	fflush(stdin);
	printf("请输入性别：\n");
	scanf_s("%s", (ptail->sex),5);
	printf("请输入语文成绩：\n");
	scanf_s("%d", &(ptail->Chinese));
	fflush(stdin);
	printf("请输入数学成绩：\n"); 
	fflush(stdin);
	scanf_s("%d", &(ptail->Maths));
	fflush(stdin);
	printf("请输入英语成绩：\n");
	scanf_s("%d", &(ptail->English));
	fflush(stdin);
	printf("--------保存成功--------\n");

	return ptail;
}
void findInfo(PNODE phead) {
	PNODE p = phead->pnext;
	if (p == NULL)
	{
		printf("\n\n--------暂无信息!!!\n\n"); return;
	}
	   
	while (p!=NULL)
	{
     	printf("学号：%d    姓名：%s   性别：%s    语文：%d    数学：%d    英语：%d\n", p->num, p->name, p->sex, p->Chinese, p->Maths, p->English);
		p = p->pnext;
	}
	printf("\n\n"); return;
}
void removeInfo(PNODE phead) {
	PNODE p = phead;
	if (phead->pnext == NULL)
	{
		printf("-------------系统中暂无信息------------\n\n");
		return;
	}
	printf("\n\n----------已存信息-----------\n");
	findInfo(phead);
	PNODE p0 = phead->pnext;
	int i = 0;
	printf("请输入学号以便删除对应学生的成绩信息：\n");
		scanf_s("%d",&i);
		while ((p0->num)!=i&&p0->pnext!=NULL)
		{
			p = p0;
			p0 = p0->pnext;
		}
	
	    if (p0->num == i)
		{
			p->pnext = p0->pnext;
			free(p0);
			printf("-----------------删除成功-----------------\n\n");
		}
		else
		{
			printf("-------未发现对应学生信息!!!\n\n");
			return;
		}
}