/*
�ֱ����õ�ÿ�����ܲ�ֳɶ��ٸ�2�Ͷ��ٸ�5�ĳ˻�������2^i*5^j*k����ʽ��
���ͳ�����г˻��õ��˶��ٸ�2�Ͷ��ٸ�5�����2����Ŀ��5�࣬ȡ5����Ŀ�����5����Ŀ��2�࣬ȡ2����Ŀ��
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
