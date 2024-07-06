/*
分别计算得到每个数能拆分成多少个2和多少个5的乘积，形如2^i*5^j*k的形式。
最后统计所有乘积得到了多少个2和多少个5，如果2的数目比5多，取5的数目；如果5的数目比2多，取2的数目；
*/
#include<iostream>
#include<cmath>
#include<iomanip>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;
int cal1(int n) {
	int ans = 0;
	while (n != 0 && n % 2 == 0) {
		ans++;
		n /= 2;
	}
	return ans;
}
int cal2(int n) {
	int ans = 0;
	while (n != 0 && n % 5 == 0) {
		ans++;
		n /= 5;
	}
	return ans;
}
int a, b;
int main()
{
	cin >> a >> b;
	int sum2 = 0, sum5 = 0;
	for (int i = a; i <= b; i++) {
		sum2 += cal1(i);
		sum5 += cal2(i);
	}
	int mini = min(sum2, sum5);
	cout << mini;
	return 0;
}
