#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
int t, n, a[210];
int f[210][210];//dp[i][j]��ʾ��a[i]��a[j]�ָܷ�����������ݶεĸ���
/*
����dp���⣬���ö�����䳤�ȣ��ڲ�ö����㣬ע������볤�ȵĹ�ϵ�Ӷ��õ��յ�
������Ӧ�������i���յ�j֮����a[k]=a[j]�ĵ㣬Ȼ����м�Ĳ�������
ʣ�µ�a[j]��ǰ���a[i]->a[k]�ϲ�����һ�����������ݶ�����Ϊdp[i][k]
for(int len=2;len<=n;len++){
	for(int i=1;i+len-1<=n;i++){//���
		int j=i+len-1;//�յ�
		for(int k=i;k<=j;k++){
			if(a[k]==a[j])
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j-1]);
			else
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
		}
	}
}
*/

int main() {
	cin >> t;
	for (int x = 1; x <= t; x++) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				f[i][j] = 1 << 30;
			}
		}
		for (int i = 1; i <= n; i++)
			f[i][i] = 1;
		for (int len = 2; len <= n; len++) {
			for (int i = 1; i + len - 1 <= n; i++) {
				int j = i + len - 1;
				for (int k = i; k <= j; k++) {
					if (a[k] == a[j])
						f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j - 1]);
					else
						f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
				}
			}
		}
		cout << "Case " << x << ": " << f[1][n] << endl;
	}
	return 0;
}

