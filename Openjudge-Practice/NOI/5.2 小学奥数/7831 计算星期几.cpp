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
int quick_power_mod(int base, int power, int mod) {//快速幂取模算法
	/*
	(a^b)%c=((a%c)^b)%c;
	a%c可以看做是新的a,从而做到迭代，将数据大小控制在c以内
	*/
	base %= mod;
	int ans = 1;
	while (power!=0) {
		if (power & 1)//等价于power%2==1
			ans = (ans * base) % mod;//把多出来的一次方收集好
		power >>= 1;//等价于power/=2
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
