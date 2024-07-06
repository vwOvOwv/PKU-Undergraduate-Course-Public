#include<iostream>
#include<cmath>
#include<iomanip>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;
int cal(int n) {//¼ÇÒäÒ»ÏÂ
	if (n == 1 || n == 2)
		return 9;
	if (n % 2 == 1)
		return cal(n - 1) * 10;
	else
		return cal(n - 2) * 10;
}
int main()
{
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += cal(i);
	}
	cout << ans;
	return 0;
}
