#define _CRT_SECURE_NO_WARNINGS 1 
#include "stu.h"

//��ʼ��
void init(Data* d)
{
	d->data = (StuInfo*)malloc(sizeof(StuInfo) * 4);
	d->size = 0;
	d->capacity = 4;
}


//����Ƿ���Ҫ����
void is_full(Data* d)
{
	if (d->capacity == d->size)
	{
		StuInfo* tmp = (StuInfo*)realloc(d->data, sizeof(StuInfo) * (d->capacity + 4));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		d->data = tmp;
		d->capacity += 4;
	}
}


//���ѧ������
void add(Data* d)
{
	is_full(d);
	char province[20];
	char city[20];
	printf("����������ѧ����������");
	scanf("%s", d->data[d->size].name);
	printf("����������ѧ�����Ա�");
	scanf("%s", d->data[d->size].sex);
	printf("����������ѧ����ѧ�ţ�");
	scanf("%d", &d->data[d->size].num);
	printf("����������ѧ���ĳɼ���");
	scanf("%d", &d->data[d->size].score);
	printf("����������ѧ���ĵ�ַ(���ÿո�ָ�ʡ����)��");
	scanf("%s", province);
	scanf("%s", city);
	addr_to_code();
	printf("��ӳɹ�\n");

	d->size++;
}


//������������ѧ��
int find_by_name(char name[], Data d)
{
	for (int i = 0; i < d.size; i++)
		if (strcmp(name, d.data[i].name) == 0)
			return i;
	return -1;
}


//ɾ��ѧ��
void erase(Data* d)
{
	if (d->size == 0)
	{
		printf("û��ѧ��������ɾ��\n");
		return;
	}
	char name[20] = { 0 };
	printf("������Ҫɾ����ѧ����������");
	scanf("%s", name);
	int pos = find_by_name(name, *d);
	if (pos != -1)
	{
		for (int j = pos; j < d->size; j++)
			d->data[j] = d->data[j + 1];
		d->size--;
		printf("ɾ���ɹ�\n");
		return;
	}
	else
		printf("ѧ��%s������\n", name);
}


//����ѧ��������ӡ������ѧ������Ϣ
void search(Data d)
{
	char name[20] = { 0 };
	printf("������Ҫ���ҵ�ѧ����������");
	scanf("%s", name);
	int pos = find_by_name(name, d);
	if (pos != -1)
	{
		printf("%-10s\t%-4s\t%-9s\t%-4s\t%-20s\n", "����", "�Ա�", "ѧ��", "�ɼ�", "��ַ");
		printf("%-10s\t%-4s\t%-9d\t%-4d\t%-20s\n",
			d.data[pos].name, d.data[pos].sex, d.data[pos].num, d.data[pos].score, d.data[pos].addr);
		return;
	}
	else
		printf("ѧ��%s������\n", name);
}


//�޸�ָ��ѧ������Ϣ
void modify(Data* d)
{
	char name[20] = { 0 };
	printf("������Ҫ���ҵ�ѧ����������");
	scanf("%s", name);
	int pos = find_by_name(name, *d);
	if (pos != -1)
	{
		printf("%sѧ����ǰ��Ϣ���£�\n", name);
		printf("%-10s\t%-4s\t%-9s\t%-4s\t%-20s\n", "����", "�Ա�", "ѧ��", "�ɼ�", "��ַ");
		printf("%-10s\t%-4s\t%-9d\t%-4d\t%-20s\n",
			d->data[pos].name, d->data[pos].sex, d->data[pos].num, d->data[pos].score, d->data[pos].addr);
		printf("�������޸ĺ��������");
		scanf("%s", d->data[pos].name);
		printf("�������޸ĺ���Ա�");
		scanf("%s", d->data[pos].sex);
		printf("�������޸ĺ��ѧ�ţ�");
		scanf("%d", &d->data[pos].num);
		printf("�������޸ĺ�ĳɼ���");
		scanf("%d", &d->data[pos].score);
		printf("�������޸ĺ�ĵ�ַ��");
		scanf("%s", d->data[pos].addr);
		printf("�޸ĳɹ�\n");
		return;
	}
	else
		printf("ѧ��%s������\n", name);
}


//����������������
int cmp(const void* a, const void* b)
{
	return strcmp(((StuInfo*)a)->name, ((StuInfo*)b)->name);
}
void sort_by_name(Data* d)
{
	qsort(d->data, d->size, sizeof(StuInfo), cmp);
}


//��ӡ����ѧ����Ϣ
void print(Data d)
{
	printf("%-10s\t%-4s\t%-9s\t%-4s\t%-20s\n", "����", "�Ա�", "ѧ��", "�ɼ�", "��ַ");
	for (int i = 0; i < d.size; i++)
	{
		code_to_addr;
		printf("%-10s\t%-4s\t%-9d\t%-4d\t%-20s\n",
			d.data[i].name, d.data[i].sex, d.data[i].num, d.data[i].score, d.data[i].addr);
	}
}


//���ļ��ж�ȡ����
void read_data(Data* d)
{
	FILE* fp = fopen("data.dat", "rb");
	if (fp == NULL)
	{
		perror("fopen");
		return;
	}
	StuInfo tmp;
	while (fread(&tmp, sizeof(StuInfo), 1, fp))
	{
		is_full(d);
		d->data[d->size] = tmp;
		d->size++;
	}
	printf("���ݶ�ȡ���\n");
}


//��������
void store_data(Data d)
{
	FILE* pf = fopen("data.dat", "wb");
	if (pf == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	for (int i = 0; i < d.size; i++)
		fwrite(&d.data[i], sizeof(StuInfo), 1, pf);
	printf("���ݱ���ɹ�\n");
}


//�ͷſռ�
void free_data(Data* d)
{
	free(d->data);
	d->size = 0;
	d->capacity = 0;
}

void code_to_addr(char a[], Data* d)
{
	switch(a[0])
	{
	case 1:
		d->data[]
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	case 11:
		break;
	case 12:
		break;
	case 13:
		break;
	case 14:
		break;
	case 15:
		break;
	case 16:
		break;
	case 17:
		break;
	case 18:
		break;
	case 19:
		break;
	case 20:
		break;
	case 21:
		break;
	case 22:
		break;
	case 23:
		break;
	case 24:
		break;
	case 25:
		break;
	case 26:
		break;
	case 27:
		break;
	case 28:
		break;
	case 29:
		break;
	case 30:
		break;
	case 31:
		break;
	case 32:
		break;
	case 33:
		break;
	case 34:
		break;
	default:
		printf("��ַ������Ч\n");
		break;
	}
}