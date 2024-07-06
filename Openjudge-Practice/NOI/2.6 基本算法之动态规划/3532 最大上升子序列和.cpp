#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
int n;
int a[1010];
int f[1010];//f[i]表示以a[i]结尾的最大上升子序列和
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		f[i] = a[i];
	for (int i = 2; i <= n; i++) {
		for (int k = 1; k < i; k++) {
			if (a[i] > a[k])
				f[i] = max(f[i], f[k] + a[i]);
		}
	}
	cout << *max_element(f + 1, f + n + 1) << endl;
	return 0;
}
