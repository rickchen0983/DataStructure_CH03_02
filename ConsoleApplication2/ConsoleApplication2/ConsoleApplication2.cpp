// ConsoleApplication2.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	int select, student_no = 0, num = 0;
	float Msum = 0, Esum = 0;
	struct student 
	{
		char name[20];
		int Math;
		int Eng;
		char no[10];
		struct student *next;
	};
	typedef struct student s_data;
	s_data *ptr;
	s_data *head;
	s_data *new_data;

	head = (s_data*)malloc(sizeof(s_data));
	head->next = NULL;
	ptr = head;
	do 
	{
		printf(" (1)新增 (2)離開 =>");
		scanf("%d", &select);
		if(select!=2)
		{
			printf("姓名 學號 數學成績 英文成績");
			new_data = (s_data*)malloc(sizeof(s_data));
			scanf("%s %s %d %d", new_data->name, new_data->no, &new_data->Math, &new_data->Eng);
			ptr->next = new_data;
			new_data->next = NULL;
			ptr = ptr->next;
			num++;		
		}
	} while (select != 2);
	ptr = head->next;
	putchar('\n');
	while (ptr != NULL)
	{
		printf("姓名:%s\t 學號:%s\t 數學成績:%d\t 英文成績:%d\n", ptr->name, ptr->no, ptr->Math, ptr->Eng);
		Msum += ptr->Math;
		Esum += ptr->Eng;
		student_no++;
		ptr = ptr->next;
	}
	printf("-----------------------------------------------------------------------------------------------\n");
	printf("本串列學生平均數學成績:%.2f 英文平均成績:%.2f", Msum/student_no, Esum/student_no);
	system("pause");
	return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
