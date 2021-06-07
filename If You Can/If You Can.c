#pragma comment(lib, "winmm.lib") //����

#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <mmsystem.h>

#define kbhit _kbhit
#define getch _getch
//�� ����� ���� �ذ��� ����

#define Width 60 //�ܼ�â ���� ����
#define Height 40 //�ܼ�â ���� ����

void gotoxy(int x, int y); //Ŀ�� �̵� �Լ�
void Console_Size(); //�ܼ� ������ ����
void CursorView(char show); //Ŀ������� 0�̸� ����, 1�̸� ����
void DesignStartScreen(); //�⺻ �ڽ� ���
void Main_Start(); //�� ó�� ���ȭ��
int Main_Second(); //���� �޴� ����
void MenuTwo(); //���۹� �޴�
void MenuThree(); //������ �޴�
void SelectSong(); //�뷡 ���� �޴�
void PrintNote(return_x, return_y); //��Ʈ �� ���
void LoadNote(FILE * inp); //��Ʈ �ε��� �迭�� ����

void PlayBba(); //������ �뷡 ���
void PlayPick(); //�ȹ� ���
void PlayAir(); //����� ���
// ������, �ȹ�, ����� �̷��� 3���� �뷡�� ���������ν�, ���������� 3�ܰ� �̻� �����Ͽ���.

char NoteData[40][30]; //���Ͽ��� �ε�� ��Ʈ �迭�� ����� 2�����迭

int main()
{
	char NoteData[40][30] = { 0, }; //�迭�� ����ְ� ����

	PlaySound(TEXT("title.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //������� ���
	
	SetConsoleTitle("If You Can - Made By �̿���, ������"); //�ܼ� �̸� ����
	CursorView(0); //Ŀ�� ������ �����
	Console_Size(); //�ܼ� ������ ����
	DesignStartScreen(); //����ȭ�� ���
	Main_Start(); //���θ޴� ���
	PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //�޴����� ��� ���

	while (1) //���� �޴� ����
	{
		int return_n = Main_Second(); //�޴� ����, Main_Second()�Լ����� ��ȯ���� ����Ű�� ��ǥ���� �̿��� ������ �޴��� �Ǵ���

		if (return_n == 0) SelectSong(); //���ӽ���
		else if (return_n == 2) MenuTwo(); //�÷��� ���
		else if (return_n == 4) MenuThree(); //������
		else exit(1); //��������
	}

	return 0;
}

void gotoxy(int x, int y) //Ŀ�� �̵� �Լ�
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Console_Size() //�ܼ� ������ ����
{
	char temp[50];
	sprintf(temp, "Mode con cols=%d lines=%d", Width, Height);
	system(temp);
}

void CursorView(char show)//Ŀ������� 0�̸� ����, 1�̸� ����
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void DesignStartScreen() //����ȭ�� ����
{
	for (int i = 1; i <= Height; i++)
	{
		for (int j = 1; j <= Width; j++)
		{
			if (i == 1 || i == Height)
				printf("=");
			else if (j == 1 || j == Width)
				printf("|");
			else
				printf(" ");
		}
	}
}

void Main_Start() //��ó�� ���ȭ��
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //�۾� ��������� ����
	gotoxy(Width / 2 - 5, Height / 2);
	printf("If You Can");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //��� �� �Ͼ������ �ٽ� ����
	gotoxy(Width / 2 - 8, Height / 2 + 4);
	//��Ʈ��

	while (1)
	{
		printf("�ƹ�Ű�� ��������!");
		Sleep(500);
		if (kbhit()) break;
		gotoxy(Width / 2 - 8, Height / 2 + 4);
		printf("                  ");
		Sleep(500);
		gotoxy(Width / 2 - 8, Height / 2 + 4);
	} //Ű���� �Է��� ���� �� ���� �۾��� �����Ÿ�
}

int Main_Second() //�޴� ���� ȭ��
{
	system("cls");
	DesignStartScreen(); //�ʱ�ȭ �� ����ȭ�� ���
	gotoxy(Width / 2 - 5, Height / 2 - 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //�۾� ��������� ����
	printf("If You Can");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //��� �� �Ͼ������ ����

	gotoxy(Width / 2 - 4, Height / 2);
	printf("���� ����");
	gotoxy(Width / 2 - 5, Height / 2 + 2);
	printf("�÷��� ���");
	gotoxy(Width / 2 - 3, Height / 2 + 4);
	printf("������");
	gotoxy(Width / 2 - 4, Height / 2 + 6);
	printf("���� ����");
	gotoxy(Width / 2 + 8, Height / 2);
	printf("��");

	int return_n = 0;
	while (1) //Ű���� ������ (ȭ��ǥ ������)
	{
		int key;
		if (kbhit()) //Ű���� �Է��� ������ ���
		{
			key = getch(); //�� Ű�� �ƽ�Ű�ڵ尪�� �޾� key�� ����
			if (key == 224 || key == 0) //�� Ű�� ����Ű�� ��� �۵�
			{
				key = getch();
				switch (key)
				{
				case 72: //���� ����Ű�� ���� ���
					gotoxy(Width / 2 + 8, Height / 2 + return_n); //���� �ڸ��� �̵�
					printf("  "); //����
					return_n -= 2; //ȭ��ǥ�� ��ǥ�� ���� 2�����Ű��
					if (return_n < 0) return_n = 0; //���������� ������ ���ϰ�
					gotoxy(Width / 2 + 8, Height / 2 + return_n);
					printf("��"); //�ٲ� ��ǥ�� ����Ű ���
					break;
				case 80: //�Ʒ��� ����Ű�� ���� ���
					gotoxy(Width / 2 + 8, Height / 2 + return_n); //���� �ڸ��� �̵�
					printf("  "); //����
					return_n += 2; //ȭ��ǥ�� ��ǥ�� �Ʒ��� 2�����Ű��
					if (return_n > 6) return_n = 6; //���������� ������ ���ϰ�
					gotoxy(Width / 2 + 8, Height / 2 + return_n);
					printf("��"); //�ٲ� ��ǥ�� ����Ű ���
					break;
				default:
					break;
				}
			}
			else
				if (key == 13) //����Ű�� ������ ��
					return return_n; //ȭ��ǥ�� ��ǥ���� ��ȯ
		}
	}
}

void PlayBba() //ũ������ - ������ ��������
{
	system("cls");
	PlaySound(TEXT("bba3.wav"), NULL, SND_FILENAME | SND_ASYNC); //������ ���

	gotoxy(Width / 2, Height / 2);
	printf("��");

	int return_x = Width / 2, return_y = Height / 2;
	int score = 0;
	int cnt = 0;

	time_t startTime = clock(); //�ܰ��� ���۽ð��� ����, �뷡�� ������ ��� ������ �����ϱ� ����
	time_t notestart = clock(); //��Ʈ �� ��½ð��� üũ�Ͽ� ��ũ�� ���߱� ����
	int notecheck = 1; //��� ��Ʈ�� ����� �� �ΰ� ���̽��� �̿�
	int noteprint = 0; //��Ʈ ��� ���� 1�̸� ��¿Ϸ�, 0�̸� �����
	int notecount = 1; //��Ʈ�� ����� ��ü Ƚ��

	while (1) //Ű���� ������
	{
		int key;
		if (kbhit())
		{
			key = getch();
			if (key == 224 || key == 0)
			{
				key = getch();
				switch (key)
				{
				case 72: //��
					gotoxy(return_x, return_y);
					printf("  ");
					return_y--;
					if (return_y < 1) return_y = 1;
					gotoxy(return_x, return_y);
					printf("��");
					break;
				case 75: //��
					gotoxy(return_x, return_y);
					printf("  ");
					return_x -= 2;
					if (return_x < 2) return_x = 2;
					gotoxy(return_x, return_y);
					printf("��");
					break;
				case 77: //��
					gotoxy(return_x, return_y);
					printf("  ");
					return_x += 2;
					if (return_x > 56) return_x = 56;
					gotoxy(return_x, return_y);
					printf("��");
					break;
				case 80: //��
					gotoxy(return_x, return_y);
					printf("  ");
					return_y++;
					if (return_y > 38) return_y = 38;
					gotoxy(return_x, return_y);
					printf("��");
					break;
				default:
					break;
				}
			}
		}

		time_t noteend = clock(); //����ؼ� �ð��� üũ��
		float notegap = (float)(noteend - notestart) / (CLOCKS_PER_SEC); //���ð� - ó���ð����� �ҿ�ð��� ������

		gotoxy(Width / 2 - 5, 0);

		printf(" ���� : %d ", score); //���� ���
		cnt++;
		if (cnt > 500)
		{
			cnt = 0;
			score += 10;
		} //������ �ӵ��� ������ ������Ű�� ����

		time_t endTime = clock();
		float gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC); //������ �� ����ð��� üũ��

		if (gap > 14.5) {
			if (NoteData[return_y][return_x / 2] == '1') //�浹üũ, ��ֹ��� �迭�� ĳ������ ��ǥ�� ���Ͽ� �� ��ġ�� 1 (��) �� ����Ǿ������� �浹��ٰ� �Ǵ��Ͽ� ���� ����
			{
				system("cls");
				DesignStartScreen();

				PlaySound(TEXT("ending.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //���� ��� ���

				gotoxy(Width / 2 - 6, Height / 2);
				printf("���� : %d��", score);
				gotoxy(Width / 2 - 8, Height / 2 + 4);
				printf("�ٽ��Ͻðڽ��ϱ�?");
				gotoxy(Width / 2 - 6, Height / 2 + 6);
				printf("��");
				gotoxy(Width / 2 + 1, Height / 2 + 6);
				printf("�ƴϿ�");
				gotoxy(Width / 2 - 3, Height / 2 + 6);
				printf("��");

				int return_n = 0;
				while (1) //Ű���� ������
				{
					int key;
					if (kbhit())
					{
						key = getch();
						if (key == 224 || key == 0)
						{
							key = getch();
							switch (key)
							{
							case 75: //�� �⺻
								gotoxy(Width / 2 - 3 + return_n, Height / 2 + 6);
								printf("  ");
								return_n = 0;
								gotoxy(Width / 2 - 3, Height / 2 + 6);
								printf("��");
								break;
							case 77: //�� 11ĭ��
								return_n = 11;
								gotoxy(Width / 2 + 8 - return_n, Height / 2 + 6);
								printf("  ");
								gotoxy(Width / 2 + 8, Height / 2 + 6);
								printf("��");
								break;
							default:
								break;
							}
						}
						else
							if (key == 13)//����
							{
								if (return_n == 0)
									main();
								else
									exit(0);
							}
					}
				}
			}
		}

		
		switch (notecheck) //��ֹ� ��� �� �ڵ�, �̰Ͷ����� �ڵ尡 �ſ� ��ϴ�..�Ф� ���� -�� ������ ���°� �����մϴ�
		{
		case 1: //none
			if (noteprint == 0) //�ѹ��� ����ϱ� ���� noteprint üũ
			{
				FILE * note = fopen("none.txt", "r"); //������ �����ϰ�
				LoadNote(note); //�� ������ �Ű������� �Ѱ��� �� �Լ������� ������ ������ 2���� �迭�� ������
				PrintNote(return_x, return_y); //������ �迭�� 0�̸� ��ĭ, 1�̸� ��, 2�̸� ������ ��ȯ�Ͽ� �����,
												//�Ű������� �ѱ�� ������ ĳ������ ��ǥ���� ����� ���� �ʱ� ����.
												//�׷��� �ʴ´ٸ� ĳ���� ��ġ�� �������� ����� �Ǿ� ��� ĳ���Ͱ� �����.
				
				noteprint = 1; //1���� ����ϱ� ���� 1�� ����
			}
			if (notecount == 1 && notegap > 14.5) //14.5�� �Ŀ� ����
			{
				notecount++; //notecount�� 1�� ���Ͽ� ���� ��Ʈ�� ����ϰڴٴ� ���� �˸�
				notecheck = 2; //2��° ��Ʈ�� ����϶�� �ǹ� case 2:�� �̵��ϰ� ��
				notestart = clock(); //���۽ð��� �ʱ�ȭ�����ν� �ð��� ó������ �ٽ� ��
				noteprint = 0; //�ٽ� ����ϱ� ���� 0���� ����

				// �� �� �ڵ�� �� ���� �ƶ��� �ڵ��̹Ƿ� ������ ��������� ���ڽ��ϴ�. ��� ���� ����� �ڵ��Դϴ�.
			}
			else if (notecount == 4 && notegap > 0.32)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 6 && notegap > 0.32)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 8 && notegap > 0.24)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 10 && notegap > 0.74)
			{
				notecount++;
				notecheck = 4;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 13 && notegap > 0.32)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 15 && notegap > 0.32)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 17 && notegap > 0.24)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 19 && notegap > 0.74)
			{
				notecount++;
				notecheck = 5;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 36 && notegap > 0.32)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 38 && notegap > 0.32)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 40 && notegap > 0.24)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 42 && notegap > 0.74)
			{
				notecount++;
				notecheck = 20;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 45 && notegap > 0.32)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 47 && notegap > 0.32)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 49 && notegap > 0.24)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 51 && notegap > 0.74)
			{
				notecount++;
				notecheck = 5;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 2: //1
			if (noteprint == 0)
			{
				FILE * note = fopen("1.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			else if (notecount == 2 && notegap > 0.5)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 77 && notegap > 0.65)
			{
				notecount++;
				notecheck = 31;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 3: //bba
			if (noteprint == 0)
			{
				FILE * note = fopen("bba.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 3 && notegap > 0.32)
			{
				notecount++;
				notecheck = 1;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 5 && notegap > 0.48)
			{
				notecount++;
				notecheck = 1;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 7 && notegap > 0.32)
			{
				notecount++;
				notecheck = 1;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 9 && notegap > 0.32)
			{
				notecount++;
				notecheck = 1;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 12 && notegap > 0.32)
			{
				notecount++;
				notecheck = 1;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 14 && notegap > 0.48)
			{
				notecount++;
				notecheck = 1;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 16 && notegap > 0.32)
			{
				notecount++;
				notecheck = 1;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 18 && notegap > 0.32)
			{
				notecount++;
				notecheck = 1;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 35 && notegap > 0.32)
			{
				notecount++;
				notecheck = 1;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 37 && notegap > 0.48)
			{
				notecount++;
				notecheck = 1;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 39 && notegap > 0.32)
			{
				notecount++;
				notecheck = 1;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 41 && notegap > 0.32)
			{
				notecount++;
				notecheck = 1;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 44 && notegap > 0.32)
			{
				notecount++;
				notecheck = 1;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 46 && notegap > 0.48)
			{
				notecount++;
				notecheck = 1;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 48 && notegap > 0.32)
			{
				notecount++;
				notecheck = 1;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 50 && notegap > 0.32)
			{
				notecount++;
				notecheck = 1;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 4: //2
			if (noteprint == 0)
			{
				FILE * note = fopen("2.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 11 && notegap > 0.5)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 76 && notegap > 0.65)
			{
				notecount++;
				notecheck = 2;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 5: //ho1
			if (noteprint == 0)
			{
				FILE * note = fopen("ho1.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 20 && notegap > 0.35)
			{
				notecount++;
				notecheck = 6;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 52 && notegap > 0.35)
			{
				notecount++;
				notecheck = 6;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 6: //ho2
			if (noteprint == 0)
			{
				FILE * note = fopen("ho2.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 21 && notegap > 0.35)
			{
				notecount++;
				notecheck = 7;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 53 && notegap > 0.35)
			{
				notecount++;
				notecheck = 7;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 7: //ho3
			if (noteprint == 0)
			{
				FILE * note = fopen("ho3.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 22 && notegap > 0.35)
			{
				notecount++;
				notecheck = 8;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 54 && notegap > 0.35)
			{
				notecount++;
				notecheck = 8;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 8: //ho4
			if (noteprint == 0)
			{
				FILE * note = fopen("ho4.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 23 && notegap > 0.5)
			{
				notecount++;
				notecheck = 9;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 55 && notegap > 0.5)
			{
				notecount++;
				notecheck = 9;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 9: //kung1
			if (noteprint == 0)
			{
				FILE * note = fopen("kung1.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 24 && notegap > 0.28)
			{
				notecount++;
				notecheck = 10;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 56 && notegap > 0.28)
			{
				notecount++;
				notecheck = 10;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 10: //kung2
			if (noteprint == 0)
			{
				FILE * note = fopen("kung2.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 25 && notegap > 0.28)
			{
				notecount++;
				notecheck = 11;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 57 && notegap > 0.28)
			{
				notecount++;
				notecheck = 11;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 11: //kung3
			if (noteprint == 0)
			{
				FILE * note = fopen("kung3.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 26 && notegap > 0.28)
			{
				notecount++;
				notecheck = 12;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 58 && notegap > 0.28)
			{
				notecount++;
				notecheck = 12;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 12: //kung4
			if (noteprint == 0)
			{
				FILE * note = fopen("kung4.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 27 && notegap > 0.28)
			{
				notecount++;
				notecheck = 13;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 59 && notegap > 0.28)
			{
				notecount++;
				notecheck = 13;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 13: //kung5
			if (noteprint == 0)
			{
				FILE * note = fopen("kung5.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 28 && notegap > 0.28)
			{
				notecount++;
				notecheck = 14;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 60 && notegap > 0.28)
			{
				notecount++;
				notecheck = 14;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 14: //follow1
			if (noteprint == 0)
			{
				FILE * note = fopen("follow1.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 29 && notegap > 0.84)
			{
				notecount++;
				notecheck = 15;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 61 && notegap > 0.84)
			{
				notecount++;
				notecheck = 15;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 15: //follow2
			if (noteprint == 0)
			{
				FILE * note = fopen("follow2.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 30 && notegap > 0.84)
			{
				notecount++;
				notecheck = 16;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 62 && notegap > 0.84)
			{
				notecount++;
				notecheck = 16;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 16: //follow3
			if (noteprint == 0)
			{
				FILE * note = fopen("follow3.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 31 && notegap > 0.84)
			{
				notecount++;
				notecheck = 17;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 63 && notegap > 0.84)
			{
				notecount++;
				notecheck = 17;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 17: //follow4
			if (noteprint == 0)
			{
				FILE * note = fopen("follow4.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 32 && notegap > 0.84)
			{
				notecount++;
				notecheck = 18;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 64 && notegap > 0.84)
			{
				notecount++;
				notecheck = 18;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 18: //follow5
			if (noteprint == 0)
			{
				FILE * note = fopen("follow5.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 33 && notegap > 0.84)
			{
				notecount++;
				notecheck = 20;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 65 && notegap > 0.84)
			{
				notecount++;
				notecheck = 21;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 20: //go
			if (noteprint == 0)
			{
				FILE * note = fopen("go.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 34 && notegap > 0.5)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 43 && notegap > 0.5)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 78 && notegap > 0.2)
			{
				notecount++;
				notecheck = 32;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 79 && notegap > 0.2)
			{
				notecount++;
				notecheck = 32;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 21: //pop1
			if (noteprint == 0)
			{
				FILE * note = fopen("pop1.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 66 && notegap > 0.3)
			{
				notecount++;
				notecheck = 22;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 22: //pop2
			if (noteprint == 0)
			{
				FILE * note = fopen("pop2.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 67 && notegap > 0.3)
			{
				notecount++;
				notecheck = 23;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 23: //pop3
			if (noteprint == 0)
			{
				FILE * note = fopen("pop3.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 68 && notegap > 0.3)
			{
				notecount++;
				notecheck = 24;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 24: //pop4
			if (noteprint == 0)
			{
				FILE * note = fopen("pop4.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 69 && notegap > 0.3)
			{
				notecount++;
				notecheck = 25;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 25: //pop5
			if (noteprint == 0)
			{
				FILE * note = fopen("pop5.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 70 && notegap > 0.3)
			{
				notecount++;
				notecheck = 26;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 26: //pop6
			if (noteprint == 0)
			{
				FILE * note = fopen("pop6.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 71 && notegap > 0.3)
			{
				notecount++;
				notecheck = 27;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 27: //crayon1
			if (noteprint == 0)
			{
				FILE * note = fopen("crayon1.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 72 && notegap > 0.5)
			{
				notecount++;
				notecheck = 28;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 28: //crayon2
			if (noteprint == 0)
			{
				FILE * note = fopen("crayon2.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 73 && notegap > 0.5)
			{
				notecount++;
				notecheck = 29;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 29: //crayon3
			if (noteprint == 0)
			{
				FILE * note = fopen("crayon3.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 74 && notegap > 0.5)
			{
				notecount++;
				notecheck = 30;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 30: //crayon4
			if (noteprint == 0)
			{
				FILE * note = fopen("crayon4.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 75 && notegap > 0.5)
			{
				notecount++;
				notecheck = 4;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 31: //ready
			if (noteprint == 0)
			{
				FILE * note = fopen("ready.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 78 && notegap > 1.8)
			{
				notecount++;
				notecheck = 20;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 32: //jump1
			if (noteprint == 0)
			{
				FILE * note = fopen("jump1.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 80 && notegap > 0.45)
			{
				notecount++;
				notecheck = 33;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 87 && notegap > 0.45)
			{
				notecount++;
				notecheck = 33;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 108 && notegap > 0.45)
			{
				notecount++;
				notecheck = 33;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 115 && notegap > 0.45)
			{
				notecount++;
				notecheck = 33;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 33: //jump2
			if (noteprint == 0)
			{
				FILE * note = fopen("jump2.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 81 && notegap > 0.45)
			{
				notecount++;
				notecheck = 34;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 88 && notegap > 0.45)
			{
				notecount++;
				notecheck = 34;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 109 && notegap > 0.45)
			{
				notecount++;
				notecheck = 34;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 116 && notegap > 0.45)
			{
				notecount++;
				notecheck = 34;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 34: //jump3
			if (noteprint == 0)
			{
				FILE * note = fopen("jump3.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 82 && notegap > 0.45)
			{
				notecount++;
				notecheck = 35;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 89 && notegap > 0.45)
			{
				notecount++;
				notecheck = 35;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 110 && notegap > 0.45)
			{
				notecount++;
				notecheck = 35;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 117 && notegap > 0.45)
			{
				notecount++;
				notecheck = 35;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 35: //jump4
			if (noteprint == 0)
			{
				FILE * note = fopen("jump4.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 83 && notegap > 0.45)
			{
				notecount++;
				notecheck = 36;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 90 && notegap > 0.45)
			{
				notecount++;
				notecheck = 36;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 111 && notegap > 0.45)
			{
				notecount++;
				notecheck = 36;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 118 && notegap > 0.45)
			{
				notecount++;
				notecheck = 36;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 36: //jump5
			if (noteprint == 0)
			{
				FILE * note = fopen("jump5.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 84 && notegap > 0.45)
			{
				notecount++;
				notecheck = 37;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 91 && notegap > 0.45)
			{
				notecount++;
				notecheck = 37;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 112 && notegap > 0.45)
			{
				notecount++;
				notecheck = 37;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 119 && notegap > 0.45)
			{
				notecount++;
				notecheck = 37;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 37: //jump6
			if (noteprint == 0)
			{
				FILE * note = fopen("jump6.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 85 && notegap > 0.45)
			{
				notecount++;
				notecheck = 38;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 92 && notegap > 0.45)
			{
				notecount++;
				notecheck = 39;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 113 && notegap > 0.45)
			{
				notecount++;
				notecheck = 38;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 120 && notegap > 0.45)
			{
				notecount++;
				notecheck = 39;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 38: //everybody
			if (noteprint == 0)
			{
				FILE * note = fopen("everybody.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 86 && notegap > 0.9)
			{
				notecount++;
				notecheck = 32;
				notestart = clock();
				noteprint = 0;
			}
			if (notecount == 114 && notegap > 0.9)
			{
				notecount++;
				notecheck = 32;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 39: //dduieo
			if (noteprint == 0)
			{
				FILE * note = fopen("dduieo.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 93 && notegap > 0.9)
			{
				notecount++;
				notecheck = 40;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 121 && notegap > 0.9)
			{
				notecount++;
				notecheck = 40;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 40: //jump7
			if (noteprint == 0)
			{
				FILE * note = fopen("jump7.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 94 && notegap > 0.45)
			{
				notecount++;
				notecheck = 41;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 122 && notegap > 0.45)
			{
				notecount++;
				notecheck = 41;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 41: //jump8
			if (noteprint == 0)
			{
				FILE * note = fopen("jump8.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 95 && notegap > 0.45)
			{
				notecount++;
				notecheck = 42;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 123 && notegap > 0.45)
			{
				notecount++;
				notecheck = 42;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 42: //jump9
			if (noteprint == 0)
			{
				FILE * note = fopen("jump9.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 96 && notegap > 0.9)
			{
				notecount++;
				notecheck = 43;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 124 && notegap > 0.9)
			{
				notecount++;
				notecheck = 43;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 43: //jump10
			if (noteprint == 0)
			{
				FILE * note = fopen("jump10.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 97 && notegap > 0.45)
			{
				notecount++;
				notecheck = 44;
				notestart = clock();
				noteprint = 0;
			}
			if (notecount == 125 && notegap > 0.45)
			{
				notecount++;
				notecheck = 44;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 44: //jump11
			if (noteprint == 0)
			{
				FILE * note = fopen("jump11.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 98 && notegap > 0.45)
			{
				notecount++;
				notecheck = 45;
				notestart = clock();
				noteprint = 0;
			}
			if (notecount == 126 && notegap > 0.45)
			{
				notecount++;
				notecheck = 45;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 45: //jump12
			if (noteprint == 0)
			{
				FILE * note = fopen("jump12.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 99 && notegap > 0.9)
			{
				notecount++;
				notecheck = 46;
				notestart = clock();
				noteprint = 0;
			}
			if (notecount == 127 && notegap > 0.9)
			{
				notecount++;
				notecheck = 46;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 46: //want1
			if (noteprint == 0)
			{
				FILE * note = fopen("want1.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 100 && notegap > 0.45)
			{
				notecount++;
				notecheck = 47;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 104 && notegap > 0.45)
			{
				notecount++;
				notecheck = 47;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 128 && notegap > 0.45)
			{
				notecount++;
				notecheck = 47;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 132 && notegap > 0.45)
			{
				notecount++;
				notecheck = 47;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 136 && notegap > 0.45)
			{
				notecount++;
				notecheck = 47;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 140 && notegap > 0.45)
			{
				notecount++;
				notecheck = 47;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 47: //want2
			if (noteprint == 0)
			{
				FILE * note = fopen("want2.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 101 && notegap > 0.45)
			{
				notecount++;
				notecheck = 48;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 105 && notegap > 0.45)
			{
				notecount++;
				notecheck = 48;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 129 && notegap > 0.45)
			{
				notecount++;
				notecheck = 48;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 133 && notegap > 0.45)
			{
				notecount++;
				notecheck = 48;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 137 && notegap > 0.45)
			{
				notecount++;
				notecheck = 48;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 141 && notegap > 0.45)
			{
				notecount++;
				notecheck = 48;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 48: //want3
			if (noteprint == 0)
			{
				FILE * note = fopen("want3.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 102 && notegap > 0.45)
			{
				notecount++;
				notecheck = 49;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 106 && notegap > 0.6)
			{
				notecount++;
				notecheck = 49;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 130 && notegap > 0.45)
			{
				notecount++;
				notecheck = 49;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 134 && notegap > 0.6)
			{
				notecount++;
				notecheck = 49;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 138 && notegap > 0.45)
			{
				notecount++;
				notecheck = 49;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 142 && notegap > 0.6)
			{
				notecount++;
				notecheck = 49;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 49: //want4
			if (noteprint == 0)
			{
				FILE * note = fopen("want4.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 103 && notegap > 0.45)
			{
				notecount++;
				notecheck = 46;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 107 && notegap > 0.15)
			{
				notecount++;
				notecheck = 32;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 131 && notegap > 0.45)
			{
				notecount++;
				notecheck = 46;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 135 && notegap > 0.15)
			{
				notecount++;
				notecheck = 46;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 139 && notegap > 0.45)
			{
				notecount++;
				notecheck = 46;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 143 && notegap > 0.15)
			{
				notecount++;
				notecheck = 1;
				notestart = clock();
				noteprint = 0;
			}
			break;
		}

		// ========================  ���� ���� ��  ============================
		if (gap > 87.0) //�������� �� ������ 87�ʰ� ������ ������ ������
		{
			system("cls");
			DesignStartScreen();

			PlaySound(TEXT("clear.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

			gotoxy(Width / 2 - 8, Height / 2 - 5);
			printf("Ŭ���� �ϼ̽��ϴ�!!");
			gotoxy(Width / 2 - 6, Height / 2);
			printf("���� : %d��", score);
			gotoxy(Width / 2 - 8, Height / 2 + 4);
			printf("�ٽ��Ͻðڽ��ϱ�?");
			gotoxy(Width / 2 - 6, Height / 2 + 6);
			printf("��");
			gotoxy(Width / 2 + 1, Height / 2 + 6);
			printf("�ƴϿ�");
			gotoxy(Width / 2 - 3, Height / 2 + 6);
			printf("��");

			int return_n = 0;
			while (1) //Ű���� ������, �ٽ��ϱ� ���� Ȯ��
			{
				int key;
				if (kbhit())
				{
					key = getch();
					if (key == 224 || key == 0)
					{
						key = getch();
						switch (key)
						{
						case 75: //�� �⺻
							gotoxy(Width / 2 - 3 + return_n, Height / 2 + 6);
							printf("  ");
							return_n = 0;
							gotoxy(Width / 2 - 3, Height / 2 + 6);
							printf("��");
							break;
						case 77: //�� 11ĭ��
							return_n = 11;
							gotoxy(Width / 2 + 8 - return_n, Height / 2 + 6);
							printf("  ");
							gotoxy(Width / 2 + 8, Height / 2 + 6);
							printf("��");
							break;
						default:
							break;
						}
					}
					else
						if (key == 13)//����
						{
							if (return_n == 0)
								main();
							else
								exit(0);
						}

				}
			}
		}
	}
}

void MenuTwo() //���θ޴����� �÷��� ��� �޴��� ���� ����Ǵ� �Լ�
{
	system("cls");
	DesignStartScreen();
	gotoxy(Width / 2 - 5, Height / 2 - 9);
	printf("�÷��� ���");
	gotoxy(Width / 2 - 6, Height / 2 - 5);
	printf("���� : ����Ű");
	gotoxy(Width / 2 - 16, Height / 2 - 3);
	printf("�� ������ ���ǿ� ���缭 �����Ǵ�");
	gotoxy(Width / 2 - 15, Height / 2 - 1);
	printf("��ֹ��� ���ϸ� �Ǵ� �����Դϴ�.");
	gotoxy(Width / 2 - 11, Height / 2 + 1);
	printf("�׷� ��հ� ����ּ���!");

	gotoxy(Width / 2 - 8, Height / 2 + 7);
	printf("�����Ͻðڽ��ϱ�?");
	gotoxy(Width / 2 - 6, Height / 2 + 9);
	printf("��");
	gotoxy(Width / 2 + 1, Height / 2 + 9);
	printf("�ƴϿ�");
	gotoxy(Width / 2 - 3, Height / 2 + 9);
	printf("��");

	int return_n = 0;
	while (1) //Ű���� ������
	{
		int key;
		if (kbhit())
		{
			key = getch();
			if (key == 224 || key == 0)
			{
				key = getch();
				switch (key)
				{
				case 75: //�� �⺻
					gotoxy(Width / 2 - 3 + return_n, Height / 2 + 9);
					printf("  ");
					return_n = 0;
					gotoxy(Width / 2 - 3, Height / 2 + 9);
					printf("��");
					break;
				case 77: //�� 11ĭ��
					return_n = 11;
					gotoxy(Width / 2 + 8 - return_n, Height / 2 + 9);
					printf("  ");
					gotoxy(Width / 2 + 8, Height / 2 + 9);
					printf("��");
					break;
				default:
					break;
				}
			}
			else
				if (key == 13)//����
				{
					if (return_n == 0)
						exit(1);
					else
						break;
				}

		}
	}
}

void MenuThree() //���θ޴����� ���� �޴��� ���� ����Ǵ� �Լ�
{
	system("cls");
	DesignStartScreen();
	gotoxy(Width / 2 - 2, Height / 2 - 7);
	printf("����");
	gotoxy(Width / 2 - 11, Height / 2 - 3);
	printf("�ѱ������й̵�����б�");
	gotoxy(Width / 2 - 5, Height / 2 - 1);
	printf("1425 �̿���");
	gotoxy(Width / 2 - 5, Height / 2 + 1);
	printf("1434 ������");

	gotoxy(Width / 2 - 8, Height / 2 + 7);
	printf("�����Ͻðڽ��ϱ�?");
	gotoxy(Width / 2 - 6, Height / 2 + 9);
	printf("��");
	gotoxy(Width / 2 + 1, Height / 2 + 9);
	printf("�ƴϿ�");
	gotoxy(Width / 2 - 3, Height / 2 + 9);
	printf("��");

	int return_n = 0;
	while (1) //Ű���� ������
	{
		int key;
		if (kbhit())
		{
			key = getch();
			if (key == 224 || key == 0)
			{
				key = getch();
				switch (key)
				{
				case 75: //�� �⺻
					gotoxy(Width / 2 - 3 + return_n, Height / 2 + 9);
					printf("  ");
					return_n = 0;
					gotoxy(Width / 2 - 3, Height / 2 + 9);
					printf("��");
					break;
				case 77: //�� 11ĭ��
					return_n = 11;
					gotoxy(Width / 2 + 8 - return_n, Height / 2 + 9);
					printf("  ");
					gotoxy(Width / 2 + 8, Height / 2 + 9);
					printf("��");
					break;
				default:
					break;
				}
			}
			else
				if (key == 13)//����
				{
					if (return_n == 0)
						exit(1);
					else
						break;
				}

		}
	}
}

void SelectSong() //���θ޴����� ���� ���� �޴��� ���� ������ �뷡��� �޴�
{
	system("cls");
	DesignStartScreen();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	gotoxy(Width / 2 - 3, 4);
	printf("�뷡 ���");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(Width / 2 - 8, 11);
	printf("ũ������ - ������");
	gotoxy(Width / 2 - 10, 16);
	printf("���εེ101 - Pick Me");
	gotoxy(Width / 2 - 6, 21);
	printf("���� - �����");
	gotoxy(Width / 2 - 9, 26);
	printf("������ - ����� �ߴ�");
	gotoxy(Width / 2 - 10, 31);
	printf("������ - Not That Type");
	gotoxy(Width / 2 + 15, 11);
	printf("��");

	int return_n = 0;
	int playing = -1; //�뷡�� �ѹ��� ����ϱ� ����
	while (1) //Ű���� ������
	{
		int key;
		if (kbhit())
		{
			key = getch();
			if (key == 224 || key == 0)
			{
				key = getch();
				switch (key)
				{
				case 72: //��
					gotoxy(Width / 2 + 15, 11 + return_n);
					printf("  ");
					return_n -= 5;
					if (return_n < 0) return_n = 0;
					gotoxy(Width / 2 + 15, 11 + return_n);
					printf("��");
					break;
				case 80: //��
					gotoxy(Width / 2 + 15, 11 + return_n);
					printf("  ");
					return_n += 5;
					if (return_n > 20) return_n = 20;
					gotoxy(Width / 2 + 15, 11 + return_n);
					printf("��");
					break;
				default:
					break;
				}
			}
			else
				if (key == 13)//����
				{
					if (return_n == 0)
					{
						PlayBba();
						break;
					}
					else if (return_n == 5)
					{
						PlayPick();
						break;
					}
					else if (return_n == 10)
					{
						PlayAir();
						break;
					}
					else
					{
						PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
						break;
					}
				}
		}

		//�� �� ��ġ�� �´� �뷡 ���̶���Ʈ�� �����
		if (return_n == 0)
		{
			if (playing != 0)
			{
				PlaySound(TEXT("bba3_sample.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				playing = 0;
			}
		}
		else if (return_n == 5)
		{
			if (playing != 1)
			{
				PlaySound(TEXT("PICKME_sample.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				playing = 1;
			}
		}
		else if (return_n == 10)
		{
			if (playing != 2)
			{
				PlaySound(TEXT("airplane_sample.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				playing = 2;
			}
		}
		else if (return_n == 15)
		{
			if (playing != 3)
			{
				PlaySound(TEXT("LoveScenario_sample.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				playing = 3;
			}
		}
		else if (return_n == 20)
		{
			if (playing != 4)
			{
				PlaySound(TEXT("NOTTHATTYPE_sample.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				playing = 4;
			}
		}
	}
}

void LoadNote(FILE * inp) //������ ������ 2���� �迭�� ����, ������ �Ű������� ����
{
	char arr;

	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			arr = fgetc(inp); //ó������ �ѱ��ھ� �޾Ƽ�
			NoteData[i][j] = arr; //�迭�� �������
		}
	}
}

void PrintNote(int x, int y) //�迭�� ������ ��ȣ�� �����Ͽ� �����
{
	gotoxy(0, 0); //0,0���� �̵�

	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (j > 10 && j < 20 && i == 0) printf("  ");
			else if (x == j * 2 && y == i) printf("��"); //ĳ������ ��ġ���� ������� ����
			else if (NoteData[i][j] == '0') printf("  "); //0�ϰ�� ��ĭ
			else if (NoteData[i][j] == '1') printf("��"); //1�ϰ�� ��
			else if (NoteData[i][j] == '2') printf("��"); //2�ϰ�� �� ���
		}
		if (i != 39) printf("\n");
	}
}

void PlayPick() //���εེ 101 - PICK ME �������� (������ �������� (PlayBba()) �� ����� �����ϹǷ� �������� �ʰ���)
{
	system("cls");
	PlaySound(TEXT("PICKME.wav"), NULL, SND_FILENAME | SND_ASYNC);

	gotoxy(Width / 2, Height / 2);
	printf("��");

	int return_x = Width / 2, return_y = Height / 2;
	int score = 0;
	int cnt = 0;

	time_t startTime = clock();
	time_t notestart = clock();
	int notecheck = 1; //��� ��Ʈ�� ����� �� �ΰ� ���̽��� �̿�
	int noteprint = 0; //��Ʈ ��� ���� 1�̸� ��¿Ϸ�, 0�̸� �����
	int notecount = 1; //��Ʈ�� ����� ��ü Ƚ��

	while (1) //Ű���� ������
	{
		int key;
		if (kbhit())
		{
			key = getch();
			if (key == 224 || key == 0)
			{
				key = getch();
				switch (key)
				{
				case 72: //��
					gotoxy(return_x, return_y);
					printf("  ");
					return_y--;
					if (return_y < 1) return_y = 1;
					gotoxy(return_x, return_y);
					printf("��");
					break;
				case 75: //��
					gotoxy(return_x, return_y);
					printf("  ");
					return_x -= 2;
					if (return_x < 2) return_x = 2;
					gotoxy(return_x, return_y);
					printf("��");
					break;
				case 77: //��
					gotoxy(return_x, return_y);
					printf("  ");
					return_x += 2;
					if (return_x > 56) return_x = 56;
					gotoxy(return_x, return_y);
					printf("��");
					break;
				case 80: //��
					gotoxy(return_x, return_y);
					printf("  ");
					return_y++;
					if (return_y > 38) return_y = 38;
					gotoxy(return_x, return_y);
					printf("��");
					break;
				default:
					break;
				}
			}
		}

		time_t noteend = clock(); //����ؼ� �ð��� üũ��
		float notegap = (float)(noteend - notestart) / (CLOCKS_PER_SEC); //���ð� - ó���ð����� �ҿ�ð��� ������

		gotoxy(Width / 2 - 5, 0);

		printf(" ���� : %d ", score); //���� ���
		cnt++;
		if (cnt > 500)
		{
			cnt = 0;
			score += 10;
		} //������ �ӵ��� ������ ������Ű�� ����

		time_t endTime = clock();
		float gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC); //������ �� ����ð��� üũ��
		
		if(gap > 0.5) {
			if (NoteData[return_y][return_x / 2] == '1')
			{
				system("cls");
				DesignStartScreen();

				PlaySound(TEXT("ending.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

				gotoxy(Width / 2 - 6, Height / 2);
				printf("���� : %d��", score);
				gotoxy(Width / 2 - 8, Height / 2 + 4);
				printf("�ٽ��Ͻðڽ��ϱ�?");
				gotoxy(Width / 2 - 6, Height / 2 + 6);
				printf("��");
				gotoxy(Width / 2 + 1, Height / 2 + 6);
				printf("�ƴϿ�");
				gotoxy(Width / 2 - 3, Height / 2 + 6);
				printf("��");

				int return_n = 0;
				while (1) //Ű���� ������
				{
					int key;
					if (kbhit())
					{
						key = getch();
						if (key == 224 || key == 0)
						{
							key = getch();
							switch (key)
							{
							case 75: //�� �⺻
								gotoxy(Width / 2 - 3 + return_n, Height / 2 + 6);
								printf("  ");
								return_n = 0;
								gotoxy(Width / 2 - 3, Height / 2 + 6);
								printf("��");
								break;
							case 77: //�� 11ĭ��
								return_n = 11;
								gotoxy(Width / 2 + 8 - return_n, Height / 2 + 6);
								printf("  ");
								gotoxy(Width / 2 + 8, Height / 2 + 6);
								printf("��");
								break;
							default:
								break;
							}
						}
						else
							if (key == 13)//����
							{
								if (return_n == 0)
									main();
								else
									exit(0);
							}
					}
				}
			}
		}

		switch (notecheck)
		{
		case 1: //none
			if (noteprint == 0)
			{
				FILE * note = fopen("none.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 1 && notegap > 0.5)
			{
				notecount++;
				notecheck = 2;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 2: //triangle
			if (noteprint == 0)
			{
				FILE * note = fopen("triangle.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 2 && notegap > 15)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 73 && notegap > 9.0)
			{
				notecount++;
				notecheck = 33;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 3: //dance1
			if (noteprint == 0)
			{
				FILE * note = fopen("dance1.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 3 && notegap > 0.9)
			{
				notecount++;
				notecheck = 4;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 5 && notegap > 0.9)
			{
				notecount++;
				notecheck = 4;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 16 && notegap > 0.9)
			{
				notecount++;
				notecheck = 4;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 18 && notegap > 0.9)
			{
				notecount++;
				notecheck = 4;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 4: //dance2
			if (noteprint == 0)
			{
				FILE * note = fopen("dance2.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 4 && notegap > 0.9)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 6 && notegap > 0.9)
			{
				notecount++;
				notecheck = 5;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 17 && notegap > 0.9)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 19 && notegap > 0.9)
			{
				notecount++;
				notecheck = 5;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 5: //dance3
			if (noteprint == 0)
			{
				FILE * note = fopen("dance3.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 7 && notegap > 0.9)
			{
				notecount++;
				notecheck = 6;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 9 && notegap > 0.9)
			{
				notecount++;
				notecheck = 7;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 20 && notegap > 0.9)
			{
				notecount++;
				notecheck = 6;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 22 && notegap > 0.9)
			{
				notecount++;
				notecheck = 7;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 6: //dance4
			if (noteprint == 0)
			{
				FILE * note = fopen("dance4.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 8 && notegap > 0.9)
			{
				notecount++;
				notecheck = 5;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 21 && notegap > 0.9)
			{
				notecount++;
				notecheck = 5;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 7: //dance5
			if (noteprint == 0)
			{
				FILE * note = fopen("dance5.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 10 && notegap > 0.9)
			{
				notecount++;
				notecheck = 8;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 23 && notegap > 0.9)
			{
				notecount++;
				notecheck = 8;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 8: //dance6
			if (noteprint == 0)
			{
				FILE * note = fopen("dance6.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 11 && notegap > 0.9)
			{
				notecount++;
				notecheck = 9;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 13 && notegap > 0.9)
			{
				notecount++;
				notecheck = 9;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 24 && notegap > 0.9)
			{
				notecount++;
				notecheck = 9;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 26 && notegap > 0.9)
			{
				notecount++;
				notecheck = 9;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 9: //dance7
			if (noteprint == 0)
			{
				FILE * note = fopen("dance7.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 12 && notegap > 0.9)
			{
				notecount++;
				notecheck = 8;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 14 && notegap > 0.9)
			{
				notecount++;
				notecheck = 10;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 25 && notegap > 0.9)
			{
				notecount++;
				notecheck = 8;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 27 && notegap > 0.9)
			{
				notecount++;
				notecheck = 11;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 10: //paradise
			if (noteprint == 0)
			{
				FILE * note = fopen("paradise.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 15 && notegap > 4)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 11: //secret
			if (noteprint == 0)
			{
				FILE * note = fopen("secret.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 28 && notegap > 4)
			{
				notecount++;
				notecheck = 12;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 12: //can
			if (noteprint == 0)
			{
				FILE * note = fopen("can.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 29 && notegap > 0.5)
			{
				notecount++;
				notecheck = 13;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 34 && notegap > 0.5)
			{
				notecount++;
				notecheck = 13;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 39 && notegap > 0.5)
			{
				notecount++;
				notecheck = 13;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 13: //you
			if (noteprint == 0)
			{
				FILE * note = fopen("you.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 30 && notegap > 0.5)
			{
				notecount++;
				notecheck = 14;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 35 && notegap > 0.5)
			{
				notecount++;
				notecheck = 17;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 40 && notegap > 0.5)
			{
				notecount++;
				notecheck = 19;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 14: //feel1
			if (noteprint == 0)
			{
				FILE * note = fopen("feel1.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 31 && notegap > 0.6)
			{
				notecount++;
				notecheck = 15;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 15: //me
			if (noteprint == 0)
			{
				FILE * note = fopen("me.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 32 && notegap > 0.4)
			{
				notecount++;
				notecheck = 16;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 37 && notegap > 0.4)
			{
				notecount++;
				notecheck = 18;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 42 && notegap > 0.4)
			{
				notecount++;
				notecheck = 20;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 16: //feel2
			if (noteprint == 0)
			{
				FILE * note = fopen("feel2.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 33 && notegap > 2.0)
			{
				notecount++;
				notecheck = 12;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 17: //touch1
			if (noteprint == 0)
			{
				FILE * note = fopen("touch1.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 36 && notegap > 0.6)
			{
				notecount++;
				notecheck = 15;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 18: //touch2
			if (noteprint == 0)
			{
				FILE * note = fopen("touch2.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 38 && notegap > 2.0)
			{
				notecount++;
				notecheck = 12;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 19: //hug1
			if (noteprint == 0)
			{
				FILE * note = fopen("hold1.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 41 && notegap > 0.6)
			{
				notecount++;
				notecheck = 15;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 20: //hug2
			if (noteprint == 0)
			{
				FILE * note = fopen("hold2.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 43 && notegap > 4.5)
			{
				notecount++;
				notecheck = 21;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 21: //pickme
			if (noteprint == 0)
			{
				FILE * note = fopen("pickme.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 44 && notegap > 0.8)
			{
				notecount++;
				notecheck = 22;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 22: //main1
			if (noteprint == 0)
			{
				FILE * note = fopen("main1.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 45 && notegap > 0.2)
			{
				notecount++;
				notecheck = 23;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 47 && notegap > 0.2)
			{
				notecount++;
				notecheck = 24;
				notestart = clock();
				noteprint = 0;
			}

			else if (notecount == 49 && notegap > 0.2)
			{
				notecount++;
				notecheck = 23;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 52 && notegap > 0.2)
			{
				notecount++;
				notecheck = 23;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 54 && notegap > 0.2)
			{
				notecount++;
				notecheck = 24;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 56 && notegap > 0.2)
			{
				notecount++;
				notecheck = 23;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 23: //main2
			if (noteprint == 0)
			{
				FILE * note = fopen("main2.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 46 && notegap > 0.2)
			{
				notecount++;
				notecheck = 22;
				notestart = clock();
				noteprint = 0;
			}
			if (notecount == 50 && notegap > 0.2)
			{
				notecount++;
				notecheck = 25;
				notestart = clock();
				noteprint = 0;
			}
			if (notecount == 53 && notegap > 0.2)
			{
				notecount++;
				notecheck = 22;
				notestart = clock();
				noteprint = 0;
			}
			if (notecount == 57 && notegap > 0.2)
			{
				notecount++;
				notecheck = 25;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 24: //main3
			if (noteprint == 0)
			{
				FILE * note = fopen("main3.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 48 && notegap > 0.2)
			{
				notecount++;
				notecheck = 22;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 55 && notegap > 0.2)
			{
				notecount++;
				notecheck = 22;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 25: //main4
			if (noteprint == 0)
			{
				FILE * note = fopen("main4.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 51 && notegap > 0.6)
			{
				notecount++;
				notecheck = 22;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 58 && notegap > 0.6)
			{
				notecount++;
				notecheck = 26;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 26: //heart1
			if (noteprint == 0)
			{
				FILE * note = fopen("heart1.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 59 && notegap > 0.5)
			{
				notecount++;
				notecheck = 27;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 63 && notegap > 0.5)
			{
				notecount++;
				notecheck = 27;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 71 && notegap > 0.5)
			{
				notecount++;
				notecheck = 27;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 27: //heart2
			if (noteprint == 0)
			{
				FILE * note = fopen("heart2.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 60 && notegap > 0.5)
			{
				notecount++;
				notecheck = 28;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 64 && notegap > 0.5)
			{
				notecount++;
				notecheck = 28;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 72 && notegap > 0.5)
			{
				notecount++;
				notecheck = 2;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 28: //heart3
			if (noteprint == 0)
			{
				FILE * note = fopen("heart3.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 61 && notegap > 0.5)
			{
				notecount++;
				notecheck = 29;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 65 && notegap > 0.5)
			{
				notecount++;
				notecheck = 29;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 69 && notegap > 0.5)
			{
				notecount++;
				notecheck = 29;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 29: //heart4
			if (noteprint == 0)
			{
				FILE * note = fopen("heart4.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 62 && notegap > 0.5)
			{
				notecount++;
				notecheck = 26;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 66 && notegap > 0.5)
			{
				notecount++;
				notecheck = 30;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 70 && notegap > 0.5)
			{
				notecount++;
				notecheck = 26;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 30: //main5
			if (noteprint == 0)
			{
				FILE * note = fopen("main5.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 67 && notegap > 1.8)
			{
				notecount++;
				notecheck = 31;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 31: //main6
			if (noteprint == 0)
			{
				FILE * note = fopen("main6.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 68 && notegap > 1.8)
			{
				notecount++;
				notecheck = 28;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 32: //left1
			if (noteprint == 0)
			{
				FILE * note = fopen("left1.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 77 && notegap > 1.0)
			{
				notecount++;
				notecheck = 33;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 82 && notegap > 0.5)
			{
				notecount++;
				notecheck = 33;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 87 && notegap > 0.5)
			{
				notecount++;
				notecheck = 36;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 33: //left2
			if (noteprint == 0)
			{
				FILE * note = fopen("left2.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 74 && notegap > 0.5)
			{
				notecount++;
				notecheck = 35;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 76 && notegap > 0.5)
			{
				notecount++;
				notecheck = 32;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 78 && notegap > 0.5)
			{
				notecount++;
				notecheck = 34;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 81 && notegap > 0.5)
			{
				notecount++;
				notecheck = 32;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 83 && notegap > 0.5)
			{
				notecount++;
				notecheck = 35;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 86 && notegap > 0.5)
			{
				notecount++;
				notecheck = 32;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 34: //left3
			if (noteprint == 0)
			{
				FILE * note = fopen("left3.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 79 && notegap > 0.5)
			{
				notecount++;
				notecheck = 35;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 85 && notegap > 0.5)
			{
				notecount++;
				notecheck = 33;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 35: //left4
			if (noteprint == 0)
			{
				FILE * note = fopen("left4.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 75 && notegap > 0.5)
			{
				notecount++;
				notecheck = 33;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 80 && notegap > 0.5)
			{
				notecount++;
				notecheck = 33;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 84 && notegap > 1.0)
			{
				notecount++;
				notecheck = 34;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 36: //punchright
			if (noteprint == 0)
			{
				FILE * note = fopen("punchright.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 88 && notegap > 1.0)
			{
				notecount++;
				notecheck = 37;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 37: //punchleft
			if (noteprint == 0)
			{
				FILE * note = fopen("punchleft.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 89 && notegap > 1.5)
			{
				notecount++;
				notecheck = 38;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 92 && notegap > 0.5)
			{
				notecount++;
				notecheck = 1;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 38: //punchdown
			if (noteprint == 0)
			{
				FILE * note = fopen("punchdown.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 90 && notegap > 0.5)
			{
				notecount++;
				notecheck = 39;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 39: //punchdowndown
			if (noteprint == 0)
			{
				FILE * note = fopen("punchdowndown.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 91 && notegap > 0.5)
			{
				notecount++;
				notecheck = 37;
				notestart = clock();
				noteprint = 0;
			}
			break;
		}

		// ========================  ���� ���� ��  ============================
		if (gap > 100.0)
		{
			system("cls");
			DesignStartScreen();

			PlaySound(TEXT("clear.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

			gotoxy(Width / 2 - 8, Height / 2 - 5);
			printf("Ŭ���� �ϼ̽��ϴ�!!");
			gotoxy(Width / 2 - 6, Height / 2);
			printf("���� : %d��", score);
			gotoxy(Width / 2 - 8, Height / 2 + 4);
			printf("�ٽ��Ͻðڽ��ϱ�?");
			gotoxy(Width / 2 - 6, Height / 2 + 6);
			printf("��");
			gotoxy(Width / 2 + 1, Height / 2 + 6);
			printf("�ƴϿ�");
			gotoxy(Width / 2 - 3, Height / 2 + 6);
			printf("��");

			int return_n = 0;
			while (1) //Ű���� ������
			{
				int key;
				if (kbhit())
				{
					key = getch();
					if (key == 224 || key == 0)
					{
						key = getch();
						switch (key)
						{
						case 75: //�� �⺻
							gotoxy(Width / 2 - 3 + return_n, Height / 2 + 6);
							printf("  ");
							return_n = 0;
							gotoxy(Width / 2 - 3, Height / 2 + 6);
							printf("��");
							break;
						case 77: //�� 11ĭ��
							return_n = 11;
							gotoxy(Width / 2 + 8 - return_n, Height / 2 + 6);
							printf("  ");
							gotoxy(Width / 2 + 8, Height / 2 + 6);
							printf("��");
							break;
						default:
							break;
						}
					}
					else
						if (key == 13)//����
						{
							if (return_n == 0)
								main();
							else
								exit(0);
						}

				}
			}
		}
	}
}

void PlayAir() //���� - ����� �������� (�� ���� ������, PICK ME�� ����� �����ϹǷ� �������� �ʰ���)
{
	system("cls");
	PlaySound(TEXT("airplane.wav"), NULL, SND_FILENAME | SND_ASYNC);

	gotoxy(Width / 2, Height / 2);
	printf("��");

	int return_x = Width / 2, return_y = Height / 2;
	int score = 0;
	int cnt = 0;

	time_t startTime = clock();
	time_t notestart = clock();
	int notecheck = 1; //��� ��Ʈ�� ����� �� �ΰ� ���̽��� �̿�
	int noteprint = 0; //��Ʈ ��� ���� 1�̸� ��¿Ϸ�, 0�̸� �����
	int notecount = 1; //��Ʈ�� ����� ��ü Ƚ��

	while (1) //Ű���� ������
	{
		int key;
		if (kbhit())
		{
			key = getch();
			if (key == 224 || key == 0)
			{
				key = getch();
				switch (key)
				{
				case 72: //��
					gotoxy(return_x, return_y);
					printf("  ");
					return_y--;
					if (return_y < 1) return_y = 1;
					gotoxy(return_x, return_y);
					printf("��");
					break;
				case 75: //��
					gotoxy(return_x, return_y);
					printf("  ");
					return_x -= 2;
					if (return_x < 2) return_x = 2;
					gotoxy(return_x, return_y);
					printf("��");
					break;
				case 77: //��
					gotoxy(return_x, return_y);
					printf("  ");
					return_x += 2;
					if (return_x > 56) return_x = 56;
					gotoxy(return_x, return_y);
					printf("��");
					break;
				case 80: //��
					gotoxy(return_x, return_y);
					printf("  ");
					return_y++;
					if (return_y > 38) return_y = 38;
					gotoxy(return_x, return_y);
					printf("��");
					break;
				default:
					break;
				}
			}
		}

		time_t noteend = clock(); //����ؼ� �ð��� üũ��
		float notegap = (float)(noteend - notestart) / (CLOCKS_PER_SEC); //���ð� - ó���ð����� �ҿ�ð��� ������

		gotoxy(Width / 2 - 5, 0);

		printf(" ���� : %d ", score); //���� ���
		cnt++;
		if (cnt > 500)
		{
			cnt = 0;
			score += 10;
		} //������ �ӵ��� ������ ������Ű�� ����

		time_t endTime = clock();
		float gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC); //������ �� ����ð��� üũ��

		if (gap > 5.5) {
			if (NoteData[return_y][return_x / 2] == '1')
			{
				system("cls");
				DesignStartScreen();

				PlaySound(TEXT("ending.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

				gotoxy(Width / 2 - 6, Height / 2);
				printf("���� : %d��", score);
				gotoxy(Width / 2 - 8, Height / 2 + 4);
				printf("�ٽ��Ͻðڽ��ϱ�?");
				gotoxy(Width / 2 - 6, Height / 2 + 6);
				printf("��");
				gotoxy(Width / 2 + 1, Height / 2 + 6);
				printf("�ƴϿ�");
				gotoxy(Width / 2 - 3, Height / 2 + 6);
				printf("��");

				int return_n = 0;
				while (1) //Ű���� ������
				{
					int key;
					if (kbhit())
					{
						key = getch();
						if (key == 224 || key == 0)
						{
							key = getch();
							switch (key)
							{
							case 75: //�� �⺻
								gotoxy(Width / 2 - 3 + return_n, Height / 2 + 6);
								printf("  ");
								return_n = 0;
								gotoxy(Width / 2 - 3, Height / 2 + 6);
								printf("��");
								break;
							case 77: //�� 11ĭ��
								return_n = 11;
								gotoxy(Width / 2 + 8 - return_n, Height / 2 + 6);
								printf("  ");
								gotoxy(Width / 2 + 8, Height / 2 + 6);
								printf("��");
								break;
							default:
								break;
							}
						}
						else
							if (key == 13)//����
							{
								if (return_n == 0)
									main();
								else
									exit(0);
							}
					}
				}
			}
		}

		switch (notecheck)
		{
		case 1: //none
			if (noteprint == 0)
			{
				FILE * note = fopen("none.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 1 && notegap > 5.5)
			{
				notecount++;
				notecheck = 2;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 2: //airplane1
			if (noteprint == 0)
			{
				FILE * note = fopen("airplane1.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 2 && notegap > 0.6)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 6 && notegap > 0.6)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 10 && notegap > 0.6)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 3: //airplane2
			if (noteprint == 0)
			{
				FILE * note = fopen("airplane2.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 3 && notegap > 0.6)
			{
				notecount++;
				notecheck = 4;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 5 && notegap > 0.6)
			{
				notecount++;
				notecheck = 2;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 7 && notegap > 0.6)
			{
				notecount++;
				notecheck = 4;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 9 && notegap > 0.6)
			{
				notecount++;
				notecheck = 2;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 11 && notegap > 0.6)
			{
				notecount++;
				notecheck = 4;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 13 && notegap > 0.6)
			{
				notecount++;
				notecheck = 5;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 4: //airplane3
			if (noteprint == 0)
			{
				FILE * note = fopen("airplane3.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 4 && notegap > 0.6)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 8 && notegap > 0.6)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			else if (notecount == 12 && notegap > 0.6)
			{
				notecount++;
				notecheck = 3;
				notestart = clock();
				noteprint = 0;
			}
			break;
		case 5: //airplanebig
			if (noteprint == 0)
			{
				FILE * note = fopen("airplanebig.txt", "r");
				LoadNote(note);
				PrintNote(return_x, return_y);

				noteprint = 1;
			}
			if (notecount == 5 && notegap > 2.4)
			{
				notecount++;
				notecheck = 5;
				notestart = clock();
				noteprint = 0;
			}
			break;
		}

		// ========================  ���� ���� ��  ============================
		if (gap > 17.0)
		{
			system("cls");
			DesignStartScreen();

			PlaySound(TEXT("clear.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

			gotoxy(Width / 2 - 8, Height / 2 - 5);
			printf("Ŭ���� �ϼ̽��ϴ�!!");
			gotoxy(Width / 2 - 6, Height / 2);
			printf("���� : %d��", score);
			gotoxy(Width / 2 - 8, Height / 2 + 4);
			printf("�ٽ��Ͻðڽ��ϱ�?");
			gotoxy(Width / 2 - 6, Height / 2 + 6);
			printf("��");
			gotoxy(Width / 2 + 1, Height / 2 + 6);
			printf("�ƴϿ�");
			gotoxy(Width / 2 - 3, Height / 2 + 6);
			printf("��");

			int return_n = 0;
			while (1) //Ű���� ������
			{
				int key;
				if (kbhit())
				{
					key = getch();
					if (key == 224 || key == 0)
					{
						key = getch();
						switch (key)
						{
						case 75: //�� �⺻
							gotoxy(Width / 2 - 3 + return_n, Height / 2 + 6);
							printf("  ");
							return_n = 0;
							gotoxy(Width / 2 - 3, Height / 2 + 6);
							printf("��");
							break;
						case 77: //�� 11ĭ��
							return_n = 11;
							gotoxy(Width / 2 + 8 - return_n, Height / 2 + 6);
							printf("  ");
							gotoxy(Width / 2 + 8, Height / 2 + 6);
							printf("��");
							break;
						default:
							break;
						}
					}
					else
						if (key == 13)//����
						{
							if (return_n == 0)
								main();
							else
								exit(0);
						}

				}
			}
		}
	}
}