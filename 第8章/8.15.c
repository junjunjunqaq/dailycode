#include<stdio.h>
int main()
{
	int a[4][5];
	int *p=a;
	int i,j;
	for(i=0;i<4;i++)
		{
			for(j=0;j<5;j++)
			{
				printf("�������%dλѧ���ĵ�%d�ſεĳɼ�",i+i,j+i);
				scanf("%d",&a[i][j]);
			}
		}

	void aver(int *p);
	aver(p);
	void fail(int *p);
	fail(p); 
	void search(int *p);
	return 0;
}

	void aver(int *p)
	{
		int sum=0,aver=0;
		int i;
		for(i=0;i<4;i++)
			sum+= *(p+i);
		aver=sum/4;
		printf("��һ�ſε�ƽ������%d",aver);
	}
	
	void fail(int *p)
	{
		int fail=0;
		int i,j;
		for(i=0;i<4;i++)
		{
			for(j=0;j<5;j++)
			{
				if ( *(*(p+i)+j) <60 )
				{
					fail++;
				}
				if(fail>2)  
				{
					printf("�������������Ͽγ̲�����,ѧ����%d,",i+1);
					printf("����ȫ���γ̳ɼ�Ϊ%d %d %d %d %d\n",*(*(p+i)+0),*(*(p+i)+1),
					*(*(p+i)+2),*(*(p+i)+3),*(*(p+i)+4));
					int average;
					average=1/5*(*(*(p+i)+0)+*(*(p+i)+1)+
					*(*(p+i)+2)+*(*(p+i)+3)+*(*(p+i)+4));
					printf("ƽ������%d",average);
					)
					break;
				}
			}
		}
		
	}
	
	void search(int *p)
	{
		int i,j;
		int score=0;
		int aver=0;
		for(i=0;i<4;i++)
		{
			for(j=0;j<5;j++)
			{
				if(*(*(p+i))+j>85)
				{
					score++;
				}
				if(score=5)
					printf("��%dλѧ��ȫ���γ̳ɼ���85������\n",i+1); 
			}		
		}
		for(i=0;i<4;i++)
		{
			aver=1/5*(*(*(p+i)+0)+*(*(p+i)+1)+
					*(*(p+i)+2)+*(*(p+i)+3)+*(*(p+i)+4));
			if(aver>90)
				printf("��%dλѧ��ƽ���ɼ���90������\n",i+1); 
		}
	}	
	
