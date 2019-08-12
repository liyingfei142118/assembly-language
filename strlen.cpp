#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10000
int main()
{
	int count;
	char buffer[max];
	printf("please input str:\n");
	scanf_s("%s", buffer, max);
	_asm {
		LEA EAX, buffer
		XOR ESI, ESI
		NEXT :
			CMP BYTE PTR[EAX], '\0'//一个一个字母的判断
			JE LABE0
			INC ESI//计数
			INC EAX//下一个字母地址
			JMP NEXT
		LABE0 :
			MOV count, ESI

	}
	printf("count:\n%d \n", count);

	system("pause");
	return 0;
	return 0;
}