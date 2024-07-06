#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int fz = 0;
	int fm = 1;
	if(n<=30)
		for (int i = 1; i <= n; i++) {
			fz = fz * 2 + 1;
			fm *= 2;
		}
	else
		for (int i = 1; i <= 30; i++) {
			fz = fz * 2 + 1;
			fm *= 2;
		}
	cout << fixed<<setprecision(5)<<(fz * 1.0) / fm;
	return 0;
}
