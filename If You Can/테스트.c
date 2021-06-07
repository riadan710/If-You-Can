//#pragma comment(lib, "winmm.lib") //사운드
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
////↑ 언더바 문제 해결을 위함
//
//#define Width 60 //콘솔창 가로 길이
//#define Height 40 //콘솔창 세로 길이
//
//#define Empty 0 //빈공간 0
//#define Note 1 //장애물 1
//#define Wall 2 //벽 2
//
//void gotoxy(int x, int y); //커서 이동 함수
//void Console_Size(); //콘솔 사이즈 설정
//void CursorView(char show); //커서숨기기 0이면 숨김, 1이면 보임
//void DesignStartScreen(); //기본 박스 출력
//void Main_Start(); //맨 처음 대기화면
//int Main_Second(); //메인 메뉴 선택
//void MenuTwo(); //조작법 메뉴
//void MenuThree(); //제작자 메뉴
//void SelectSong(); //노래 선택 메뉴
//void MenuOne(); //빠빠빠 노래 재생
//void PrintNote(); //노트 블럭 출력
//
//int main()
//{
//	PlaySound(TEXT("title.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //배경화면 재생
//
//	SetConsoleTitle("If You Can"); //콘솔 이름 설정
//	CursorView(0); //마우스 커서 숨기기
//	Console_Size(); //콘솔 사이즈 설정
//	DesignStartScreen(); //시작화면 출력
//	Main_Start(); //메인메뉴 출력
//	PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC); //메뉴선택 브금 재생
//
//	while (1) //게임 메뉴 선택
//	{
//		Console_Size();
//		int return_n = Main_Second(); //메뉴 선택
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
//void CursorView(char show)//커서숨기기 0이면 숨김, 1이면 보임
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
//void DesignStartScreen() //시작화면 설정
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
//	//인트로
//
//	while (1)
//	{
//		printf("아무키나 누르세요!");
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
//	printf("게임 시작");
//	gotoxy(Width / 2 - 5, Height / 2 + 2);
//	printf("플레이 방법");
//	gotoxy(Width / 2 - 3, Height / 2 + 4);
//	printf("제작자");
//	gotoxy(Width / 2 - 4, Height / 2 + 6);
//	printf("게임 종료");
//	gotoxy(Width / 2 + 8, Height / 2);
//	printf("◀");
//
//	int return_n = 0;
//	while (1) //키보드 움직임
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
//				case 72: //상
//					gotoxy(Width / 2 + 8, Height / 2 + return_n);
//					printf("  ");
//					return_n -= 2;
//					if (return_n < 0) return_n = 0;
//					gotoxy(Width / 2 + 8, Height / 2 + return_n);
//					printf("◀");
//					break;
//				case 80: //하
//					gotoxy(Width / 2 + 8, Height / 2 + return_n);
//					printf("  ");
//					return_n += 2;
//					if (return_n > 6) return_n = 6;
//					gotoxy(Width / 2 + 8, Height / 2 + return_n);
//					printf("◀");
//					break;
//				default:
//					break;
//				}
//			}
//			else
//				if (key == 13)//엔터
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
//	printf("◎");
//
//	int return_x = Width / 2, return_y = Height / 2;
//	int score = 0;
//	int cnt = 0;
//
//	time_t startTime = clock();
//	time_t notestart = clock();
//	int notecheck = 1; //몇번 노트를 출력할 것 인가 케이스문 이용
//	int noteprint = 0; //노트 출력 여부 1이면 출력완료, 0이면 미출력
//	int notecount = 1; //노트를 출력한 전체 횟수
//
//	while (1) //키보드 움직임
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
//				case 72: //상
//					gotoxy(return_x, return_y);
//					printf("  ");
//					return_y--;
//					if (return_y < 1) return_y = 1;
//					gotoxy(return_x, return_y);
//					printf("◎");
//					break;
//				case 75: //좌
//					gotoxy(return_x, return_y);
//					printf("  ");
//					return_x--;
//					if (return_x < 2) return_x = 2;
//					gotoxy(return_x, return_y);
//					printf("◎");
//					break;
//				case 77: //우
//					gotoxy(return_x, return_y);
//					printf("  ");
//					return_x++;
//					if (return_x > 56) return_x = 56;
//					gotoxy(return_x, return_y);
//					printf("◎");
//					break;
//				case 80: //하
//					gotoxy(return_x, return_y);
//					printf("  ");
//					return_y++;
//					if (return_y > 38) return_y = 38;
//					gotoxy(return_x, return_y);
//					printf("◎");
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
//		printf(" 점수 : %d ", score);
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
//		// ========================  게임 종료 시  ============================
//		if (gap > 87.0)
//		{
//			system("cls");
//			DesignStartScreen();
//
//			PlaySound(TEXT("ending.wav"), NULL, SND_FILENAME | SND_ASYNC);
//
//			gotoxy(Width / 2 - 6, Height / 2);
//			printf("점수 : %d점", score);
//			gotoxy(Width / 2 - 8, Height / 2 + 4);
//			printf("다시하시겠습니까?");
//			gotoxy(Width / 2 - 6, Height / 2 + 6);
//			printf("예");
//			gotoxy(Width / 2 + 1, Height / 2 + 6);
//			printf("아니오");
//			gotoxy(Width / 2 - 3, Height / 2 + 6);
//			printf("◀");
//
//			int return_n = 0;
//			while (1) //키보드 움직임
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
//						case 75: //좌 기본
//							gotoxy(Width / 2 - 3 + return_n, Height / 2 + 6);
//							printf("  ");
//							return_n = 0;
//							gotoxy(Width / 2 - 3, Height / 2 + 6);
//							printf("◀");
//							break;
//						case 77: //우 11칸앞
//							return_n = 11;
//							gotoxy(Width / 2 + 8 - return_n, Height / 2 + 6);
//							printf("  ");
//							gotoxy(Width / 2 + 8, Height / 2 + 6);
//							printf("◀");
//							break;
//						default:
//							break;
//						}
//					}
//					else
//						if (key == 13)//엔터
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
//	printf("플레이 방법");
//	gotoxy(Width / 2 - 6, Height / 2 - 5);
//	printf("조작 : 방향키");
//	gotoxy(Width / 2 - 16, Height / 2 - 3);
//	printf("이 게임은 음악에 맞춰서 생성되는");
//	gotoxy(Width / 2 - 15, Height / 2 - 1);
//	printf("장애물을 피하면 되는 게임입니다.");
//	gotoxy(Width / 2 - 11, Height / 2 + 1);
//	printf("그럼 재밌게 즐겨주세요!");
//
//	gotoxy(Width / 2 - 8, Height / 2 + 7);
//	printf("종료하시겠습니까?");
//	gotoxy(Width / 2 - 6, Height / 2 + 9);
//	printf("예");
//	gotoxy(Width / 2 + 1, Height / 2 + 9);
//	printf("아니오");
//	gotoxy(Width / 2 - 3, Height / 2 + 9);
//	printf("◀");
//
//	int return_n = 0;
//	while (1) //키보드 움직임
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
//				case 75: //좌 기본
//					gotoxy(Width / 2 - 3 + return_n, Height / 2 + 9);
//					printf("  ");
//					return_n = 0;
//					gotoxy(Width / 2 - 3, Height / 2 + 9);
//					printf("◀");
//					break;
//				case 77: //우 11칸앞
//					return_n = 11;
//					gotoxy(Width / 2 + 8 - return_n, Height / 2 + 9);
//					printf("  ");
//					gotoxy(Width / 2 + 8, Height / 2 + 9);
//					printf("◀");
//					break;
//				default:
//					break;
//				}
//			}
//			else
//				if (key == 13)//엔터
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
//	printf("제작");
//	gotoxy(Width / 2 - 11, Height / 2 - 3);
//	printf("한국디지털미디어고등학교");
//	gotoxy(Width / 2 - 5, Height / 2 - 1);
//	printf("1425 이우진");
//	gotoxy(Width / 2 - 5, Height / 2 + 1);
//	printf("1434 최현우");
//
//	gotoxy(Width / 2 - 8, Height / 2 + 7);
//	printf("종료하시겠습니까?");
//	gotoxy(Width / 2 - 6, Height / 2 + 9);
//	printf("예");
//	gotoxy(Width / 2 + 1, Height / 2 + 9);
//	printf("아니오");
//	gotoxy(Width / 2 - 3, Height / 2 + 9);
//	printf("◀");
//
//	int return_n = 0;
//	while (1) //키보드 움직임
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
//				case 75: //좌 기본
//					gotoxy(Width / 2 - 3 + return_n, Height / 2 + 9);
//					printf("  ");
//					return_n = 0;
//					gotoxy(Width / 2 - 3, Height / 2 + 9);
//					printf("◀");
//					break;
//				case 77: //우 11칸앞
//					return_n = 11;
//					gotoxy(Width / 2 + 8 - return_n, Height / 2 + 9);
//					printf("  ");
//					gotoxy(Width / 2 + 8, Height / 2 + 9);
//					printf("◀");
//					break;
//				default:
//					break;
//				}
//			}
//			else
//				if (key == 13)//엔터
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
//	printf("노래 목록");
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//	gotoxy(Width / 2 - 8, 11);
//	printf("크레용팝 - 빠빠빠");
//	gotoxy(Width / 2 - 9, 16);
//	printf("아이콘 - 사랑을 했다");
//	gotoxy(Width / 2 - 10, 21);
//	printf("레드벨벳 - Dumb Dumb");
//	gotoxy(Width / 2 - 10, 26);
//	printf("프로듀스101 - Pick Me");
//	gotoxy(Width / 2 - 10, 31);
//	printf("구구단 - Not That Type");
//	gotoxy(Width / 2 + 15, 11);
//	printf("◀");
//
//	int return_n = 0;
//	int playing = -1;
//	while (1) //키보드 움직임
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
//				case 72: //상
//					gotoxy(Width / 2 + 15, 11 + return_n);
//					printf("  ");
//					return_n -= 5;
//					if (return_n < 0) return_n = 0;
//					gotoxy(Width / 2 + 15, 11 + return_n);
//					printf("◀");
//					break;
//				case 80: //하
//					gotoxy(Width / 2 + 15, 11 + return_n);
//					printf("  ");
//					return_n += 5;
//					if (return_n > 20) return_n = 20;
//					gotoxy(Width / 2 + 15, 11 + return_n);
//					printf("◀");
//					break;
//				default:
//					break;
//				}
//			}
//			else
//				if (key == 13)//엔터
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
//			printf("■");
//		else if (arr == '2')
//			printf("▩");
//		if (i > 30) {
//			i = 0;
//			printf("\n");
//		}
//	}
//
//	fclose(inp);
//}