#include<stdio.h>
#include<curses.h>
#include<signal.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
int main()
{
	// WINDOW * new;
    
	initscr();
 
	// move(10,50);
	addstr("Hello!");
	getch();
	clear();
 
	getch();
	// printf("你好");
	endwin();
}
