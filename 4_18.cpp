#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10000
int main()
{
	char str1[max], str2[max];
	printf("please input str1:\n");
	scanf_s("%s", str1,max);
	printf("please input str2:\n");
	scanf_s("%s", str2,max);
	int a = strlen(str1);
	int b = strlen(str2);

	_asm {
		LEA EDI,str1		
		MOV EAX,a
		ADD EDI,EAX//½«EDIÖ¸Ïò×Ö·û´®Ä©Î²

		LEA ESI,str2

		MOV ECX,b
		INC ECX
	NEXT:
		LODSB
		STOSB
		LOOP NEXT
	}
	printf("str1:%s \n", str1);
	printf("str2:%s \n", str2);
	system("pause");
	return 0;
}