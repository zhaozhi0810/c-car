
#ifndef __CAR_H__
#define __CAR_H__


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


#include "player.h"


int ShowCar(int move,struct AllPlayer *pd);
struct CAR{
	char Name[16];
	int MaxSpd;
	int energy;
	int accel;
};
struct CAR Cardata[5];		
int Init();
int ShowCarxy(int carnum, int x, int y);



#endif


