#ifndef CRCL_H

#define CRCL_H
#include <stdio.h>
#include <ncurses.h>


typedef struct

{

int x,y, color,size;
}crcl;

void drawCrcl(WINDOW * win, int x, int y, int size, int color);
void saveCrcl(int x, int y, int size, int color);
#endif
