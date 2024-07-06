#include<iostream>
#include<cmath>
#include<iomanip>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;
int f(int m, int n) {
	if (m == 0)
		return 1;
	if (n == 0)
		return 0;
	if (m <= n)
		n = m;
	return f(m - n, n) + f(m, n - 1);
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int m, n;
		cin >> m >> n;
		cout << f(m, n) << endl;
	}
	return 0;
}
