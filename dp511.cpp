//��ʾ����dp511.c
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
	printf("%d\n", cf58(data[0]));  //����cf58
	printf("%d\n", cf59(p, 2));      //����cf59
	printf("%d\n", cf591(data, 2));      //����cf591
	cf510(data, row, 0);            //����cf510
	for (i = 0; i<5; i++)
		printf("%-4d", row[i]);
	printf("\n");
	return  0;
}
//ʾ������cf58
int  cf58(int  *pit)
{
	int  s = 0;
	s += *(pit++);              //�ۼӵ�0��Ԫ��ֵ����ָ����һ��Ԫ��
	s += *(++pit);              //�ۼӵ�2��Ԫ��ֵ
	s += (*pit)++;              //�ۼӵ�2��Ԫ��ֵ����2��Ԫ��ֵ����1
	s += ++(*pit);              //��2��Ԫ��ֵ����1�����ۼ�֮
	return  s;
}

//ʾ������cf59
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
//ʾ������cf510
void cf510(int  matrix[][5], int  line[], int  i)
{
	int j;
	for (j = 0; j<5; j++)
		line[j] = matrix[i][j];
	return;
}
