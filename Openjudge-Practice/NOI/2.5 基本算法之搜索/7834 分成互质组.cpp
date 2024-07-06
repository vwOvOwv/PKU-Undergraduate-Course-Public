#include<iostream>
#include<cmath>
#include<iomanip>
#include<climits>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n, a[20];
vector<vector<int> >flag;
int mini = INT_MAX;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;//�ݹ�շת������������
}
bool judge(int a,int b) {
	if (gcd(a, b) == 1)//����
		return true;
	else
		return false;
}
void dfs(int k,vector<vector<int> >flag) {
	if (k == n + 1) {//��������������
		if (flag.size() < mini)
			mini = flag.size();
		return;
	}
	int i, j;
	for (i = 0; i < flag.size(); i++) {
		for (j = 0; j < flag[i].size(); j++) {
			if (!judge(a[k], flag[i][j]))//������
				break;
		}
		if (j == flag[i].size()) {
			flag[i].push_back(a[k]);
			dfs(k + 1, flag);
			flag[i].erase(--flag[i].end());//ע��a[k]Ҳ���ܳ���������������Ҫ����
		}
	}
	flag.push_back(vector<int>(1, a[k]));//a[k]��������һ���µ�����
	dfs(k + 1, flag);
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	flag.push_back(vector<int>(1, a[1]));
	dfs(2, flag);
	cout << mini;
	return 0;
}
