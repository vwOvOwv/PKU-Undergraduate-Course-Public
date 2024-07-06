//此题用一般递归会超时，用记忆化递归或者递推打表最佳
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>mem(1000010, -1);
int f(int n) {//求an%32767，an增速极快，long long int也装不下
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (mem[n] != -1) {
		return mem[n];
	}
	else {
		mem[n] = (2 * f(n - 1) + f(n - 2)) % 32767;
		return mem[n];
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		cout << f(k) << endl;
	}
	return 0;
}
