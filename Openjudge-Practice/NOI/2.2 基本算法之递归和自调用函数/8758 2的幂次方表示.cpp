#include<iostream>
using namespace std;
int n;
char mem_char='\0';
void f(int n) {
	if (n == 0) {
		cout << '0';
		return;
	}
	if (n == 1) {
		return;
	}
	if (n == 2) {
		cout << '2';
		return;
	}
	int i = 31;
	for (; i >= 0; i--) {
		int v = (n >> i) & 1;
		if (v == 1)
			break;
	}//求最高位
	for (; i >= 0; i--) {
		int v = (n >> i) & 1;
		if (v == 1 && i!=1) {
			if (mem_char != ')' && mem_char != '2')
				cout << "2(";
			else
				cout << "+2(";
			mem_char = '(';
			f(i);
			cout << ')';
			mem_char = ')';
		}
		if (v == 1 && i ==1) {
			if (mem_char != ')' && mem_char != '2')
				cout << '2';
			else
				cout << "+2";
			mem_char = '2';
		}
	}
}
int main()
{
	cin >> n;
	f(n);
	return 0;
}
