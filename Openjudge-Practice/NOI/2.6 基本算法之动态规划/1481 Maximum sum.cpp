//����һ������Ӷκ͵��������⣬
//˼·�Ǵ������Һʹ�������ֱ���һ����a[j]Ϊ�յ������Ӷκͣ��ҳ����е����ֵ����
/*���������Ӷκͣ�
��b[j]����jΪ�յ㣨��ζ���Ӷ�����Ϊj���������Ӷεĺ͵����ֵ��
��˱����������еõ���b[i]�����ֵ��Ϊ����Ӷκ�
����j���ԣ��Ӷ�����Ϊa[j]���������������Ӵ�������b[j]=max(b[j-1]+a[j],a[j])

*/
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<climits>
#include<cstring>
using namespace std;
int t, n;
int a[50010] = { 0 };
int b1[50010] = { 0 };//��������
int b2[50010] = { 0 };//��������
int ans1[50010] = { 0 };//��¼ÿһ��λ�����������Ӷκ͵����ֵ
int ans2[50010] = { 0 };//��¼ÿһ��λ���Ҳ�������Ӷκ͵����ֵ
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
