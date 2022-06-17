#include <stdio.h>
#include "display.h"
#include "road.h"
#include "car.h"
#include "player.h"
#include <string.h>


void PlayerInit(struct AllPlayer *pd) //玩家数据初始换  结构体指针
{
	strcpy(pd->PlayerName ,"NoName");
	pd->PlayerScore = 0;
	pd->PlayerEnergy = 99; 
	pd->PlayerSpeed = 1;
	pd->PlayerCarnum = 9;  
	pd->PlayerAccel=0.0;
	pd->PlayerCarpos = 20; 
	pd->SpeedCounter = 0;  
}

int ShowStat(struct AllPlayer *pd)
{
	int i, j;
	static int RecentEnergy = 999, RecentRpm = 999, RecentSpeed = 999;
	//score
	Gotoxy(58, 8);
	printf("%19.0f", pd->PlayerScore);
	Gotoxy(58, 11);
	if (RecentEnergy != pd->PlayerEnergy)		// 仅在值发生变化时刷新屏幕
	{
		for (i = 0, j = pd->PlayerEnergy; i<10; i++)//有十次撞击机会，撞击十次，游戏结束
		{
			if (j >= 10)
				printf("■");
			else
				printf("□");
			j -= 10;
		}
	}
	if (RecentSpeed != pd->PlayerSpeed)
	{
		Gotoxy(58, 14);
		printf("%12.0f", pd->PlayerSpeed);
	}

	//RPM 转速?
	Gotoxy(58, 16);
	j = (int)((pd->PlayerSpeed * 10) / Cardata[pd->PlayerCarnum].MaxSpd);
	if (j != RecentRpm)	//仅在值发生变化时刷新屏幕
	{
		for (i = 0; i<10; i++)
		{
			if (j>i)
				printf("■");
			else
				printf("□");
		}
	}
	RecentRpm = j;
	RecentEnergy = pd->PlayerEnergy;
	return 0;
}

int InputPlayerData(struct AllPlayer *pd)
{
	int i, j, k;
	ClcScreen();
	Gotoxy(3, 3);
	printf("Name:");
	Gotoxy(3, 7);
	printf("Select Your Car:");//5车隐藏
	ShowCarxy(0, 15, 10);
	ShowCarxy(1, 33, 10);
	ShowCarxy(2, 51, 10);
	ShowCarxy(3, 69, 10);

	Gotoxy(12, 9);
	printf("    [ 1 ]             [ 2 ]             [ 3 ]             [ 4 ] ");

	Gotoxy(2, 16);
	printf("Model Name:");

	Gotoxy(2, 18);
	printf("MAX Speed :");

	Gotoxy(2, 20);
	printf("Energy    :");

	Gotoxy(2, 22);
	printf("Accelation:");

	for (i = 16, j = 0; j<4; i += 18, j++)
	{
		Gotoxy(i, 16);
		printf("%s", Cardata[j].Name);
	}

	for (i = 16, j = 0; j<4; i += 18, j++)
	{
		Gotoxy(i, 18);
		printf("%d Km/h", Cardata[j].MaxSpd);
	}

	for (i = 16, j = 0; j<4; i += 18, j++)
	{
		Gotoxy(i, 20);
		for (k = Cardata[j].energy / 10; k>0; k--)
			printf("*");
	}

	for (i = 16, j = 0; j<4; i += 18, j++)
	{
		Gotoxy(i, 22);
		for (k = Cardata[j].accel
			; k>0; k--)
			printf("*");
	}

	Gotoxy(11, 3);
	scanf("%s", pd->PlayerName);
	while ((pd->PlayerCarnum < 0) || (pd->PlayerCarnum > 4))		//输入不对就一直输入
	{
		Gotoxy(27, 7);
		scanf("%d", &pd->PlayerCarnum);
		pd->PlayerCarnum--;	// 控制在Cardata里面的索引
	}
	return 0;
}

int kbhit(void)
{
	struct termios oldt, newt;
	int ch;
	int oldf;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);
	if (ch != EOF)
	{
		ungetc(ch, stdin);
		return 1;
	}
	return 0;
}
int getche(void)
{
	struct termios tm, tm_old;
	int fd = 0, ch;
	if (tcgetattr(fd, &tm) < 0) //保存现在的终端设置
	{
		return -1;
	}
	tm_old = tm;
	cfmakeraw(&tm);//更改终端设置为原始模式，该模式下所有的输入数据以字节为单位被处理
	if (tcsetattr(fd, TCSANOW, &tm) < 0) //设置上更改之后的设置
	{
		return -1;
	}
	ch = getchar();
	if (tcsetattr(fd, TCSANOW, &tm_old) < 0) //更改设置为最初的样子
	{
		return -1;
	}
	return ch;
}
void Gotoxy(int x, int y)
{
	printf("%c[%d;%df", 0x1B, y, x);
}

void ClcScreen()
{
	printf("\033c");
}
