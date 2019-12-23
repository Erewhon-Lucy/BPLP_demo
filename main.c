#include"head.h"

void face();
void print(struct student *head);
struct student *append(struct student *head); 
struct student *del(struct student *head);    
void searchByName(struct student *head);            
void searchByArea(struct student *head);

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
void print(struct student *head)
{
    struct student *p;
    p = head;
    clear();
    if (head != NULL)
        do
        {
            printw("你的账户名字:%s",p->name);//你的账户名字
            printw("这个账户的密码:%s\n", p->code);//这个账户的密码
            printw("密保问题:%s\n", p->answer);//密保问题
            printw("账户是用来登录这个的:%s\n", p->area);//账户是用来登录这个的
            line();
            p = p->next;
        } while (p != NULL);
    else
    {
        addstr("你傻了你的密码没保存在这\n\n");//你脑子抽了你的密码没保存在这
        line();
    }
}
void searchByName(struct student *head)
{
    char name[50];
    struct student *p1, *p2;
    p1 = head;
    p2 = p1;
    clear();
    addstr("你要回忆的密码 它的账户叫啥");
    line();
    scanw("%s",&name);
    while (p1 != NULL)
    {
        if (strcmp(p1->name, name) == 0)
        {
            printw("它的密码是:%s",p1->code);//它的密码是
            printf("密保问题是:%s",p1->name);//密保问题是
            printf("它用来登录这个:%s",p1->area);//它用来登录这个
            break;
        }
        p2 = p1;
        p1 = p1->next;
    }

    if (p1 == NULL)

        printf("醒醒你还没登记过这个账户 !!\n");//醒醒你还没登记过这个账户                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
}

int main()
{
    struct student *head = NULL;
    int input;
    setlocale(LC_ALL,"");
    face();
    input=getch();
    switch (input)
    {
    case 1:
        head = append(head);
        break;
    case 2:
        print(head);
        break;
    case 3:
        head = del(head);
        break;
    case 4:
        searchByName(head);
        break;
    case 5:
        searchByArea(head);
        break;
    default:
        // printf("Enter error!!\n");
    }
    getch();
    endwin();
    return 0;
}