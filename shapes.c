#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include "rect.h"
#include "shapes.h"
#include "tri.h"
#include "trp.h"
#include "dalton.h"
#include "crcl.h"
#include "screen.h"


////defines
//#define EMPTY 0;;
//#define RECT 1;
//#define TRIANGEL_1 2;
//#define TRIANGLE_2 3
//#define TRAPEZ 4;
//#define DALTON 5
//#define CIRCLE 6;
//#define BIOHAZARD 7;

shapes s;

//call the right shape
void drawShape(WINDOW * win,int x, int y,int size, int ch, int color, int full)
{

	if(ch==0)
	{
		clear();
		refresh();
	}
	if(ch==1)
	{
		drawRect(win, x,y, size,color, full);
	}
	if(ch==2)
	{
		drawTri(win, x,y, size,color,full);
	}
	if(ch == 3)
	{
		drawET(win, x,y, size,color,full);
	}
	if(ch == 4)
	{
		drawTrp(win,x,y,size,color,full);
	}
	if(ch == 5)
	{
		drawDlt(win,x+size/2,y,size,color,full);
	}
	if(ch == 6)
	{
		drawCrcl(win,x,y+(size/2),size,color);
	}
	if(ch==7)
	{
		drawHazrd(win,x,y,size,color);
	}

	refresh();
}
//creates the colors and calls the painting method
void onScreen (WINDOW * win, int ch, int x, int y, int size , int color , int full)
{
	if ( has_colors() && COLOR_PAIRS >= 12 ) {

		init_pair(1,  COLOR_RED,     COLOR_BLACK);
		init_pair(2,  COLOR_GREEN,   COLOR_BLACK);
		init_pair(3,  COLOR_YELLOW,  COLOR_BLACK);
		init_pair(4,  COLOR_BLUE,    COLOR_BLACK);
		init_pair(5,  COLOR_MAGENTA, COLOR_BLACK);
		init_pair(6,  COLOR_CYAN,    COLOR_BLACK);
		init_pair(7,  COLOR_WHITE,    COLOR_BLACK);
		init_pair(8,  COLOR_WHITE,   COLOR_RED);
		init_pair(9,  COLOR_BLACK,   COLOR_GREEN);
		init_pair(10, COLOR_BLUE,    COLOR_YELLOW);
		init_pair(11, COLOR_WHITE,   COLOR_BLUE);
		init_pair(12, COLOR_WHITE,   COLOR_MAGENTA);


	}

	int rows  = 24, cols   = 80;
	drawShape(win,x,y,size,ch,color, full);
	setScreen(win,cols,rows);
	refresh();
}
//saves the shape into a Shape
shapes saveShape(int x, int y,int size, int shape, int color,int full)
{
	s.x = x;
	s.y = y;
	s.size = size;
	s.shape = shape;
	s.color = color;
	s.full = full;
	return s;
}
// add the shape to linked list
void insert(node *pointer, shapes s1)
{
	/* Iterate through the list till we encounter the last node.*/
	while(pointer->next!=NULL)
	{
		pointer = pointer -> next;
	}
	/* Allocate memory for the new node and put data in it.*/
	pointer->next = (node *)malloc(sizeof(node));
	pointer = pointer->next;
	pointer->s = s1;
	pointer->next = NULL;
}
//to be used in future exercise
int find(node *pointer, int shape)
{
	pointer =  pointer -> next; //First node is dummy node.
	/* Iterate through the entire linked list and search for the key. */
	while(pointer!=NULL)
	{
		if(pointer->s.shape == shape) //key is found.
		{
			return 1;
		}
		pointer = pointer -> next;//Search in the next node.

	}
	/*Key is not found */
	return 0;
}
//deletes all saves
void Delete(node *pointer)
{
	if (pointer==NULL){
		return;
	}
	node* temp = pointer;
	pointer = pointer->next;
	free(temp);
	Delete(pointer);
}
//prints the linked list
void print(WINDOW * win,node *pointer, int rows, int cols)
{
	if(pointer==NULL)
	{
		mvwaddstr(win,0,0, "Press 'b' to Get Back to the Last Shape !");
		return;
	}

	drawShape(win,pointer->s.x,pointer->s.y,pointer->s.size,pointer->s.shape,pointer->s.color,pointer->s.full);
	setScreen(win,cols,rows);
	refresh();

	print(win,pointer->next, rows,cols);
}
