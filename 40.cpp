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
		mov esi,0//���������
		mov edx,0//���ż����
	Next:
		cmp ecx,max
		jge labe1
		mov eax,[ebx+ecx*4]
		


		and eax,1H//�� ��ȡ���λ
		cmp eax,1//�������1 ֤��������
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
//�жϴ�С
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
	cout << "������:" << b << endl;
	cout << "ż����:" << a << endl;
	cout << "��:" << val << endl;
	system("pause");
}