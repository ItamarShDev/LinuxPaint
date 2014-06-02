#include <stdio.h>
#include <curses.h>
#include "trp.h"



void drawTrp(WINDOW * win, int x, int y, int size1, int color, int full)
{
	if(full==0)
	{

		/*******************************************************************/
		/*-----------------------------METHOD------------------------------*/
		/************* create horizontal lines in y and y+size *************/
		/****** in line y - create from place  x+size/3 to x+size*2/3 ******/
		/*********** in line y+size/3 create line from x to x+size *********/
		/************* create vertical lines in x and x+size/3: ************/
		/* each time you do down, start on x earlier and finish on x after */
		/*******************************************************************/
		int size = (size1-1)/3;
		int i;
		color_set(color, NULL);

		for (i=x+size; i<=x+(2*size);i++)
		{
			mvwaddstr(win,y, i, "*" );

		}/*top*/
		for (i=x; i<=x+3*size-1;i++)
		{
			mvwaddstr(win,y+size, i, "*" );
		}/*bottom*/
		/*to print the top and bottom lines*/
		int j =y;
		for (i=x+size;i>=x;i--)
		{
			mvwaddstr(win,j++, i, "*" );
		}
		j =y;
		for(i=x+2*size; i<=x+3*size; i++)
		{
			mvwaddstr(win,j++, i, "*" );
		}/*to print the side lines*/

		refresh();
	}
	if(full==1)
	{
		int size = (size1-1)/3;
		int i,j, l=0,h=0;
		color_set(color, NULL);

		for(j=y+size; j>=y;--j)
		{
			for (i=x+l; i<=x+(3*size)-h;i++)
			{
				mvwaddstr(win,j, i, "*" );
			}
			++l;
			++h;
		}

		refresh();

	}

}
