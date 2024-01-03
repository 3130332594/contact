#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 5 
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3//默认刚开始三个联系人的空间

enum option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE
};

//通讯录类型
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;
typedef struct Contact
{
	struct PeoInfo *date;//存放一个信息
	int size;//记录已有元素个数
	int capacity;//记录当前的最大容量
}Contact;


//申明函数
//初始化联系人
void InitContact(Contact *ps);
//增加联系人
void AddContact(Contact* ps);
//查看联系人
void ShowContact(Contact* ps);
//删除联系人
void DelContact(Contact* ps);
//查找联系人
void SearchContact(const Contact* ps);
//修改联系人
void ModifyContact(Contact* ps);
//按名字比较
int cmp(PeoInfo* e1, PeoInfo* e2);
//释放动态开辟的空间
void DestroyContact(Contact* ps);
//保存通讯录到文件
void SaveContact(Contact* ps);