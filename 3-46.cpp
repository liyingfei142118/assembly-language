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
	NEXT://��ÿһ���ַ������Ӻ����ж�
		LEA EBX, str1
		CALL BTO
		INC EAX //��һ����ĸ
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
		CMP BYTE PTR[EBX],'\0'//�ж��Ƿ�ȫ���ж���
		JE OVER

		CMP BYTE PTR[EBX],DL//�Ƚ�
		JE LABE1//�����ȣ���ת
		INC EBX//Ԫ���ַ���++
		JMP NEXT1
	LABE1:
		INC ESI//count++
	OVER:
		RET
	


	}
}