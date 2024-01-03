
#include"Contact.h"

//把文件的联系人加载到通讯录中
void LoadContact(Contact* ps)
{
	PeoInfo temp = { 0 };
	FILE* pfread = fopen("contact.dat", "rb");
	if (pfread == NULL)
	{
		perror("Load file contact.dat");
		return;
	}
	while (fread(&temp, sizeof(PeoInfo), 1, pfread))
	{
		ps->date[ps->size] = temp;
		ps->size++;
		CheckCapacity(ps);
	}
	fclose(pfread);
	pfread = NULL;
}


//初始化通讯录
void InitContact( Contact* ps)
{
	ps->date = ( PeoInfo*)malloc(3 * sizeof( PeoInfo));
	if (ps->date == NULL)
		return;
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	LoadContact(ps);
}

//检查容量，若已满返回则开辟2个空间，开辟成功返回1，失败返回0,若未满，也返回1
int CheckCapacity(Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(ps->date, (ps->capacity + 2) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			ps->date = ptr;
			ps->capacity += 2;
			return 1;
		}
		else
		{
			printf("空间不足，增加失败!\n");
			return 0;
		}
	}
	return 1;
}
//增加联系人
void AddContact( Contact* ps)
{
	int flag=CheckCapacity(ps);
	if(flag==1)
	{
		printf("请输入姓名:\n");
		scanf("%s",ps->date[ps->size].name);
		printf("请输入年龄:\n");
		scanf("%d",&(ps->date[ps->size].age));
		printf("请输入性别:\n");
		scanf("%s", ps->date[ps->size].sex);
		printf("请输入电话:\n");
		scanf("%s", ps->date[ps->size].tele);
		printf("请输入地址:\n");
		scanf("%s", ps->date[ps->size].addr);
		ps->size++;
		printf("添加成功!\n");
	}
}

//展示通讯录
void ShowContact(const Contact* ps)
{
	int i = 0;
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
	for (i = 0; i < ps->size; i++)
	{
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->date[i].name,
			ps->date[i].age,
			ps->date[i].sex,
			ps->date[i].tele,
			ps->date[i].addr);
	}
}

//通过名字来查找，成功返回该联系人下标，失败返回-1。用static使得只在该头文件使用
static int FindByName(const Contact* ps, char* name)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->date[i].name, name) == 0)
			return i;
	}
	return -1;
}

//删除联系人
void DelContact(Contact* ps)
{
	int pos;//所要查找的联系人的下标
	char name[MAX_NAME];
	printf("请输入要删除的联系人:\n");
	scanf("%s", name);
	pos = FindByName(ps, name);
	if(pos==-1)
		printf("该联系人不存在!\n");
	else
	{
		//删除联系人
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;//联系人的总数减少一个
		printf("删除成功\n");
	}
}

//查找联系人
void SearchContact(Contact* ps)
{
	int pos=0;
	char name[MAX_NAME];
	printf("请输入要查找的联系人名字:\n");
	scanf("%s", name);
	pos = FindByName(ps, name);
	if (pos == -1)
		printf("该联系人不存在!\n");
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->date[pos].name,
			ps->date[pos].age,
			ps->date[pos].sex,
			ps->date[pos].tele,
			ps->date[pos].addr);
	}
}

//修改联系人
void ModifyContact(Contact* ps)
{
	int pos;
	char name[MAX_NAME];
	printf("请输入要修改的联系人名字:\n");
	scanf("%s", name);
	pos = FindByName(ps, name);
	if (pos == -1)
		printf("该联系人不存在!\n");
	else
	{
		printf("请输入姓名:\n");
		scanf("%s", ps->date[pos].name);
		printf("请输入年龄:\n");
		scanf("%d", &(ps->date[pos].age));
		printf("请输入性别:\n");
		scanf("%s", ps->date[pos].sex);
		printf("请输入电话:\n");
		scanf("%s", ps->date[pos].tele);
		printf("请输入地址:\n");
		scanf("%s", ps->date[pos].addr);
		printf("修改成功!\n");
	}
}

//按名字比较
int cmp(PeoInfo* e1, PeoInfo* e2)
{
	return strcmp(e1->name, e2->name);
}

//释放动态开辟的空间
void DestroyContact(Contact* ps)
{
	free(ps->date);
	ps->date = NULL;
}

//保存通讯录到文件
void SaveContact(Contact* ps)
{
	int i = 0;
	FILE* pfwrite = fopen("contact.dat", "wb");
	if (pfwrite == NULL)
	{
		perror("Save file contact.dat");
		return;
	}
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->date[i]), sizeof(PeoInfo), 1, pfwrite);
	}
	fclose(pfwrite);
	pfwrite = NULL;
	printf("保存成功!\n");
}