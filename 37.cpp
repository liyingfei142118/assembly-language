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
		 s[i]=a;//ǿ��ת��
	}
	_asm {
		lea ebx,s//ȡ�׵�ַ
		mov eax,lp//��
		mov ecx,rp//��
		mov edx,0//�����±�
	labe:
		cmp edx,max//�Ƿ�ȡ��
		jge labe3//����
		cmp [ebx+edx],0//�Ƚ�����
		jl labe1//С����ת
		cmp[ebx + edx], 0//�Ƚ�����
		jg labe2//������ת

		inc edx//�����±��ַ++
		jmp labe//��������

		labe1:
			inc eax
			inc edx//�����±��ַ++
			jmp labe
		labe2:
			inc ecx
			inc edx//�����±��ַ++
			jmp labe
		labe3:
			mov lp,eax
			mov rp,ecx
	}
	cout << "����" << lp << endl;
	cout << "����" << rp << endl;
	system("pause");
 }