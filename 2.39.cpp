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
		mov esi, 0//����±�
		mov edi,0//���������±�

	Next:
		mov al, [ecx + esi]//ȡ��ǰ�ַ�
		
		cmp al, '\0'//�����ַ�������
		je labe2
		
		mov edi,esi//ÿһ�δӵ�ǰ�ַ��������
		inc edi//j++
	Next1://��������ÿ���ַ�
		mov bl,[ecx+edi]
		cmp bl, '\0'
		je labe1

		cmp al,bl
		jb labe0//С�ڽ���
		inc edi//j++
		jmp Next1
	labe0:
		mov [ecx + edi],al//С�ķŻ�����
		mov al,bl//al����
		inc edi//j++
		jmp Next1
	labe1:
		mov [ecx + esi], al//���µ�ǰ�ַ�
		inc esi//i++
		jmp Next
	labe2:
	}
	cout << "new str:" << str << endl;
	system("pause");
}