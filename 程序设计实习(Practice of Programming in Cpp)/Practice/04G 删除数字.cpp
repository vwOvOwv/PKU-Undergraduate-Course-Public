#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;
#define mem(a) memset(a,0,sizeof(a))
int t, n;
int a[1010];
int f[1010][1010];//f[i][j]��ʾǰi������ɾȥj�������������������ĸ���
int mymax(int a, int b, int c) {
	int ans = a;
	ans = max(ans, b);
	ans = max(ans, c);
	return ans;
}
int main()
{
	cin >> t;
	while (t--) {
		cin >> n;
		mem(a), mem(f);
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= i; j++) {
				if (a[i] == i - j)//a[i]���Էŵ���i��λ��
					f[i][j] = f[i - 1][j] + 1;//ǰ��i-1������ɾ��j�����ڳ���i-j��λ��
				f[i][j] = mymax(f[i - 1][j - 1], f[i - 1][j], f[i][j]);//ɾ/��ɾ
			}
		}
		int ans = 0;
		for (int i = 0; i <= n; i++)
			ans = max(ans, f[n][i]);
		cout << ans << endl;
	}
	return 0;
}
