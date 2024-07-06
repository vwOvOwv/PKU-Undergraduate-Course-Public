#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
int l1, l2;
int s1[510], s2[510];
int f[510][510];//f[i][j]��ʾ��s1��ǰi��Ԫ����s2��ǰj��Ԫ����s2[j]��β����������������еĳ���
vector<vector<int>>rec(510);//rec[j]��¼��iΪĳȷ��ֵʱ��s1��ǰi��Ԫ����s2��ǰj��Ԫ����s2[j]��β�������������
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
				rec[j].clear();//һ��Ҫ�У�����i,j������rec[j].size()��Ȼ�ǵ����ģ���˿������
				for (int k = 1; k < j; k++) {//ö�ٽ���s2����һ��λ�ú���
					if (s2[k]<s2[j] && f[i - 1][k] + 1>f[i][j]) {
						f[i][j] = f[i - 1][k] + 1;
						rec[j] = rec[k];
					}
				}
				rec[j].push_back(s2[j]);
			}
			else//ѡ����
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
