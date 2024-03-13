#include<windows.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>

typedef double ElemType;

typedef struct Asset
{
	int assetCode;//资产代号
	char assetName[100];//资产名称
	char custodian[100];//保管人
	char category[100];//资产类别
	struct Asset* next;
}Asset;


Asset* head = NULL;

//菜单
void Menu()
{
	system("color 0b");//淡浅绿色，好看:)
	printf("**********  固定资产管理系统           **********\n");
	printf("**********  1、建立资产表              **********\n");
	printf("**********  2、添加资产到资产表        **********\n");
	printf("**********  3、删除特定资产            **********\n");
	printf("**********  4、以资产代号查资产明细    **********\n");
	printf("**********  5、以资产名称查资产明细    **********\n");
	printf("**********  6、以资产保管人查资产明细  **********\n");
	printf("**********  0、退出该界面              **********\n");
}

//创建资产表
void createAssetTable()
{
	printf("请确认是否要创建资产表\n");
	printf("1--确认\n");
	printf("0--返回");
    char choose;
	scanf("%s",&choose);
	switch(choose){
        case '0':break;
		case '1':
		if (head != NULL)
	    {
		    printf("资产表已经建立!\n");
		    break;
	    }
        head = (Asset*)malloc(sizeof(Asset));
        if (head == NULL)
	    {
		    printf("存储空间建立失败!\n");
			exit(1);
	    }
        head->next = NULL;
	    printf("资产表已成功建立。\n");
        break;
    }
}

//增加
void addAsset()
{
	if (head == NULL)
	{
		printf("资产表还没建立。请先建立资产表!\n");
		return;
	}
	Asset* newAsset = (Asset*)malloc(sizeof(Asset));//建立存储空间
	if (newAsset == NULL)
	{
		printf("存储空间建立失败。\n");
		exit(1);
	}
	printf("请输入资产代号: ");
	scanf("%d", &newAsset->assetCode);
	printf("请输入资产名称: ");
	scanf("%s", newAsset->assetName,100);
	printf("固定资产分为电脑类、网络类、空调类及教学类\n");
	printf("请输入资产类别:");
	scanf("%s", newAsset->category, 100);
	printf("请输入保管人: ");
	scanf("%s", newAsset->custodian,100);
	newAsset->next = head->next;
	head->next = newAsset;
	printf("新资产增加成功。\n");
}

//删除
void deleteAsset()
{
	if (head == NULL || head->next == NULL)//判断表是否存在
	{
		printf("资产表空空如也。\n");
		return;
	}
	int code=0;
	printf("请输入要删除的资产的代号。\n");
	scanf("%d", &code);
	Asset* current = head->next;//current为表头下一个节点
	Asset* previous = head;
	while (current != NULL && current->assetCode != code)//判断所选的节点是否为空且表中是否有要删除的节点，有则执行
	{
		previous = current;
		current = current->next;
	}
	if (current == NULL)
	{
		printf(" 未在资产表中找到代号为%d的资产。\n", code);
		return;
	}
	previous->next = current->next;
	free(current);//释放节点
	printf("资产表中所选代号的资产信息已经删除成功。\n");
}



int main()
{
	SetConsoleOutputCP(65001);//防止终端输出乱码
	int choice;
	do {
		Menu();
		printf("请输入编号进行操作:");
		scanf("%d", &choice);
		system("cls");
		switch (choice)
		{
		case 1:
			createAssetTable();
			break;
		case 2:
			addAsset();
			break;
		case 3:
			deleteAsset();
			break;
		case 0:
			printf("退出系统!\n");
			break;
		default:
			printf("编号不存在，请重新输入!\n");
		}
	} while (choice != 0);
	
	return 0;
}