#define _CRT_SECURE_NO_WARNINGS
/*中文使用GBK编码*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_MAX_LENGTH 10
#define ADDRESS_MAX_LENGTH 100
#define MAX_N 1001


void SplitAddress();
int ProvinceCode(char *);
int CityCode(char *);
char *ProvinceString(int id);
char *CityString(int id);

struct Student
{
    char id[12];                      // 学号
    char name[NAME_MAX_LENGTH];       // 姓名，上限五个字
    char gender[3];                   // 一个汉字对应GBK编码2个字节
    int age;                          // 年龄
    char address[ADDRESS_MAX_LENGTH]; // 地址，上限15字
    int province;                     // 省份
    int city;                         // 城市
} stu[MAX_N];
int num = 0;

typedef struct Addr
{
    int id;
    char name[10];
} addr;

typedef struct ProvinceNode
{
    addr province;
    struct ProvinceNode *next;
} province;
province *pHead;

typedef struct CityNode
{
    addr city;
    struct CityNode *next;
} city;
city *cHead;

void NodeInitialization()
{
    pHead = (province *)malloc(sizeof(province));
    pHead->province.id = 0;
    pHead->next = NULL;
    cHead = (city *)malloc(sizeof(city));
    cHead->city.id = 0;
    cHead->next = NULL;
}

void ReadFile()
{
    num = 0;
    FILE* fp = fopen("output.txt", "r+");
    if (fp == NULL)
    {
        perror("fopen");
        return;
    }
    while (fscanf(fp, "%s %s %s %d %s", 
        stu[num].id, stu[num].name, stu[num].gender, &stu[num].age, stu[num].address) != EOF)
    {
        SplitAddress(num, 1);
        num++;
    }
    if (num != 0)
    {
        printf("成功读取%d条信息。\n", num);
        system("pause");
    }
    fclose(fp);
}

void SaveFile()
{
    FILE *fp = fopen("output.txt", "w+");
    for (int i = 0; i < num; i++)
    {
        fprintf(fp, "%s %s %s %d ", stu[i].id, stu[i].name, stu[i].gender, stu[i].age);
        if (stu[i].province != 0)
            fprintf(fp, "%s省", ProvinceString(stu[i].province));
        if (stu[i].city != 0)
            fprintf(fp, "%s市%s\n", CityString(stu[i].city), stu[i].address);
    }
    printf("成功保存到output.txt文件。\n");
    fclose(fp);
    system("pause");
    system("cls");
    getchar();
}

void PrintFile()
{
    system("cls");
    for (int i = 0; i < num; i++)
    {
        printf("%s %s %s %d ", stu[i].id, stu[i].name, stu[i].gender, stu[i].age);
        if (stu[i].province != 0)
            printf("%s省", ProvinceString(stu[i].province));
        if (stu[i].city != 0)
            printf("%s市%s\n", CityString(stu[i].city), stu[i].address);
    }
    system("pause");
    getchar();
}

void SplitAddress(int begin, int n) // 针对新加或修改的条目压缩信息
{
    for (int i = begin; i < begin + n; i++)
    {
        char tmp[10];
        char *p = stu[i].address;
        while (*p != '\0')
        {
            int j = 0;
            memset(tmp, 0, sizeof(tmp));
            while ((*p != -54 && *(p + 1) != -95) || (*p != -54 && *(p + 1) != -48)) // GBK编码下，省: -54 -95; 市: -54 -48;
            {
                tmp[j] = *p;
                tmp[j + 1] = *(p + 1);
                if (*(p + 2) == '\0')
                    break;
                p += 2, j += 2;
            }
            if (*p == -54 && *(p + 1) == -95) // GBK编码下，省: -54 -95
            {
                stu[i].province = ProvinceCode(tmp);
                p += 2; // 跳过"省"字符
                continue;
            }
            else if (*p == -54 && *(p + 1) == -48)
            {
                stu[i].city = CityCode(tmp);
                p += 2; // 跳过"市"字符
                strcpy(stu[i].address, p);
                break;
            }
        }
    }
}

int ProvinceCode(char *tmp)
{
    province *p = pHead;
    while (strcmp(p->province.name, tmp) != 0 && p->next != NULL)
    {
        p = p->next;
    }
    if (strcmp(p->province.name, tmp) == 0)
        return p->province.id;
    else if (p->next == NULL)
    {
        int id = p->province.id;
        p->next = (province *)malloc(sizeof(province));
        p = p->next;
        p->province.id = id + 1;
        strcpy(p->province.name, tmp);
        p->next = NULL;
        return p->province.id;
    }
}

int CityCode(char *tmp)
{
    city *p = cHead;
    while (strcmp(p->city.name, tmp) != 0 && p->next != NULL)
    {
        p = p->next;
    }
    if (strcmp(p->city.name, tmp) == 0)
        return p->city.id;
    else if (p->next == NULL)
    {
        int id = p->city.id;
        p->next = (city *)malloc(sizeof(city));
        p = p->next;
        p->city.id = id + 1;
        strcpy(p->city.name, tmp);
        p->next = NULL;
        return p->city.id;
    }
}

char *ProvinceString(int id)
{
    province *p = pHead;
    while (p->province.id != id)
        p = p->next;
    return p->province.name;
}

char *CityString(int id)
{
    city *p = cHead;
    while (p->city.id != id)
        p = p->next;
    return p->city.name;
}

void PrintMenu()
{
    printf("==================简单学生管理系统================\n");
    if (num == 0)
        printf("\n  读取文件为空或文件名有误，当前状态下只可增加条目。\n\n");
    else printf("\n                 当前共有%d条信息。\n\n", num);
    printf("                 输入'1' 增加条目\n");
    if (num != 0)
    {
        printf("                 输入'2' 删除条目\n");
        printf("                 输入'3' 查找条目\n");
        printf("                 输入'4' 修改条目\n");
        printf("                 输入'5' 保存文件\n");
        printf("                 输入'6' 打印到屏幕\n");
    }
    printf("\n");
    printf("                 输入'0' 退出本程序\n");
    printf("===================================================\n");
    printf("请输入菜单编号:");
}

int LookUp(int isLookUp)
{
    char id[12];
    if (isLookUp)
        printf("请输入要查找的");
    printf("目标学号: ");
    scanf("%s", id);
    for (int i = 0; i < num; i++)
    {
        if (strcmp(stu[i].id,id)==0)
        {
            printf("找到了，是\n学号:%s 姓名:%s 性别:%s 年龄:%d 地址:", stu[i].id, stu[i].name, stu[i].gender, stu[i].age);
            /*输出省份和城市*/
            if (stu[i].province != 0)
                printf("%s省", ProvinceString(stu[i].province));
            printf("%s市%s\n", CityString(stu[i].city), stu[i].address);
            system("pause");
            getchar();
            return i;
        }
    }
    printf("没有找到目标学号。\n");
    system("pause");
    getchar();
    return -1;
}

void Add()
{
    printf("请输入要添加的条目数量: ");
    int n;
    scanf("%d", &n);
    getchar();
    char ch;
    if (num == 0)
        ch = 'y';
    else
    {
        printf("您希望添加条目到末尾吗? (y/N) ");
        ch = getchar();
    }
    if (ch == 'y')
    {
        printf("请以\"学号 姓名 性别 年龄 地址\"的格式输入学生信息: \n");
        for (int i = num; i < num + n; i++)
        {
            memset(&stu[i],0,sizeof(stu[i]));
            scanf("%s %s %s %d %s", stu[i].id, stu[i].name, stu[i].gender, &stu[i].age, stu[i].address);
        }
        num+=n;
        printf("成功添加%d条条目。\n", n);
        SplitAddress(num-n, n);
    }
    else if (ch == 'N')
    {
        printf("请输入要在其之前添加的");
        int id = LookUp(0);
        if (id != -1)
        {
            for (int i = num + n - 1; i > id + n - 1; i--)
                stu[i] = stu[i - n];
            printf("请以\"学号 姓名 性别 年龄 地址\"的格式输入学生信息: \n");
            for (int i = id; i < id + n; i++)
            {
                memset(&stu[i], 0, sizeof(stu[i]));
                scanf("%s %s %s %d %s", stu[i].id, stu[i].name, stu[i].gender, &stu[i].age, stu[i].address);
                num++;
            }
            printf("成功添加%d条条目。\n", n);
            SplitAddress(id, n);
        }
    }
    system("pause");
    system("cls");
    getchar();
}

void Delete()
{
    printf("请输入要删除的");
    int id = LookUp(0);
    if (id != -1)
    {
        printf("您确认要删除吗? (y/N)");
        char ch;
        scanf("%c", &ch);
        if (ch == 'y')
        {
            memset(&stu[id], 0, sizeof(stu[id]));
            for (int i = id; i < num; i++)
                stu[i] = stu[i + 1];
            num--;
            printf("成功删除目标条目。\n");
            printf("当前共有%d条信息。\n", num);
        }
    }
    system("pause");
    system("cls");
    getchar();
}

void Change()
{
    printf("请输入要修改的");
    int id = LookUp(0);
    if (id != -1)
    {
        memset(&stu[id], 0, sizeof(stu[id]));
        printf("请以\"学号 姓名 性别 年龄 地址\"的格式输入学生信息: \n");
        scanf("%s %s %s %d %s", stu[id].id, stu[id].name, stu[id].gender, &stu[id].age, stu[id].address);
        SplitAddress(id, 1);
        printf("成功修改目标条目。\n");
    }
    system("pause");
    system("cls");
    getchar();
}

int main()
{
    NodeInitialization();
    ReadFile();
    while (1)
    {
        system("cls");
        PrintMenu();
        char ch;
        ch = getchar();
        switch (ch)
        {
        case '1':
            Add();
            break;
        case '2':
            if (num != 0)
                Delete();
            break;
        case '3':
            if (num != 0)
                LookUp(1);
            break;
        case '4':
            if (num != 0)
                Change();
            break;
        case '5':
            if (num != 0)
                SaveFile();
            break;
        case '6':
            if (num != 0)
                PrintFile();
            break;
        case '0':
            system("cls");
            printf("再见!\n");
            system("pause");
            return 0;
        default:
            printf("\n输入参数有误，请重新输入。\n");
            system("pause");
            getchar();
            break;
        }
    }
}
