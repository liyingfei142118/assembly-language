#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10000
int main()
{
	char buffer[max];
	char buffer1[10];
	printf("please input str:\n");
	scanf_s("%s", buffer,max);
	char str1[] = "AEIOUaeiou";
	int len = strlen(buffer);
	int count = 0;

	_asm {
		XOR ESI,ESI
		LEA EAX,buffer	
		MOV ECX,len//
	NEXT://对每一个字符调用子函数判断
		LEA EBX, str1
		CALL BTO
		INC EAX //下一个字母
		LOOP NEXT
		
		MOV count,ESI

			MOV EAX, ESI
			LEA ESI, buffer1
			MOV ECX, 10
			MOV EBX, 8
		NEXT3:
			XOR EDX, EDX
			DIV EBX
			ADD DL, '0'
			MOV[ESI + ECX - 1], DL
			LOOP NEXT3

			MOV BYTE PTR[ESI + 10], 0


	}
	printf("count:\n%d \n", count);
	printf("8 position buffer1:\n%s \n", buffer1);
	system("pause");
	return 0;
	_asm {
	BTO:
		MOV DL, BYTE PTR[EAX]
	NEXT1:
		CMP BYTE PTR[EBX],'\0'//判断是否全部判断完
		JE OVER

		CMP BYTE PTR[EBX],DL//比较
		JE LABE1//如果相等，跳转
		INC EBX//元音字符串++
		JMP NEXT1
	LABE1:
		INC ESI//count++
	OVER:
		RET
	


	}
}