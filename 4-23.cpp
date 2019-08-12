#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10000
int main()
{
	int count;
	char buffer[max];
	char buffer1[max];
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
			//调用16进制转化
			MOV ECX, ESI
			LEA EDX, buffer1

			CALL DST
	}
	printf("count:\n%d \n", count);
	printf("16 position buffer:\n%s \n", buffer1);
	system("pause");
	return 0;
	_asm
	{
	DST:
			PUSH ESI
			XOR ESI, ESI
			PUSH EDI
			MOV EDI, ECX
			INC ESI
		LABE1 :
			PUSH 8
			POP ECX
			SUB ECX, ESI
			SHL ECX, 2
			MOV EAX, EDI
			SHR EAX, CL
			AND AL, 15
			ADD AL, 48
			CMP AL, 57
			JLE LABE2
			ADD AL, 7
		LABE2:
			MOV BYTE PTR[EDX], AL
			INC EDX

			INC ESI
			CMP ESI, 8
			JLE LABE1

			POP EDI
			MOV BYTE PTR[EDX], 0
			POP ESI
			RET
	}
	return 0;
}