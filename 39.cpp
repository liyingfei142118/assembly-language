#include<iostream>
#include<bitset>
using namespace std;
const int sum = 16;
#define max 10
int main()
{
	char s[max];
	short count1 = 0;
	unsigned short count2 = 0;
	cout << "please input 10 number:";
	for (int i = 0; i < max; i++)
	{
		int a;
		cin >> a;
		s[i] = a;//强制转换
	}
	_asm {
		lea ebx, s
		mov si,count1//有符号
		mov di,count2//无符号
		mov eax,0
		mov ecx,0
		Next:
			cmp ecx,max
			jge labe
			mov eax, [ebx + ecx]
		
			cmp al,0//判断是否小于零
			jl labe0
		
			mov dx,0//大于等于零高8位符号扩展为0
			mov dl,al//数据扩展变成16
		//	求和
			add di,dx//wu
			add si,dx//you
			
			inc ecx//地址下标
			jmp Next
		labe0://小于零高8位符号扩展为1
				mov dx, -1
				mov dl, al
				add si, dx
//前面几步计算有符号，后面要考虑无符号，
				mov dx, 0//大于等于零高8位符号扩展为0
				mov dl, al//数据扩展变成16
				 //	求和
				add di, dx//wu
				inc ecx
				jmp Next
		labe:
			mov count1,si
			mov count2,di
	}
	cout << "YOU:" << count1 << endl;
	cout << "YOU:" <<( bitset<sum>)count1 << endl;
	cout << "NO:" <<  count2 << endl;
	cout << "NO:" << (bitset<sum>) count2 << endl;
	system("pause");
}