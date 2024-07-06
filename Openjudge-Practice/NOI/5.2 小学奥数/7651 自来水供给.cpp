#include<iostream>
#include<algorithm>
#include<iomanip>
#include<climits>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[110] = { 0 };
	for (int i = 1; i <= n; i++) {
		int s;
		cin >> s;
		a[i] = a[i - 1] + s;
	}
	int mini = INT_MAX;
	for (int i = 1; i <= n; i++) {
		int sum = 8000 * a[i];
		for (int j = i + 1; j <= n; j++) {
			sum += 2000 * (a[j] - a[i]);
		}
		mini = min(mini, sum);
	}
	cout << mini;
	return 0;
}
