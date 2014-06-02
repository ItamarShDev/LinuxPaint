#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include "rect.h"
#include "shapes.h"
#include "tri.h"
#include "trp.h"
#include "dalton.h"
#include "crcl.h"

/*
 * first screen
 */
void initScreen(WINDOW * win,int sWidth,int sHeight)
{
	init_pair(30,  COLOR_WHITE,     COLOR_BLACK);
	init_pair(33,  COLOR_CYAN, COLOR_BLACK);


	color_set(33,NULL);
	mvwaddstr(win, 5,38,"Welcome!");
	color_set(33,NULL);
	mvwaddstr(win, 7,26," Look Here! This is Your Menu ");

	int i;
	color_set(30,NULL);
	for (i=9;i<sHeight-3;i++)
	{
		mvwaddstr(win, i,42,"|");

	}
	int j = 44,k= 40;
	for(i=sHeight-3;i<sHeight-1;i++)
	{
		mvwaddstr(win, i,k,"\\");
		mvwaddstr(win, i,j,"/");
		k++;
		j--;
	}
	mvwaddstr(win, sHeight-1,42,"V");

	refresh();


}
/*
 * creates the screen and menus
 */
void setScreen(WINDOW * win,int sWidth,int sHeight)
{
	init_pair(13,  COLOR_WHITE,     COLOR_BLACK);
	init_pair(14,  COLOR_WHITE,   COLOR_CYAN);
	init_pair(15,  COLOR_BLACK,  COLOR_BLUE);
	init_pair(16,  COLOR_YELLOW,    COLOR_MAGENTA);
	init_pair(17,  COLOR_CYAN, COLOR_BLACK);
	init_pair(18,  COLOR_CYAN,    COLOR_BLACK);
	init_pair(19,  COLOR_BLUE,    COLOR_WHITE);
	init_pair(20,  COLOR_WHITE,   COLOR_YELLOW	);
	init_pair(21,  COLOR_MAGENTA,   COLOR_YELLOW);
	init_pair(22, COLOR_BLUE, COLOR_YELLOW);
	init_pair(23, COLOR_RED,   COLOR_YELLOW);
	init_pair(24, COLOR_BLACK,   COLOR_YELLOW);

	int i;
	color_set(17,NULL);
	for (i=0;i<sWidth;i++)
	{
		mvwaddstr(win, 0,i,"-");
	}
	for(i=0;i<sHeight-6;i++)
	{
		mvwaddstr(win, i,0,">");
		mvwaddstr(win, i,sWidth-1,"<");
	}
	color_set(23,NULL);
	mvwaddstr(win, sHeight-5,26,"Press the Following Buttons:");
	color_set(22,NULL);
	mvwaddstr(win, sHeight-4,26," Move with the Arrows keys! ");


	color_set(24,NULL);
	for (i=0;i<sWidth;i++)
	{
		mvwaddstr(win, sHeight-6,i,"*");
		mvwaddstr(win, sHeight-1,i,"=");
	}
	for(i=sHeight-6;i<sHeight;i++)
	{
		mvwaddstr(win, i,0,"<");
		mvwaddstr(win, i,sWidth-1,">");
	}
	color_set(24,NULL);
	mvwaddstr(win, sHeight-3,26,"   F--Full Colored Shape    ");

	mvwaddstr(win, sHeight-5,1,"  C- Change Color        ");
	mvwaddstr(win, sHeight-4,1,"  S - Save    N - Clean   ");
	mvwaddstr(win, sHeight-3,1,"  P - Print              ");
	mvwaddstr(win, sHeight-2,1,"  Q- Quite Game          ");
	color_set(14,NULL);
	mvwaddstr(win, sHeight-5,sWidth-26,"          shapes:        ");
	color_set(15,NULL);
	mvwaddstr(win, sHeight-4,sWidth-26,"  1-Rectangle   4-Trapez ");
	color_set(16,NULL);
	mvwaddstr(win, sHeight-3,sWidth-26,"  2-Triangle1   5-Dalton ");
	color_set(17,NULL);
	mvwaddstr(win, sHeight-2,sWidth-26,"  3-Triangle2   6-Circle ");
	color_set(20,NULL);

	mvwaddstr(win, sHeight-2,26,"    --7--easter egg--       ");

	refresh();


}
//if the save is empty
void errorMsg(WINDOW * win, int h,int w)
{
	init_pair(40,  COLOR_RED,     COLOR_BLACK);
	init_pair(41,  COLOR_WHITE,     COLOR_BLACK);
	int i,j=w/2-6;

	for (i =h/2; i<=h/2+6;i++)
	{
		mvwaddstr(win,i,j,"*");
		mvwaddstr(win,i,j+12,"*");
	}
	for (i=w/2-6;i<=w/2+6;i++)
	{
		mvwaddstr(win,h/2,i,"*");
		mvwaddstr(win,h/2+6,i,"*");
	}
	mvwaddstr(win,11,24, "Press 'b' to Get Back to the Last Shape !");
	mvwaddstr(win,10,30,"You Don't Have Any Save Yet");
	setScreen(win,h,w);

}
