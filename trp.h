#ifndef TRP_H

#define TRP_H
#include <stdio.h>
#include <curses.h>


typedef struct 
{

int x,y, color,size;
}trp;

void drawTrp(WINDOW * win, int x, int y, int size, int color, int full);
#endif
