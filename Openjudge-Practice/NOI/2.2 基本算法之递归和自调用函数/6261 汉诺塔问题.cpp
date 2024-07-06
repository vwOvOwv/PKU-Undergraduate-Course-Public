#include<iostream>
using namespace std;
void Hanoi(int n, char start, char mid, char des) {
	if (n == 1) {
		cout << start << "->" << 1 << "->" << des << endl;
	}
	else {
		Hanoi(n - 1, start, des, mid);
		cout << start << "->" << n << "->" << des << endl;
		Hanoi(n - 1, mid, start, des);
	}
}
int main() {
	int n;
	char a, b, c;
	cin >> n >> a >> b >> c;
	Hanoi(n, a, c, b);
	return 0;
}
