#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int t, n, m;
int a[110];

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		a[n + 1] = 101;
		int num = min(n, m);
		int ans = 0;
		for (int i = 0; i <= num; i++) {//ö�ٲ�������
			for (int j = 1; j + i - 1 <= n; j++) {//ö��ʩ����Χ
				ans = max(ans, a[j + i] - a[j - 1] - 1);//��һ���㽶λ��-ǰһ���㽶λ��-1
			}
		}
		cout << ans << endl;
	}
	return 0;
}
