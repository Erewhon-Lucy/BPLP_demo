#include<stdio.h>
#include<ncurses.h>
#include<signal.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
//编译命令:gcc face.c -lncursesw
void line()
{
    for (int i = 0; i < (COLS / 5) ; i++)
    {
        addstr(" ^_^ ");
    }
}

int main()
{
	setlocale(LC_ALL,"");//同步终端和窗口的编码格式
    initscr();
	line();
    move(2,COLS / 2 - 2);
    addstr("你好");
    move(3,COLS / 2 -11);
    addstr("我是一个没有感情的密码本\n");
    line();
    move(5,COLS / 2 -4);
    addstr("请操♂作我\n\n");
    addstr("1.记下一个密码\n");
    addstr("2.看看我的密码本\n");
    addstr("3.按账户名找到一个密码\n");
    addstr("4.按序号查找一个密码\n");
    addstr("5.离开没有感情的密码本\n\n");
    line();
    move(15,COLS /2 -5);
    addstr("开始操♂作吧！\n");
    addstr("你的操作：");
    echo();//启动屏幕响应
	char ch;
    while(ch=getch()!='\n')//留住除了回车所有响应内容
    {
        
    }
	endwin();//关闭窗口
}
