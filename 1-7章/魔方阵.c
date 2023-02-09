#include<stdio.h>
 int main()
  {
 int a[100][100] = { 0 };
 int N;
 int col,row=0;
 int prerow = 0, precol = 0;
 int i, j;
 while (1) {
  printf("请输入魔方阵的阶数，在3-100之间的奇数：");
  scanf("%d", &N);
  if (0 != N && (N >= 3 && N < 100))
   break;
 }
 col = N / 2;
 a[row][col] = 1;
 
 for (i = 2; i <= N * N; i++)
 {
  row--;
  col++;
  if (row < 0)
   row = N - 1;
  if (col >= N)
   col = 0;
  if (a[row][col] != 0)
  {
   row = prerow + 1;
   col = precol;
  }
  a[row][col] = i;
  prerow = row;
  precol = col;
 }
 
 for (i = 0; i < N; i++)
 {
  for (j = 0; j < N; j++)
   printf("%4d", a[i][j]);
  printf("\n");
 }
 return 0;
}
