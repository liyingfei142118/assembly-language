#include<iostream>
using namespace std;
#define max 32
int main()
{
	unsigned int val;
	int count=0;
	cout << "please input val:" << endl;
	cin >> val;
	_asm {
		mov eax,val
		mov esi,1
		mov edx,0
	Next:
		cmp esi,max
		jg labe2

		mov ecx,eax
		and ecx,1H//����� ��ȡ���һλ
		cmp ecx,0
		jz labe1
		shr eax,1//�߼�����һλ ��λ��0
		inc esi
		jmp Next
		labe1:
			inc edx
			shr eax,1
			inc esi
			jmp Next
		labe2:
			mov count,edx
	}
	cout << "total n wei:" << count<<endl;
	system("pause");
}