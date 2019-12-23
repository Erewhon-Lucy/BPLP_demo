

void face()
{
    initscr();//初始化屏幕
	line();
    move(2,COLS / 2 - 2);//移动光标
    addstr("你好");//输出字符串
    move(3,COLS / 2 -11);
    addstr("我是一个没有感情的密码本\n");
    line();
    move(5,COLS / 2 -4);
    addstr("请操♂作我\n\n");
    addstr("1.记下一个密码\n");
    addstr("2.看看我的密码本\n");
    addstr("3.按账户名找到一个密码\n");
    addstr("4.按登录环境查找一个密码\n");
    addstr("5.离开没有感情的密码本\n\n");
    line();
    move(15,COLS /2 -5);
    addstr("开始操♂作吧！\n");
    addstr("你的操作：");
    echo();//启动屏幕响应
	// char ch;
    // while(ch=getch()!='\n')//留住除了回车所有响应内容
    // {
        
    // }
	// endwin();//关闭窗口
    /*警告！ 此函数在调试时为main函数
    调用时应更改名称
    为测试效果 此函数包含读取字符串部分
    请组合至main函数*/
}
