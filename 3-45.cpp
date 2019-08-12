#include<stdio.h>
#include<stdlib.h>
#define max 10000
int main()
{

	char kk='a';
	char buffer[max];
	char buffer1[max];
	char buffer2[11];
	//printf("please input a:\n");
	//scanf_s("%c", kk);

	_asm
	{
		XOR ECX, ECX
		MOV CL, kk
		
		LEA ESI,buffer2
		MOV EAX,ECX
		MOV ECX,10
		MOV EBX,10
	NEXT:
		XOR EDX,EDX
		DIV EBX
		ADD DL,'0'
		MOV [ESI+ECX-1],DL
		LOOP NEXT

		MOV BYTE PTR[ESI+10],0

		XOR ECX,ECX
		MOV CL,kk
		LEA EDX, buffer
		CALL DST
		
		XOR ECX,ECX
		MOV CL,kk
		LEA EDX,buffer1
		CALL DST1
	}
	printf("10 position buffer2:\n%s \n", buffer2);
	printf("16 position buffer:\n%s \n", buffer);
	
	printf("2 position buffer1:\n%s \n", buffer1);
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
			JBE LABE2
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
	DST1 :
			PUSH ESI
			XOR ESI, ESI//i=0
			PUSH EDI
			MOV EDI, ECX//edi=kk
			INC ESI//i=1
		LABE5 :
			PUSH 32
			POP ECX//ecx=32

			SUB ECX, ESI//32-i
			MOV EAX, EDI//eax=(int)kk
			SHR EAX, CL// kk>>32-i
			AND AL, 01H//&Ox1f
			ADD AL, 48
			MOV BYTE PTR[EDX], AL//*buffer=al
			INC EDX//buffer++

			INC ESI//i++
			CMP ESI, 32//i<=32
			JLE LABE5

			POP EDI
			MOV BYTE PTR[EDX], 0
			POP ESI

			RET
	}

}