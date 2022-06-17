#include "player.h"
#include "car.h"
#include "display.h"




int ShowGameFrame(struct AllPlayer *pd)	
{
	int i;
	for (i = 1; i<CONSOL_HEIGHT - 1; i++)
	{
		Gotoxy(0, i);
		printf("┃");
		Gotoxy(56, i);
		printf("┃");
		Gotoxy(78, i);
		printf("┃");
	}
	Gotoxy(0, CONSOL_HEIGHT - 1);
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	Gotoxy(58, 1);
	printf("    Simple Racing");
	Gotoxy(58, 2);
	printf("       Ver 0.3");
	Gotoxy(57, 3);
    printf("━━━━━━━━━━━━━━━━━━━━━");
	Gotoxy(58, 4);
	printf(" Name:");
	Gotoxy(58, 5);
	printf(" %17s", pd->PlayerName);
    Gotoxy(57, 6);
    printf("━━━━━━━━━━━━━━━━━━━━━");
	Gotoxy(58, 7);
	printf(" Score:");
    Gotoxy(57, 9);
    printf("━━━━━━━━━━━━━━━━━━━━━");
	Gotoxy(58, 10);
	printf(" Energy:");
    Gotoxy(57, 12);
    printf("━━━━━━━━━━━━━━━━━━━━━");
	Gotoxy(58, 13);
	printf(" Speed:");
	Gotoxy(58, 14);
	printf("              km/h  ");
	Gotoxy(58, 15);
	printf(" RPM:");
    Gotoxy(57, 17);
    printf("━━━━━━━━━━━━━━━━━━━━━");

	Gotoxy(61, 18);
	printf("--Car Info--");
	Gotoxy(59, 19);
	printf("Model  :%s", Cardata[pd->PlayerCarnum].Name);
	Gotoxy(59, 20);
	printf("Max Spd: %d Km/h", Cardata[pd->PlayerCarnum].MaxSpd);
	Gotoxy(59, 21);
	printf("Energy :  %d", Cardata[pd->PlayerCarnum].energy);
	Gotoxy(59, 22);
	printf("Accel  :   %d", Cardata[pd->PlayerCarnum].accel);

	return 0;
}
int ShowLogo()
{
	int i;
	int LogoDelay = 5000;			//logo显示的间隔 刷新时间 5ms
	ClcScreen();
	Gotoxy(4, 2);
	for (i = 4; i<76; i++)
	{
		printf("*");   
		fflush(stdout);
		usleep(LogoDelay);		
	}
	for (i = 3; i<8; i++)
	{
		Gotoxy(75, i); printf("*");
		fflush(stdout);
		usleep(LogoDelay);
	}

	for (i = 75; i >= 4; i--)
	{
		Gotoxy(i, 7);
		printf("*");
		fflush(stdout);
		usleep(LogoDelay);
	}

	for (i = 7; i >= 3; i--)
	{
		Gotoxy(4, i); printf("*");
		fflush(stdout);
		usleep(LogoDelay);
	}
	fflush(stdout);
	usleep(80000);
	Gotoxy(32, 4);
	printf("☆  简易赛车游戏  ☆");
	fflush(stdout);
	usleep(80000);
	Gotoxy(8, 6);
	printf("Ver 0.3");
	fflush(stdout);
	usleep(80000);
	Gotoxy(56, 6);
	printf("www");
	fflush(stdout);
	ShowCarxy(0, 13, 15);
	fflush(stdout);
	usleep(200000);
	ShowCarxy(1, 27, 15);
	fflush(stdout);
	usleep(200000);
	ShowCarxy(2, 41, 15);
	fflush(stdout);
	usleep(200000);
	ShowCarxy(3, 55, 15);
	fflush(stdout);

	Gotoxy(28, 21);
	printf("请按任意键继续：");
	fflush(stdout);
	usleep(1000000);
	short num = 0;
	char TmpChar = 1, test[1000];
	while (TmpChar)
	{
		test[num++] = getche();
		if (test[--num] == 0x0D)
			TmpChar = 0;
	}
}
int ShowGameover()
{
	Gotoxy(12, 8);
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	Gotoxy(12, 9);
	printf("┃********************************┃");
	Gotoxy(12, 10);
	printf("┃*           GAME OVER          *┃");
	Gotoxy(12, 11);
	printf("┃********************************┃");
	Gotoxy(12, 12);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	return 0;
}

int ShowCount()
{
	int i, j, k;
	Gotoxy(16, 5);
	printf("┏━━━━━━━━━━━━━━━━━━━┓");
	Gotoxy(16, 6);
	printf("┃       ■■■         ┃");
	Gotoxy(16, 7);
	printf("┃     ■      ■      ┃");
	Gotoxy(16, 8);
	printf("┃             ■     ┃");
	Gotoxy(16, 9);
	printf("┃             ■     ┃");
	Gotoxy(16, 10);
	printf("┃         ■■        ┃");
	Gotoxy(16, 11);
	printf("┃             ■     ┃");
	Gotoxy(16, 12);
	printf("┃    ■        ■     ┃");
	Gotoxy(16, 13);
	printf("┃     ■      ■      ┃");
	Gotoxy(16, 14);
	printf("┃       ■■■         ┃");
	Gotoxy(16, 15);
	printf("┣━━━━━━━━━━━━━━━━━━━┫");
	Gotoxy(16, 16);
	printf("┃  ← : Move Left    ┃");
	Gotoxy(16, 17);
	printf("┃  → : Move Right   ┃");
	Gotoxy(16, 18);
	printf("┗━━━━━━━━━━━━━━━━━━━┛");

	Gotoxy(0, 23);
	fflush(stdout);
	usleep(1000000);

	Gotoxy(16, 5);
	printf("┏━━━━━━━━━━━━━━━━━━━┓");
	Gotoxy(16, 6);
	printf("┃       ■■■         ┃");
	Gotoxy(16, 7);
	printf("┃     ■      ■      ┃");
	Gotoxy(16, 8);
	printf("┃             ■     ┃");
	Gotoxy(16, 9);
	printf("┃            ■      ┃");
	Gotoxy(16, 10);
	printf("┃          ■        ┃");
	Gotoxy(16, 11);
	printf("┃        ■          ┃");
	Gotoxy(16, 12);
	printf("┃      ■            ┃");
	Gotoxy(16, 13);
	printf("┃    ■              ┃");
	Gotoxy(16, 14);
	printf("┃    ■■■■■■■■■      ┃");


	Gotoxy(0, 23);
	fflush(stdout);
	usleep(1000000);

	Gotoxy(16, 5);
	printf("┏━━━━━━━━━━━━━━━━━━━┓");
	Gotoxy(16, 6);
	printf("┃         ■         ┃");
	Gotoxy(16, 7);
	printf("┃       ■■          ┃");
	Gotoxy(16, 8);
	printf("┃         ■         ┃");
	Gotoxy(16, 9);
	printf("┃         ■         ┃");
	Gotoxy(16, 10);
	printf("┃         ■         ┃");
	Gotoxy(16, 11);
	printf("┃         ■         ┃");
	Gotoxy(16, 12);
	printf("┃         ■         ┃");
	Gotoxy(16, 13);
	printf("┃         ■         ┃");
	Gotoxy(16, 14);
	printf("┃       ■■■■■       ┃");


	Gotoxy(0, 23);
	fflush(stdout);
	usleep(1000000);

	Gotoxy(16, 5);
	printf("┏━━━━━━━━━━━━━━━━━━┓");
	Gotoxy(16, 6);
	printf("┃       ■■■        ┃");
	Gotoxy(16, 7);
	printf("┃     ■      ■     ┃");
	Gotoxy(16, 8);
	printf("┃     ■      ■     ┃");
	Gotoxy(16, 9);
	printf("┃     ■    ■■      ┃");
	Gotoxy(16, 10);
	printf("┃     ■  ■  ■      ┃");
	Gotoxy(16, 11);
	printf("┃     ■■    ■      ┃");
	Gotoxy(16, 12);
	printf("┃     ■      ■     ┃");
	Gotoxy(16, 13);
	printf("┃     ■      ■     ┃");
	Gotoxy(16, 14);
	printf("┃       ■■■        ┃");

	fflush(stdout);
	usleep(1000000);
	for (j = 16, k = 40; j <= 41; j++, k--)	 
	{
		for (i = 5; i<18; i += 2)
		{
			Gotoxy(j - 1, i);
			printf(" ");
			if (j != 41)
			{

				printf("*");
			}
			Gotoxy(k, i + 1);
			if (k != 13)
			{
				printf("*");
			}
			printf(" ");

		}
		fflush(stdout);
		usleep(80000);
	}
	return 0;

}
