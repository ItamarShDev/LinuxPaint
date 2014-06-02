#ifndef DALTON_H

#define DALTON_H
#include <stdio.h>
#include <curses.h>


typedef struct 
{

int x,y, color,size;
}dlt;

void drawDlt(WINDOW * win, int x, int y, int size, int color,int full);
void drawHazrd(WINDOW * win, int x, int y, int size, int color);
#endif
