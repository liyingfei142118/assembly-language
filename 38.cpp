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
		s[i] = a;//ǿ��ת��
	}
	_asm {
		lea ebx,s
		mov ecx,0
		mov esi,rp
		mov edx,lp

	next0://16λ��ȡ
		cmp ecx,max//��ת��32λ��ȡ
		jge next1

		mov eax,[ebx+ecx]
		cmp ax,0
		jg labe1
		add ecx,2//��֤����ִ��
		jmp next0

	next1://32λ��ȡ
		mov ecx,0
	next2:
		cmp ecx, max//����
		jge labe3
		mov eax, [ebx + ecx]
		cmp eax, 0
		jl labe2
		add ecx, 4
		jmp next2

	labe1:
		inc esi//����++
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
	cout << "����" << rp << endl;
	cout << "����" << lp << endl;
	system("pause");
}