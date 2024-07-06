#include<iostream>
#include<cmath>
#include<iomanip>
#include<climits>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int a, b;
int power_mod(int base, int power, int mod) {
	int ans = 1;
	base %= mod;
	while (power != 0) {
		if (power & 1)
			ans = (ans * base) % mod;
		base = base * base % mod;
		power >>= 1;
	}
	return ans;
}
int main()
{
	cin >> a >> b;
	cout << setw(3) << setfill('0') << power_mod(a, b, 1000);
	return 0;
}
