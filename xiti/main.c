/******************************************************************************

                  版权所有 (C), 2001-2011, DeRoy

 ******************************************************************************
  文 件 名   : main.c
  版 本 号   : 初稿
  作    者   : DeRoy
  生成日期   : 2019年12月7日
  最近修改   :
  功能描述   : 学生信息管理系统
  函数列表   :
*
*       1.                Add_Information		添加学生信息	
*       2.                Change_Information	修改学生信息
*       3.                Delete_Information	删除学生信息
*       4.                Head					学生信息管理系统字符图标
*       5.                Init					学生信息管理系统初始化字符图标
*       6.                isLogin				判断是否登录成功
*       7.                Lessons_Information	课程信息
*       8.                Login					登录系统
*       9.                main					主函数
*       10.               MainMenu				主菜单界面
*       11.               MenuSelect			菜单选择
*       12.               Quit					退出程序或重新进入主菜单
*       13.               Search_Information	查询学生信息
*       14.               Show_Information		显示所有学生信息
*       15.               Sort_Information		对学生信息进行排序	
*       16.               StuManage				学生信息管理系统 管理端字符图标
*       17.               Swap					交换两个学生信息
*

  修改历史   :
  1.日    期   : 2019年12月7日
    作    者   : DeRoy
    修改内容   : 创建文件

******************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#define MANAGER_NAME "DeRoy"
#define MANAGER_PASSWORD "666666"

typedef enum Menu
{
	Exit,Lessons,Show,Add,Sort,Change,Delete,Search
}MENU;

typedef struct Student //类型首字母大写以和变量区分
{
	char cName[50];
	char cNumber[50];
	int iMath;
	int iEnglish;
	int iProgram;
	int iScore;
	struct Student  *pNext;
}STU,*PSTU;	

PSTU pHead = NULL;	//信息学生头结点
PSTU pNew = NULL;	//待添加学生信息
size_t iCount = 0;	//学生总数
char UserName[10];
char UserWord[10];

void Init();
void MainMenu();
void StuManage();
void Head();
void Login();
int isLogin();

int MenuSelect();
void Quit();
void Lessons_Information();
void Show_Information();
void Add_Information();
void Sort_Information();
void Change_Information();
void Delete_Information();
void Search_Information();
void Swap(PSTU stu1,PSTU stu2);
int main()
{
	Init();
	MainMenu();
	return 0;
}

/*****************************************************************************
 函 数 名  : MainMenu
 功能描述  : 主菜单界面
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2019年12月7日
    作    者   : DeRoy
    修改内容   : 新生成函数

*****************************************************************************/
void MainMenu()
{
	if (isLogin())
	{
		//登录成功
		switch (MenuSelect())	//菜单选择
		{
		case Exit:		//退出程序
			system("cls");
			Head();
			Quit();	//退出或返回主菜单
			break;
		case Lessons:	//课程信息
			system("cls");
			Lessons_Information();
			Quit();
			break;
		case Show:		//显示所有学生信息
			system("cls");
			Show_Information();
			Quit();
			break;
		case Add:		//添加学生信息
			system("cls");
			Add_Information();
			Quit();
			break;
		case Sort:		//对学生信息总分进行排序
			system("cls");
			Sort_Information();
			Quit();
			break;
		case Change:	//修改学生信息
			system("cls");
			Change_Information();
			Quit();
			break;
		case Delete:	//删除学生信息
			system("cls");
			Delete_Information();
			Quit();
			break;
		case Search:	//查询学生信息
			system("cls");
			Search_Information();
			Quit();
			break;
		}
	}
}

/*****************************************************************************
 函 数 名  : Init
 功能描述  : 学生信息管理系统初始化字符图标
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2019年12月7日
    作    者   : DeRoy
    修改内容   : 新生成函数

*****************************************************************************/
void Init()
{
	/****************初始化数据****************/
	pHead = (PSTU)malloc(sizeof(STU));
	pHead->pNext = NULL;
	SetConsoleTitle(L"学生信息管理系统(管理员)");

	/****************载入界面*****************/
	printf("欢迎使用本系统！\n");
	int i;
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t");
	char heihei[] = { "即将进入学生管理系统..." };
	for (i = 0; i < strlen(heihei); i++)
	{
		printf("%c", heihei[i]);
		Sleep(10);
	}
	system("CLS");
	StuManage();
	system("cls");
	Login();
}

//学生信息管理系统字符图标
void Head()
{
	printf("\n");
	printf("\t\t\t\t\t╭ ⺌ % ╮                   ╭ ```╮  \n");
	printf("\t\t\t\t\t(@^o^@) 学生信息管理系统 (⌒:⌒)\n");
	printf("\t\t\t\t\t(~):(~)                  (~)v(~) \n");
	printf("\n\n\n");
}

//学生信息管理系统 管理端字符图标
void StuManage()
{
	printf("\n");
	printf("\t\t\t\t\t╭ ⺌ % ╮                           ╭ ```╮  \n");
	printf("\t\t\t\t\t(@^o^@) 学生信息管理系统   管理端(⌒:⌒)\n");
	printf("\t\t\t\t\t(~):(~)                          (~)v(~) \n");
	printf("\n\n\n");
}

/*****************************************************************************
 函 数 名  : Login
 功能描述  : 登录系统
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2019年12月7日
    作    者   : DeRoy
    修改内容   : 新生成函数

*****************************************************************************/
void Login()
{
	StuManage();
	char xing[] = { "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " };
	for (int i = 0; i<strlen(xing); i++)
	{
		printf("%c", xing[i]);
		Sleep(10);
	}
	printf("\n\n\t\t\t\t\t\t请输入您的账号密码:\n\n\n\n\t\t\t\t\t\t账号:");
	gets(UserName);
	printf("\n\n\t\t\t\t\t\t密码:");
	gets(UserWord);
}

/*****************************************************************************
 函 数 名  : isLogin
 功能描述  : 判断是否登录成功
 输入参数  : 无
 输出参数  : 无
 返 回 值  : int
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2019年12月7日
    作    者   : DeRoy
    修改内容   : 新生成函数

*****************************************************************************/
int isLogin()
{
	int times = 0;	//密码输入次数
	while (!(strcmp(UserName, MANAGER_NAME) == 0 && strcmp(UserWord, MANAGER_PASSWORD) == 0))
	{
		times++;	//密码输入错误 times++
		if (times > 3)
		{
			printf("\n\n\n\n\t\t\t\t账号或密码输入错误累计达到%d次，系统将于3秒后关闭", times);
			Sleep(1000);
			system("cls");
			char shutdown[] = { "系统将于%d秒后关闭..." };
			for (int i = 0; i < 3; i++)
			{
				printf(shutdown, 3 - i);
				Sleep(1000);
				system("cls");
			}
			exit(0);
		}
		printf("\n\n\n\n\t\t\t\t账号或密码输入错误,你还有%d次登录机会，按任意键重新登录...", 4 - times);
		getch();
		system("cls");
		Login();
	}
	return 1;
}

/*****************************************************************************
 函 数 名  : MenuSelect
 功能描述  : 菜单选择
 输入参数  : 无
 输出参数  : 无
 返 回 值  : int
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2019年12月7日
    作    者   : DeRoy
    修改内容   : 新生成函数

*****************************************************************************/
int MenuSelect()
{
	char c;
	do
	{
		system("cls");
		Head();
		printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
		printf("\t\t\t\t   │              学生信息管理系统              │\n");
		printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
		printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   │ 1. 课程安排                    2. 显示数据 │\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   │ 3. 添加数据                    4. 数据排名 │\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   │ 5. 修改数据                    6. 删除数据 │\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   │ 7. 查询数据                    0. 退出程序 │\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   └────────────────────────────────────────────┘\n");
		printf("\t\t\t\t\t\t  请您选择(0-7):");
		c = getche();
	} while (c < '0' || c > '7');
	return c - '0';
}

/*****************************************************************************
 函 数 名  : Lessons_Information
 功能描述  : 课程信息
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2019年12月7日
    作    者   : DeRoy
    修改内容   : 新生成函数

*****************************************************************************/
void Lessons_Information()
{
	Head();
	printf("\t\t\t╔════════════╦════════════╦════════════╦════════════╦════════════╗\n");
	printf("\t\t\t║  高等数学  ║  大学英语  ║  高等数学  ║  大学英语  ║  高等数学  ║\n");
	printf("\t\t\t╚════════════╝════════════╝════════════╝════════════╝════════════╝\n");
	printf("\t\t\t║  离散数学  ║  大学物理  ║  离散数学  ║  大学物理  ║  离散数学  ║\n");
	printf("\t\t\t╚════════════╝════════════╝════════════╝════════════╝════════════╝\n");
	printf("\t\t\t║            ║            ║            ║            ║            ║\n");
	printf("\t\t\t╚════════════╝════════════╝════════════╝════════════╝════════════╝\n");
	printf("\t\t\t║  程序设计  ║  离散数学  ║  程序设计  ║            ║  程序设计  ║\n");
	printf("\t\t\t╚════════════╝════════════╝════════════╝════════════╝════════════╝\n");
	printf("\t\t\t║            ║            ║            ║            ║            ║\n");
	printf("\t\t\t╚════════════╝════════════╝════════════╝════════════╝════════════╝\n");
}

/*****************************************************************************
 函 数 名  : Quit
 功能描述  : 退出程序或重新进入主菜单
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2019年12月7日
    作    者   : DeRoy
    修改内容   : 新生成函数

*****************************************************************************/
void Quit()
{
	char ch;
	printf("\n\t ");
	for (int i = 0; i < 50; i++)
	{
		printf("* ");
		Sleep(10);
	}
	printf("\n\n\t\t\t\t要返回登录界面按任意键\t\t退出程序请按Esc键\n");
	ch = getch();
	if (ch == 0x1b)	//esc键按下
	{
		_exit(0);
	}
	//重新进入主菜单
	MainMenu();
}

/*****************************************************************************
 函 数 名  : Show_Information
 功能描述  : 显示所有学生信息
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2019年12月7日
    作    者   : DeRoy
    修改内容   : 新生成函数

*****************************************************************************/
void Show_Information()
{
	Head();
	PSTU pCurrent = pHead->pNext;	//指向第一个节点 如果链表为 NULL pCurrent为 NULL
	int index = 1;
	printf("\t\t\t\t**********************本名单共有 %d 名学生*********************\n\n\n", iCount);
	printf("\t\t\t\t序号\t学号\t姓名\t高数\t英语\t程序设计\t总分\n\n");
	while (pCurrent != NULL)	//遍历输出所有学生
	{
		printf("\t\t\t\t %d\t %s\t %s\t %d\t %d\t %d\t\t%d\n", index, pCurrent->cNumber, pCurrent->cName, pCurrent->iMath
			, pCurrent->iEnglish, pCurrent->iProgram, pCurrent->iScore);
		pCurrent = pCurrent->pNext;	//指向下一个节点
		index++;	//下标加加
	}
	pCurrent = NULL;
	printf("\n\n\n");
}

/*****************************************************************************
 函 数 名  : Add_Information
 功能描述  : 添加学生信息
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2019年12月7日
    作    者   : DeRoy
    修改内容   : 新生成函数

*****************************************************************************/
void Add_Information()
{
	for (int in = 1; in <= 3; in++)
	{
		Sleep(100);
		printf(".");
	}
	system("CLS");
	Head();
	/************添加学生信息***********/
	pNew = (PSTU)malloc(sizeof(STU));
	printf("\t\t\t\t\t\t添加学生信息:\n\n\n\n\t\t\t\t\t\t学号:");
	scanf("%s", pNew->cNumber);
	printf("\n\t\t\t\t\t\t姓名:");
	scanf("%s", pNew->cName);
	printf("\n\t\t\t\t\t\t高等数学:");
	scanf("%d", &pNew->iMath);
	printf("\n\t\t\t\t\t\t大学英语:");
	scanf("%d", &pNew->iEnglish);
	printf("\n\t\t\t\t\t\t程序设计:");
	scanf("%d", &pNew->iProgram);
	pNew->iScore = pNew->iEnglish + pNew->iMath + pNew->iProgram;
	pNew->pNext = pHead->pNext;
	pHead->pNext = pNew;
	pNew = NULL;
	iCount++;
}

/*****************************************************************************
 函 数 名  : Sort_Information
 功能描述  : 对学生信息进行排序
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2019年12月7日
    作    者   : DeRoy
    修改内容   : 新生成函数

*****************************************************************************/
void Sort_Information()
{
	Head();
	if (iCount < 2)		//一个学生不需要排序
	{
		system("cls");
		Show_Information();
		return;	
	}
		
	//从大到小排序 冒泡排序
	PSTU pCurrent,pTemp;
	STU Temp;
	for (pCurrent = pHead->pNext; pCurrent != NULL; pCurrent = pCurrent->pNext)
	{
		for (pTemp = pCurrent->pNext; pTemp != NULL; pTemp = pTemp->pNext)
		{
			if (pCurrent->iScore < pTemp->iScore)
			{
				Swap(&Temp, pCurrent);
				Swap(pCurrent, pTemp);
				Swap(pTemp, &Temp);
			}
		}
	}
	system("cls");
	Show_Information();
}

/*****************************************************************************
 函 数 名  : Change_Information
 功能描述  : 修改学生信息
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2019年12月7日
    作    者   : DeRoy
    修改内容   : 新生成函数

*****************************************************************************/
void Change_Information()
{
	Head();
	char ID[10];
	char operate;
	printf("\t\t\t\t\t\t修改学生信息：\n\n\n");
	printf("\t\t\t\t\t\t请输入学生学号：");
	scanf("%s", ID);
	//遍历学生信息
	PSTU pCurrent = pHead->pNext;	//指向第一个节点 如果链表为 NULL pCurrent为 NULL
	while (pCurrent != NULL)	//遍历所有学生
	{
		if (strcmp(pCurrent->cNumber, ID) == 0)
		{
			printf("\n\n\n\t\t\t\t\t要修改的学生信息...\n\n");
			printf("\n\n\t\t\t\t\t学号\t姓名\t高数\t英语\t程序设计\t总分\n\n");
			printf("\t\t\t\t\t %s\t %s\t %d\t %d\t %d\t\t%d\n", pCurrent->cNumber,
				pCurrent->cName, pCurrent->iMath
				, pCurrent->iEnglish, pCurrent->iProgram,pCurrent->iScore);
			printf("\n\n\n\t\t\t\t\t是否修改该学生信息(y/Enter):");
			operate = getch();
			if (operate == 'y' || operate == 'Y' || operate == 13)	//13是回车键Enter的ASCII值
			{
				//这里又可以做一个菜单单独修改某一个变量，为了方便，直接修改全部变量
				printf("\n\n\t\t\t\t\t重新输入学生信息:\n\n\t\t\t\t\t\t学号:");
				scanf("%s", pCurrent->cNumber);
				printf("\n\t\t\t\t\t\t姓名:");
				scanf("%s", pCurrent->cName);
				printf("\n\t\t\t\t\t\t高等数学:");
				scanf("%d", &pCurrent->iMath);
				printf("\n\t\t\t\t\t\t大学英语:");
				scanf("%d", &pCurrent->iEnglish);
				printf("\n\t\t\t\t\t\t程序设计:");
				scanf("%d", &pCurrent->iProgram);
				pCurrent->iScore = pCurrent->iEnglish + pCurrent->iMath + pCurrent->iProgram;
				printf("\n\n\n\t\t\t\t\t修改成功...\n\n");
				pCurrent = NULL;
				return;
			}
			else {
				printf("\n\n\n\t\t\t\t\t修改失败...\n\n");
				return;
			}
			return;
		}
		pCurrent = pCurrent->pNext;	//指向下一个节点
	}
	pCurrent = NULL;
	printf("\n\n\n\n\t\t\t\t\t   没有找到要查询的学生信息......\n\n");
}

/*****************************************************************************
 函 数 名  : Delete_Information
 功能描述  : 删除学生信息
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2019年12月7日
    作    者   : DeRoy
    修改内容   : 新生成函数

*****************************************************************************/
void Delete_Information()
{
	Head();
	char ID[10];
	char operate;
	printf("\t\t\t\t\t\t删除学生信息：\n\n\n");
	printf("\t\t\t\t\t\t请输入学生学号：");
	scanf("%s", ID);
	//遍历学生信息
	PSTU pCurrent = pHead;	//指向头结点 
	
	while (pCurrent->pNext != NULL)	//遍历输出所有学生
	{
		if (strcmp(pCurrent->pNext->cNumber, ID) == 0)
		{
			//信息库里面有要删除的学生信息
			printf("\n\n\n\t\t\t\t\t要删除的学生信息...\n\n");
			printf("\n\n\t\t\t\t\t学号\t姓名\t高数\t英语\t程序设计\t总分\n\n");
			printf("\t\t\t\t\t %s\t %s\t %d\t %d\t %d\t\t%d\n",pCurrent->pNext->cNumber, 
				pCurrent->pNext->cName, pCurrent->pNext->iMath, pCurrent->pNext->iEnglish
				, pCurrent->pNext->iProgram,pCurrent->pNext->iScore);
			printf("\n\n\n\t\t\t\t\t是否删除该学生信息(y/Enter):");
			operate = getch();
			if (operate == 'y' || operate == 'Y' || operate == 13)	//13是回车键Enter的ASCII值
			{
				//删除学生信息
				PSTU pTemp = pCurrent->pNext;	//定义PSTU指针 pTemp 指向要删除的节点
				pCurrent->pNext = pTemp->pNext;	
				free(pTemp);
				iCount--;
				printf("\n\n\n\t\t\t\t\t删除成功...\n\n");
				return;
			}
			else{
				printf("\n\n\n\t\t\t\t\t删除失败...\n\n");
				return;
			}
		}
		pCurrent = pCurrent->pNext;	//指向下一个节点
	}
	printf("\n\n\n\n\t\t\t\t\t   没有找到要删除的学生信息......\n\n");
}

/*****************************************************************************
 函 数 名  : Search_Information
 功能描述  : 查询学生信息
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2019年12月7日
    作    者   : DeRoy
    修改内容   : 新生成函数

*****************************************************************************/
void Search_Information()
{
	Head();
	char ID[10];
	printf("\t\t\t\t\t\t查询学生信息：\n\n\n");
	printf("\t\t\t\t\t\t请输入学生学号：");
	scanf("%s", ID);
	//遍历学生信息
	PSTU pCurrent = pHead->pNext;	//指向第一个节点 如果链表为 NULL pCurrent为 NULL
	while (pCurrent != NULL)		//遍历所有学生
	{
		if (strcmp(pCurrent->cNumber, ID) == 0)
		{
			printf("\n\n\n\t\t\t\t\t要查询的学生信息...\n\n");
			printf("\n\n\t\t\t\t\t学号\t姓名\t高数\t英语\t程序设计\t总分\n\n");
			printf("\t\t\t\t\t %s\t %s\t %d\t %d\t %d\t\t%d\n", pCurrent->cNumber,
				pCurrent->cName, pCurrent->iMath
				, pCurrent->iEnglish, pCurrent->iProgram,pCurrent->iScore);
			return;
		}
		pCurrent = pCurrent->pNext;	//指向下一个节点
	}
	pCurrent = NULL;
	printf("\n\n\n\n\t\t\t\t\t   没有找到要查询的学生信息......\n\n");
}

/*****************************************************************************
 函 数 名  : Swap
 功能描述  : 交换两个学生信息
 输入参数  : PSTU stu1  
             PSTU stu2  
 输出参数  : 无
 返 回 值  : void
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2019年12月7日
    作    者   : DeRoy
    修改内容   : 新生成函数

*****************************************************************************/
void Swap(PSTU stu1, PSTU stu2)
{
	strcpy(stu1->cName, stu2->cName);
	strcpy(stu1->cNumber, stu2->cNumber);
	stu1->iEnglish = stu2->iEnglish;
	stu1->iMath = stu2->iMath;
	stu1->iProgram = stu2->iProgram;
	stu1->iScore = stu2->iScore;
}
