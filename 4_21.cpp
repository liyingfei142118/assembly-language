#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10000
int main()
{
	char str1[max], str2[max];
	printf("please input str1:\n");
	scanf_s("%s", str1, max);
	printf("please input str2:\n");
	scanf_s("%s", str2, max);
	int a = strlen(str1);
	int b = strlen(str2);
	int flag = 0;

	_asm {	
		MOV EDX, -1
		XOR EAX,EAX//iI
		
	NEXT:
		LEA EDI, str2
		LEA ESI, str1
		ADD ESI, EAX//ָ��str1��i���ַ�

		MOV ECX, b//��str1��i���ַ���ʼ��str2�Ƚ�
	LABE2 :
			CMPSB//�Ƚ��ֽ�
			JNE LABE3//��������ַ�����ȣ���ת
			LOOP LABE2//ѭ������󣬳����ַ������
			
			MOV EDX,EAX//�õ�λ��
			JMP LABE1
	LABE3 :
		INC EAX//i++
		JMP NEXT	//û���ҵ���������һ���ַ�
	LABE1:
		MOV flag,EDX

	}
	printf("str1:%s \n", str1);
	printf("str2:%s \n", str2);
	printf("flag:%d \n", flag);
	system("pause");
	return 0;

}