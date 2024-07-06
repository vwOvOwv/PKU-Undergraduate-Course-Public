#include<iostream>
#include<vector>
#include<iomanip>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>

using namespace std;

double sum = 0;

int main() {
	double a;
	while (cin >> a)
		sum += a;
	cout << '$' << fixed << setprecision(2) << sum / 12 << endl;
	return 0;
}
