#include <stdio.h>
#include <curses.h>
#include "rect.h"


void drawRect(WINDOW * win,int x, int y, int size, int color, int full)
{
	if (full == 0){
		int i;
		color_set(color, NULL);
		/******************************************/
		/*----------------- METHOD----------------*/
		/* create horizontal lines in y and y+size*/
		/* create vertical lines in x and x+size+2*/
		/******************************************/
		for (i=x; i<x+size;++i)
		{
			mvwaddstr(win,y, i, "*" );
			mvwaddstr(win,y+size, i, "*" );
			refresh();
		}/*to print the top and bottom lines*/

		for (i=y;i<=y+size;++i)
		{
			mvwaddstr(win,i, x, "*" );
			mvwaddstr(win,i, x+size, "*" );
		}/*to print the side lines*/

		refresh();
	}
	if (full == 1){
		int i,j;
		color_set(color, NULL);
		for (i=y;i<=y+size;++i)
		{

			for (j=x; j<=x+size;++j)
			{
				mvwaddstr(win,i, j, "*" );

			}/*to print the top and bottom lines*/

		}

		refresh();
	}
}

/*to save to future use*/
