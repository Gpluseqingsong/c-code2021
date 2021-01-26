#include"mylist.h"
void menu(void)
{
	printf("                成绩管理系统   \n\n");
	printf("----------------0.刷新界面----------------\n");
	printf("----------------1.查询信息----------------\n");
	printf("----------------2.存入信息----------------\n");
	printf("----------------3.删除信息----------------\n");
	printf("----------------4.修改信息----------------\n");
	printf("----------------5.退出系统----------------\n\n");

}
void reFresh(void) {
	system("cls");
	menu();
}
PNODE keyInteract(PNODE ptail,PNODE phead)
{
	int a = 0;
	scanf_s("%d", &a);
	switch (a)
	{
	case 0:reFresh(); break;
	case 1:printf("--------查询信息--------\n");findInfo(phead); 
		system("pause");
		break;
	case 2:printf("--------存入信息--------\n");ptail=insertInfo(ptail);
		system("pause");
		break;
	case 3:printf("--------删除信息--------\n");removeInfo(phead);
		system("pause");
		break;
	case 4:printf("--------修改信息--------\n");//changeInfo();
		printf("-----此功能暂未开放-----\n\n");
		system("pause");
		break;
	case 5:exit(0);
	default:
		printf("--------------输入有误，请重新输入：------------\n");

		break;
	}
	return ptail;

}
int main(void)
{
	PNODE phead = (PNODE)malloc(sizeof(NODE));
	if (phead == NULL) {
		printf("-----内存分配失败，程序终止！！！----");
		return 1;

	}
	PNODE ptail = phead;
	phead->pnext = NULL;

	menu();
	printf("----------------------------------------------\n");
	printf("----请输入你所需请求对应的序号：\n");
	while (1)
	{
		ptail=keyInteract(ptail,phead);
		printf("----请输入你所需请求对应的序号：\n");
	}
	return 0;

}