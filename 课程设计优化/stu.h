#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StuInfo
{
	char name[10];   //姓名
	char sex[3];     //性别
	int num;        //学号
	int score;      //成绩
	char a[2];    //地址,a[0]表示学生省份的下标，a[1]表示地级市的下标
}StuInfo;


typedef struct Data
{
	StuInfo* data;  //指向数据块
	int size;       //当前有多少学生
	int capacity;   //容量 —— 最多可以存放多少学生
}Data;


//初始化
void init(Data* d);


//检查是否需要扩容
void is_full(Data* d);


//添加学生数据
void add(Data* d);


//按照姓名查找学生
int find_by_name(char name[], Data d);


//删除学生
void erase(Data* d);


//查找学生，并打印出来该学生的信息
void search(Data d);


//修改指定学生的信息
void modify(Data* d);


//根据姓名进行排序
int cmp(const void* a, const void* b);
void sort_by_name(Data* d);


//打印所有学生信息
void print(Data d);


//从文件中读取数据
void read_data(Data* d);


//保存数据
void store_data(Data d);


//释放空间
void free_data(Data* d);

//将编码转换为地址
void addr_to_code(char a[], Data* d);

//将地址转换为编码
void code_to_addr();