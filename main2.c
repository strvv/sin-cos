#include <curses.h>
#define SteP 40
int abs(int x)
{
    if(x<0)return(-x);
    return(x);
}

int main(void)
{
 unsigned char oldpos,pos,max,curr,pos2;
 int x,y,oldx,oldy,key,i,lx,ly,c2,l2,dx,dy,l,oldc2,oldl2;
 unsigned char SinValue[256]={
	 128,131,134,137,140,143,146,149,152,155,158,162,165,167,170,173,\
	 176,179,182,185,188,190,193,196,198,201,203,206,208,211,213,215,\
	 218,220,222,224,226,228,230,232,234,235,237,238,240,241,243,244,\
	 245,246,248,249,250,250,251,252,253,253,254,254,254,255,255,255,\
	 255,255,255,255,254,254,254,253,253,252,251,250,250,249,248,246,\
	 245,244,243,241,240,238,237,235,234,232,230,228,226,224,222,220,\
	 218,215,213,211,208,206,203,201,198,196,193,190,188,185,182,179,\
	 176,173,170,167,165,162,158,155,152,149,146,143,140,137,134,131,\
	 128,124,121,118,115,112,109,106,103,100,97,93,90,88,85,82,\
	 79,76,73,70,67,65,62,59,57,54,52,49,47,44,42,40,\
	 37,35,33,31,29,27,25,23,21,20,18,17,15,14,12,11,\
	 10,9,7,6,5,5,4,3,2,2,1,1,1,0,0,0,\
	 0,0,0,0,1,1,1,2,2,3,4,5,5,6,7,9,\
	 10,11,12,14,15,17,18,20,21,23,25,27,29,31,33,35,\
	 37,40,42,44,47,49,52,54,57,59,62,65,67,70,73,76,\
	 79,82,85,88,90,93,97,100,103,106,109,112,115,118,121,124};
 max=255;
 pos=0;
 initscr();
 clear();
 keypad (stdscr, TRUE);
 oldx=COLS>>1;
 oldy=LINES>>1;
 oldc2=COLS>>1;
 oldl2=LINES>>1;
 do
  {
   pos2=pos+64;
   x=(COLS*SinValue[pos2])>>8;
   y=(LINES*SinValue[pos])>>8;
   c2=COLS>>1;
   l2=LINES>>1;

//clear old lines
   if((x!=oldx)||(y!=oldy))
   {
	   dx=(oldx-oldc2);
	   lx=abs(dx);
	   dy=(oldy-oldl2);
	   ly=abs(dy);
	   if(lx>ly)l=lx;
	   else l=ly;
	   for(i=l;i;i--)
	   {
	    move(oldl2+dy*i/l,oldc2+dx*i/l);
	    addch('.');
	   }
	   oldx=x;
	   oldy=y;
	   oldc2=c2;
	   oldl2=l2;
   }
   
//calculate and write newlines
   dx=(x-c2);
   lx=abs(dx);
   dy=(y-l2);
   ly=abs(dy);
   if(lx>ly)
    l=lx;
   else
    l=ly;
   for(i=l;i;i--)
   {
    move(l2+dy*i/l,c2+dx*i/l);
    addch('x');
   }

   key=getch();
   switch(key)
   {
	   case KEY_DOWN:
		   if(pos>SteP)
			   pos-=(SteP-1);
	   case KEY_LEFT:
		   if(pos>0)pos--;
		   break;
	   case KEY_UP:
		   if(pos<max-SteP)
			   pos+=(SteP-1);
	   case KEY_RIGHT:
		   if(pos<max)
			   pos++;
   }
   mvprintw(LINES-1,COLS-20,"%-u/%-u/%-u/%-d      ",pos,SinValue[pos],SinValue[pos2],key);
  }
 while(key!=27);//27 as Escape!
 endwin();
}
