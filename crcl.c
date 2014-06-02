#include <stdio.h>
#include <ncurses.h>
#include "crcl.h"
/*
 * this method will paint the Circle
 */


void drawCrcl(WINDOW * win, int x, int y, int size, int color)
{
	/*
	 * method known as Berchiem's Circle
	 * converted to ncurses library
	 */

  int radius = size/2;
  int error = 1 - radius;
  int errorY = 1;
  int errorX = -2 * radius;
  int r = radius, i = 0;
	color_set(color, NULL);

mvwaddstr(win,y+radius, x, "*" );
mvwaddstr(win,y-radius, x, "*" );
mvwaddstr(win,y, x+radius, "*" );
mvwaddstr(win,y, x-radius, "*" );


  while(r > i)
  {
    if(error >= 0) // >= 0 produces a slimmer circle. =0 produces the circle picture at radius 11 above
    {
      r--;
      errorX += 2;
      error += errorX;
    }
    i++;
    errorY += 2;
    error += errorY;
mvwaddstr(win,y+i, (x+r), "*" );
mvwaddstr(win,y+i, (x-r), "*" );
mvwaddstr(win,y-i, (x+r), "*" );
mvwaddstr(win,y-i, (x-r), "*" );
mvwaddstr(win,y+r, (x+i), "*" );
mvwaddstr(win,y+r, (x-i), "*" );
mvwaddstr(win,y-r, (x+i), "*" );
mvwaddstr(win,y-r, (x-i), "*" );

  }
	refresh();

}
