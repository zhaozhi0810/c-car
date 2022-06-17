#include <stdio.h>
#include "display.h"
#include "car.h"
#include "player.h"
#include "road.h"
static char Road[22][2] = { 15, 30, 15, 30, 15, 30, 15, 30, 15, 30, 15, 30, 15, 30, 15, 30, 15, 30, 15, 30, 15, 30, 15, 30,
	15, 30, 15, 30, 15, 30, 15, 30, 15, 30, 15, 30, 15, 30, 15, 30, 15, 30, 15, 30 };
int ShowRoad()
{
	int i, j;
	int rand_num;
	static int Road_left = 15, Road_right = 32;
	Gotoxy(Road[(RoadIndex + 1) % 22][0], 1);
	printf(" ");
	Gotoxy(Road[(RoadIndex + 1) % 22][1], 1);
	printf(" ");

	//清除原来的符号
	for (j = 2, i = RoadIndex + 1; j<23; i++, j++)  //道路总共22行
	{
		i = i % 22;
		if (Road[(i + 1) % 22][0] != Road[i][0]) 	//当上一行和下一行的道路位置相同时，屏幕上不清除道路 
		{
			Gotoxy(Road[(i + 1) % 22][0], j);   //j表示哪一行，0表示左侧
			printf(" ");  //原来的道路符号清除掉
			Gotoxy(Road[(i + 1) % 22][1], j);  //1表示右侧
			printf(" ");  //原来的道路符号清除掉
		}

	}

	rand_num = rand() % 8;  
	rand_num++;				
	switch (rand_num)
	{
	case 0:
		if (Road[(RoadIndex + 1) % 22][0] <= 4)
		{
			Road[NextIndex][0] = Road[(RoadIndex + 1) % 22][0];
			Road[NextIndex][1] = Road[(RoadIndex + 1) % 22][1];
			break;
		}
		Road[NextIndex][0] = Road[(RoadIndex + 1) % 22][0] - 2;
		Road[NextIndex][1] = Road[(RoadIndex + 1) % 22][1] - 2;
		break;
	case 1:
	case 2:
		if (Road[(RoadIndex + 1) % 22][0] <= 3)
		{
			Road[NextIndex][0] = Road[(RoadIndex + 1) % 22][0];
			Road[NextIndex][1] = Road[(RoadIndex + 1) % 22][1];
			break;
		}
		Road[NextIndex][0] = Road[(RoadIndex + 1) % 22][0] - 1;
		Road[NextIndex][1] = Road[(RoadIndex + 1) % 22][1] - 1;
		break;
	case 7:
	case 8:
		if (Road[(RoadIndex + 1) % 22][1] >= 55)
		{
			Road[NextIndex][0] = Road[(RoadIndex + 1) % 22][0];
			Road[NextIndex][1] = Road[(RoadIndex + 1) % 22][1];
			break;
		}
		Road[NextIndex][0] = Road[(RoadIndex + 1) % 22][0] + 1;
		Road[NextIndex][1] = Road[(RoadIndex + 1) % 22][1] + 1;
		break;
	case 9:
		if (Road[(RoadIndex + 1) % 22][1] >= 54)
		{
			Road[NextIndex][0] = Road[(RoadIndex + 1) % 22][0];
			Road[NextIndex][1] = Road[(RoadIndex + 1) % 22][1];
			break;
		}
		Road[NextIndex][0] = Road[(RoadIndex + 1) % 22][0] + 2;
		Road[NextIndex][1] = Road[(RoadIndex + 1) % 22][1] + 2;
		break;
	default:
		Road[NextIndex][0] = Road[(RoadIndex + 1) % 22][0];
		Road[NextIndex][1] = Road[(RoadIndex + 1) % 22][1];
		break;
	}
	RoadIndex = NextIndex;
	if (RoadIndex == 0)
		NextIndex = 21;
	else
		NextIndex = RoadIndex - 1;
	//重新绘制1-22行的道路数据
	for (j = 1, i = RoadIndex; j<23; i++, j++)
	{
		i = i % 22;
		Gotoxy(Road[i][0], j);
		printf("[");
		Gotoxy(Road[i][1], j);
		printf("]");
	}
	RoadIndex = NextIndex;
	return 0;
}




int StrikeCheck(struct AllPlayer *pd)	//检查汽车和道路是否发生碰撞，碰撞时将碰撞部分输出到屏幕
{
	int i;
	for (i = 18; i <= 19; i++)
	{
		if (Road[RoadIndex][0] >= pd->PlayerCarpos)	
		{
			ShowCar(1,pd);		//向右移动车一个距离
			pd->PlayerCarpos++;

			pd->PlayerSpeed -= 7 + (pd->PlayerSpeed / 50);	//减速
			if (pd->PlayerSpeed <0)
				pd->PlayerSpeed = 0;

			pd->PlayerEnergy -= 5;		//掉能量
			if (pd->PlayerEnergy <0)
				pd->PlayerEnergy = 0;

			pd->SpeedCounter = 0;
			Gotoxy(Road[RoadIndex][0], i);	   //碰撞位置打印***
			printf("***");
			break;
		}
		if (Road[RoadIndex][1] <= pd->PlayerCarpos + 7)		//碰到路的右侧  车的宽度是8
		{
			ShowCar(-1,pd);
			pd->PlayerCarpos--;
			pd->PlayerSpeed -= 7 + (pd->PlayerSpeed / 50);
			if (pd->PlayerSpeed <0)
				pd->PlayerSpeed = 0;

			pd->PlayerEnergy -= 5;
			if (pd->PlayerEnergy <0)
				pd->PlayerEnergy = 0;
			pd->SpeedCounter = 0;

			Gotoxy(Road[RoadIndex][1], i);
			printf("***");
			break;
		}
	}
	return 0;
}
