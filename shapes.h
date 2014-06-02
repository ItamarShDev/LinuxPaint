#ifndef SHAPES_H

#define SHAPES_H
#include <stdio.h>
#include <curses.h>
#include "rect.h"
#include "tri.h"
#include "trp.h"
#include "dalton.h"
#include "screen.h"
typedef struct
{
	int x,y,size, shape,color,full;
}shapes;
typedef struct Node
{
	shapes s;
	struct Node *next;
}node;

void onScreen (WINDOW * win, int ch, int x, int y, int size, int color, int full);
void drawShape(WINDOW * win, int x, int y,int size, int ch, int color, int full);
shapes saveShape(int x, int y,int size, int shape, int color, int full);
void insert(node *pointer, shapes s);
int find(node *pointer, int shape);
void print(WINDOW *win,node *pointer, int rows,int cols);
void initScreen(WINDOW * win,int sWidth,int sHeight);
void Delete(node *pointer);
#endif


