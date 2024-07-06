#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
int l1, l2;
int s1[510], s2[510];
int f[510][510];//f[i][j]表示以s1的前i个元素与s2的前j个元素以s2[j]结尾的最长公共上升子序列的长度
vector<vector<int>>rec(510);//rec[j]记录当i为某确定值时，s1的前i个元素与s2的前j个元素以s2[j]结尾的最长公共子序列
int main()
{
	cin >> l1;
	for (int i = 1; i <= l1; i++)
		cin >> s1[i];
	cin >> l2;
	for (int i = 1; i <= l2; i++)
		cin >> s2[i];

	for (int i = 1; i <= l1; i++) {
		for (int j = 1; j <= l2; j++) {
			f[i][j] = f[i - 1][j];
			if (s1[i] == s2[j]) {
				f[i][j] = 1;
				rec[j].clear();//一定要有，随着i,j的增大rec[j].size()必然是递增的，因此可以清空
				for (int k = 1; k < j; k++) {//枚举接在s2的哪一个位置后面
					if (s2[k]<s2[j] && f[i - 1][k] + 1>f[i][j]) {
						f[i][j] = f[i - 1][k] + 1;
						rec[j] = rec[k];
					}
				}
				rec[j].push_back(s2[j]);
			}
			else//选不了
				f[i][j] = f[i - 1][j];
		}
	}
	int ans = 0;
	int max_j = 0;
	for (int i = 1; i <= l2; i++) {
		ans = max(ans, f[l1][i]);
		if (ans == f[l1][i])
			max_j = i;
	}
	cout << ans << endl;
	for (int i = 0; i < rec[max_j].size(); i++) {
		cout << rec[max_j][i];
		if (i != rec[max_j].size())
			cout << ' ';
	}
	return 0;
}
