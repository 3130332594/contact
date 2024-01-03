#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 5 
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3//Ĭ�ϸտ�ʼ������ϵ�˵Ŀռ�

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

//ͨѶ¼����
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
	struct PeoInfo *date;//���һ����Ϣ
	int size;//��¼����Ԫ�ظ���
	int capacity;//��¼��ǰ���������
}Contact;


//��������
//��ʼ����ϵ��
void InitContact(Contact *ps);
//������ϵ��
void AddContact(Contact* ps);
//�鿴��ϵ��
void ShowContact(Contact* ps);
//ɾ����ϵ��
void DelContact(Contact* ps);
//������ϵ��
void SearchContact(const Contact* ps);
//�޸���ϵ��
void ModifyContact(Contact* ps);
//�����ֱȽ�
int cmp(PeoInfo* e1, PeoInfo* e2);
//�ͷŶ�̬���ٵĿռ�
void DestroyContact(Contact* ps);
//����ͨѶ¼���ļ�
void SaveContact(Contact* ps);