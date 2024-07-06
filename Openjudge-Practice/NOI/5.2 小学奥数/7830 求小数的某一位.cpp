#include<iostream>
#include<cmath>
#include<iomanip>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;
int a, b, n;
int main()
{
	cin >> a >> b >> n;
	int tmp;
	for (int i = 0; i <= n; i++) {//Ä£ÄâÁÐÊúÊ½
		tmp = a / b;
		a %= b;
		a *= 10;
	}
	cout << tmp;
	return 0;
}
