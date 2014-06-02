#ifndef SCREEN_H

#define SCREEN_H
#include <stdio.h>
#include <curses.h>
#include "rect.h"
#include "tri.h"
#include "trp.h"
#include "dalton.h"


void setScreen(WINDOW * win,int sWidth,int sHeight);
void initScreen(WINDOW * win,int sWidth,int sHeight);
void errorMsg(WINDOW * win, int h,int w);

#endif
