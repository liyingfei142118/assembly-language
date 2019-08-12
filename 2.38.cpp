#include<iostream>
using namespace std;
#define max 1000
int main()
{
	char str[max];
	int a, b, c;
	cout << "please input str:" << endl;
	cin.getline(str,max);
	cout << "str:" << str << endl;
	_asm {
		lea ebx,str
		mov esi,0//存放下标
		mov edi,0//存放非
		mov ecx,0//存放数字
		mov edx,0//存放字母
	Next:	
		mov al,[ebx+esi]
		cmp al,'\0'
		je labe4
		cmp al,48
		jb labe1
		cmp al,57
		ja labe2
		
		inc ecx//数字加加
		inc esi
		jmp Next

		labe1:
			inc edi//非 加加
			inc esi
			jmp Next
		labe2:
			cmp al,65
			jb labe1
			cmp al, 90
			ja labe3
			inc edx//字母加
			inc esi
			jmp Next
		labe3:
			cmp al, 97
			jb labe1
			cmp al, 122
			ja labe1
			inc edx//字母加
			inc esi
			jmp Next
		labe4:
				mov a,edi//存放非
				mov b,ecx//存放数字
				mov c,edx//存放字母
	}
	cout<<"非a:"<<a << endl;
	cout<<"数字b:"<<b << endl;
	cout<<"字母c:"<<c << endl;
	system("pause");
}