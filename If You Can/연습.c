//#include <stdio.h>
//#include <Windows.h>
//#include <time.h>
//#include <stdlib.h>
//#include <conio.h>
//
//#define Width 60
//#define Height 40
//
//void gotoxy(int x, int y) //커서 이동 함수
//{
//	COORD pos = { x,y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//
//void Console_Size() //콘솔 사이즈 설정
//{
//	char temp[50];
//	sprintf(temp, "Mode con cols=%d lines=%d", Width, Height);
//	system(temp);
//}
//
//int main()
//{
//	Console_Size();
//
//	char arr[40][30];
//	FILE * inp = fopen("bba.txt", "r");
//	char ch;
//
//	for (int i = 0; i < 40; i++)
//	{
//		for (int j = 0; j < 31; j++)
//		{
//			ch = fgetc(inp);
//			arr[i][j] = ch;
//		}
//	}
//
//	for (int i = 0; i < 40; i++)
//	{
//		for (int j = 0; j < 30; j++)
//		{
//			if (arr[i][j] == '0')
//				printf("  ");
//			else if (arr[i][j] == '1')
//				printf("■");
//			else if (arr[i][j] == '2')
//				printf("▩");
//		}
//		if (i != 39)
//			printf("\n");
//	}
//
//	getchar();
//
//	return 0;
//}