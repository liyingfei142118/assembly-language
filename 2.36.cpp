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
	//��a��b�и�ȡ4λ�γ�cx���8λ	
			//ȡb�е�λ
			mov cl,bl//ֻ������8λ��Ӱ���8λ����Ӱ��bl��ֵ
			and cl,1H//cl�������ȡ�����λ
			shr bl,1//�߼����ƣ����λ��0
			ror cx,1//��ѭ����λ�����λ�����λ
			//ȡa��λ
			mov cl,al
			and cl,1H
			shr al, 1
			ror cx, 1
			inc esi
			jmp Next
		labe:
			    cmp esi, 8
				jg labe1
	//��a��b��ȡʣ��4λ�γ�dx���8λ
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
			mov dl,ch//cx�ĸ�ch 8λ������Ҫ��ĵ�8λ
			mov c,dx
	}
	cout << "c:" << (bitset<16>)c << endl;
	system("pause");
}