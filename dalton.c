#include <stdio.h>
#include <ncurses.h>
#include "dalton.h"



void drawDlt(WINDOW * win, int x, int y, int size, int color, int full)
{
	if(full==0)
	{
		/************************************************/
		/*-------------------METHOD---------------------*/
		/* create two triangles, one mirror of the other*/
		/************************************************/
		/*to print the top and bottom lines*/
		int j =x;
		int k =x;
		int i;
		color_set(color, NULL);

		for(i=y; i<=y+(size/2); i++)
		{
			mvwaddstr(win,i+(size/2), j-(size/2), "*" );
			mvwaddstr(win,i, j++, "*" );
			mvwaddstr(win,i+(size/2), k+(size/2), "*" );
			mvwaddstr(win,i, k--, "*" );
		}/*to print the top side lines*/

		refresh();
	}

	if(full==1)
	{
		int j =0;
		int i, l=0,h=0;
		color_set(color, NULL);

		for(i=y+(size/2); i>=y; i--)
		{
			for(j=x+l;j<x+size-h;j++){
				mvwaddstr(win,i, j+1-4, "*" );
			}
			l++;
			h++;
		}
		h=0;
		l=0;
		for(i=y+(size/2); i<=y+size; i++)
		{
			for(j= x+l;j<x+size-h;j++)
			{
				mvwaddstr(win,i, j+1-4, "*" );
			}
			l++;
			h++;
		}
		refresh();
	}
}
void drawHazrd(WINDOW * win, int x, int y, int size, int color)
{

	int j =0;
	int i, l=0,h=0;
	color_set(color, NULL);

	for(i=y; i<=y+(size); i++)
	{
		for(j=x+size/2+1+l;j<x+3*(size/2)-h;j++){
			mvwaddstr(win,i, j+1-4, "*" );
		}
		l++;
		h++;
	}
	h=0;
	l=0;
	for(i=y+(size/2); i<=y+size; i++)
	{
		for(j= x+l;j<=x+size-h;j++)
		{
			mvwaddstr(win,i, j+1-4, "*" );
			mvwaddstr(win,i, j+size+1-4, "*" );
		}
		l++;
		h++;
	}
	refresh();
}
