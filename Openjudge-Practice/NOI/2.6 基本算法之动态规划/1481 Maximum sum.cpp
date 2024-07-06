//这是一道最大子段和的延伸问题，
//思路是从左向右和从右向左分别求一边以a[j]为终点的最大子段和，找出其中的最大值即可
/*如何求最大子段和？
设b[j]是以j为终点（意味着子段至少为j）的所有子段的和的最大值，
因此遍历整个序列得到的b[i]的最大值即为最大子段和
对于j而言，子段至少为a[j]，考虑向左扩张子串，即有b[j]=max(b[j-1]+a[j],a[j])

*/
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<climits>
#include<cstring>
using namespace std;
int t, n;
int a[50010] = { 0 };
int b1[50010] = { 0 };//从左向右
int b2[50010] = { 0 };//从右向左
int ans1[50010] = { 0 };//记录每一个位置左侧的所有子段和的最大值
int ans2[50010] = { 0 };//记录每一个位置右侧的所有子段和的最大值
int ans = INT_MIN;
int main()
{
	scanf("%d", &t);
	while (t--) {
		ans = INT_MIN;
		memset(ans1, 0, sizeof(ans1));
		memset(ans2, 0, sizeof(ans2));
		memset(a, 0, sizeof(a));
		memset(b1, 0, sizeof(b1));
		memset(b2, 0, sizeof(b2));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		ans1[1] = a[1];
		b1[1] = a[1];
		ans2[n] = a[n];
		b2[n] = a[n];
		for (int i = 2; i <= n; i++) {
			b1[i] = max(b1[i - 1] + a[i], a[i]);
			ans1[i] = max(ans1[i - 1], b1[i]);
		}
		for (int i = n-1; i >= 1; i--) {
			b2[i] = max(b2[i + 1] + a[i], a[i]);
			ans2[i] = max(ans2[i + 1], b2[i]);
		}
		for (int i = 1; i < n; i++) {
			ans = max(ans, ans1[i] + ans2[i + 1]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
