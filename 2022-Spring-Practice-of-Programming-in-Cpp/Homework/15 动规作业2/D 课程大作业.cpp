#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
//״ѹdp
const int MAX = 1 << 16;//�ö����Ʊ�ʾ���е�״̬
int t, n;
string s[20];
int d[20], c[20];
int dp[MAX];//ÿ��״̬�µ����Ž⣬�����ٿ۷���
string ans[MAX];//ÿ��״̬��·����¼
int sum[MAX];//�ﵽĳ��״̬�����ʱ��
int main()
{
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s[i] >> d[i] >> c[i];
			sum[1 << i] = c[i];//ֻ��� i����ʱ�伴Ϊc[i]
		}
		for (int i = 1; i < (1 << n); i++) {//ö������״̬��ע��i��ȡֵ��Χ
			for (int j = 0; j < n; j++) {
				if (i & (1 << j))//�Ѿ������j
					sum[i] = sum[i ^ (1 << j)] + c[j];//��û���j��״̬ת�ƹ���
			}
		}
		dp[0] = 0;
		for (int i = 0; i < (1 << n); i++)
			ans[i] = "";
		for (int i = 1; i < (1 << n); i++) {
			for (int j = 0; j < n; j++) {
				int tmp = sum[i] - d[j];
				if (tmp < 0)
					tmp = 0;
				if (i & (1 << j) && (dp[i ^ (1 << j)] + tmp <= dp[i] || ans[i] == "")) {
					if (dp[i ^ (1 << j)] + tmp < dp[i] || ans[i ^ (1 << j)] + s[j] + "\n" < ans[i]||ans[i]=="") {
						ans[i] = ans[i ^ (1 << j)] + s[j] + "\n";
					}
					dp[i] = dp[i ^ (1 << j)] + tmp;
				}
			}
		}
		cout << dp[(1 << n) - 1] << endl;
		cout << ans[(1 << n) - 1];
	}
	return 0;
}
