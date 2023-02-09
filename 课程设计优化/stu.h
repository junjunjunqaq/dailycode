#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StuInfo
{
	char name[10];   //����
	char sex[3];     //�Ա�
	int num;        //ѧ��
	int score;      //�ɼ�
	char a[2];    //��ַ,a[0]��ʾѧ��ʡ�ݵ��±꣬a[1]��ʾ�ؼ��е��±�
}StuInfo;


typedef struct Data
{
	StuInfo* data;  //ָ�����ݿ�
	int size;       //��ǰ�ж���ѧ��
	int capacity;   //���� ���� �����Դ�Ŷ���ѧ��
}Data;


//��ʼ��
void init(Data* d);


//����Ƿ���Ҫ����
void is_full(Data* d);


//���ѧ������
void add(Data* d);


//������������ѧ��
int find_by_name(char name[], Data d);


//ɾ��ѧ��
void erase(Data* d);


//����ѧ��������ӡ������ѧ������Ϣ
void search(Data d);


//�޸�ָ��ѧ������Ϣ
void modify(Data* d);


//����������������
int cmp(const void* a, const void* b);
void sort_by_name(Data* d);


//��ӡ����ѧ����Ϣ
void print(Data d);


//���ļ��ж�ȡ����
void read_data(Data* d);


//��������
void store_data(Data d);


//�ͷſռ�
void free_data(Data* d);

//������ת��Ϊ��ַ
void addr_to_code(char a[], Data* d);

//����ַת��Ϊ����
void code_to_addr();