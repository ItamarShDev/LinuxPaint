
#ifndef RECT_H

#define RECT_H
#include <stdio.h>
#include <curses.h>
typedef struct
{
	int color;
	int size;
	int x,y;/*coordinates*/

}rect;
void drawRect(WINDOW * win, int x, int y, int size, int color, int full);
#endif
