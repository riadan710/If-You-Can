//time_t noteend = clock();
//float notegap = (float)(noteend - notestart) / (CLOCKS_PER_SEC);
//switch (notecheck)
//{
//case 1: //none
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("none.txt", "r");
//		LoadNote(note);
//		PrintNote();
//
//		noteprint = 1;
//	}
//	if (notecount == 1 && notegap > 14.5)
//	{
//		notecount++;
//		notecheck = 2;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 4 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 3;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 6 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 3;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 8 && notegap > 0.24)
//	{
//		notecount++;
//		notecheck = 3;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 10 && notegap > 0.74)
//	{
//		notecount++;
//		notecheck = 4;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 13 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 3;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 15 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 3;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 17 && notegap > 0.24)
//	{
//		notecount++;
//		notecheck = 3;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 19 && notegap > 0.74)
//	{
//		notecount++;
//		notecheck = 5;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 36 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 3;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 38 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 3;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 40 && notegap > 0.24)
//	{
//		notecount++;
//		notecheck = 3;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 42 && notegap > 0.74)
//	{
//		notecount++;
//		notecheck = 20;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 45 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 3;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 47 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 3;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 49 && notegap > 0.24)
//	{
//		notecount++;
//		notecheck = 3;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 51 && notegap > 0.74)
//	{
//		notecount++;
//		notecheck = 5;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 2: //1
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("1.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	else if (notecount == 2 && notegap > 0.5)
//	{
//		notecount++;
//		notecheck = 3;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 77 && notegap > 0.65)
//	{
//		notecount++;
//		notecheck = 31;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 3: //bba
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("bba.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 3 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 1;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 5 && notegap > 0.48)
//	{
//		notecount++;
//		notecheck = 1;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 7 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 1;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 9 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 1;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 12 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 1;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 14 && notegap > 0.48)
//	{
//		notecount++;
//		notecheck = 1;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 16 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 1;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 18 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 1;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 35 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 1;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 37 && notegap > 0.48)
//	{
//		notecount++;
//		notecheck = 1;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 39 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 1;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 41 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 1;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 44 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 1;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 46 && notegap > 0.48)
//	{
//		notecount++;
//		notecheck = 1;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 48 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 1;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 50 && notegap > 0.32)
//	{
//		notecount++;
//		notecheck = 1;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 4: //2
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("2.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 11 && notegap > 0.5)
//	{
//		notecount++;
//		notecheck = 3;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 76 && notegap > 0.65)
//	{
//		notecount++;
//		notecheck = 2;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 5: //ho1
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("ho1.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 20 && notegap > 0.35)
//	{
//		notecount++;
//		notecheck = 6;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 52 && notegap > 0.35)
//	{
//		notecount++;
//		notecheck = 6;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 6: //ho2
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("ho2.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 21 && notegap > 0.35)
//	{
//		notecount++;
//		notecheck = 7;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 53 && notegap > 0.35)
//	{
//		notecount++;
//		notecheck = 7;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 7: //ho3
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("ho3.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 22 && notegap > 0.35)
//	{
//		notecount++;
//		notecheck = 8;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 54 && notegap > 0.35)
//	{
//		notecount++;
//		notecheck = 8;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 8: //ho4
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("ho4.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 23 && notegap > 0.5)
//	{
//		notecount++;
//		notecheck = 9;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 55 && notegap > 0.5)
//	{
//		notecount++;
//		notecheck = 9;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 9: //kung1
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("kung1.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 24 && notegap > 0.28)
//	{
//		notecount++;
//		notecheck = 10;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 56 && notegap > 0.28)
//	{
//		notecount++;
//		notecheck = 10;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 10: //kung2
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("kung2.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 25 && notegap > 0.28)
//	{
//		notecount++;
//		notecheck = 11;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 57 && notegap > 0.28)
//	{
//		notecount++;
//		notecheck = 11;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 11: //kung3
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("kung3.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 26 && notegap > 0.28)
//	{
//		notecount++;
//		notecheck = 12;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 58 && notegap > 0.28)
//	{
//		notecount++;
//		notecheck = 12;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 12: //kung4
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("kung4.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 27 && notegap > 0.28)
//	{
//		notecount++;
//		notecheck = 13;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 59 && notegap > 0.28)
//	{
//		notecount++;
//		notecheck = 13;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 13: //kung5
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("kung5.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 28 && notegap > 0.28)
//	{
//		notecount++;
//		notecheck = 14;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 60 && notegap > 0.28)
//	{
//		notecount++;
//		notecheck = 14;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 14: //follow1
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("follow1.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 29 && notegap > 0.84)
//	{
//		notecount++;
//		notecheck = 15;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 61 && notegap > 0.84)
//	{
//		notecount++;
//		notecheck = 15;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 15: //follow2
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("follow2.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 30 && notegap > 0.84)
//	{
//		notecount++;
//		notecheck = 16;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 62 && notegap > 0.84)
//	{
//		notecount++;
//		notecheck = 16;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 16: //follow3
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("follow3.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 31 && notegap > 0.84)
//	{
//		notecount++;
//		notecheck = 17;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 63 && notegap > 0.84)
//	{
//		notecount++;
//		notecheck = 17;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 17: //follow4
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("follow4.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 32 && notegap > 0.84)
//	{
//		notecount++;
//		notecheck = 18;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 64 && notegap > 0.84)
//	{
//		notecount++;
//		notecheck = 18;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 18: //follow5
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("follow5.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 33 && notegap > 0.84)
//	{
//		notecount++;
//		notecheck = 20;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 65 && notegap > 0.84)
//	{
//		notecount++;
//		notecheck = 21;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 20: //go
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("go.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 34 && notegap > 0.5)
//	{
//		notecount++;
//		notecheck = 3;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 43 && notegap > 0.5)
//	{
//		notecount++;
//		notecheck = 3;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 78 && notegap > 0.2)
//	{
//		notecount++;
//		notecheck = 32;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 79 && notegap > 0.2)
//	{
//		notecount++;
//		notecheck = 32;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 21: //pop1
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("pop1.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 66 && notegap > 0.3)
//	{
//		notecount++;
//		notecheck = 22;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 22: //pop2
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("pop2.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 67 && notegap > 0.3)
//	{
//		notecount++;
//		notecheck = 23;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 23: //pop3
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("pop3.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 68 && notegap > 0.3)
//	{
//		notecount++;
//		notecheck = 24;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 24: //pop4
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("pop4.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 69 && notegap > 0.3)
//	{
//		notecount++;
//		notecheck = 25;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 25: //pop5
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("pop5.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 70 && notegap > 0.3)
//	{
//		notecount++;
//		notecheck = 26;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 26: //pop6
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("pop6.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 71 && notegap > 0.3)
//	{
//		notecount++;
//		notecheck = 27;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 27: //crayon1
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("crayon1.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 72 && notegap > 0.5)
//	{
//		notecount++;
//		notecheck = 28;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 28: //crayon2
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("crayon2.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 73 && notegap > 0.5)
//	{
//		notecount++;
//		notecheck = 29;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 29: //crayon3
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("crayon3.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 74 && notegap > 0.5)
//	{
//		notecount++;
//		notecheck = 30;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 30: //crayon4
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("crayon4.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 75 && notegap > 0.5)
//	{
//		notecount++;
//		notecheck = 4;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 31: //ready
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("ready.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 78 && notegap > 1.8)
//	{
//		notecount++;
//		notecheck = 20;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 32: //jump1
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("jump1.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 80 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 33;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 87 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 33;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 108 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 33;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 115 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 33;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 33: //jump2
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("jump2.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 81 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 34;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 88 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 34;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 109 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 34;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 116 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 34;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 34: //jump3
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("jump3.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 82 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 35;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 89 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 35;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 110 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 35;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 117 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 35;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 35: //jump4
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("jump4.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 83 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 36;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 90 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 36;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 111 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 36;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 118 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 36;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 36: //jump5
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("jump5.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 84 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 37;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 91 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 37;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 112 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 37;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 119 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 37;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 37: //jump6
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("jump6.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 85 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 38;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 92 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 39;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 113 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 38;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 120 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 39;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 38: //everybody
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("everybody.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 86 && notegap > 0.9)
//	{
//		notecount++;
//		notecheck = 32;
//		notestart = clock();
//		noteprint = 0;
//	}
//	if (notecount == 114 && notegap > 0.9)
//	{
//		notecount++;
//		notecheck = 32;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 39: //dduieo
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("dduieo.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 93 && notegap > 0.9)
//	{
//		notecount++;
//		notecheck = 40;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 121 && notegap > 0.9)
//	{
//		notecount++;
//		notecheck = 40;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 40: //jump7
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("jump7.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 94 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 41;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 122 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 41;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 41: //jump8
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("jump8.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 95 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 42;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 123 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 42;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 42: //jump9
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("jump9.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 96 && notegap > 0.9)
//	{
//		notecount++;
//		notecheck = 43;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 124 && notegap > 0.9)
//	{
//		notecount++;
//		notecheck = 43;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 43: //jump10
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("jump10.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 97 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 44;
//		notestart = clock();
//		noteprint = 0;
//	}
//	if (notecount == 125 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 44;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 44: //jump11
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("jump11.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 98 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 45;
//		notestart = clock();
//		noteprint = 0;
//	}
//	if (notecount == 126 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 45;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 45: //jump12
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("jump12.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 99 && notegap > 0.9)
//	{
//		notecount++;
//		notecheck = 46;
//		notestart = clock();
//		noteprint = 0;
//	}
//	if (notecount == 127 && notegap > 0.9)
//	{
//		notecount++;
//		notecheck = 46;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 46: //want1
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("want1.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 100 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 47;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 104 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 47;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 128 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 47;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 132 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 47;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 136 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 47;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 140 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 47;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 47: //want2
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("want2.txt", "r");
//		PrintNote(note);
//
//		noteprint = 1;
//	}
//	if (notecount == 101 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 48;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 105 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 48;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 129 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 48;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 133 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 48;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 137 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 48;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 141 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 48;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 48: //want3
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("want3.txt", "r");
//		PrintNote;
//
//		noteprint = 1;
//	}
//	if (notecount == 102 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 49;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 106 && notegap > 0.6)
//	{
//		notecount++;
//		notecheck = 49;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 130 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 49;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 134 && notegap > 0.6)
//	{
//		notecount++;
//		notecheck = 49;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 138 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 49;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 142 && notegap > 0.6)
//	{
//		notecount++;
//		notecheck = 49;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//case 49: //want4
//	if (noteprint == 0)
//	{
//		FILE * note = fopen("want4.txt", "r");
//		PrintNote;
//
//		noteprint = 1;
//	}
//	if (notecount == 103 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 46;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 107 && notegap > 0.15)
//	{
//		notecount++;
//		notecheck = 32;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 131 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 46;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 135 && notegap > 0.15)
//	{
//		notecount++;
//		notecheck = 46;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 139 && notegap > 0.45)
//	{
//		notecount++;
//		notecheck = 46;
//		notestart = clock();
//		noteprint = 0;
//	}
//	else if (notecount == 143 && notegap > 0.15)
//	{
//		notecount++;
//		notecheck = 1;
//		notestart = clock();
//		noteprint = 0;
//	}
//	break;
//}