#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int f[1000010];//f[i]��ʾ����[0,i]��������ˮͷ����
/*
i��������������
1.i��ż��(��ˮ�뾶�������Ҳ��ܳ�����Χ��i������ʱ�޽�)
2.iλ�ò�������ţ��i?(S,E)(���Ե���S,E)(i��������ˮͷ���紦����Ȼ��������ˮͷ��������)
3.i>=2*A
4.��i>2*Bʱ������j��[i-2*B,i-2*A]��j������������������ʹ��f[i]=f[j]+1
  (�絽i������ˮͷ����˿����絽�ķ�Χ��[i-2*B,i-2*A])
5.f[i]=1:2*A<=i<=2*B
*/
int n, l, a, b;
int s,e;
int flag[1000010];
int main()
{
	cin >> n >> l >> a >> b;
	for (int i = 1; i <= n; i++) {
		cin >> s >> e;
		for (int i = s + 1; i < e; i++)
			flag[i] = 1;
	}
	if (l % 2 || l < 2 * a || flag[l]) {
		cout << "-1" << endl;
		return 0;
	}
	for (int i = 1; i <= l; i++) {
		if (i % 2||i<2*a||flag[i])
			f[i] = 1 << 30;
		else if (i >= 2 * a && i <= 2 * b)
			f[i] = 1;
		else {
			int mini = 1 << 30;
			for (int j = i - 2 * b; j <= i - 2 * a; j++) {
				mini = min(mini, f[j]);
				f[i] = mini + 1;
			}
		}
	}
	/*���Ӷ�ΪO(1000000*1000),tle
	������������ֵ����Сֵ����ʹ�����ȼ������Ż�(priority_queue)
	*/
	cout << f[l] << endl;
	return 0;
}
