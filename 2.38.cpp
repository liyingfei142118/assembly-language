#include<iostream>
using namespace std;
#define max 1000
int main()
{
	char str[max];
	int a, b, c;
	cout << "please input str:" << endl;
	cin.getline(str,max);
	cout << "str:" << str << endl;
	_asm {
		lea ebx,str
		mov esi,0//����±�
		mov edi,0//��ŷ�
		mov ecx,0//�������
		mov edx,0//�����ĸ
	Next:	
		mov al,[ebx+esi]
		cmp al,'\0'
		je labe4
		cmp al,48
		jb labe1
		cmp al,57
		ja labe2
		
		inc ecx//���ּӼ�
		inc esi
		jmp Next

		labe1:
			inc edi//�� �Ӽ�
			inc esi
			jmp Next
		labe2:
			cmp al,65
			jb labe1
			cmp al, 90
			ja labe3
			inc edx//��ĸ��
			inc esi
			jmp Next
		labe3:
			cmp al, 97
			jb labe1
			cmp al, 122
			ja labe1
			inc edx//��ĸ��
			inc esi
			jmp Next
		labe4:
				mov a,edi//��ŷ�
				mov b,ecx//�������
				mov c,edx//�����ĸ
	}
	cout<<"��a:"<<a << endl;
	cout<<"����b:"<<b << endl;
	cout<<"��ĸc:"<<c << endl;
	system("pause");
}