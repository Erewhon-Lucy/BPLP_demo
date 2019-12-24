#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define LEN sizeof(struct student)

struct student
{
    char number[20];  //用户序号
    char name[100];   //用户姓名
    char danwei[100]; //用户单位
    char phone[20];   //电话号码
    char home[100];   //家庭地址
    struct student *next;
};

void face(void); /*主菜单函数*/
void print(struct student *head);
struct student *append(struct student *head); //增添电子通讯录中的内容，即创建连表过程
struct student *del(struct student *head);    //电子通讯录的维护（删除），通过输入联系人姓名删除联系人数据
void search(struct student *head);            //电子通讯录的查找，关键字为用户姓名；
void searchByNumber(struct student *head);    //电子通讯录的查找，关键字为用户序号；

void main()
{
    // FILE *fp1,*fp2;
    int c; //功能选择需要的号码
    system("cls");
    //system("color 2f");
    system("cls");
    struct student *head = NULL;

    face();
    printf("选择你需要操作的功能号码:"); //改成addstr
    scanf("%d", &c);
    getchar(); //getch()
    switch (c)
    {
    case 0:
        head = append(head);
        break;
    case 1:
        print(head);
        break;
    case 4:
        head = del(head);
        break;
    case 2:
        search(head);
        break;
    case 3:
        searchByNumber(head);
        break;
    case 5:
        exit(0);
        break; //endwin()
    default:
        // printf("Enter error!!\n");
    }
    // printf("*****************\n");
    // printf("◇◆请按ENTER返回功能操作菜单◇◆\n");
    // printf("*****************\n");
    // getchar();
    system("CLS");//clear()
}

void face(void) /*主菜单函数*///懒逼lsz写了这个了 
{
    printf("***************************MENU*****************************************");
    printf("\t\t\t\t☆★☆★☆★ ~_~ ~_~ ~_~ ☆★☆★☆★\n");
    printf("\n\t\t\t☆★☆★");
    printf("\n\n\t☆★选择你需要操作的功能:☆★(现无记录，建议先填加记录)★☆\n");
    printf("\n");
    printf("\t\t\t0.【输入通讯录信息〗\n");
    printf("\t\t\t1.〖显示通讯录中所有记录】\n");
    printf("\t\t\t4.【删除记录〗\n");
    printf("\t\t\t2.〖按姓名查找显示记录】\n");
    printf("\t\t\t3.【按序号查找显示记录〗\n");
    printf("\t\t\t5〖退出!!】\n");
    printf("\n");
    printf("\t☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★");
    printf("\n\n********************************************************************\n\n");
}

void print(struct student *head)
{
    struct student *p;
    p = head;
    system("CLS"); //clear()
    // printf("*************************************************************\n");
    // printf("==================== → 用 户 信 息 记 录 表 ←===================\n");
    // printf("*************************************************************\n");
    if (head != NULL)
        do
        {
            printf("用户序号:%s\n", p->number);//你的账户名字
            printf("联系人姓名:%s\n", p->name);//这个账户的密码
            printf("用户单位:%s\n", p->danwei);//你把它们存在这里的日期
            printf("联系人电话号码:%s\n", p->phone);//账户是用来登录这个的
            printf("学生地址:%s\n", p->home);//垃圾密码本不需要这么多结构成员
            // printf("********************************************************\n");
            p = p->next;
        } while (p != NULL);
    else
    {
        printf("对不起!!没有任何联系人记录!!\n\n");//你脑子抽了你的密码没保存在这
        // printf("=============================================================\n");
    }
}

//增添电子通讯录中的内容，即创建连表过程
struct student *append(struct student *head)
{
    struct student *p0 = NULL, *p1, *p2; //p0 为要插入的新节点
    p1 = head;
    p2 = head;
    system("CLS");//clear()
    // printf("\n\n***********************************************************\n");
    printf("\t\t 你能在此目录下创建并添加联系人信息");//你能在这里保存你愚蠢脑瓜记不住的密码
    // printf("\n***********************************************************\n");
    p0 = (struct student *)malloc(LEN);
    printf("请输入用户序号:");//你的账户
    gets(p0->number);
    printf("请输入联系人姓名:");//你的密码
    gets(p0->name);
    printf("请输入联系人单位");//保存的日期 hint: 后期升级功能 自动从系统获取时间
    gets(p0->danwei);
    printf("请输入联系人电话号码:");//顺便记一下这是个干嘛的账户免得你的憨憨脑子忘记
    gets(p0->phone);
    printf("请输入联系人地址:");//多余了
    gets(p0->home);
    //对插入的节点排序，按姓名的拼音顺序
    if (head == NULL)
    {
        head = p0;
        p0->next = NULL;
    }
    else
    {
        while ((strcmp(p0->name, p1->name) > 0) && (p1->next != NULL))
        {
            p2 = p1;
            p1 = p1->next;
        }
        if ((strcmp(p0->name, p1->name)) <= 0)
        {
            if (head == p1)
                head = p0;

            else
                p2->next = p0;
            p0->next = p1;
        }
        else
        {
            p1->next = p0;
            p0->next = NULL;
        }
    }
    printf("恭喜你!!成功添加了联系人信息!!");//恭喜你 可以从脑子里忘记你的密码了
    // printf("\n************************************************************\n");
    // printf("\n\n");
    return (head);
}

//电子通讯录的维护（删除），通过输入联系人姓名删除联系人数据
struct student *del(struct student *head)
{
    struct student *p1, *p2;
    char name[100];
    system("CLS");//clear()
    // printf("\n\n************************************************************\n");
    // printf("================= → 用 户 信 息 记 录 删 除 功 能 ←===============\n");
    // printf("************************************************************\n");
    printf("输入要删除的联系人姓名:");//你哪个号没了？
    gets(name);
    p1 = head;
    if (head == NULL)
    {
        printf("很抱歉!!没有任何联系人纪录!!\n");//你还没临幸过这个莫得感情的密码本
        // printf("\n*******************************************************\n");
        return (head);
    }
    while (p1 != NULL)
    {
        if (strcmp(p1->name, name) == 0)
        {
            if (p1 == head)
                head = p1->next;
            else
                p2->next = p1->next;
            free(p1);
            printf("删除记录成功!!\n");//你号没了
            return (head);
        }
        p2 = p1;
        p1 = p1->next;
    }
    printf("对不起!!没有要删除的联系人纪录!!\n");//你记错了你根本就没来登记过它
    return (head);
}

//电子通讯录的查找，关键字为用户姓名；
void search(struct student *head)
{
    struct student *p1, *p2;
    char name[20];
    p1 = head;
    p2 = p1;
    system("CLS");//clear()
    // printf("\n**************************************************************\n");
    // printf("================ → 用 户 信 息 记 录 查 询 功 能 ←==================\n");
    // printf("**************************************************************\n");
    printf("输入要查找联系人的姓名:");//你要回忆的密码 它的账户叫啥
    gets(name);
    while (p1 != NULL)
    {
        if (strcmp(p1->name, name) == 0)
        {
            printf("联系人序号:");//它的密码是
            puts(p1->number);
            printf("联系人姓名:");//你在这天保存了它
            puts(p1->name);
            printf("联系人电话号码:");//它用来登录这个
            puts(p1->phone);
            printf("联系人地址:");//多余的成员请滚蛋
            puts(p1->home);
            //printf("联系人出生日期:");
            // puts(p1->birthday);
            // printf("\n=============================================================\n");
            break;
        }
        p2 = p1;
        p1 = p1->next;
    }

    if (p1 == NULL)

        printf("对不起!!没有该联系人的纪录!!\n");//醒醒你还没登记过这个账户
}

//电子通讯录的查找，关键字为用户序
void searchByNumber(struct student *head)
{
    struct student *p1, *p2;
    char number[20];
    p1 = head;
    p2 = p1;
    system("CLS");//clear()
    // printf("\n**************************************************************\n");
    // printf("================ → 用 户 信 息 记 录 查 询 功 能 ←==================\n");
    // printf("**************************************************************\n");
    printf("输入要查找联系人序号:");//你想回忆的密码 是用来登录什么网站的
    gets(number);
    while (p1 != NULL)
    {
        if (strcmp(p1->number, number) == 0)
        {
            printf("联系人序号:");//你的账户是
            puts(p1->number);
            printf("联系人姓名:"); //密码是
            puts(p1->name);
            printf("联系人电话号码:");//在这天保存了它
            puts(p1->phone);
            printf("联系人地址:");
            puts(p1->home);
            printf("\n=============================================================\n");
            break;
        }
        p2 = p1;
        p1 = p1->next;
    }
    if (p1 == NULL)
        printf("对不起!!没有该联系人的纪录!!\n");//请先去这个里%s注册一个账户再来登记吧
}
/*hint 结构成员修改的想法
    账户
    密码
    保存日期
    登录环境

    对应的两种查询方式
    通过账户查询
    通过登录环境查询
*/
