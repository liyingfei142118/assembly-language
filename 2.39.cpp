#include<iostream>
using namespace std;
#define max 1000
int main()
{
	char str[max];
	cout << "please input str:" << endl;
	cin.getline(str, max);
	cout << "str:" << str << endl;
	_asm {
		lea ecx,str
		mov esi, 0//存放下标
		mov edi,0//遍历后面下标

	Next:
		mov al, [ecx + esi]//取当前字符
		
		cmp al, '\0'//所有字符遍历完
		je labe2
		
		mov edi,esi//每一次从当前字符后面遍历
		inc edi//j++
	Next1://遍历后面每个字符
		mov bl,[ecx+edi]
		cmp bl, '\0'
		je labe1

		cmp al,bl
		jb labe0//小于交换
		inc edi//j++
		jmp Next1
	labe0:
		mov [ecx + edi],al//小的放回数组
		mov al,bl//al存大的
		inc edi//j++
		jmp Next1
	labe1:
		mov [ecx + esi], al//更新当前字符
		inc esi//i++
		jmp Next
	labe2:
	}
	cout << "new str:" << str << endl;
	system("pause");
}