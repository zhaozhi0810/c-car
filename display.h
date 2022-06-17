#ifndef DISPLAY_H
#define DISPLAY_H

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

#include "player.h"

#define CONSOL_WIDTH	80
#define CONSOL_HEIGHT	24


int ShowGameFrame(struct AllPlayer *pd);
int ShowLogo();
int ShowGameover();
int ShowCount();

#endif
