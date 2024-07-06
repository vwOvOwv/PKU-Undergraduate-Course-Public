//������������������е�������
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<cmath>
#include<climits>
#include<cstring>
#include<iomanip>
using namespace std;
#define maxn 1010
int n;
int maxlen_up[maxn];
int maxlen_down[maxn];
vector<int>pos;
int f(int k) {//��1��k�������������
	for (int i = 2; i <= k; i++) {
		for (int j = 1; j < i; j++) {
			if (pos[i] > pos[j]) {
				maxlen_up[i] = max(maxlen_up[j] + 1, maxlen_up[i]);
			}
		}
	}
	int ans = *max_element(maxlen_up + 1, maxlen_up + k);
	return ans;
}
int g(int k) {//��k��n����½�������
	for (int i = k + 1; i <= n; i++) {
		for (int j = k; j < i; j++) {
			if (pos[i] < pos[j]) {
				maxlen_down[i] = max(maxlen_down[j] + 1, maxlen_down[i]);
			}
		}
	}
	int ans = *max_element(maxlen_down + k, maxlen_down + n + 1);
	return ans;
}
int main()
{
	cin >> n;
	pos.push_back(-1);
	for (int i = 1; i <= n; i++) {
		int h;
		cin >> h;
		pos.push_back(h);
	}
	int maxi = INT_MIN;
	for (int i = 1; i <= n; i++) {//ö��"����"
		for (int j = 1; j <= n; j++) {//ע���������飨ò�Ʋ�����Ҳ�ɣ���
			maxlen_down[j] = 1;
			maxlen_up[j] = 1;
		}
		maxi = max(f(i) + g(i), maxi);
	}
	cout << maxi << endl;
	return 0;
}
