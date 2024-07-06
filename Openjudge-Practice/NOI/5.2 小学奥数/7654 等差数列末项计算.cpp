#include<iostream>
using namespace std;
int main()
{
	int a1, a2, n;
	cin >> a1 >> a2 >> n;
	int d = a2 - a1;
	if (n < 3) {
		if (n == 1)
			cout << a1;
		else
			cout << a2;
	}
	for (int i = 3; i <= n; i++) {
		a2 += d;
	}
	cout << a2;
}
