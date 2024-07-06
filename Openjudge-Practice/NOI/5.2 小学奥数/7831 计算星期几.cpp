#include<iostream>
#include<cmath>
#include<iomanip>
#include<climits>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int a, b;
string days[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
int quick_power_mod(int base, int power, int mod) {//������ȡģ�㷨
	/*
	(a^b)%c=((a%c)^b)%c;
	a%c���Կ������µ�a,�Ӷ����������������ݴ�С������c����
	*/
	base %= mod;
	int ans = 1;
	while (power!=0) {
		if (power & 1)//�ȼ���power%2==1
			ans = (ans * base) % mod;//�Ѷ������һ�η��ռ���
		power >>= 1;//�ȼ���power/=2
		base = (base * base) % mod;
	}
	return ans;
}
int main()
{
	cin >> a >> b;
	cout << days[quick_power_mod(a, b, 7)];
	return 0;
}
