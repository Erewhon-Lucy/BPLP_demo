#include<stdio.h>
#include<ncurses.h>
#include<signal.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

#define LEN sizeof(struct student)

struct student
{
    char name[50];  //用户名
    char code[21];   //密码
    char answer[5];   //密保答案
    char area[100]; //登录环境
    struct student *next;
};

void line()//分割线函数
{
    for (int i = 0; i < (COLS / 5) ; i++)
    {
        addstr(" ^_^ ");
    }
}