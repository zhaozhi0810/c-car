//*****************************************************************
//	Silple Race Ver 0.1
//	Made by 'k-net 9th' Jae-Dong
//	E-Mail: pjd@kw.ac.kr
//*****************************************************************
#include <stdio.h>
#include <sys/ioctl.h>
//#include <ncurses.h>
#include <stdlib.h>
#include <termios.h>
#include <termio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
//#include <curses.h>
#include <math.h>
#include <string.h>
#include "display.h"
#include "road.h"
#include "car.h"
#include "player.h"



#define KEY_LEFT	68
#define KEY_RIGHT	67



int InputPlayerData(struct AllPlayer *pd);
char VideoBuf[CONSOL_HEIGHT][CONSOL_WIDTH + 1];	



int main(int argc, char* argv[])
{

	double delay;
	//int frame = 0;
	int i;
	char KeyTemp;

	struct AllPlayer *pd = malloc(sizeof (struct AllPlayer));
	if(pd == NULL)
	{
		printf("ERROR: malloc pd\n");
		return -1;
	}

	
	PlayerInit(pd);
	Init();		//车的属性初始化
	ShowLogo();	//打印logo
	InputPlayerData(pd);	//输入玩家数据
	ClcScreen();
	pd->PlayerEnergy = Cardata[pd->PlayerCarnum].energy;  //根据输入的Carnum获取该车的能量值 
	ShowGameFrame(pd);
	//ShowStat(pd);		//刷新状态
	ShowCount();		//倒计时动画
	pd->PlayerAccel = (float)Cardata[pd->PlayerCarnum].accel / 10;
	for (i = 0; i <= 200000; i++)	//游戏开始 
	{
		// if (kbhit())	//linux下需要重写 
		// {					//_getche有返回显示 不需要回车的读取字符
		// 	KeyTemp = getche();	//读取方向键的固定方式 
		// 		Gotoxy(0, 24);
		// 		putchar(' ');	//在dalay那一行 
		// 		switch (KeyTemp)
		// 		{
		// 		case KEY_LEFT:
		// 			ShowCar(-1,pd);
		// 			pd->PlayerSpeed -= 1;	//左右移动后减速
		// 			StrikeCheck(pd);
		// 			break;
		// 		case KEY_RIGHT:
		// 			ShowCar(1,pd);
		// 			pd->PlayerSpeed -= 1;
		// 			StrikeCheck(pd);
		// 			break;
		// 		}
	
		// 	StrikeCheck(pd);
		// }
		// StrikeCheck(pd);
		if (pd->PlayerSpeed < 100)
			pd->PlayerSpeed += 2.7;
		if (pd->SpeedCounter > 6)		//加速
		{
			if (pd->PlayerSpeed < 100)
			{
				pd->PlayerSpeed = pd->PlayerSpeed + (7.6 * pd->PlayerAccel);
			}
			else if (pd->PlayerSpeed < 200)
			{
				pd->PlayerSpeed = pd->PlayerSpeed + (1.2 * pd->PlayerAccel);
			}
			else if (pd->PlayerSpeed < 300)
			{
				pd->PlayerSpeed = pd->PlayerSpeed + (0.3 * pd->PlayerAccel);
			}
			else if (pd->PlayerSpeed < 315)
			{
				pd->PlayerSpeed = pd->PlayerSpeed + (0.1 * pd->PlayerAccel);
			}
			else
			{
				pd->PlayerSpeed = pd->PlayerSpeed + (0.06 * pd->PlayerAccel);
			}
			if (pd->PlayerSpeed>Cardata[pd->PlayerCarnum].MaxSpd)
				pd->PlayerSpeed = Cardata[pd->PlayerCarnum].MaxSpd;
		}

		double dp=pd->PlayerSpeed;
		delay = 350 - (351 * (1 - exp(- dp / 150)));	
		if (delay<0)
			delay = 0.01;
		if (i % 50 == 0)			//for每循环50次的逻辑    
		{
			pd->PlayerScore = (float)((pd->PlayerScore + pd->PlayerSpeed / 50)* 1.0003);	//根据当前速度加分
			ShowStat(pd);
		//	ShowCar(0,pd);
			ShowRoad();
		//	StrikeCheck(pd);
			pd->SpeedCounter++;
		}
		ShowStat(pd);
		if (pd->PlayerEnergy <= 0)
		{
			ShowGameover();
			short num = 0;
			char TmpChar = 1, test[1000];
			while (TmpChar)
			{
				test[num++] = getche();
				if (test[--num] == 0x0D)
					TmpChar = 0;
			}
			break;
		}
		Gotoxy(10, 24);
		printf("delay: %10.2f", (float)delay);
		Gotoxy(0, 24);
		usleep((unsigned int)delay*50);

	}
	free(pd);
	pd=NULL;
	Gotoxy(2, 2);	//用于测试
	return 0;
}
