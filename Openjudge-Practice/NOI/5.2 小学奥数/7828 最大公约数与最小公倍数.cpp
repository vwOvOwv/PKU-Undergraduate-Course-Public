#include<iostream>
#include<cmath>
#include<iomanip>
#include<climits>
#include<algorithm>
using namespace std;
int g, l;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;//¼Ç×¡
}
int main()
{
	int mini = INT_MAX;
	cin >> g >> l;
	for (int i = g; i <= l; i++) {
		if ((l * g) % i == 0) {
			int j = l * g / i;
			if (gcd(j, i) == g) {
				mini = min(mini, i + j);
			}
		}
	}
	cout << mini;
	return 0;
}
