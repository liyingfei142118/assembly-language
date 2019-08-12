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
		cmp eax,0//判断是否小于0
		jl labe1
		cmp ebx, 0
		jl labe2
	labe0:
		mov cx,ax//交换 cx位媒介
		mov ax,bx
		mov bx,cx
		mov a,ebx
		mov b,eax
		jmp labe3
	labe1://负数得其绝对值，取反加一
		not eax//否运算
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