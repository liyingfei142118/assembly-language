#include<stdio.h>
#include<stdlib.h>
#define max 10000
int main()
{
	int a=0x11111111, b= 0x11111111, c= 0x11111111, d= 0x11111111,count=0,len=0;
	char str1[max];
	//printf("please input a,b,c,d:\n");
	//scanf_s("%d,%d,%d,%d", &a, &b, &c, &d);
	/*scanf_s("%d\n", &a);
	scanf_s("%d\n", &b);
	scanf_s("%d\n", &c);
	scanf_s("%d\n", &d);*/
	_asm{
		LEA EAX, str1
		MOV EBX, EAX
		//��4�����������ַ�����ÿ8λΪһ���ַ�	
		MOV ECX, a
		MOV [EAX], ECX
		ADD EAX, 4
		MOV ECX, b
		MOV[EAX], ECX
		ADD EAX, 4
		MOV ECX, c
		MOV[EAX], ECX
		ADD EAX, 4
		MOV ECX, d
		MOV[EAX], ECX
		ADD EAX, 4//ĩβ�������
		MOV BYTE PTR[EAX], '\0'

		PUSH EBX

		CALL BTO
		MOV count,ESI
		ADD ESP,4
		
		LEA EAX, str1
		PUSH EAX
		//PUSH len
		CALL BTO1
		MOV len,ESI
		ADD ESP, 4
	}
	printf("str1:\n%s \n", str1);
	printf("count:\n%d \n", count);
	printf("len:\n%d \n", len);
	system("pause");
	return 0;
	_asm {
	BTO:
		PUSH EBP
		MOV EBP,ESP

		MOV EDI,[EBP+8]//str1

		//MOV ESI,[EBP+8]//count
		XOR ESI,ESI
		//MOV EAX,EBX
		
	NEXT:
		MOV EAX, [EDI]
		MOV ECX, 8//8λ���һ��
	NEXT1:
		CMP BYTE PTR[EDI],'\0'
		JE OVER
		XOR EDX,EDX
		MOV EDX,EAX//edxΪ��ʱ����
		AND DL,1//ȡ���һλ
		
		CMP DL,1
		JL LABE1
		INC ESI//count++
	LABE1:
		SHR EAX,1//�߼�����
		LOOP NEXT1

		ADD EDI,1//��ַ++
		JMP NEXT
	OVER:
		POP EBP
		RET
	BTO1 :
			PUSH EBP
			MOV EBP, ESP
			XOR ESI, ESI
			MOV EBX, [EBP + 8]//str1

		//	MOV ESI, [EBP + 8]//len

			MOV EAX, EBX
			XOR EBX,EBX
	NEXT2 :
			MOV EDI, [EAX]
			MOV ECX, 8//8λ���һ��
	NEXT3 :
			CMP BYTE PTR[EAX], '\0'
			JE OVER1
			XOR EDX, EDX
			MOV EDX, EDI//edxΪ��ʱ����
			AND DL, 1//ȡ���һλ

			CMP DL, 0
			JNE LABE2
			INC ESI//count++
			JMP LABE4
	LABE2 :
			CMP ESI,EBX//�Ƚ��������len����ʱ��ebx��С
			JL LABE3
			MOV EBX,ESI//ebx=len
	LABE3 :
			XOR ESI,ESI//��������0��Ϊ������
	LABE4:
			SHR EDI, 1//�߼�����
			LOOP NEXT3

			ADD EAX, 1//��ַ++
			JMP NEXT2
	OVER1 :
			MOV ESI,EBX//len=��ʱ��ebx
			POP EBP
			RET
	}

}