#include<iostream>
using namespace std;
#define max 10
int main()
{
	char s[max];
	int lp = 0, rp = 0;
	cout << "please input ten number:";
	for (int i = 0; i < max; i++)
	{
		int a;
		cin >> a;
		 s[i]=a;//强制转换
	}
	_asm {
		lea ebx,s//取首地址
		mov eax,lp//负
		mov ecx,rp//正
		mov edx,0//数组下标
	labe:
		cmp edx,max//是否取完
		jge labe3//跳出
		cmp [ebx+edx],0//比较正负
		jl labe1//小于跳转
		cmp[ebx + edx], 0//比较正负
		jg labe2//大于跳转

		inc edx//数组下标地址++
		jmp labe//等于跳回

		labe1:
			inc eax
			inc edx//数组下标地址++
			jmp labe
		labe2:
			inc ecx
			inc edx//数组下标地址++
			jmp labe
		labe3:
			mov lp,eax
			mov rp,ecx
	}
	cout << "负：" << lp << endl;
	cout << "正：" << rp << endl;
	system("pause");
 }