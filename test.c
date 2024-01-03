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
	int input = 0;//菜单选项
	 Contact con;//con就是通讯录，包含所有的信息和size
	//初始化通讯录
	InitContact(&con);
	do
	{
		//打印菜单
		menu();
		printf("请选择:\n");
		//功能选择
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
			SaveContact(&con);//保存到文件
			DestroyContact(&con);//释放动态内存
			printf("退出通讯录\n");
			break;
		case SAVE:
			SaveContact(&con);
			break;
		default:
			printf("输入错误，请重新输入!\n");
			break;
		}
	} while (input);

	return 0;
}