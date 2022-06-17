#ifndef PLAYER_H
#define PLAYER_H


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

struct AllPlayer{
	char PlayerName[20];
	float PlayerScore;
	int PlayerEnergy; 
	double PlayerSpeed;
	int PlayerCarnum;
	float PlayerAccel;
	int PlayerCarpos; 
	int SpeedCounter;  	
	}Playerdata; 

	
int kbhit();
int getche();
int ShowStat(struct AllPlayer *pd);
int InputPlayerData(struct AllPlayer *pd);
void Gotoxy(int x, int y);
void ClcScreen();
void PlayerInit(struct AllPlayer *pd);  //chushihua
int VideoRefresh();


#endif
