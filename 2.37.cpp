#include<iostream>
#include<bitset>
using namespace std;
const int sum = 32;
int main()
{
	int a, b;
	cout << "please input a & b:" << endl;
	cin >> a >> b;
	cout << "a:" << (bitset<sum>)a << endl;
	cout << "b:" << (bitset<sum>)b << endl;
	_asm {
		mov eax,a
		mov ebx,b
		cmp eax,0//�ж��Ƿ�С��0
		jl labe1
		cmp ebx, 0
		jl labe2
	labe0:
		mov cx,ax//���� cxλý��
		mov ax,bx
		mov bx,cx
		mov a,ebx
		mov b,eax
		jmp labe3
	labe1://�����������ֵ��ȡ����һ
		not eax//������
		add eax,1
		jmp labe0
	labe2:
		not ebx
		add ebx,1
		jmp labe0
	labe3:
	}
	cout << "a:" << a<<" "<<(bitset<sum>)a << endl;
	cout << "b:" << b<<" "<<(bitset<sum>)b << endl;
	system("pause");
}