#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10000
int main()
{
	char str1[max];
	char KK='e';
	int n;
	//printf("please input ch:\n");
	//scanf_s("%c", &a1);
	printf("please input n:\n");
	scanf_s("%d", &n);
	
	_asm {

		LEA EAX, str1//�õ��ַ�����ַ
		MOV EBX,n
		XOR ECX,ECX
		MOV CL,KK
				  PUSH EAX
				  PUSH EBX
				  PUSH ECX
				  CALL BTOS
				  ADD ESP,12
	}
	printf("str:%s \n", str1);
	system("pause");
	return 0;
	_asm {
	BTOS:
		PUSH EBP
		MOV EBP,ESP


		MOV EAX,[EBP+16]//str
		MOV EBX,[EBP+8]//ch
		MOV ECX,[EBP+12]//n*/

	NEXT :
			MOV BYTE PTR[EAX], BL//put ch in str
			INC EAX//��ַ++
			LOOP NEXT//ѭ��


			MOV BYTE PTR[EAX], '\0'
			POP EBP
			RET
	}
	

/*	_asm {
		XOR EBX,EBX
		LEA EAX,str1//�õ��ַ�����ַ
		
		MOV BL,KK//
/*		CALL BTOS
	}
	printf("str:%s \n", str1);
	system("pause");
	return 0;
	_asm {
	BTOS:
		MOV ECX, n//n
	NEXT:
		MOV BYTE PTR[EAX],BL//put ch in str
		INC EAX//��ַ++
		LOOP NEXT//ѭ��
		
		
		MOV BYTE PTR[EAX],'\0'

		RET
	}*/
}