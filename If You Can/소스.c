//#pragma comment(lib,"winmm.lib") // 사운드  
//
//#include<stdio.h>       
//
//#include<conio.h>
//
//#include<Windows.h>          
//
//#include<time.h> 
//
//#include<stdlib.h> 
//
//#include <MMsystem.h> // 사운드 재생 
//
//
//
//#define nemomax 30
//
//#define wally 24
//
//#define wallx 2
//
//#define wall2x 42
//
//#define wall3x 20
//
//// 난이도스코어 
//
//#define lv2 3500
//
//#define lv3 7000
//
//#define lv4 10500
//
//#define lv5 14000
//
//
//
//struct nemo1 {//네모 구조체
//
//	int x, y;
//
//	int speed;
//
//	int bkspeed;
//
//	int color;
//
//};
//
//
//
//struct ningen1 { //플레이어 구조체
//
//	int x, y;
//
//};
//
//
//
//typedef struct nemo1 nemo; //네모 이름 변경
//
//typedef struct ningen1 nins; //내캐릭터 이름 변경
//
//
//
//
//
//void gotoxy(int x, int y); // 좌표이동함수
//
//void textcolor(int color); // 컬러 함수
//
//void dos_size(); // 창 사이즈
//
//void nemo_spawnpos(nemo *ne); // 네모 스폰위치,컬러
//
//void nemo_speed(nemo *ne, int le, int le2); // 네모 스피드
//
//void showmain(); // 메인메뉴 
//
//void showcredit(); // 크레딧메뉴
//
//void maps(); // 맵제작
//
//void showend(); //게임오버 메시지
//
//
//
//int main() //메인
//
//{
//
//	int i; //for 문용 변수
//
//	int regame = 1; // 리게임 변수
//
//	int music = 0;
//
//	int tx; // 버튼 변수
//
//
//
//	int levels = 0; // 게임난이도 변수 
//
//	int clo = 0, bkcl = 0; // 스코어 변수 , 스코어 백업 변수
//
//	int lvlcolor = 10; // 스코어,난이도 색상조절 변수 
//
//	int level[5] = { 60, 22, 15, 5, 1 };
//
//	int level2[5] = { 30, 3, 2, 1, 1 };
//
//	char *levelname[5] = { "Easy", "Normal", "Hard  ", "Nightmare", "HELL     " }; // 난이도 이름단위
//
//	char move; // 캐릭터 이동변수
//
//
//
//	dos_size(); //게임창사이즈 함수
//
//	srand(time(NULL)); // 랜덤함수
//
//	system("title 네모 피하기 Ver4 by Spore");  // 게임 타이틀 이름
//
//
//
//	nins nin; // 플레이어 구조체 
//
//	nemo nem[nemomax]; // 네모 구조체 
//
//
//
//	nin.x = 22; // 플레이어 스폰 x좌표
//
//	nin.y = wally - 2; // 플레이어 스폰 y좌표
//
//
//
//	showmain(); // 메인메뉴 출력
//
//	tx = _getch(); // 버튼
//
//
//
//	while (1) // 게임메인메뉴 
//
//	{
//
//		if (tx == 49) // 1. 게임시작 
//
//		{
//
//			system("cls");
//
//			bkcl = clock();
//
//
//			break;
//
//		}
//
//		else if (tx == 50) // 2. 제작자
//
//		{
//
//			system("cls");
//
//			showcredit();
//
//			if (_getch())
//
//			{
//
//				system("cls");
//
//				showmain();
//
//				tx = _getch();
//
//			}
//
//		}
//
//		else if (tx == 51) // 나가기 
//
//			exit(0);
//
//		else // 그 외 클릭시 무작동
//
//			tx = _getch();
//
//
//
//	}
//
//
//
//	while (1) // 게임시작후 
//
//	{
//
//		if (regame)
//
//		{
//
//			maps(); // 맵제작
//
//			for (i = 0; i < nemomax; ++i) //네모탄생 
//
//			{
//
//				nemo_spawnpos(&nem[i]);
//
//				nemo_speed(&nem[i], level[levels], level2[levels]);
//
//				nem[i].bkspeed = nem[i].speed;
//
//				gotoxy(nem[i].x, nem[i].y);
//
//				textcolor(nem[i].color);
//
//				printf("■");
//
//			}
//
//
//
//			regame = 0;
//
//		}
//
//		clo = (clock() - bkcl) / 10; // 스코어는 프로그램실행부터 지속되던 시간에서 게임메뉴에있던 시간을 뺀후 10으로 나눈다.
//
//		if (clo >= lv2 && levels == 0) // 난이도와 색상.
//
//		{
//
//
//			lvlcolor = 14;
//
//			levels = 1;
//
//		}
//
//		else if (clo >= lv3 && levels == 1)
//
//		{
//
//
//
//			lvlcolor = 12;
//
//			levels = 2;
//
//		}
//
//		else if (clo >= lv4 && levels == 2)
//
//		{
//
//
//			lvlcolor = 9;
//
//			levels = 3;
//
//		}
//
//		else if (clo >= lv5 && levels == 3)
//
//		{
//
//
//			lvlcolor = 13;
//
//			levels = 4;
//
//		}
//
//		gotoxy(2, 24);
//
//		textcolor(lvlcolor);
//
//		printf("Score : %d - Level : %s", clo, levelname[levels]); // 스코어 난이도판
//
//
//
//		for (i = 0; i < nemomax; ++i)
//
//		{
//
//			if (nem[i].y == nin.y && nem[i].x == nin.x) //              게임오버
//
//			{
//
//
//
//				showend();
//
//				gotoxy(10, 12);
//
//				printf("점수 : %d  - 레벨 : %s \n", clo, levelname[levels]);
//
//				
//
//				gotoxy(12, 14);
//
//				printf("Re  (1)  -  Exit  (2) \n");
//
//				while (1) // 위의 단축키와 상관없는 단축키를 눌럿을경우를 위한 while문 
//
//				{
//
//					switch (_getch())
//
//					{
//
//					case 49: // 1번 클릭시
//
//						regame = 1;
//
//						
//
//						bkcl = clock();
//
//						clo = (clock() - bkcl) / 10;
//
//						levels = 0;
//
//						lvlcolor = 10;
//
//						break;
//
//					case 50:
//
//						exit(0);
//
//						break;
//
//					default:
//
//						continue;
//
//					}
//
//					break;
//
//				}
//
//			}
//
//		}
//
//		gotoxy(nin.x, nin.y);
//
//		textcolor(15);
//
//		printf("♀");
//
//		Sleep(45);
//
//		for (i = 0; i < nemomax; i++) // 네모 이동부분
//
//		{
//
//			if (nem[i].speed>0)
//
//				nem[i].speed -= 1;
//
//			else
//
//			{
//
//				if (nem[i].y < wally - 2) // 땅에 접촉시 다시 위로 올라오게 되는 부분
//
//				{
//
//					gotoxy(nem[i].x, nem[i].y);
//
//					printf(" ");
//
//					nem[i].y += 1;
//
//					gotoxy(nem[i].x, nem[i].y);
//
//					textcolor(nem[i].color);
//
//					printf("■");
//
//				}
//
//				else
//
//				{
//
//					gotoxy(nem[i].x, nem[i].y);
//
//					printf(" ");
//
//					nemo_spawnpos(&nem[i]);
//
//					nemo_speed(&nem[i], level[levels], level2[levels]);
//
//					nem[i].bkspeed = nem[i].speed;
//
//					gotoxy(nem[i].x, nem[i].y);
//
//				}
//
//			}
//
//		}
//
//		if (_kbhit())  // 플레이어 이동부분
//
//		{
//
//			gotoxy(nin.x, nin.y);
//
//			move = _getch();
//
//			printf(" ");
//
//
//
//			switch (move)
//
//			{
//
//			case 75:
//
//				nin.x -= 2;
//
//				if (nin.x<wallx + 2)
//
//					nin.x = wallx + 2;
//
//				break;
//
//			case 77:
//
//				nin.x += 2;
//
//				if (nin.x>wall2x - 2)
//
//					nin.x = wall2x - 2;
//
//				break;
//
//			}
//
//		}
//
//	}
//
//}
//
//
//
//void gotoxy(int x, int y) // 좌표이동함수
//
//{
//
//	COORD pos = { x, y };
//
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//
//}
//
//void textcolor(int color) // 컬러 함수 
//
//{
//
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
//
//}
//
//void dos_size() // 창 사이즈
//
//{
//
//	system("mode con: cols=46 lines=25");
//
//}
//
//
//
//void nemo_spawnpos(nemo *ne) // 네모 스폰위치,컬러
//
//{
//
//	// ne->x= (rand()%(wallx+61))+(wallx+2);
//
//	ne->x = ((rand() % 19) * 2) + 4;
//
//	ne->y = rand() % 4;
//
//	ne->color = (rand() % 15) + 1;
//
//}
//
//
//
//void nemo_speed(nemo *ne, int le, int le2) // 네모 스피드
//
//{
//
//	ne->speed = rand() % le + le2;
//
//}
//
//
//
//void showmain() // 메인메뉴 
//
//{
//
//	// 메인메뉴
//
//	gotoxy(16, 10);
//
//	printf("게임 시작 : 1번 \n");
//
//	gotoxy(18, 12);
//
//	printf("정보 : 2번 \n");
//
//	gotoxy(17, 14);
//
//	printf("나가기 : 3번 \n");
//
//	gotoxy(20, 22);
//
//	printf("조작키 \n");
//
//	gotoxy(14, 24);
//
//	printf("왼쪽 : ← , 오른쪽: → \n");
//
//}
//
//
//
//void showcredit() // 크레딧메뉴
//
//{
//
//	gotoxy(15, 10);
//
//	printf("HELP : 생쥐,네모 (C언어)\n");
//
//	gotoxy(15, 12);
//
//	printf("       김춘추 (BGM) \n");
//
//	gotoxy(15, 14);
//
//	printf("Maker by Spore \n");
//
//	gotoxy(8, 16);
//
//	printf("아무 버튼이나 클릭시 게임메뉴로 \n");
//
//}
//
//
//
//void maps() // 맵제작
//
//{
//
//	int i, j;
//
//	int map[26][22] =
//
//	{
//
//		{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//
//	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
//
//	};
//
//	for (i = 0; i < 25; i++) // 맵제작
//
//	{
//
//		for (j = 0; j < 22; j++)
//
//		{
//
//			textcolor(7);
//
//			if (map[i][j] == 1)
//
//			{
//
//				printf("▩");
//
//			}
//
//			else
//
//			{
//
//				printf("  ");
//
//			}
//
//		}
//
//		printf("\n");
//
//	}
//
//}
//
//
//
//
//
//
//
//void showend()
//
//{
//
//	gotoxy(18, 8);
//
//	printf("Game Over \n");
//
//	gotoxy(10, 10);
//
//	printf("Your ass was broken by Nemo \n");
//
//}