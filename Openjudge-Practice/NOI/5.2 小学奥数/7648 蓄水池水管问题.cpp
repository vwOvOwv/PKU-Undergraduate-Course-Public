#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int vec[4] = { b * c * d,-1 * a * c * d, a * b * d,-1 * a * b * c };
	int cnt = 0;
	int v = 0;
	while (1) {
		v += vec[cnt % 4];
		cnt++;
		if (v >= a * b * c * d) {
			cnt--;
			v -= vec[cnt % 4];
			break;
		}
	}
	int t = a * b * c * d - v;
	double ans = cnt + (t * 1.0) / vec[cnt % 4];
	cout << fixed << setprecision(2) << ans << endl;
	return 0;
}
