#include"head.h"
void print(struct student *head)
{
    struct student *p;
    p = head;
    clear();
    if (head != NULL)
        do
        {
            addstr("你的账户名字:%s\n", p->name);//你的账户名字
            addstr("这个账户的密码:%s\n", p->code);//这个账户的密码
            addstr("密保问题:%s\n", p->answer);//密保问题
            addstr("账户是用来登录这个的:%s\n", p->area);//账户是用来登录这个的
            line();
            p = p->next;
        } while (p != NULL);
    else
    {
        printf("你脑子抽了你的密码没保存在这\n\n");//你脑子抽了你的密码没保存在这
        line();
    }
}