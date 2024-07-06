#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 1;; i++) {
		for (int x = 1; x <= i; x++) {
			if ((1 + i) * i / 2 - x * 2 == n) {
				cout << x << ' ' << i << endl;
				return 0;
			}
		}
	}
	return 0;
}
