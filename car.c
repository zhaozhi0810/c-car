#include <stdio.h>
#include "display.h"
#include "road.h"
#include "player.h"
#include "car.h"
static char Carr[5][5][9] = { ".-TTTT-.",
                              "0-++++-0",
				   "  IIII  ",
				   "[]+--+[]",
				   "  A--A  ",

				   ".-TTTT-.",
				   "0-++++-0",
				   "  IIII  ",
				   "[]+--+[]",
				   "  B--B  ",

				   ".-TTTT-.",
				   "0-++++-0",
				   "  IIII  ",
				   "[]+--+[]",
				   "  C--C  ",

				   ".-TTTT-.",
				   "0-++++-0",
				   "  IIII  ",
				   "[]+--+[]",
				   "  D--D  ",

				   ".-TTTT-.",
				   "0-++++-0",
				   "  IIII  ",
				   "[]+--+[]",
				   "  E--E  ",};

int ShowCar(int move,struct AllPlayer *pd)
{
	pd->PlayerCarpos =pd->PlayerCarpos + move;
	//修改坐标，防止汽车偏离屏幕
	if (pd->PlayerCarpos <2)
		pd->PlayerCarpos = 2;
	if (pd->PlayerCarpos >48)
		pd->PlayerCarpos = 48;
	ShowCarxy(pd->PlayerCarnum, pd->PlayerCarpos, 18);
	return 0;
}
int Init()
{
	int i, j;
	ClcScreen();
	RoadIndex = 0;
	NextIndex = 0;

	sprintf(Cardata[0].Name, "Laser");
	Cardata[0].MaxSpd = 350;
	Cardata[0].energy = 70;
	Cardata[0].accel = 7;

	sprintf(Cardata[1].Name, "Fire");
	Cardata[1].MaxSpd = 320;
	Cardata[1].energy = 90;
	Cardata[1].accel = 8;

	sprintf(Cardata[2].Name, "Shot Gun");
	Cardata[2].MaxSpd = 290;
	Cardata[2].energy = 70;
	Cardata[2].accel = 9;

	sprintf(Cardata[3].Name, "Monster");
	Cardata[3].MaxSpd = 295;
	Cardata[3].energy = 40;
	Cardata[3].accel = 6;

	sprintf(Cardata[4].Name, "K-Machine");
	Cardata[4].MaxSpd = 320;
	Cardata[4].energy = 100;
	Cardata[4].accel = 10;

	//随机数种子
	srand((unsigned)time(NULL));

	return 0;

}
int ShowCarxy(int carnum, int x, int y)
{
	static int i;
	i = y;
	for (; i <= y + 4; i++)
	{
		Gotoxy(x - 1, i);
		printf(" %8s ", Carr[carnum][i - y]);
	}
	return 0;
}
