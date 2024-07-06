#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
long long int dp[260][260];
//dp[i][j]��ʾi��j��ͷ�ĵ�����ķֽ������ɼ�i-2*j>=j
//dp[i][j]=sum{dp[i-2*j][k]},k>=j,i-2*j>=k(ע�����ﲻ����i-2*j-2*k>=k����Ϊ�����Ե���ֹͣ�ֽ⣬��i-2*j=k)
//�ݹ��˼��
int main()
{
	for (int i = 1; i <= 250; i++)
		dp[i][i] = 1;
	for (int i = 2; i <= 250; i+=2)
		dp[i][i / 2] = 1;
	//dp��ʼ��
	for (int i = 1; i <= 250; i++) {
		for (int j = 1; i - 2 * j >= j; j++) {
			for (int k = j; i - 2 * j >= k; k++) {
				dp[i][j] += dp[i - 2 * j][k];
			}
		}
	}
	while (cin >> n) {
		if (n == 0)
			break;
		cout << n << ' ';
		long long int ans = 0;
		for (int j = 1; j <= n; j++)
			ans += dp[n][j];
		cout << ans << endl;
	}
	return 0;
}
