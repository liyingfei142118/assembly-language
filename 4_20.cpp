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
	
		LEA EBX,str1//�õ�str1��ַ
		MOV EDX,0//i
		//INC EAX
	LABE1:
		CMP EDX,a//�Ƚ��Ƿ���str1���һ���ַ�
		JGE OVER

		MOV AL,[EBX+EDX]//�õ���i���ַ�
		MOV ECX,b//����b��
		
		LEA EDI,str2
	NEXT:
		SCASB//ɨ��
		LOOPNZ NEXT
		JNZ NOT_FOUND
	FOUND://�ҵ�
		MOV flag,EDX
		JMP OVER
	NOT_FOUND://û���ҵ���������һ���ַ�
		MOV flag,-1
		INC EDX//i++
		JMP LABE1
	OVER:
	}
	printf("str1:%s \n", str1);
	printf("str2:%s \n", str2);
	printf("flag:%d \n",flag);
	system("pause");
	return 0;
}