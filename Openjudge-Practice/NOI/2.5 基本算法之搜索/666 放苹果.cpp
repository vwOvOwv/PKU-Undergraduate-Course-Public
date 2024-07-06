#include<iostream>
using namespace std;
int m, n;
int f(int m, int n) {
	if (m == 0)
		return 1;
	if (n == 0)
		return 0;
	if (m < n)
		n = m;
	return f(m - n, n) + f(m, n - 1);
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		cout << f(m, n) << endl;
	}
	return 0;
}
