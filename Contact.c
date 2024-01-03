
#include"Contact.h"

//���ļ�����ϵ�˼��ص�ͨѶ¼��
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


//��ʼ��ͨѶ¼
void InitContact( Contact* ps)
{
	ps->date = ( PeoInfo*)malloc(3 * sizeof( PeoInfo));
	if (ps->date == NULL)
		return;
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	LoadContact(ps);
}

//��������������������򿪱�2���ռ䣬���ٳɹ�����1��ʧ�ܷ���0,��δ����Ҳ����1
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
			printf("�ռ䲻�㣬����ʧ��!\n");
			return 0;
		}
	}
	return 1;
}
//������ϵ��
void AddContact( Contact* ps)
{
	int flag=CheckCapacity(ps);
	if(flag==1)
	{
		printf("����������:\n");
		scanf("%s",ps->date[ps->size].name);
		printf("����������:\n");
		scanf("%d",&(ps->date[ps->size].age));
		printf("�������Ա�:\n");
		scanf("%s", ps->date[ps->size].sex);
		printf("������绰:\n");
		scanf("%s", ps->date[ps->size].tele);
		printf("�������ַ:\n");
		scanf("%s", ps->date[ps->size].addr);
		ps->size++;
		printf("��ӳɹ�!\n");
	}
}

//չʾͨѶ¼
void ShowContact(const Contact* ps)
{
	int i = 0;
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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

//ͨ�����������ң��ɹ����ظ���ϵ���±꣬ʧ�ܷ���-1����staticʹ��ֻ�ڸ�ͷ�ļ�ʹ��
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

//ɾ����ϵ��
void DelContact(Contact* ps)
{
	int pos;//��Ҫ���ҵ���ϵ�˵��±�
	char name[MAX_NAME];
	printf("������Ҫɾ������ϵ��:\n");
	scanf("%s", name);
	pos = FindByName(ps, name);
	if(pos==-1)
		printf("����ϵ�˲�����!\n");
	else
	{
		//ɾ����ϵ��
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;//��ϵ�˵���������һ��
		printf("ɾ���ɹ�\n");
	}
}

//������ϵ��
void SearchContact(Contact* ps)
{
	int pos=0;
	char name[MAX_NAME];
	printf("������Ҫ���ҵ���ϵ������:\n");
	scanf("%s", name);
	pos = FindByName(ps, name);
	if (pos == -1)
		printf("����ϵ�˲�����!\n");
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->date[pos].name,
			ps->date[pos].age,
			ps->date[pos].sex,
			ps->date[pos].tele,
			ps->date[pos].addr);
	}
}

//�޸���ϵ��
void ModifyContact(Contact* ps)
{
	int pos;
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ���ϵ������:\n");
	scanf("%s", name);
	pos = FindByName(ps, name);
	if (pos == -1)
		printf("����ϵ�˲�����!\n");
	else
	{
		printf("����������:\n");
		scanf("%s", ps->date[pos].name);
		printf("����������:\n");
		scanf("%d", &(ps->date[pos].age));
		printf("�������Ա�:\n");
		scanf("%s", ps->date[pos].sex);
		printf("������绰:\n");
		scanf("%s", ps->date[pos].tele);
		printf("�������ַ:\n");
		scanf("%s", ps->date[pos].addr);
		printf("�޸ĳɹ�!\n");
	}
}

//�����ֱȽ�
int cmp(PeoInfo* e1, PeoInfo* e2)
{
	return strcmp(e1->name, e2->name);
}

//�ͷŶ�̬���ٵĿռ�
void DestroyContact(Contact* ps)
{
	free(ps->date);
	ps->date = NULL;
}

//����ͨѶ¼���ļ�
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
	printf("����ɹ�!\n");
}