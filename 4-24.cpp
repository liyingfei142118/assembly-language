
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10000
int main()
{
	char buffer[max];
	char buffer1[max];
	char buffer2[max];
	char buffer3[max];
	int math = 0;
	int math1 = 0;
	int math2, math3;
	printf("please input str:\n");
	scanf_s("%s", buffer, max);
	printf("please input str:\n");
	scanf_s("%s", buffer1, max);
	int len = strlen(buffer);
	int len1 = strlen(buffer1);
	_asm {
		//16������������Ӧ��ֵ1
		LEA ESI, buffer
		MOV ECX, len
		CALL BTO
		MOV math, EAX
		//16��������1����Ӧ��ֵ1
		LEA ESI, buffer1
		MOV ECX, len1
		CALL BTO
		MOV math1, EAX
		//��
		MOV EAX, math
		MOV EBX, math1
		ADD EAX, EBX
		MOV math2, EAX
		//�Ͷ�Ӧ 16��������
		MOV ECX, math2
		LEA EDX, buffer2

		CALL DST
		//��
		MOV EAX, math
		MOV EBX, math1
		SUB EAX, EBX
		MOV math3, EAX
		//���Ӧ 16��������1
		MOV ECX, math3
		LEA EDX, buffer3
		CALL DST
	}
	printf("16��������:\n%s \n", buffer);
	printf("16��������1:\n%s \n", buffer1);
	printf("��Ӧ��ֵ:\n%d \n", math);
	printf("��Ӧ��ֵ1:\n%d \n", math1);
	printf("��:\n%d \n", math2);
	printf("��:\n%d \n", math3);
	printf("�Ͷ�Ӧ 16��������:\n%s \n", buffer2);
	printf("���Ӧ 16��������1:\n%s \n", buffer3);
	system("pause");
	return 0;
	_asm {
	BTO://��������3-58���������Ӧ��ֵ
			XOR EDX, EDX
			XOR EAX, EAX
			//MOV ECX,EDI
			JECXZ LABE2
		LABE1 :
			IMUL EDX, 16
			MOV AL, BYTE PTR[ESI]
			INC ESI
			AND AL, 0FH
			ADD EDX, EAX
			LOOP LABE1
		LABE2 :
			MOV EAX, EDX
			RET
	DST :
			PUSH ESI
			XOR ESI, ESI
			PUSH EDI
			MOV EDI, ECX
			INC ESI
		LABE4 :
			PUSH 8
			POP ECX
			SUB ECX, ESI
			SHL ECX, 2
			MOV EAX, EDI
			SHR EAX, CL
			AND AL, 15
			ADD AL, 48
			CMP AL, 57
			JLE LABE3
			ADD AL, 7
		LABE3:
			MOV BYTE PTR[EDX], AL
			INC EDX

			INC ESI
			CMP ESI, 8
			JLE LABE4

			POP EDI
			MOV BYTE PTR[EDX], 0
			POP ESI
			RET
	}
}