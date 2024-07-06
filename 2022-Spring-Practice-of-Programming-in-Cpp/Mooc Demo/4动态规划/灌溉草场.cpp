#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int INFINITE = 1 << 31;
const int MAXL = 100000;
const int MAXN = 1010;
int F[MAXL];
int cowThere[MAXL];
int N, L, A, B;
struct Fx
{
	int x;
	int f;
	bool operator<(const Fx& a)const {
		return f > a.f;
	}
	Fx(int xx = 0, int ff = 0):x(xx),f(ff){}
};
priority_queue<Fx>qFx;
int main()
{
	cin >> N >> L;
	cin >> A >> B;//��A,B�Ķ����Ϊ���ǵ�ֱ��
	A *= 2; B *= 2;
	memset(cowThere, 0, sizeof(cowThere));
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		++cowThere[s + 1];//��s+1�����һ����ţ��
		--cowThere[e];//��e���˳�һ����ţ��
	}
	int inCows = 0;//��ʾ��ǰ��λ�ڶ���ͷ��ţ�Ļ��Χ֮��
	for (int i = 0; i <= L; i++) {//���ÿ�����Ƿ�����ţ
		F[i] = INFINITE;
		inCows += cowThere[i];
		if (inCows > 0)
			cowThere[i] += inCows;
	}
	for (int i = A; i <= B; i++) {//��ʼ������
		if (!cowThere[i]) {
			F[i] = 1;
			if (i <= B + 2 - A)//����F[i]ʱ��Ҫȷ��������ĵ�x,x<=i-A
				qFx.push(Fx(i, 1));
		}
	}
	for (int i = B + 2; i <= L; i += 2) {
		if (!cowThere[i]) {
			Fx fx;
			while (!qFx.empty()) {
				fx = qFx.top();
				if (fx.x < i - B)
					qFx.pop();
				else
					break;
			}
			if (!qFx.empty())
				F[i] = fx.f + 1;
		}
		if (F[i - A + 2] != INFINITE)
			qFx.push(Fx(i - A + 2, F[i - A + 2]));
	}
	if (F[L] == INFINITE)
		cout << -1 << endl;
	else
		cout << F[L];
	return 0;
}
