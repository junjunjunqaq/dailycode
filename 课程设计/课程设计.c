#define _CRT_SECURE_NO_WARNINGS
/*����ʹ��GBK����*/
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
    char id[12];                      // ѧ��
    char name[NAME_MAX_LENGTH];       // ���������������
    char gender[3];                   // һ�����ֶ�ӦGBK����2���ֽ�
    int age;                          // ����
    char address[ADDRESS_MAX_LENGTH]; // ��ַ������15��
    int province;                     // ʡ��
    int city;                         // ����
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
        printf("�ɹ���ȡ%d����Ϣ��\n", num);
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
            fprintf(fp, "%sʡ", ProvinceString(stu[i].province));
        if (stu[i].city != 0)
            fprintf(fp, "%s��%s\n", CityString(stu[i].city), stu[i].address);
    }
    printf("�ɹ����浽output.txt�ļ���\n");
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
            printf("%sʡ", ProvinceString(stu[i].province));
        if (stu[i].city != 0)
            printf("%s��%s\n", CityString(stu[i].city), stu[i].address);
    }
    system("pause");
    getchar();
}

void SplitAddress(int begin, int n) // ����¼ӻ��޸ĵ���Ŀѹ����Ϣ
{
    for (int i = begin; i < begin + n; i++)
    {
        char tmp[10];
        char *p = stu[i].address;
        while (*p != '\0')
        {
            int j = 0;
            memset(tmp, 0, sizeof(tmp));
            while ((*p != -54 && *(p + 1) != -95) || (*p != -54 && *(p + 1) != -48)) // GBK�����£�ʡ: -54 -95; ��: -54 -48;
            {
                tmp[j] = *p;
                tmp[j + 1] = *(p + 1);
                if (*(p + 2) == '\0')
                    break;
                p += 2, j += 2;
            }
            if (*p == -54 && *(p + 1) == -95) // GBK�����£�ʡ: -54 -95
            {
                stu[i].province = ProvinceCode(tmp);
                p += 2; // ����"ʡ"�ַ�
                continue;
            }
            else if (*p == -54 && *(p + 1) == -48)
            {
                stu[i].city = CityCode(tmp);
                p += 2; // ����"��"�ַ�
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
    printf("==================��ѧ������ϵͳ================\n");
    if (num == 0)
        printf("\n  ��ȡ�ļ�Ϊ�ջ��ļ������󣬵�ǰ״̬��ֻ��������Ŀ��\n\n");
    else printf("\n                 ��ǰ����%d����Ϣ��\n\n", num);
    printf("                 ����'1' ������Ŀ\n");
    if (num != 0)
    {
        printf("                 ����'2' ɾ����Ŀ\n");
        printf("                 ����'3' ������Ŀ\n");
        printf("                 ����'4' �޸���Ŀ\n");
        printf("                 ����'5' �����ļ�\n");
        printf("                 ����'6' ��ӡ����Ļ\n");
    }
    printf("\n");
    printf("                 ����'0' �˳�������\n");
    printf("===================================================\n");
    printf("������˵����:");
}

int LookUp(int isLookUp)
{
    char id[12];
    if (isLookUp)
        printf("������Ҫ���ҵ�");
    printf("Ŀ��ѧ��: ");
    scanf("%s", id);
    for (int i = 0; i < num; i++)
    {
        if (strcmp(stu[i].id,id)==0)
        {
            printf("�ҵ��ˣ���\nѧ��:%s ����:%s �Ա�:%s ����:%d ��ַ:", stu[i].id, stu[i].name, stu[i].gender, stu[i].age);
            /*���ʡ�ݺͳ���*/
            if (stu[i].province != 0)
                printf("%sʡ", ProvinceString(stu[i].province));
            printf("%s��%s\n", CityString(stu[i].city), stu[i].address);
            system("pause");
            getchar();
            return i;
        }
    }
    printf("û���ҵ�Ŀ��ѧ�š�\n");
    system("pause");
    getchar();
    return -1;
}

void Add()
{
    printf("������Ҫ��ӵ���Ŀ����: ");
    int n;
    scanf("%d", &n);
    getchar();
    char ch;
    if (num == 0)
        ch = 'y';
    else
    {
        printf("��ϣ�������Ŀ��ĩβ��? (y/N) ");
        ch = getchar();
    }
    if (ch == 'y')
    {
        printf("����\"ѧ�� ���� �Ա� ���� ��ַ\"�ĸ�ʽ����ѧ����Ϣ: \n");
        for (int i = num; i < num + n; i++)
        {
            memset(&stu[i],0,sizeof(stu[i]));
            scanf("%s %s %s %d %s", stu[i].id, stu[i].name, stu[i].gender, &stu[i].age, stu[i].address);
        }
        num+=n;
        printf("�ɹ����%d����Ŀ��\n", n);
        SplitAddress(num-n, n);
    }
    else if (ch == 'N')
    {
        printf("������Ҫ����֮ǰ��ӵ�");
        int id = LookUp(0);
        if (id != -1)
        {
            for (int i = num + n - 1; i > id + n - 1; i--)
                stu[i] = stu[i - n];
            printf("����\"ѧ�� ���� �Ա� ���� ��ַ\"�ĸ�ʽ����ѧ����Ϣ: \n");
            for (int i = id; i < id + n; i++)
            {
                memset(&stu[i], 0, sizeof(stu[i]));
                scanf("%s %s %s %d %s", stu[i].id, stu[i].name, stu[i].gender, &stu[i].age, stu[i].address);
                num++;
            }
            printf("�ɹ����%d����Ŀ��\n", n);
            SplitAddress(id, n);
        }
    }
    system("pause");
    system("cls");
    getchar();
}

void Delete()
{
    printf("������Ҫɾ����");
    int id = LookUp(0);
    if (id != -1)
    {
        printf("��ȷ��Ҫɾ����? (y/N)");
        char ch;
        scanf("%c", &ch);
        if (ch == 'y')
        {
            memset(&stu[id], 0, sizeof(stu[id]));
            for (int i = id; i < num; i++)
                stu[i] = stu[i + 1];
            num--;
            printf("�ɹ�ɾ��Ŀ����Ŀ��\n");
            printf("��ǰ����%d����Ϣ��\n", num);
        }
    }
    system("pause");
    system("cls");
    getchar();
}

void Change()
{
    printf("������Ҫ�޸ĵ�");
    int id = LookUp(0);
    if (id != -1)
    {
        memset(&stu[id], 0, sizeof(stu[id]));
        printf("����\"ѧ�� ���� �Ա� ���� ��ַ\"�ĸ�ʽ����ѧ����Ϣ: \n");
        scanf("%s %s %s %d %s", stu[id].id, stu[id].name, stu[id].gender, &stu[id].age, stu[id].address);
        SplitAddress(id, 1);
        printf("�ɹ��޸�Ŀ����Ŀ��\n");
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
            printf("�ټ�!\n");
            system("pause");
            return 0;
        default:
            printf("\n��������������������롣\n");
            system("pause");
            getchar();
            break;
        }
    }
}
