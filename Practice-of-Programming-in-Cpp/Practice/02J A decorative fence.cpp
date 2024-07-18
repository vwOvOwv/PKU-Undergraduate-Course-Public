#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int t, n;
long long int c;
long long dp[30][30][2];
//dp[i][j][0]��ʾi���ȣ���j�������Ϊ��ͷ��"�ߵ͸ߵ͸�"�͵ķ�����
//dp[i][j][1]��ʾi���ȣ���j�������Ϊ��ͷ��"�͸ߵ͸ߵ�"�͵ķ�����
//dp[i+1][j][1]=sum(dp[i][k][0]),j<=k<=i
//dp[i+1][j][0]=sum(dp[i][k][1]),1<=k<j
//�ؼ�������δӷ�������ԭ������Ҫ�ķ���
bool flag[30];//��¼�Ƿ��ù�
int res[30];

int main()
{
	dp[1][1][1] = dp[1][1][0] = 1;
	for (int i = 2; i <= 20; i++) {
		for (int j = 1; j <= i; j++) {
			for (int k = j; k <= i; k++) {
				dp[i][j][1] += dp[i - 1][k][0];//ע��k����ȡ��j���������������(��ô��⣿)
			}
			for (int k = 1; k < j; k++) {
				dp[i][j][0] += dp[i - 1][k][1];
			}
		}
	}
	cin >> t;
	while (t--) {
		cin >> n >> c;
		memset(flag, 0, sizeof(flag));
		memset(res, 0, sizeof(res));
		//��ԭ����Ӧ����
		//ö�ٵ�ǰδʹ�ù���ľ��
		/*
		�����1�̵�ľ����Ϊ��һ��������ʱ�ķ�����P(1)�Ƿ�>=C,�������Ӧ���õڶ��̵���Ϊ��һ��,
		C ��ȥP(1)���ٿ���ʱ������P(2)��C����Ρ������< C ����Ӧ�Ե����̵���Ϊ��һ��,C�ټ�ȥP(2) ��.
		������ �� i�̵���Ϊ��һ��ʱ���������Ѿ���С��C����ȷ��Ӧ���Ե�i�̵���Ϊ��һ����
		C��ȥ�� i�̵���Ϊ��һ�������з�������Ȼ����ȥȷ���ڶ�����.
		*/
		long long int skipped = 0;
		for (int i = 1; i <= n; i++) {//ö������λ��
			long long int old_val = skipped;
			int no = 0;
			for (int j = 1; j <= n; j++) {//ö��iλ�õĸ߶�
				old_val = skipped;
				if (!flag[j]) {
					no++;
					if (i == 1) //����
						skipped += (dp[n][no][0] + dp[n][no][1]);
					else {
						if (j > res[i - 1] && (i <= 2 || res[i - 2] > res[i - 1]))//�ߵ� ��
							skipped += dp[n - i + 1][no][0];//��iλ�����Ǹߵ͸�
						if (j < res[i - 1] && (i <= 2 || res[i - 2] < res[i - 1]))//�͸� ��
							skipped += dp[n - i + 1][no][1];//��iλ�����ǵ͸ߵ�
					}
					if (skipped >= c) {//��ǰ��j�а����ŵ�c������
						res[i] = j;
						flag[j] = true;
						skipped = old_val;//ע����£��Ӷ����Լ���������λ�ò���
						break;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++)
			cout << res[i] << ' ';
		cout << endl;
	}
	return 0;
}

