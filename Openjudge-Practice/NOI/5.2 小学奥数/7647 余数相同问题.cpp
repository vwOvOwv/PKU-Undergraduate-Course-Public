#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int sup = min(min(a, b), c);
	for (int x = 2; x <= sup; x++) {
		if (a % x == b % x && a % x == c % x) {
			cout << x;
			return 0;
		}
	}
	return 0;
}
