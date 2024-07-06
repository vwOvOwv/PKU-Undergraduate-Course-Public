#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
#include<vector>

using namespace std;

int n, k;
long long int f[210][15];//f[i][j]表示将i划分为j份的分法数目,i>=j
/*
* 本题与分苹果相似但仍有不同
对于每一个i,j都可以将情况划分为包含1的和不包含1的
f[i][j]=f[i-j][j] + f[i-1][j-1]
         不包含1       包含1
f[i][1]=1;
*/

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		f[i][1] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= i && j <= k; j++) {//注意j的范围
			f[i][j] = f[i - j][j] + f[i - 1][j - 1];
		}
	}
	cout << f[n][k];
	return 0;
}
