#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10000
int main()
{
	char buffer[max];
	char buffer1[max];
	
	int math=0;
	printf("please input str:\n");
	scanf_s("%s", buffer, max);
	int len = strlen(buffer);
	_asm {
		LEA ESI,buffer
		MOV ECX,len
		CALL BTO
		MOV math,EAX

		MOV ECX, EAX
		LEA EDX, buffer1
		CALL DST
	}
	printf("math:\n%d \n", math);
	printf("buffer:\n%s \n", buffer);
	printf("16 position buffer:\n%s \n", buffer1);
	system("pause");
	return 0;
	_asm {
	BTO://利用例题3-58方法求其对应数值
		XOR EDX,EDX
		XOR EAX,EAX
		//MOV ECX,EDI
		JECXZ LABE2
	LABE1:
		IMUL EDX,10
		MOV AL,BYTE PTR[ESI]
		INC ESI
		AND AL,0FH
		ADD EDX,EAX
		LOOP LABE1
	LABE2:
		MOV EAX,EDX
		RET
	DST :
			PUSH ESI
			XOR ESI, ESI
			PUSH EDI
			MOV EDI, ECX
			INC ESI
	LABE3 ://利用题44方法
			PUSH 8
			POP ECX
			SUB ECX, ESI
			SHL ECX, 2
			MOV EAX, EDI
			SHR EAX, CL
			AND AL, 15
			ADD AL, 48
			CMP AL, 57
			JLE LABE4
			ADD AL, 7
	LABE4:
			MOV BYTE PTR[EDX], AL
			INC EDX

			INC ESI
			CMP ESI, 8
			JLE LABE3

			POP EDI
			MOV BYTE PTR[EDX], 0
			POP ESI
			RET
	}
}