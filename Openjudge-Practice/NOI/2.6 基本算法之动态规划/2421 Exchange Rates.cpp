#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;
int d;
double pre[375];
int f[375][2];//f[i][0]��ʾ��i�����ӵ�еļ�Ԫ��f[i][1]��ʾ��Ԫ

int main() {
	while (cin >> d && d) {
		for (int i = 1; i <= d; i++)
			cin >> pre[i];
		memset(f, 0, sizeof(f));
		f[0][0] = 0, f[0][1] = 100000;//���ƾ�ȷ��
		for (int i = 1; i <= d; i++) {
			f[i][0] = max(f[i - 1][0], int((f[i - 1][1] * 0.97) / pre[i]));
			f[i][1] = max(f[i - 1][1], int((f[i - 1][0] * 0.97) * pre[i]));
		}
		cout << fixed << setprecision(2) << (f[d][1] * 1.0) / 100 << endl;
	}
	return 0;
}
