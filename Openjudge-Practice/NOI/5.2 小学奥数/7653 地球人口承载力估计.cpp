#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int x, a, y, b;
	cin >> x >> a >> y >> b;
	cout << fixed << setprecision(2) << ((a * x - b * y) * 1.0) / (a - b) << endl;
	return 0;
}
