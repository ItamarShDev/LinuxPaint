#ifndef TRI_H

#define TRI_H
#include <stdio.h>
#include <curses.h>


typedef struct 
{

int x,y, color,size;
}tri;

void drawTri(WINDOW * win, int x, int y, int size, int color,int full);
void drawET(WINDOW * win,int x, int y, int size, int color, int full);
#endif
