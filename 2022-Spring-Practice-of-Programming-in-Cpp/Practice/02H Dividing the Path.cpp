#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

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
struct Fx
{
	int x, f;
	bool operator<(const Fx& a)const {
		return f > a.f;//fԽС���ȼ�Խ��
	}
	Fx(int xx, int ff) :x(xx), f(ff) {}
	Fx() {}
};
priority_queue<Fx>qFx;
int main()
{
	cin >> n >> l >> a >> b;
	for (int i = 1; i <= n; i++) {
		cin >> s >> e;
		++flag[s + 1];
		--flag[e];
	}
	int inCow = 0;//��ǰ��λ�ڶ���ͷ��ţ�Ļ��Χ֮��
	for (int i = 0; i <= l; i++) {//���ÿ�����Ƿ�����ţ
		f[i] = 1 << 30;
		inCow += flag[i];
		flag[i] = inCow > 0;
	}
	for (int i = 2 * a; i <= 2 * b; i += 2) {
		if (!flag[i]) {
			f[i] = 1;
			if (i <= 2 * b + 2 - 2 * a)
				qFx.push(Fx(i, 1));
		}
	}//���Ƴ�ʼ��
	for (int i = 2 * b + 2; i <= l; i += 2) {//O(nlog(n))
		if (!flag[i]) {//������ţ������
			Fx fx;
			while (!qFx.empty()) {
				fx = qFx.top();
				if (fx.x < i - 2 * b)//�Ե�������
					qFx.pop();
				else
					break;
			}
			if (!qFx.empty())//�ҵ��˺��ʵ�fx
				f[i] = fx.f + 1;
		}
		if (f[i - 2 * a + 2] != 1 << 30)//Ϊ��һ��������׼��
			qFx.push(Fx(i - 2 * a + 2, f[i - 2 * a + 2]));
	}
	if (f[l] == 1 << 30)
		cout << -1 << endl;
	else
		cout << f[l] << endl;
	return 0;
}
