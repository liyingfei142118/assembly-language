#include<iostream>
using namespace std;
#define max 20
int main()
{
	char s[max];
	int lp = 0, rp = 0;
	cout << "please input 20 number:";
	for (int i = 0; i < max; i++)
	{
		int a;
		cin >> a;
		s[i] = a;//强制转换
	}
	_asm {
		lea ebx,s
		mov ecx,0
		mov esi,rp
		mov edx,lp

	next0://16位的取
		cmp ecx,max//跳转到32位的取
		jge next1

		mov eax,[ebx+ecx]
		cmp ax,0
		jg labe1
		add ecx,2//保证继续执行
		jmp next0

	next1://32位的取
		mov ecx,0
	next2:
		cmp ecx, max//跳出
		jge labe3
		mov eax, [ebx + ecx]
		cmp eax, 0
		jl labe2
		add ecx, 4
		jmp next2

	labe1:
		inc esi//个数++
		add ecx,2
		jmp next0
	labe2:
		inc edx
		add ecx,4
		jmp next2
	labe3:
		mov rp,esi
		mov lp,edx
	}
	cout << "正：" << rp << endl;
	cout << "负：" << lp << endl;
	system("pause");
}