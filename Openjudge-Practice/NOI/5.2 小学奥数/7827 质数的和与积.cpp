#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
bool judge(int k) {
	for (int i = 2; i < k; i++) {
		if (k % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int s;
	cin >> s;
	int maxi;
	for (int i = s / 2; i >= 2;i--) {
		if (judge(i) && judge(s - i)) {
			cout << i * (s - i);
			return 0;
		}
	}
	return 0;
}
