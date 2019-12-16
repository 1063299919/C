/******************************************************************************

                  版权所有 (C), 2001-2011, rookiest

 ******************************************************************************
  文 件 名   : main.c
  版 本 号   : 初稿
  作    者   : rookiest
  生成日期   : 2019年12月16日
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
******************************************************************************/
#include<stdio.h>
typedef struct Student
{
    int number;
    char name[10];
    int score;
    struct Student *next_p;
}student;//定义学生的结构体

student *head_p = NULL;

void init(void)
{
    head_p = (student*)malloc(sizeof(student));
    head_p->next_p = NULL;
}