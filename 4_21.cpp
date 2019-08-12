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
		ADD ESI, EAX//指向str1第i个字符

		MOV ECX, b//从str1第i个字符开始和str2比较
	LABE2 :
			CMPSB//比较字节
			JNE LABE3//如果两个字符不相等，挑转
			LOOP LABE2//循环至最后，出现字符串相等
			
			MOV EDX,EAX//得到位置
			JMP LABE1
	LABE3 :
		INC EAX//i++
		JMP NEXT	//没有找到，继续下一个字符
	LABE1:
		MOV flag,EDX

	}
	printf("str1:%s \n", str1);
	printf("str2:%s \n", str2);
	printf("flag:%d \n", flag);
	system("pause");
	return 0;

}