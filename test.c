#include<stdio.h>
#include<curses.h>
#include<signal.h>
 
int main()
{
	// WINDOW * new;
    
	initscr();
 
	move(LINES/2,COLS/2);
	addstr("Hello!");
 
 
	getch();
 
	endwin();
}
