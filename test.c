#include"Contact.h"

menu()
{
	printf("********************************\n");
	printf("****   1.add       2.del    ****\n");
	printf("****   3.search    4.modify ****\n");
	printf("****   5.show      6.sort   ****\n");
	printf("****   7.save      0.exit   ****\n");
	printf("********************************\n");
}

int main()
{
	int input = 0;//�˵�ѡ��
	 Contact con;//con����ͨѶ¼���������е���Ϣ��size
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		//��ӡ�˵�
		menu();
		printf("��ѡ��:\n");
		//����ѡ��
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			qsort(con.date, con.size, sizeof((con.date)[0]), cmp);
			break;
		case EXIT:
			SaveContact(&con);//���浽�ļ�
			DestroyContact(&con);//�ͷŶ�̬�ڴ�
			printf("�˳�ͨѶ¼\n");
			break;
		case SAVE:
			SaveContact(&con);
			break;
		default:
			printf("�����������������!\n");
			break;
		}
	} while (input);

	return 0;
}