#pragma comment(lib, "winmm.lib") //사운드

#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <mmsystem.h>

#define kbhit _kbhit
#define getch _getch
//↑ 언더바 문제 해결을 위함

#define Width 60 //콘솔창 가로 길이
#define Height 40 //콘솔창 세로 길이

void gotoxy(int x, int y); //커서 이동 함수
void Console_Size(); //콘솔 사이즈 설정
void CursorView(char show); //커서숨기기 0이면 숨김, 1이면 보임
void DesignStartScreen(); //기본 박스 출력
void Main_Start(); //맨 처음 대기화면
int Main_Second(); //메인 메뉴 선택
void MenuTwo(); //조작법 메뉴
void MenuThree(); //제작자 메뉴
void SelectSong(); //노래 선택 메뉴
void PrintNote(return_x, return_y); //노트 블럭 출력
void LoadNote(FILE * inp); //노트 로드후 배열에 저장

void PlayBba(); //빠빠빠 노래 재생
void PlayPick(); //픽미 재생
void PlayAir(); //비행기 재생
// 빠빠빠, 픽미, 비행기 이렇게 3개의 노래를 구현함으로써, 스테이지를 3단계 이상 구현하였음.

char NoteData[40][30]; //파일에서 로드된 노트 배열이 저장될 2차원배열

int main()
{
	char NoteData[40][30] = { 0, }; //배열을 비워주고 시작

	PlaySound(TEXT("title.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //배경음악 재생
	
	SetConsoleTitle("If You Can - Made By 이우진, 최현우"); //콘솔 이름 변경
	CursorView(0); //커서 깜빡임 숨기기
	Console_Size(); //콘솔 사이즈 설정
	DesignStartScreen(); //시작화면 출력
	Main_Start(); //메인메뉴 출력
	PlaySound(TEXT("select.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //메뉴선택 브금 재생

	while (1) //게임 메뉴 선택
	{
		int return_n = Main_Second(); //메뉴 선택, Main_Second()함수에서 반환받은 방향키의 좌표값을 이용해 선택한 메뉴를 판단함

		if (return_n == 0) SelectSong(); //게임시작
		else if (return_n == 2) MenuTwo(); //플레이 방법
		else if (return_n == 4) MenuThree(); //제작자
		else exit(1); //게임종료
	}

	return 0;
}

void gotoxy(int x, int y) //커서 이동 함수
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Console_Size() //콘솔 사이즈 설정
{
	char temp[50];
	sprintf(temp, "Mode con cols=%d lines=%d", Width, Height);
	system(temp);
}

void CursorView(char show)//커서숨기기 0이면 숨김, 1이면 보임
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void DesignStartScreen() //시작화면 설정
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

void Main_Start() //맨처음 대기화면
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //글씨 노란색으로 변경
	gotoxy(Width / 2 - 5, Height / 2);
	printf("If You Can");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //출력 후 하얀색으로 다시 변경
	gotoxy(Width / 2 - 8, Height / 2 + 4);
	//인트로

	while (1)
	{
		printf("아무키나 누르세요!");
		Sleep(500);
		if (kbhit()) break;
		gotoxy(Width / 2 - 8, Height / 2 + 4);
		printf("                  ");
		Sleep(500);
		gotoxy(Width / 2 - 8, Height / 2 + 4);
	} //키보드 입력이 들어올 때 까지 글씨가 깜빡거림
}

int Main_Second() //메뉴 선택 화면
{
	system("cls");
	DesignStartScreen(); //초기화 후 시작화면 출력
	gotoxy(Width / 2 - 5, Height / 2 - 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //글씨 노란색으로 변경
	printf("If You Can");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //출력 후 하얀색으로 변경

	gotoxy(Width / 2 - 4, Height / 2);
	printf("게임 시작");
	gotoxy(Width / 2 - 5, Height / 2 + 2);
	printf("플레이 방법");
	gotoxy(Width / 2 - 3, Height / 2 + 4);
	printf("제작자");
	gotoxy(Width / 2 - 4, Height / 2 + 6);
	printf("게임 종료");
	gotoxy(Width / 2 + 8, Height / 2);
	printf("◀");

	int return_n = 0;
	while (1) //키보드 움직임 (화살표 움직임)
	{
		int key;
		if (kbhit()) //키보드 입력이 들어왔을 경우
		{
			key = getch(); //그 키의 아스키코드값을 받아 key에 저장
			if (key == 224 || key == 0) //그 키가 방향키인 경우 작동
			{
				key = getch();
				switch (key)
				{
				case 72: //위쪽 방향키를 누른 경우
					gotoxy(Width / 2 + 8, Height / 2 + return_n); //원래 자리로 이동
					printf("  "); //삭제
					return_n -= 2; //화살표의 좌표를 위로 2변경시키고
					if (return_n < 0) return_n = 0; //범위밖으로 나가지 못하게
					gotoxy(Width / 2 + 8, Height / 2 + return_n);
					printf("◀"); //바뀐 좌표에 방향키 출력
					break;
				case 80: //아래쪽 방향키를 누른 경우
					gotoxy(Width / 2 + 8, Height / 2 + return_n); //원래 자리로 이동
					printf("  "); //삭제
					return_n += 2; //화살표의 좌표를 아래로 2변경시키고
					if (return_n > 6) return_n = 6; //범위밖으로 나가지 못하게
					gotoxy(Width / 2 + 8, Height / 2 + return_n);
					printf("◀"); //바뀐 좌표에 방향키 출력
					break;
				default:
					break;
				}
			}
			else
				if (key == 13) //엔터키를 눌렀을 때
					return return_n; //화살표의 좌표값을 반환
		}
	}
}

void PlayBba() //크레용팝 - 빠빠빠 스테이지
{
	system("cls");
	PlaySound(TEXT("bba3.wav"), NULL, SND_FILENAME | SND_ASYNC); //빠빠빠 재생

	gotoxy(Width / 2, Height / 2);
	printf("◎");

	int return_x = Width / 2, return_y = Height / 2;
	int score = 0;
	int cnt = 0;

	time_t startTime = clock(); //단계의 시작시간을 저장, 노래가 끝났을 경우 게임을 종료하기 위함
	time_t notestart = clock(); //노트 별 출력시간을 체크하여 싱크를 맞추기 위함
	int notecheck = 1; //몇번 노트를 출력할 것 인가 케이스문 이용
	int noteprint = 0; //노트 출력 여부 1이면 출력완료, 0이면 미출력
	int notecount = 1; //노트를 출력한 전체 횟수

	while (1) //키보드 움직임
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
				case 72: //상
					gotoxy(return_x, return_y);
					printf("  ");
					return_y--;
					if (return_y < 1) return_y = 1;
					gotoxy(return_x, return_y);
					printf("◎");
					break;
				case 75: //좌
					gotoxy(return_x, return_y);
					printf("  ");
					return_x -= 2;
					if (return_x < 2) return_x = 2;
					gotoxy(return_x, return_y);
					printf("◎");
					break;
				case 77: //우
					gotoxy(return_x, return_y);
					printf("  ");
					return_x += 2;
					if (return_x > 56) return_x = 56;
					gotoxy(return_x, return_y);
					printf("◎");
					break;
				case 80: //하
					gotoxy(return_x, return_y);
					printf("  ");
					return_y++;
					if (return_y > 38) return_y = 38;
					gotoxy(return_x, return_y);
					printf("◎");
					break;
				default:
					break;
				}
			}
		}

		time_t noteend = clock(); //계속해서 시간을 체크함
		float notegap = (float)(noteend - notestart) / (CLOCKS_PER_SEC); //끝시간 - 처음시간으로 소요시간을 저장함

		gotoxy(Width / 2 - 5, 0);

		printf(" 점수 : %d ", score); //점수 출력
		cnt++;
		if (cnt > 500)
		{
			cnt = 0;
			score += 10;
		} //적당한 속도로 점수를 증가시키기 위함

		time_t endTime = clock();
		float gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC); //게임의 총 진행시간을 체크함

		if (gap > 14.5) {
			if (NoteData[return_y][return_x / 2] == '1') //충돌체크, 장애물의 배열과 캐릭터의 좌표를 비교하여 그 위치에 1 (블럭) 이 저장되어있으면 충돌됬다고 판단하여 게임 종료
			{
				system("cls");
				DesignStartScreen();

				PlaySound(TEXT("ending.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //엔딩 브금 재생

				gotoxy(Width / 2 - 6, Height / 2);
				printf("점수 : %d점", score);
				gotoxy(Width / 2 - 8, Height / 2 + 4);
				printf("다시하시겠습니까?");
				gotoxy(Width / 2 - 6, Height / 2 + 6);
				printf("예");
				gotoxy(Width / 2 + 1, Height / 2 + 6);
				printf("아니오");
				gotoxy(Width / 2 - 3, Height / 2 + 6);
				printf("◀");

				int return_n = 0;
				while (1) //키보드 움직임
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
							case 75: //좌 기본
								gotoxy(Width / 2 - 3 + return_n, Height / 2 + 6);
								printf("  ");
								return_n = 0;
								gotoxy(Width / 2 - 3, Height / 2 + 6);
								printf("◀");
								break;
							case 77: //우 11칸앞
								return_n = 11;
								gotoxy(Width / 2 + 8 - return_n, Height / 2 + 6);
								printf("  ");
								gotoxy(Width / 2 + 8, Height / 2 + 6);
								printf("◀");
								break;
							default:
								break;
							}
						}
						else
							if (key == 13)//엔터
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

		
		switch (notecheck) //장애물 출력 용 코드, 이것때문에 코드가 매우 깁니다..ㅠㅠ 옆에 -를 눌러서 접는걸 권장합니다
		{
		case 1: //none
			if (noteprint == 0) //한번만 출력하기 위해 noteprint 체크
			{
				FILE * note = fopen("none.txt", "r"); //파일을 오픈하고
				LoadNote(note); //이 파일을 매개변수로 넘겨줌 이 함수에서는 파일의 내용을 2차원 배열에 저장함
				PrintNote(return_x, return_y); //저장한 배열을 0이면 빈칸, 1이면 블럭, 2이면 벽으로 변환하여 출력함,
												//매개변수를 넘기는 이유는 캐릭터의 좌표에는 출력을 하지 않기 위함.
												//그렇지 않는다면 캐릭터 위치에 덮어져서 출력이 되어 잠시 캐릭터가 사라짐.
				
				noteprint = 1; //1번만 출력하기 위해 1로 변경
			}
			if (notecount == 1 && notegap > 14.5) //14.5초 후에 실행
			{
				notecount++; //notecount에 1을 더하여 다음 노트를 출력하겠다는 것을 알림
				notecheck = 2; //2번째 노트를 출력하라는 의미 case 2:로 이동하게 됨
				notestart = clock(); //시작시간을 초기화함으로써 시간을 처음부터 다시 잼
				noteprint = 0; //다시 출력하기 위해 0으로 변경

				// 이 긴 코드는 다 같은 맥락에 코드이므로 설명을 여기까지만 쓰겠습니다. 모두 같은 방식의 코드입니다.
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

		// ========================  게임 종료 시  ============================
		if (gap > 87.0) //빠빠빠의 총 길이인 87초가 끝나면 게임을 종료함
		{
			system("cls");
			DesignStartScreen();

			PlaySound(TEXT("clear.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

			gotoxy(Width / 2 - 8, Height / 2 - 5);
			printf("클리어 하셨습니다!!");
			gotoxy(Width / 2 - 6, Height / 2);
			printf("점수 : %d점", score);
			gotoxy(Width / 2 - 8, Height / 2 + 4);
			printf("다시하시겠습니까?");
			gotoxy(Width / 2 - 6, Height / 2 + 6);
			printf("예");
			gotoxy(Width / 2 + 1, Height / 2 + 6);
			printf("아니오");
			gotoxy(Width / 2 - 3, Height / 2 + 6);
			printf("◀");

			int return_n = 0;
			while (1) //키보드 움직임, 다시하기 여부 확인
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
						case 75: //좌 기본
							gotoxy(Width / 2 - 3 + return_n, Height / 2 + 6);
							printf("  ");
							return_n = 0;
							gotoxy(Width / 2 - 3, Height / 2 + 6);
							printf("◀");
							break;
						case 77: //우 11칸앞
							return_n = 11;
							gotoxy(Width / 2 + 8 - return_n, Height / 2 + 6);
							printf("  ");
							gotoxy(Width / 2 + 8, Height / 2 + 6);
							printf("◀");
							break;
						default:
							break;
						}
					}
					else
						if (key == 13)//엔터
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

void MenuTwo() //메인메뉴에서 플레이 방법 메뉴로 들어가면 실행되는 함수
{
	system("cls");
	DesignStartScreen();
	gotoxy(Width / 2 - 5, Height / 2 - 9);
	printf("플레이 방법");
	gotoxy(Width / 2 - 6, Height / 2 - 5);
	printf("조작 : 방향키");
	gotoxy(Width / 2 - 16, Height / 2 - 3);
	printf("이 게임은 음악에 맞춰서 생성되는");
	gotoxy(Width / 2 - 15, Height / 2 - 1);
	printf("장애물을 피하면 되는 게임입니다.");
	gotoxy(Width / 2 - 11, Height / 2 + 1);
	printf("그럼 재밌게 즐겨주세요!");

	gotoxy(Width / 2 - 8, Height / 2 + 7);
	printf("종료하시겠습니까?");
	gotoxy(Width / 2 - 6, Height / 2 + 9);
	printf("예");
	gotoxy(Width / 2 + 1, Height / 2 + 9);
	printf("아니오");
	gotoxy(Width / 2 - 3, Height / 2 + 9);
	printf("◀");

	int return_n = 0;
	while (1) //키보드 움직임
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
				case 75: //좌 기본
					gotoxy(Width / 2 - 3 + return_n, Height / 2 + 9);
					printf("  ");
					return_n = 0;
					gotoxy(Width / 2 - 3, Height / 2 + 9);
					printf("◀");
					break;
				case 77: //우 11칸앞
					return_n = 11;
					gotoxy(Width / 2 + 8 - return_n, Height / 2 + 9);
					printf("  ");
					gotoxy(Width / 2 + 8, Height / 2 + 9);
					printf("◀");
					break;
				default:
					break;
				}
			}
			else
				if (key == 13)//엔터
				{
					if (return_n == 0)
						exit(1);
					else
						break;
				}

		}
	}
}

void MenuThree() //메인메뉴에서 제작 메뉴에 들어가면 실행되는 함수
{
	system("cls");
	DesignStartScreen();
	gotoxy(Width / 2 - 2, Height / 2 - 7);
	printf("제작");
	gotoxy(Width / 2 - 11, Height / 2 - 3);
	printf("한국디지털미디어고등학교");
	gotoxy(Width / 2 - 5, Height / 2 - 1);
	printf("1425 이우진");
	gotoxy(Width / 2 - 5, Height / 2 + 1);
	printf("1434 최현우");

	gotoxy(Width / 2 - 8, Height / 2 + 7);
	printf("종료하시겠습니까?");
	gotoxy(Width / 2 - 6, Height / 2 + 9);
	printf("예");
	gotoxy(Width / 2 + 1, Height / 2 + 9);
	printf("아니오");
	gotoxy(Width / 2 - 3, Height / 2 + 9);
	printf("◀");

	int return_n = 0;
	while (1) //키보드 움직임
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
				case 75: //좌 기본
					gotoxy(Width / 2 - 3 + return_n, Height / 2 + 9);
					printf("  ");
					return_n = 0;
					gotoxy(Width / 2 - 3, Height / 2 + 9);
					printf("◀");
					break;
				case 77: //우 11칸앞
					return_n = 11;
					gotoxy(Width / 2 + 8 - return_n, Height / 2 + 9);
					printf("  ");
					gotoxy(Width / 2 + 8, Height / 2 + 9);
					printf("◀");
					break;
				default:
					break;
				}
			}
			else
				if (key == 13)//엔터
				{
					if (return_n == 0)
						exit(1);
					else
						break;
				}

		}
	}
}

void SelectSong() //메인메뉴에서 게임 시작 메뉴로 들어가면 나오는 노래목록 메뉴
{
	system("cls");
	DesignStartScreen();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	gotoxy(Width / 2 - 3, 4);
	printf("노래 목록");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(Width / 2 - 8, 11);
	printf("크레용팝 - 빠빠빠");
	gotoxy(Width / 2 - 10, 16);
	printf("프로듀스101 - Pick Me");
	gotoxy(Width / 2 - 6, 21);
	printf("동요 - 비행기");
	gotoxy(Width / 2 - 9, 26);
	printf("아이콘 - 사랑을 했다");
	gotoxy(Width / 2 - 10, 31);
	printf("구구단 - Not That Type");
	gotoxy(Width / 2 + 15, 11);
	printf("◀");

	int return_n = 0;
	int playing = -1; //노래를 한번만 출력하기 위함
	while (1) //키보드 움직임
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
				case 72: //상
					gotoxy(Width / 2 + 15, 11 + return_n);
					printf("  ");
					return_n -= 5;
					if (return_n < 0) return_n = 0;
					gotoxy(Width / 2 + 15, 11 + return_n);
					printf("◀");
					break;
				case 80: //하
					gotoxy(Width / 2 + 15, 11 + return_n);
					printf("  ");
					return_n += 5;
					if (return_n > 20) return_n = 20;
					gotoxy(Width / 2 + 15, 11 + return_n);
					printf("◀");
					break;
				default:
					break;
				}
			}
			else
				if (key == 13)//엔터
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

		//↓ 각 위치에 맞는 노래 하이라이트를 재생함
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

void LoadNote(FILE * inp) //파일의 내용을 2차원 배열에 저장, 파일을 매개변수로 받음
{
	char arr;

	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			arr = fgetc(inp); //처음부터 한글자씩 받아서
			NoteData[i][j] = arr; //배열에 집어넣음
		}
	}
}

void PrintNote(int x, int y) //배열의 값들을 기호로 변경하여 출력함
{
	gotoxy(0, 0); //0,0으로 이동

	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (j > 10 && j < 20 && i == 0) printf("  ");
			else if (x == j * 2 && y == i) printf("◎"); //캐릭터의 위치에는 출력하지 않음
			else if (NoteData[i][j] == '0') printf("  "); //0일경우 빈칸
			else if (NoteData[i][j] == '1') printf("■"); //1일경우 블럭
			else if (NoteData[i][j] == '2') printf("▩"); //2일경우 벽 출력
		}
		if (i != 39) printf("\n");
	}
}

void PlayPick() //프로듀스 101 - PICK ME 스테이지 (빠빠빠 스테이지 (PlayBba()) 와 방식이 유사하므로 설명하지 않겠음)
{
	system("cls");
	PlaySound(TEXT("PICKME.wav"), NULL, SND_FILENAME | SND_ASYNC);

	gotoxy(Width / 2, Height / 2);
	printf("◎");

	int return_x = Width / 2, return_y = Height / 2;
	int score = 0;
	int cnt = 0;

	time_t startTime = clock();
	time_t notestart = clock();
	int notecheck = 1; //몇번 노트를 출력할 것 인가 케이스문 이용
	int noteprint = 0; //노트 출력 여부 1이면 출력완료, 0이면 미출력
	int notecount = 1; //노트를 출력한 전체 횟수

	while (1) //키보드 움직임
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
				case 72: //상
					gotoxy(return_x, return_y);
					printf("  ");
					return_y--;
					if (return_y < 1) return_y = 1;
					gotoxy(return_x, return_y);
					printf("◎");
					break;
				case 75: //좌
					gotoxy(return_x, return_y);
					printf("  ");
					return_x -= 2;
					if (return_x < 2) return_x = 2;
					gotoxy(return_x, return_y);
					printf("◎");
					break;
				case 77: //우
					gotoxy(return_x, return_y);
					printf("  ");
					return_x += 2;
					if (return_x > 56) return_x = 56;
					gotoxy(return_x, return_y);
					printf("◎");
					break;
				case 80: //하
					gotoxy(return_x, return_y);
					printf("  ");
					return_y++;
					if (return_y > 38) return_y = 38;
					gotoxy(return_x, return_y);
					printf("◎");
					break;
				default:
					break;
				}
			}
		}

		time_t noteend = clock(); //계속해서 시간을 체크함
		float notegap = (float)(noteend - notestart) / (CLOCKS_PER_SEC); //끝시간 - 처음시간으로 소요시간을 저장함

		gotoxy(Width / 2 - 5, 0);

		printf(" 점수 : %d ", score); //점수 출력
		cnt++;
		if (cnt > 500)
		{
			cnt = 0;
			score += 10;
		} //적당한 속도로 점수를 증가시키기 위함

		time_t endTime = clock();
		float gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC); //게임의 총 진행시간을 체크함
		
		if(gap > 0.5) {
			if (NoteData[return_y][return_x / 2] == '1')
			{
				system("cls");
				DesignStartScreen();

				PlaySound(TEXT("ending.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

				gotoxy(Width / 2 - 6, Height / 2);
				printf("점수 : %d점", score);
				gotoxy(Width / 2 - 8, Height / 2 + 4);
				printf("다시하시겠습니까?");
				gotoxy(Width / 2 - 6, Height / 2 + 6);
				printf("예");
				gotoxy(Width / 2 + 1, Height / 2 + 6);
				printf("아니오");
				gotoxy(Width / 2 - 3, Height / 2 + 6);
				printf("◀");

				int return_n = 0;
				while (1) //키보드 움직임
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
							case 75: //좌 기본
								gotoxy(Width / 2 - 3 + return_n, Height / 2 + 6);
								printf("  ");
								return_n = 0;
								gotoxy(Width / 2 - 3, Height / 2 + 6);
								printf("◀");
								break;
							case 77: //우 11칸앞
								return_n = 11;
								gotoxy(Width / 2 + 8 - return_n, Height / 2 + 6);
								printf("  ");
								gotoxy(Width / 2 + 8, Height / 2 + 6);
								printf("◀");
								break;
							default:
								break;
							}
						}
						else
							if (key == 13)//엔터
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

		// ========================  게임 종료 시  ============================
		if (gap > 100.0)
		{
			system("cls");
			DesignStartScreen();

			PlaySound(TEXT("clear.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

			gotoxy(Width / 2 - 8, Height / 2 - 5);
			printf("클리어 하셨습니다!!");
			gotoxy(Width / 2 - 6, Height / 2);
			printf("점수 : %d점", score);
			gotoxy(Width / 2 - 8, Height / 2 + 4);
			printf("다시하시겠습니까?");
			gotoxy(Width / 2 - 6, Height / 2 + 6);
			printf("예");
			gotoxy(Width / 2 + 1, Height / 2 + 6);
			printf("아니오");
			gotoxy(Width / 2 - 3, Height / 2 + 6);
			printf("◀");

			int return_n = 0;
			while (1) //키보드 움직임
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
						case 75: //좌 기본
							gotoxy(Width / 2 - 3 + return_n, Height / 2 + 6);
							printf("  ");
							return_n = 0;
							gotoxy(Width / 2 - 3, Height / 2 + 6);
							printf("◀");
							break;
						case 77: //우 11칸앞
							return_n = 11;
							gotoxy(Width / 2 + 8 - return_n, Height / 2 + 6);
							printf("  ");
							gotoxy(Width / 2 + 8, Height / 2 + 6);
							printf("◀");
							break;
						default:
							break;
						}
					}
					else
						if (key == 13)//엔터
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

void PlayAir() //동요 - 비행기 스테이지 (이 역시 빠빠빠, PICK ME와 방식이 동일하므로 설명하지 않겠음)
{
	system("cls");
	PlaySound(TEXT("airplane.wav"), NULL, SND_FILENAME | SND_ASYNC);

	gotoxy(Width / 2, Height / 2);
	printf("◎");

	int return_x = Width / 2, return_y = Height / 2;
	int score = 0;
	int cnt = 0;

	time_t startTime = clock();
	time_t notestart = clock();
	int notecheck = 1; //몇번 노트를 출력할 것 인가 케이스문 이용
	int noteprint = 0; //노트 출력 여부 1이면 출력완료, 0이면 미출력
	int notecount = 1; //노트를 출력한 전체 횟수

	while (1) //키보드 움직임
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
				case 72: //상
					gotoxy(return_x, return_y);
					printf("  ");
					return_y--;
					if (return_y < 1) return_y = 1;
					gotoxy(return_x, return_y);
					printf("◎");
					break;
				case 75: //좌
					gotoxy(return_x, return_y);
					printf("  ");
					return_x -= 2;
					if (return_x < 2) return_x = 2;
					gotoxy(return_x, return_y);
					printf("◎");
					break;
				case 77: //우
					gotoxy(return_x, return_y);
					printf("  ");
					return_x += 2;
					if (return_x > 56) return_x = 56;
					gotoxy(return_x, return_y);
					printf("◎");
					break;
				case 80: //하
					gotoxy(return_x, return_y);
					printf("  ");
					return_y++;
					if (return_y > 38) return_y = 38;
					gotoxy(return_x, return_y);
					printf("◎");
					break;
				default:
					break;
				}
			}
		}

		time_t noteend = clock(); //계속해서 시간을 체크함
		float notegap = (float)(noteend - notestart) / (CLOCKS_PER_SEC); //끝시간 - 처음시간으로 소요시간을 저장함

		gotoxy(Width / 2 - 5, 0);

		printf(" 점수 : %d ", score); //점수 출력
		cnt++;
		if (cnt > 500)
		{
			cnt = 0;
			score += 10;
		} //적당한 속도로 점수를 증가시키기 위함

		time_t endTime = clock();
		float gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC); //게임의 총 진행시간을 체크함

		if (gap > 5.5) {
			if (NoteData[return_y][return_x / 2] == '1')
			{
				system("cls");
				DesignStartScreen();

				PlaySound(TEXT("ending.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

				gotoxy(Width / 2 - 6, Height / 2);
				printf("점수 : %d점", score);
				gotoxy(Width / 2 - 8, Height / 2 + 4);
				printf("다시하시겠습니까?");
				gotoxy(Width / 2 - 6, Height / 2 + 6);
				printf("예");
				gotoxy(Width / 2 + 1, Height / 2 + 6);
				printf("아니오");
				gotoxy(Width / 2 - 3, Height / 2 + 6);
				printf("◀");

				int return_n = 0;
				while (1) //키보드 움직임
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
							case 75: //좌 기본
								gotoxy(Width / 2 - 3 + return_n, Height / 2 + 6);
								printf("  ");
								return_n = 0;
								gotoxy(Width / 2 - 3, Height / 2 + 6);
								printf("◀");
								break;
							case 77: //우 11칸앞
								return_n = 11;
								gotoxy(Width / 2 + 8 - return_n, Height / 2 + 6);
								printf("  ");
								gotoxy(Width / 2 + 8, Height / 2 + 6);
								printf("◀");
								break;
							default:
								break;
							}
						}
						else
							if (key == 13)//엔터
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

		// ========================  게임 종료 시  ============================
		if (gap > 17.0)
		{
			system("cls");
			DesignStartScreen();

			PlaySound(TEXT("clear.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

			gotoxy(Width / 2 - 8, Height / 2 - 5);
			printf("클리어 하셨습니다!!");
			gotoxy(Width / 2 - 6, Height / 2);
			printf("점수 : %d점", score);
			gotoxy(Width / 2 - 8, Height / 2 + 4);
			printf("다시하시겠습니까?");
			gotoxy(Width / 2 - 6, Height / 2 + 6);
			printf("예");
			gotoxy(Width / 2 + 1, Height / 2 + 6);
			printf("아니오");
			gotoxy(Width / 2 - 3, Height / 2 + 6);
			printf("◀");

			int return_n = 0;
			while (1) //키보드 움직임
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
						case 75: //좌 기본
							gotoxy(Width / 2 - 3 + return_n, Height / 2 + 6);
							printf("  ");
							return_n = 0;
							gotoxy(Width / 2 - 3, Height / 2 + 6);
							printf("◀");
							break;
						case 77: //우 11칸앞
							return_n = 11;
							gotoxy(Width / 2 + 8 - return_n, Height / 2 + 6);
							printf("  ");
							gotoxy(Width / 2 + 8, Height / 2 + 6);
							printf("◀");
							break;
						default:
							break;
						}
					}
					else
						if (key == 13)//엔터
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