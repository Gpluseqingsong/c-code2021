#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu(void) {
	printf("----------------------------------------------\n");
	printf("-----------------1.玩家VS电脑-----------------\n");
	printf("-----------------2.玩家VS玩家-----------------\n");
	printf("-----------------0.退出游戏-------------------\n");
	printf("----------------------------------------------\n");
	printf("请输入序号进行选择：\n");
}
void init(char(*a)[5]) {
	int i = 0;
	int j = 0;
	char* p = *a;
	for (j = 0; j < 5; j++)
	{
		for (i = 0; i < 5; i++) {
			p = *(a + j);
			*(p + i) = ' ';
		}
	}
	

}
void board(char(*a)[5]) {
	int n = 0;
	char* p = *a;
	for (n = 0; n < 5; n++) {
		p = *(a + n);
		printf(" %c | %c | %c | %c | %c \n", *p, *(p + 1), *(p + 2), *(p + 3), *(p + 4));
		if (n < 4)
			printf("-------------------\n");
	}
	printf("\n\n");
}
void computerPlay(char(*a)[5]){
	system("cls");
	int row = 1, col = 1;
	row = (rand() % 5) + 1;
	col= (rand() % 5) + 1;
	if (*(*(a + row - 1) + col - 1) == ' ')
	{
		*(*(a + row - 1) + col - 1) = '@';
		board(a);
		printf("----电脑在 第 %d 行，第 %d 列 放置了一个 @ \n\n",row,col);
	}
	else computerPlay(a);

}
void playerPlay(char(*a)[5],char z) {
	int row = 1, col = 1;
	printf("请输入 %c 想要放入的位置\n----行：",z);
	scanf_s("%d", &row);
	if (row >= 1 && row <= 5);
	else {
		printf("输入有误，请重新输入！！！\n");
		playerPlay(a,z); return;
	}
	printf("----列：");
	scanf_s("%d", &col);
	if (row >= 1 && row <= 5 && col >= 1 && col <= 5&& *(*(a + row - 1) + col - 1)==' ')
	{
		*(*(a + row - 1) + col - 1) = z;
		system("cls");
		board(a);
		printf("你在 第 %d 行，第 %d 列 放置了一个 %c\n\n",row,col,z);
		
	}
	else {
		printf("输入有误，请重新输入!!!\n");
		playerPlay(a,z);
	}

}
int ifWin(char(*a)[5]) 
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		if (**(a + i) == *(*(a + i) + 1) && *(*(a + i) + 1) == *(*(a + i) + 2) && *(*(a + i) + 2) == *(*(a + i) + 3) && *(*(a + i) + 3) == *(*(a + i) + 4) && *(*(a + i) + 1) != ' ')
			return 1;
	}
	for (i = 0; i < 5; i++)
	{
		if (*(*(a)+i) == *(*(a + 1) + i) && *(*(a + 1) + i) == *(*(a + 2) + i) && *(*(a + 2) + i) == *(*(a + 3) + i) && *(*(a + 3) + i) == *(*(a + 4) + i) && *(*(a + 1) + i) != ' ')
			return 1;
	}
	if (*(*(a)) == *(*(a + 1) + 1) && *(*(a + 1) + 1) == *(*(a + 2) + 2) && *(*(a + 2) + 2) == *(*(a + 3) + 3) && *(*(a + 3) + 3) == *(*(a + 4) + 4) && *(*(a + 4) + 4) != ' ')
		return 1;
	if (*(*(a + 4)) == *(*(a + 3) + 1) && *(*(a + 3) + 1) == *(*(a + 2) + 2) && *(*(a + 2) + 2) == *(*(a + 1) + 3) && *(*(a + 1) + 3) == *(*(a)+4) && *(*(a)+4) != ' ')
		return 1;
	return 0;
}
int ifDraw(char(*a)[5]) 
{
	int i = 0, j = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (*(*(a + i) + j) == ' ')
				return 0;
		}
	}
	return 1;
}
void START(char(*a)[5]) {
	init(a);
	system("cls");
	board(a);
	while (1)
	{
		int cho = 0;
		int t = 0;
		playerPlay(a,'#');
		t = ifWin(a); 
		if (t)
		{
			printf("-----玩家赢！！！\n\n");
			return;
		}
		t = ifDraw(a); 
		if (t) {
			printf("--------平局--------\n\n");
			return;
		}
		computerPlay(a);
		t = ifWin(a);
		if (t)
		{
			printf("-----电脑赢！！！\n\n");
			return;
		}
		t = ifDraw(a);
		if (t) {
			printf("--------平局--------\n\n");
			return;
		}
		printf("输入 1 ----继续游戏\n输入 0 ----结束本局游戏\n(若输入其它整数则默认继续游戏)\n\n---请输入：");
		scanf_s("%d", &cho);
		switch (cho)
		{
		case 1:break;
		case 0:
		printf("\n-----------游戏结束-----------\n\n");
				return;
		default:
			break;
		}
		printf("\n-----------游戏继续-----------\n\n");
	}
}
void start2(char(*a)[5])
{
	init(a);
	system("cls");
	board(a);
	while (1)
	{
		int cho = 0;
		int t = 0;
		playerPlay(a,'#');
		t = ifWin(a);
		if (t)
		{
			printf("----- # 玩家赢！！！\n\n");
			return;
		}
		t = ifDraw(a);
		if (t) {
			printf("--------平局--------\n\n");
			return;
		}
		playerPlay(a, '@');
		t = ifWin(a);
		if (t)
		{
			printf("----- @ 玩家赢！！！\n\n");
			return;
		}
		t = ifDraw(a);
		if (t) {
			printf("--------平局--------\n\n");
			return;
		}
		printf("输入 1 ----继续游戏\n输入 0 ----结束本局游戏\n(若输入其它整数则默认继续游戏)\n\n---请输入：");
		scanf_s("%d", &cho);
		switch (cho)
		{
		case 1:break;
		case 0:return;
		default:
			break;
		}
	}
}
int main(void)
{
	srand((unsigned int)time(NULL));
	char a[5][5];
	init(a);
	while (1) {
		menu();
		int c = 0;
		scanf_s("%d", &c);
		switch (c)
		{
		case 1:START(a); break;
		case 2:start2(a); break;
		case 0:exit(0); 
		default:
			printf("请重新选择：\n");
			break;
		}
	
	}
	

	return 0;
}
