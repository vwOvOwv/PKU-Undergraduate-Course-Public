//01±³°ü
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int ans[25] = { 0 };
	ans[1] = 1;
	ans[2] = 2;
	for (int i = 3; i <= 20; i++)
		ans[i] = ans[i - 1] + ans[i - 2];
	int n;
	cin >> n;
	cout << ans[n];
	return 0;
}
