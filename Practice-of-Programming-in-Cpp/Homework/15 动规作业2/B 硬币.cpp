#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n, x;
int a[210];
int dp[10010];//dp[i]��ʾǮ������iʱ�����з�����
int rec[10010];//rec[i]��¼Ǯ��Ϊiʱ��ѡĳ��Ӳ�ҵķ���������
int cnt = 0;
int ans[10010];//��¼����ѡ��Ӳ�ҵı��
int main()
{
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dp[0] = 1;//��Ҫ
	for (int i = 1; i <= n; i++) {//�뱳��������ʽ���ƣ�����Ҫ������ܷ�����
		for (int j = x; j >= a[i]; j--)
			dp[j] += dp[j - a[i]];//��ÿһ��j>=a[i]������ѡ��a[i]�ճ���j
	}
	for (int i = 1; i <= n; i++) {
		memset(rec, 0, sizeof(rec));
		for (int j = 0; j <= x; j++) {
			if (j < a[i])
				rec[j] = dp[j];//һ��ûѡa[i]
			else//����ѡa[i]
				rec[j] = dp[j] - rec[j - a[i]];//�ܷ�����-ѡ��a[i]����j�ķ�������ע��۲�dp����ĵ���ģʽ
		}
		if (rec[x] == 0) {//��ѡa[i]����
			ans[cnt] = a[i];
			cnt++;
		}
	}
	cout << cnt << endl;
	if (cnt != 0) {
		for (int i = 0; i < cnt; i++)
			cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}
