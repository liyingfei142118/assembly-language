//Ê¾Àıº¯Êıcf520
#include<stdio.h>

unsigned  int  cf520(unsigned  char  n)
{
	unsigned  int  x, y, sum;
	x = n * 8;
	y = n / 8;
	sum = x + y;
	return  sum;
}
unsigned  int  cf5201(int  n)
{
	unsigned  int  x, y, sum;
	x = n * 8;
	y = n / 8;
	sum = x + y;
	return  sum;
}
int main()
{
	unsigned  char  n = '0';
	int a = 1;
	cf520(n);
	cf5201(a);
	return 0;
}