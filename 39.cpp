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
		s[i] = a;//ǿ��ת��
	}
	_asm {
		lea ebx, s
		mov si,count1//�з���
		mov di,count2//�޷���
		mov eax,0
		mov ecx,0
		Next:
			cmp ecx,max
			jge labe
			mov eax, [ebx + ecx]
		
			cmp al,0//�ж��Ƿ�С����
			jl labe0
		
			mov dx,0//���ڵ������8λ������չΪ0
			mov dl,al//������չ���16
		//	���
			add di,dx//wu
			add si,dx//you
			
			inc ecx//��ַ�±�
			jmp Next
		labe0://С�����8λ������չΪ1
				mov dx, -1
				mov dl, al
				add si, dx
//ǰ�漸�������з��ţ�����Ҫ�����޷��ţ�
				mov dx, 0//���ڵ������8λ������չΪ0
				mov dl, al//������չ���16
				 //	���
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