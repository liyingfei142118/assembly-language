#include<iostream>
using namespace std;
int main()
{
	int c;
	_asm {
		mov eax,0
		 mov ecx,12
		 jcxz Over
	Next:
		 add eax,4
		 loop Next
	Over:
		 mov c,eax
	}
	cout << "c:" << c << endl;
	system("pause");
}