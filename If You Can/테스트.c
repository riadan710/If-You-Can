//#pragma comment(lib, "winmm.lib") //����
//
//#include <stdio.h>
//#include <Windows.h>
//#include <time.h>
//#include <stdlib.h>
//#include <conio.h>
//#include <mmsystem.h>
//
//#define kbhit _kbhit
//#define getch _getch
////�� ����� ���� �ذ��� ����
//
//#define Width 60 //�ܼ�â ���� ����
//#define Height 40 //�ܼ�â ���� ����
//
//#define Empty 0 //����� 0
//#define Note 1 //��ֹ� 1
//#define Wall 2 //�� 2
//
//void gotoxy(int x, int y); //Ŀ�� �̵� �Լ�
//void Console_Size(); //�ܼ� ������ ����
//void CursorView(char show); //Ŀ������� 0�̸� ����, 1�̸� ����
//void DesignStartScreen(); //�⺻ �ڽ� ���
//void Main_Start(); //�� ó�� ���ȭ��
//int Main_Second(); //���� �޴� ����
//void MenuTwo(); //���۹� �޴�
//void MenuThree(); //������ �޴�
//void SelectSong(); //�뷡 ���� �޴�
//void MenuOne(); //������ �뷡 ���
//void PrintNote(); //��Ʈ �� ���
//
//int main()
//{
//	PlaySound(TEXT("title.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //���ȭ�� ���
//
//	SetConsoleTitle("If You Can"); //�ܼ� �̸� ����
//	CursorView(0); //���콺 Ŀ�� �����
//	Console_Size(); //�ܼ� ������ ����
//	DesignStartScreen(); //����ȭ�� ���
//	Main_Start(); //���θ޴� ���
//	PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC); //�޴����� ��� ���
//
//	while (1) //���� �޴� ����
//	{
//		Console_Size();
//		int return_n = Main_Second(); //�޴� ����
//
//		if (return_n == 0) SelectSong();
//		else if (return_n == 2) MenuTwo();
//		else if (return_n == 4) MenuThree();
//		else return 0;
//	}
//
//	return 0;
//}
//
//void gotoxy(int x, int y) //Ŀ�� �̵� �Լ�
//{
//	COORD pos = { x,y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//
//void Console_Size() //�ܼ� ������ ����
//{
//	char temp[50];
//	sprintf(temp, "Mode con cols=%d lines=%d", Width, Height);
//	system(temp);
//}
//
//void CursorView(char show)//Ŀ������� 0�̸� ����, 1�̸� ����
//{
//	HANDLE hConsole;
//	CONSOLE_CURSOR_INFO ConsoleCursor;
//
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	ConsoleCursor.bVisible = show;
//	ConsoleCursor.dwSize = 1;
//
//	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
//}
//
//void DesignStartScreen() //����ȭ�� ����
//{
//	for (int i = 1; i <= Height; i++)
//	{
//		for (int j = 1; j <= Width; j++)
//		{
//			if (i == 1 || i == Height)
//				printf("=");
//			else if (j == 1 || j == Width)
//				printf("|");
//			else
//				printf(" ");
//		}
//	}
//}
//
//void Main_Start()
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//	gotoxy(Width / 2 - 5, Height / 2);
//	printf("If You Can");
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//	gotoxy(Width / 2 - 8, Height / 2 + 4);
//	//��Ʈ��
//
//	while (1)
//	{
//		printf("�ƹ�Ű�� ��������!");
//		Sleep(500);
//		if (kbhit()) break;
//		gotoxy(Width / 2 - 8, Height / 2 + 4);
//		printf("                  ");
//		Sleep(500);
//		gotoxy(Width / 2 - 8, Height / 2 + 4);
//	}
//	system("cls");
//}
//
//int Main_Second()
//{
//	DesignStartScreen();
//	gotoxy(Width / 2 - 5, Height / 2 - 6);
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//	printf("If You Can");
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//
//	gotoxy(Width / 2 - 4, Height / 2);
//	printf("���� ����");
//	gotoxy(Width / 2 - 5, Height / 2 + 2);
//	printf("�÷��� ���");
//	gotoxy(Width / 2 - 3, Height / 2 + 4);
//	printf("������");
//	gotoxy(Width / 2 - 4, Height / 2 + 6);
//	printf("���� ����");
//	gotoxy(Width / 2 + 8, Height / 2);
//	printf("��");
//
//	int return_n = 0;
//	while (1) //Ű���� ������
//	{
//		int key;
//		if (kbhit())
//		{
//			key = getch();
//			if (key == 224 || key == 0)
//			{
//				key = getch();
//				switch (key)
//				{
//				case 72: //��
//					gotoxy(Width / 2 + 8, Height / 2 + return_n);
//					printf("  ");
//					return_n -= 2;
//					if (return_n < 0) return_n = 0;
//					gotoxy(Width / 2 + 8, Height / 2 + return_n);
//					printf("��");
//					break;
//				case 80: //��
//					gotoxy(Width / 2 + 8, Height / 2 + return_n);
//					printf("  ");
//					return_n += 2;
//					if (return_n > 6) return_n = 6;
//					gotoxy(Width / 2 + 8, Height / 2 + return_n);
//					printf("��");
//					break;
//				default:
//					break;
//				}
//			}
//			else
//				if (key == 13)//����
//					return return_n;
//		}
//	}
//}
//
//void MenuOne()
//{
//	system("cls");
//	DesignStartScreen();
//	PlaySound(TEXT("bba3.wav"), NULL, SND_FILENAME | SND_ASYNC);
//
//	gotoxy(Width / 2, Height / 2);
//	printf("��");
//
//	int return_x = Width / 2, return_y = Height / 2;
//	int score = 0;
//	int cnt = 0;
//
//	time_t startTime = clock();
//	time_t notestart = clock();
//	int notecheck = 1; //��� ��Ʈ�� ����� �� �ΰ� ���̽��� �̿�
//	int noteprint = 0; //��Ʈ ��� ���� 1�̸� ��¿Ϸ�, 0�̸� �����
//	int notecount = 1; //��Ʈ�� ����� ��ü Ƚ��
//
//	while (1) //Ű���� ������
//	{
//		int key;
//		if (kbhit())
//		{
//			key = getch();
//			if (key == 224 || key == 0)
//			{
//				key = getch();
//				switch (key)
//				{
//				case 72: //��
//					gotoxy(return_x, return_y);
//					printf("  ");
//					return_y--;
//					if (return_y < 1) return_y = 1;
//					gotoxy(return_x, return_y);
//					printf("��");
//					break;
//				case 75: //��
//					gotoxy(return_x, return_y);
//					printf("  ");
//					return_x--;
//					if (return_x < 2) return_x = 2;
//					gotoxy(return_x, return_y);
//					printf("��");
//					break;
//				case 77: //��
//					gotoxy(return_x, return_y);
//					printf("  ");
//					return_x++;
//					if (return_x > 56) return_x = 56;
//					gotoxy(return_x, return_y);
//					printf("��");
//					break;
//				case 80: //��
//					gotoxy(return_x, return_y);
//					printf("  ");
//					return_y++;
//					if (return_y > 38) return_y = 38;
//					gotoxy(return_x, return_y);
//					printf("��");
//					break;
//				default:
//					break;
//				}
//			}
//		}
//
//		time_t noteend = clock();
//		float notegap = (float)(noteend - notestart) / (CLOCKS_PER_SEC);
//		switch (notecheck)
//		{
//		case 1:
//			if (noteprint == 0)
//			{
//				FILE * note = fopen("none.txt", "r");
//				PrintNote(note);
//
//				noteprint = 1;
//			}
//			if (notecount == 1 && notegap > 14.5)
//			{
//				notecount++;
//				notecheck = 2;
//				notestart = clock();
//				noteprint = 0;
//			}
//			else if (notecount == 4 && notegap > 0.32)
//			{
//				notecount++;
//				notecheck = 3;
//				notestart = clock();
//				noteprint = 0;
//			}
//			break;
//		case 2:
//			if (noteprint == 0)
//			{
//				FILE * note = fopen("1.txt", "r");
//				PrintNote(note);
//
//				noteprint = 1;
//			}
//			if (notecount == 2 && notegap > 0.5)
//			{
//				notecount++;
//				notecheck = 3;
//				notestart = clock();
//				noteprint = 0;
//			}
//			break;
//		case 3:
//			if (noteprint == 0)
//			{
//				FILE * note = fopen("bba.txt", "r");
//				PrintNote(note);
//
//				noteprint = 1;
//			}
//			if (notecount == 3 && notegap > 0.32)
//			{
//				notecount++;
//				notecheck = 1;
//				notestart = clock();
//				noteprint = 0;
//			}
//			else if (notecount == 5 && notegap > 0.48)
//			{
//				notecount++;
//				notecheck = 1;
//				notestart = clock();
//				noteprint = 0;
//			}
//		}
//
//
//		gotoxy(Width / 2 - 5, 0);
//
//		printf(" ���� : %d ", score);
//		cnt++;
//		if (cnt > 500)
//		{
//			cnt = 0;
//			score += 10;
//		}
//
//		time_t endTime = clock();
//		float gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC);
//
//		// ========================  ���� ���� ��  ============================
//		if (gap > 87.0)
//		{
//			system("cls");
//			DesignStartScreen();
//
//			PlaySound(TEXT("ending.wav"), NULL, SND_FILENAME | SND_ASYNC);
//
//			gotoxy(Width / 2 - 6, Height / 2);
//			printf("���� : %d��", score);
//			gotoxy(Width / 2 - 8, Height / 2 + 4);
//			printf("�ٽ��Ͻðڽ��ϱ�?");
//			gotoxy(Width / 2 - 6, Height / 2 + 6);
//			printf("��");
//			gotoxy(Width / 2 + 1, Height / 2 + 6);
//			printf("�ƴϿ�");
//			gotoxy(Width / 2 - 3, Height / 2 + 6);
//			printf("��");
//
//			int return_n = 0;
//			while (1) //Ű���� ������
//			{
//				int key;
//				if (kbhit())
//				{
//					key = getch();
//					if (key == 224 || key == 0)
//					{
//						key = getch();
//						switch (key)
//						{
//						case 75: //�� �⺻
//							gotoxy(Width / 2 - 3 + return_n, Height / 2 + 6);
//							printf("  ");
//							return_n = 0;
//							gotoxy(Width / 2 - 3, Height / 2 + 6);
//							printf("��");
//							break;
//						case 77: //�� 11ĭ��
//							return_n = 11;
//							gotoxy(Width / 2 + 8 - return_n, Height / 2 + 6);
//							printf("  ");
//							gotoxy(Width / 2 + 8, Height / 2 + 6);
//							printf("��");
//							break;
//						default:
//							break;
//						}
//					}
//					else
//						if (key == 13)//����
//						{
//							if (return_n == 0)
//								main();
//							else
//								exit(0);
//						}
//
//				}
//			}
//		}
//	}
//}
//
//void MenuTwo()
//{
//	system("cls");
//	DesignStartScreen();
//	gotoxy(Width / 2 - 5, Height / 2 - 9);
//	printf("�÷��� ���");
//	gotoxy(Width / 2 - 6, Height / 2 - 5);
//	printf("���� : ����Ű");
//	gotoxy(Width / 2 - 16, Height / 2 - 3);
//	printf("�� ������ ���ǿ� ���缭 �����Ǵ�");
//	gotoxy(Width / 2 - 15, Height / 2 - 1);
//	printf("��ֹ��� ���ϸ� �Ǵ� �����Դϴ�.");
//	gotoxy(Width / 2 - 11, Height / 2 + 1);
//	printf("�׷� ��հ� ����ּ���!");
//
//	gotoxy(Width / 2 - 8, Height / 2 + 7);
//	printf("�����Ͻðڽ��ϱ�?");
//	gotoxy(Width / 2 - 6, Height / 2 + 9);
//	printf("��");
//	gotoxy(Width / 2 + 1, Height / 2 + 9);
//	printf("�ƴϿ�");
//	gotoxy(Width / 2 - 3, Height / 2 + 9);
//	printf("��");
//
//	int return_n = 0;
//	while (1) //Ű���� ������
//	{
//		int key;
//		if (kbhit())
//		{
//			key = getch();
//			if (key == 224 || key == 0)
//			{
//				key = getch();
//				switch (key)
//				{
//				case 75: //�� �⺻
//					gotoxy(Width / 2 - 3 + return_n, Height / 2 + 9);
//					printf("  ");
//					return_n = 0;
//					gotoxy(Width / 2 - 3, Height / 2 + 9);
//					printf("��");
//					break;
//				case 77: //�� 11ĭ��
//					return_n = 11;
//					gotoxy(Width / 2 + 8 - return_n, Height / 2 + 9);
//					printf("  ");
//					gotoxy(Width / 2 + 8, Height / 2 + 9);
//					printf("��");
//					break;
//				default:
//					break;
//				}
//			}
//			else
//				if (key == 13)//����
//				{
//					if (return_n == 0)
//						exit(1);
//					else
//						break;
//				}
//
//		}
//	}
//}
//
//void MenuThree()
//{
//	system("cls");
//	DesignStartScreen();
//	gotoxy(Width / 2 - 2, Height / 2 - 7);
//	printf("����");
//	gotoxy(Width / 2 - 11, Height / 2 - 3);
//	printf("�ѱ������й̵�����б�");
//	gotoxy(Width / 2 - 5, Height / 2 - 1);
//	printf("1425 �̿���");
//	gotoxy(Width / 2 - 5, Height / 2 + 1);
//	printf("1434 ������");
//
//	gotoxy(Width / 2 - 8, Height / 2 + 7);
//	printf("�����Ͻðڽ��ϱ�?");
//	gotoxy(Width / 2 - 6, Height / 2 + 9);
//	printf("��");
//	gotoxy(Width / 2 + 1, Height / 2 + 9);
//	printf("�ƴϿ�");
//	gotoxy(Width / 2 - 3, Height / 2 + 9);
//	printf("��");
//
//	int return_n = 0;
//	while (1) //Ű���� ������
//	{
//		int key;
//		if (kbhit())
//		{
//			key = getch();
//			if (key == 224 || key == 0)
//			{
//				key = getch();
//				switch (key)
//				{
//				case 75: //�� �⺻
//					gotoxy(Width / 2 - 3 + return_n, Height / 2 + 9);
//					printf("  ");
//					return_n = 0;
//					gotoxy(Width / 2 - 3, Height / 2 + 9);
//					printf("��");
//					break;
//				case 77: //�� 11ĭ��
//					return_n = 11;
//					gotoxy(Width / 2 + 8 - return_n, Height / 2 + 9);
//					printf("  ");
//					gotoxy(Width / 2 + 8, Height / 2 + 9);
//					printf("��");
//					break;
//				default:
//					break;
//				}
//			}
//			else
//				if (key == 13)//����
//				{
//					if (return_n == 0)
//						exit(1);
//					else
//						break;
//				}
//
//		}
//	}
//}
//
//void SelectSong()
//{
//	system("cls");
//	DesignStartScreen();
//
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//	gotoxy(Width / 2 - 3, 4);
//	printf("�뷡 ���");
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//	gotoxy(Width / 2 - 8, 11);
//	printf("ũ������ - ������");
//	gotoxy(Width / 2 - 9, 16);
//	printf("������ - ����� �ߴ�");
//	gotoxy(Width / 2 - 10, 21);
//	printf("���座�� - Dumb Dumb");
//	gotoxy(Width / 2 - 10, 26);
//	printf("���εེ101 - Pick Me");
//	gotoxy(Width / 2 - 10, 31);
//	printf("������ - Not That Type");
//	gotoxy(Width / 2 + 15, 11);
//	printf("��");
//
//	int return_n = 0;
//	int playing = -1;
//	while (1) //Ű���� ������
//	{
//		int key;
//		if (kbhit())
//		{
//			key = getch();
//			if (key == 224 || key == 0)
//			{
//				key = getch();
//				switch (key)
//				{
//				case 72: //��
//					gotoxy(Width / 2 + 15, 11 + return_n);
//					printf("  ");
//					return_n -= 5;
//					if (return_n < 0) return_n = 0;
//					gotoxy(Width / 2 + 15, 11 + return_n);
//					printf("��");
//					break;
//				case 80: //��
//					gotoxy(Width / 2 + 15, 11 + return_n);
//					printf("  ");
//					return_n += 5;
//					if (return_n > 20) return_n = 20;
//					gotoxy(Width / 2 + 15, 11 + return_n);
//					printf("��");
//					break;
//				default:
//					break;
//				}
//			}
//			else
//				if (key == 13)//����
//				{
//					if (return_n == 0)
//					{
//						MenuOne();
//						break;
//					}
//					else
//					{
//						PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
//						break;
//					}
//				}
//		}
//
//		if (return_n == 0)
//		{
//			if (playing != 0)
//			{
//				PlaySound(TEXT("bba3_sample.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
//				playing = 0;
//			}
//		}
//		else if (return_n == 5)
//		{
//			if (playing != 1)
//			{
//				PlaySound(TEXT("LoveScenario_sample.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
//				playing = 1;
//			}
//		}
//		else if (return_n == 10)
//		{
//			if (playing != 2)
//			{
//				PlaySound(TEXT("DumbDumb_sample.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
//				playing = 2;
//			}
//		}
//		else if (return_n == 15)
//		{
//			if (playing != 3)
//			{
//				PlaySound(TEXT("PICKME_sample.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
//				playing = 3;
//			}
//		}
//		else if (return_n == 20)
//		{
//			if (playing != 4)
//			{
//				PlaySound(TEXT("NOTTHATTYPE_sample.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
//				playing = 4;
//			}
//		}
//	}
//}
//
//void PrintNote(FILE * inp)
//{
//	gotoxy(0, 0);
//	char arr;
//	int i = 0;
//
//	while ((arr = fgetc(inp)) != EOF)
//	{
//		i++;
//		if (arr == '0')
//			printf("  ");
//		else if (arr == '1')
//			printf("��");
//		else if (arr == '2')
//			printf("��");
//		if (i > 30) {
//			i = 0;
//			printf("\n");
//		}
//	}
//
//	fclose(inp);
//}