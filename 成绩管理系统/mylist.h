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
		printf("�ڴ����ʧ��,�����ԣ�����\n");
			return ptail;
	}
	ptail = ptail->pnext;
	ptail->pnext = NULL;
	printf("������ѧ�ţ�\n");
	scanf_s("%d",&(ptail->num));
	fflush(stdin);
	printf("����������:\n");
	scanf_s("%s",(ptail->name),15);
	fflush(stdin);
	printf("�������Ա�\n");
	scanf_s("%s", (ptail->sex),5);
	printf("���������ĳɼ���\n");
	scanf_s("%d", &(ptail->Chinese));
	fflush(stdin);
	printf("��������ѧ�ɼ���\n"); 
	fflush(stdin);
	scanf_s("%d", &(ptail->Maths));
	fflush(stdin);
	printf("������Ӣ��ɼ���\n");
	scanf_s("%d", &(ptail->English));
	fflush(stdin);
	printf("--------����ɹ�--------\n");

	return ptail;
}
void findInfo(PNODE phead) {
	PNODE p = phead->pnext;
	if (p == NULL)
	{
		printf("\n\n--------������Ϣ!!!\n\n"); return;
	}
	   
	while (p!=NULL)
	{
     	printf("ѧ�ţ�%d    ������%s   �Ա�%s    ���ģ�%d    ��ѧ��%d    Ӣ�%d\n", p->num, p->name, p->sex, p->Chinese, p->Maths, p->English);
		p = p->pnext;
	}
	printf("\n\n"); return;
}
void removeInfo(PNODE phead) {
	PNODE p = phead;
	if (phead->pnext == NULL)
	{
		printf("-------------ϵͳ��������Ϣ------------\n\n");
		return;
	}
	printf("\n\n----------�Ѵ���Ϣ-----------\n");
	findInfo(phead);
	PNODE p0 = phead->pnext;
	int i = 0;
	printf("������ѧ���Ա�ɾ����Ӧѧ���ĳɼ���Ϣ��\n");
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
			printf("-----------------ɾ���ɹ�-----------------\n\n");
		}
		else
		{
			printf("-------δ���ֶ�Ӧѧ����Ϣ!!!\n\n");
			return;
		}
}