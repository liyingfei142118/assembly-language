#include<iostream>
using namespace std;
#define max 13
int main()
{
	unsigned int s[max];
	unsigned int val=0;
	int a, b;
	cout << "plaese input 13 number:" << endl;
	for (int i = 0; i < max; i++)
	{
		cin >> s[i];
	}
	_asm {
		lea ebx,s
		mov ecx,0
		mov esi,0//存放奇数和
		mov edx,0//存放偶数和
	Next:
		cmp ecx,max
		jge labe1
		mov eax,[ebx+ecx*4]
		


		and eax,1H//与 截取最低位
		cmp eax,1//如果等于1 证明是奇数
		jz labe
		
		mov eax, [ebx + ecx * 4]
		add esi,eax
		inc ecx
		jmp Next
	labe:
		mov eax, [ebx + ecx * 4]
		add edx,eax
		inc ecx
		jmp Next
	labe1:
		mov a,esi
		mov b,edx
//判断大小
		cmp esi,edx
		jge labe2
		sub edx,esi
		mov val,edx
		jmp labe3
	labe2:
		sub esi, edx
		mov val, esi
	labe3:
	}
	cout << "奇数和:" << b << endl;
	cout << "偶数和:" << a << endl;
	cout << "差:" << val << endl;
	system("pause");
}