#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
stack<double>num;
vector<string>v;
int main()
{
	string s;
	while (cin >> s) {
		v.push_back(s);
	}
	for (int i = v.size() - 1; i >= 0; i--) {//从后向前扫描
		if (v[i][0] >= '0' && v[i][0] <= '9')
			num.push(atof(v[i].c_str()));
		else {
			double n1 = num.top();
			num.pop();
			double n2 = num.top();
			num.pop();
			if (v[i] == "+") {
				num.push(n1 + n2);
			}
			if (v[i] == "-") {
				num.push(n1 - n2);
			}
			if (v[i] == "*") {
				num.push(n1 * n2);
			}
			if (v[i] == "/") {
				num.push(n1 / n2);
			}
		}
	}
	cout << fixed << setprecision(6) << num.top() << endl;
	return 0;
}
