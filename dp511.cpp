//演示程序dp511.c
#include  <stdio.h>
int   cf58(int *pit);
int   cf59(int  **ppt, int i);
int   cf591(int  ppt[][5], int i);
void  cf510(int  matrix[][5], int  line[], int i);
int  main()
{
	int  data[3][5] = { { 1,  2,  3,  4,  5 },
	{ 11, 12, 13, 14, 15 },
	{ 101,102,103,104,105 } };
	int  *p[3] = { data[0], data[1], data[2] };
	int  row[5];
	int  i;
	printf("%d\n", cf58(data[0]));  //调用cf58
	printf("%d\n", cf59(p, 2));      //调用cf59
	printf("%d\n", cf591(data, 2));      //调用cf591
	cf510(data, row, 0);            //调用cf510
	for (i = 0; i<5; i++)
		printf("%-4d", row[i]);
	printf("\n");
	return  0;
}
//示例函数cf58
int  cf58(int  *pit)
{
	int  s = 0;
	s += *(pit++);              //累加第0个元素值，并指向下一个元素
	s += *(++pit);              //累加第2个元素值
	s += (*pit)++;              //累加第2个元素值，第2个元素值增加1
	s += ++(*pit);              //第2个元素值增加1，并累加之
	return  s;
}

//示例函数cf59
int  cf59(int  **ppt, int i)
{
	int s = 0;
	s += *(*ppt + i);           //ppt[0][i]
	s += *(*(ppt + i));         //ppt[i][0]
	return  s;
}
int  cf591(int ppt[][5], int i)
{
	int s = 0;
	s += *(*ppt + i);           //ppt[0][i]
	s += *(*(ppt + i));         //ppt[i][0]
	return  s;
}
//示例函数cf510
void cf510(int  matrix[][5], int  line[], int  i)
{
	int j;
	for (j = 0; j<5; j++)
		line[j] = matrix[i][j];
	return;
}
