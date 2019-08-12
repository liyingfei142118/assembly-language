#include<iostream>
#include<bitset>
using namespace std;
const int sum = 8;
int main()
{
	char a, b;
	unsigned short c;
	cout << "please input a & b:" << endl;
	cin >> a >> b;
	cout << "a:" << (bitset<sum>)a<< endl;
	cout << "b:" << (bitset<sum>)b << endl;
	_asm {
		mov al,a
		mov bl,b
		mov cx,0
		mov dx,0
		mov esi,1
	Next:
			cmp esi,4
			jg labe
	//在a，b中各取4位形成cx最高8位	
			//取b中的位
			mov cl,bl//只操作低8位补影响高8位，不影响bl的值
			and cl,1H//cl与操作，取得最低位
			shr bl,1//逻辑右移，最高位补0
			ror cx,1//右循环移位，最低位到最高位
			//取a中位
			mov cl,al
			and cl,1H
			shr al, 1
			ror cx, 1
			inc esi
			jmp Next
		labe:
			    cmp esi, 8
				jg labe1
	//在a，b中取剩下4位形成dx最高8位
				mov dl, bl
				and dl, 1H
				shr bl, 1
				ror dx, 1
				
				mov dl, al
				and dl, 1H
				shr al, 1
				ror dx, 1
				inc esi
				jmp Next
		labe1:
			mov dl,ch//cx的高ch 8位是我们要求的低8位
			mov c,dx
	}
	cout << "c:" << (bitset<16>)c << endl;
	system("pause");
}