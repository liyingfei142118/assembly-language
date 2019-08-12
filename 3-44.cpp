#include<stdio.h>
#include<stdlib.h>
#define max 10000
int main()
{
	unsigned int m;
	char buffer[max];
	printf("please input unsigned int a:\n");
	scanf_s("%d", &m);
	_asm
	{

		
		MOV ECX,m 
		LEA EDX,buffer
		CALL DST
	}

	printf("16 position buffer:\n%s \n", buffer);
	system("pause");
	return 0;
	_asm
	{
DST://ÀýÌâ3-55Ë¼Ïë
		PUSH ESI
		XOR ESI,ESI
		PUSH EDI
		MOV EDI,ECX
		INC ESI
	LABE1:
		PUSH 8
		POP ECX
		SUB ECX,ESI
		SHL ECX,2
		MOV EAX,EDI
		SHR EAX,CL
		AND AL,15
		ADD AL,48
		CMP AL,57
		JLE LABE2
		ADD AL,7
	LABE2:
		MOV BYTE PTR[EDX],AL
		INC EDX

		INC ESI
		CMP ESI,8
		JLE LABE1

		POP EDI
		MOV BYTE PTR[EDX],0
		POP ESI
		RET
	}

}