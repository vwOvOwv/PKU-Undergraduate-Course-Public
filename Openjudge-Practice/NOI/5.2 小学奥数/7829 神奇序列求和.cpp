#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;

int main()
{
	int x, y, n;
	cin >> x >> y >> n;
	int s[20] = { 0 };
	s[0] = x + y;
	for (int i = 1; i <= n; i++) {
		s[i] = 3 * s[i - 1] - s[0];
	}
	cout << s[n];
	return 0;
}
