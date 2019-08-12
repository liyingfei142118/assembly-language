#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10000
int main()
{
	char buffer[max];


	int math = 0;
	printf("please input str:\n");
	scanf_s("%s", buffer, max);
	int len = strlen(buffer);
	_asm {
		LEA ESI, buffer
		MOV ECX, len
		CALL BTO
		MOV math, EAX


	}
	printf("buffer:\n%s \n", buffer);
	printf("math:\n%d \n", math);


	system("pause");
	return 0;
	_asm {
	BTO://利用例题3-58方法求其对应数值
			XOR EDX, EDX
			XOR EAX, EAX
			//MOV ECX,EDI
			JECXZ LABE2
		LABE1 :
			IMUL EDX, 16
			MOV AL, BYTE PTR[ESI]
			CMP  BYTE PTR[ESI],'9'
			JGE  LABE3
			JMP LABE4
		LABE3:
			SUB AL,7
			SUB AL,48
		LABE4:
			INC ESI
			AND AL, 0FH
			ADD EDX, EAX
			LOOP LABE1
		LABE2 :
			MOV EAX, EDX
			RET


	}
}