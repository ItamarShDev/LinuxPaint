#include <stdio.h>
#include <curses.h>
#include "tri.h"

/*
 * this method will create both filled and empty triangle.
 * the triangles to be shown will be either 90 degrees triangle
 * or 60 degrees on all angles
 *
 */
void drawTri(WINDOW * win,int x, int y, int size, int color, int full)
{
	if (full == 0)
	{
		int i=x;
		int j = y;
		color_set(color, NULL);//to bee colored as chosen
		/*
		 * METHOD:
		 * height and base are the same size.
		 * -1- go from up to down (using j++) and print * the the left
		 * and one on the right - which increases every step
		 *
		 * -2- print one line od * in the same length as the height
		 * 		at the y+height position
		 */
		for (i=x;i<x+size;i++)
		{
			mvwaddstr(win,j++, i, "*" );
			mvwaddstr(win,j, x, "*" );
		}/*to print the side lines*/

		for (i=x; i<=x+size;i++)
		{
			mvwaddstr(win,y+size, i, "*" );

		}/*to print the  bottom line*/

		refresh();
	}
	if (full ==1)
	{
		color_set(color, NULL);

		int i,j,k=x+size;

		/***********************************************************************/
		/*--------------------------- METHOD-----------------------------------*/
		/*              go from up to down and in each step:				   */
		/* 			   go from x to k, and paint * each time				   */
		/*             		decrease k after each step						   */
		/***********************************************************************/
		for (i=y+size; i>=y;--i)
		{
			for (j=x;j<=k;j++){
				mvwaddstr(win,i, j, "*" );

			}
			k--;
		}//using  mathematics calculations to create.
		refresh();
	}

}
void drawET(WINDOW * win,int x, int y, int size, int color,int full)
{
	if (full == 0)
	{
		int i= x;
		color_set(color, NULL);

		/***********************************************************************/
		/*--------------------------------METHOD-------------------------------*/
		/*              			paint the bottom line 					   */
		/* 	  go from up to down, each time paint * in the beginning and end   */
		/*             		start in +1 x and finish in -1 x				   */
		/***********************************************************************/
		for (i=x; i<x+size;i++)
		{
			mvwaddstr(win,y+size, i, "*" );
		}/*to print the bottom line*/
		int j =y+size/2;
		for (i=x+size/2;i>=x;i--)
		{
			mvwaddstr(win,j++, i, "*" );
		}
		j =y+size/2;
		for(i=x+size/2; i<=x+size; i++)
		{
			mvwaddstr(win,j++, i, "*" );
		}/*to print the side lines*/

		refresh();
	}
	if(full == 1)
	{

		int i= x;
		int l=0,h=0,j;
		color_set(color, NULL);
		for (j=y+size;j>=y;--j)
		{
			for (i=(x+l); i<=x+(size-h);i++)
			{
				mvwaddstr(win,j, i, "*" );
			}/*to print the bottom line*/
			l++;
			h++;
		}

	}

}

