#include <stdio.h> 
#include <math.h> 

   
int main() 
{
	void aver_stu(int t[][5]);     
    void aver_course(int t[][5]); 
    void high(int t[][5]);       
    void vari(int t[][5]); 
	int stu[10][5];
	int i, j;
	printf("�����������10��ѧ���ĳɼ���\n");
	for (i = 0; i < 10; i++)
		for (j = 0; j < 5; j++)
			scanf_s("%d", &stu[i][j]);  
	aver_stu(stu);  
	aver_course(stu); 
	high(stu);  
	vari(stu);  
	return 0;
}
 
  void aver_stu(int t[][5])
  {
	int i, j;
	float k, ave;
	for (i = 0; i < 10; i++) {
		k = 0.0;
		for (j = 0; j < 5; j++)
			k += t[i][j];
		ave = k / 5;
		printf("��%d��ѧ����ƽ������ %f\n", i + 1, ave);
	}
} 
 
void aver_course(int t[][5]) {
	int i, j;
	float k, ave;

	for (j = 0; j < 5; j++) {
		for (i = 0, k = 0.0; i < 10; i++)
			k += t[i][j];
		ave = k / 10;
		printf("��%d�ſε�ƽ������%f\n", j + 1, ave);
	}
}

void high(int t[][5]) {
	int i, j, h = 0, stu, cour;
	for (i = 0, stu = 0, cour = 0; i < 10; i++) {
		for (j = 0; j < 5; j++) {
			if (t[i][j] > h) {
				h = t[i][j];
				stu = i + 1;
				cour = j + 1;
			}
		}
	}
	printf("��߷���%d, �ǵ�%d��ѧ���ĵ�%d�ſ�\n", h, stu, cour);
}


void vari(int t[][5]) {
	int i, j, k, m;
	float temp[10], var, x1, x2;
	for (i = 0, m = 0; i < 10; i++, m++) {
		for (j = 0, k = 0; j < 5; j++)
			k += t[i][j];
		temp[m] = k / 5;
	}
	for (i = m = x1 = x2 = 0; i < 10; i++) {
		x1 += pow(temp[i], 2);

		x2 += temp[i];
	}
	var = x1 / 10 - pow(x2 / 10, 2);
	printf("ƽ���ַ���Ϊ %f\n", var);
}


  
