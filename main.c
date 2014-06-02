#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "rect.h"
#include "tri.h"
#include "shapes.h"
#include "dalton.h"
#include "screen.h"

//defines
#define EMPTY 0;
#define RECT 1;
#define TRIANGEL_1 2;
#define TRIANGLE_2 3
#define TRAPEZ 4;
#define DALTON 5
#define CIRCLE 6;
#define BIOHAZARD 7;
int main()
{
	// needed variables
	WINDOW * win;
	node *start,*temp;// to linked list
	start = (node *)malloc(sizeof(node));
	temp = start;
	temp -> next = NULL;// to create list for future
	shapes sShape;
	int size=4;//first size
	int shape;//to determine the shape
	int ch = getch();//the listener
	int rows  = 24, cols   = 80;//screen size
	int full = 0;//full shape or empty?
	int x = (cols - size)  / 2;// first place to draw
	int y = (rows - (size+2)) / 2;// first place to draw
	//screen size and menu size
	int sWidth = (cols-1), sHeight = (rows-7);// shapes screen
	int color = 1;//initial color

	//initialize the screen
	if ( (win = initscr()) == NULL ) {
		fprintf(stderr, "Error initializing ncurses.\n");
		exit(EXIT_FAILURE);
	}
	start_color();
	curs_set(0);
	noecho();
	keypad(win,TRUE);


	//start

	//opening screen
	initScreen(win,sWidth,sHeight);
	setScreen(win,cols,rows);
	// listening to the user's choice via keyboard
	while ( ((ch = getch()) != 'q'))
	{
		clear();
		switch ( ch )
		{
		case KEY_UP:

			if(shape==3)//triangle
			{
				if ( y-size/2> 0 )
					--y;
			}
				else if ( y > 1 )
					--y;

			break;

		case KEY_DOWN:
			if(shape==4)//case its Trp
			{
				if ( y< (sHeight-(size-1)/3) )
					++y;
			}

			else
				if(shape==5)// case its a Dalton
				{
					if ( y < (sHeight-size)+1 )
						++y;
				}
				else if ( y < (sHeight-size) )
					++y;
			break;

		case KEY_LEFT:
			if(shape == 5)//case its Dalton
			{
				if ( (x-2*size)>1)
				{
					--x;
				}
			}
			if(shape == 6)//case its a circle
			{
				if ( x-size-1>1)
				{
					--x;
				}			}
			else if ( x > 1 )
				--x;
			break;

		case KEY_RIGHT:
			if(shape==4)//case its Trp
			{
				if ( x< (sWidth-3*size)-3)
					++x;
			}
			if(shape==5)//case its Dalton
			{
				if ( x<=sWidth-(3*(size/2)))
					++x;
			}
			if(shape==6)//case its Circle
			{
				if ( x< (sWidth-(size/2)-1))
					++x;
			}
			else
				if ( x < (sWidth-size)-1)
					++x;
			break;

		case KEY_HOME:
			x = 0;
			y = 0;
			break;

		case KEY_END:
			x = (sWidth-size);
			y = (sHeight-size);
			break;
		case 'c':
			color ++;
			if (full == 1)
			{
				if (color>=12)
					color = 1;
			}
			if(full==0)
			{
				if (color >=7)
					color = 1;
			}
			break;

		case '1':
			size = 4;
			shape = RECT;
			break;
		case '2':
			size = 4;
			shape = TRIANGEL_1;
			break;
		case '3':
			size = 4;
			shape = TRIANGLE_2;
			break;
		case '4':
			size = 4;
			shape = TRAPEZ;
			break;
		case '5':
			size = 4;
			shape =DALTON;
			break;
		case '6':
			size = 4;
			shape = CIRCLE;
			break;
		case '7':
			shape = BIOHAZARD;
			size = 4;
			break;
		case '+':
			if (shape == 4)//case its a Trp  which built differently
			{
				if((x+size)<sWidth&&(y+(size-1)/3)<sHeight)
				{
					size+=3;
				}
			}
			if(shape == 6)// case its a Circle
			{
				if((sWidth-(size/2)-1)<sWidth&&(y+(size-1))<sHeight)
				{
					size+=3;
				}
			}
			else
				if((x+size)<sWidth&&(y+size)<sHeight)
				{
					size+=2;
				}
			break;
		case '-':
			if (shape == 4 || shape == 6)//case its a Trp or Circle which built differently
			{
				if(size>6)
					size-=3;
			}
			else
				if(size>3)
					size-=2;
			break;
		case 's':
			sShape=	saveShape(x,y,size,shape,color,full);
			insert(start, sShape);
			break;
		case 'a':

			do{
				print(win ,start->next, rows, cols);
			}
			while((ch = getch()) != 'b');
			clear();
			break;
		case 'n':
			shape = EMPTY;
			Delete(start);
			start = (node *)malloc(sizeof(node));
			break;

		case 'f':
			if(full == 0)
				full =1;
			else
				full = 0;
			break;

		}
		onScreen(win,shape,x,y,size,color, full);// print the shape
		refresh();
	}

	bool canBeDrawnUp(int x,int y, int size, int shape)
	{
		if(shape==3)//triangle
		{
			if ( y-size/2> 0 )
			return TRUE;
		}
			else if ( y > 1 )
				return TRUE;

	}
	bool canBeDrawnDown(int x,int y, int size, int shape)
	{

	}
	bool canBeDrawnRight(int x,int y, int size, int shape)
	{

	}
	bool canBeDrawnLeft(int x,int y, int size, int shape)
	{

	}
	/*cleanup..*/
	delwin(win);
	endwin();
	refresh();
	return EXIT_SUCCESS;
}
