//������һ��ݹ�ᳬʱ���ü��仯�ݹ���ߵ��ƴ�����
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>mem(1000010, -1);
int f(int n) {//��an%32767��an���ټ��죬long long intҲװ����
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (mem[n] != -1) {
		return mem[n];
	}
	else {
		mem[n] = (2 * f(n - 1) + f(n - 2)) % 32767;
		return mem[n];
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		cout << f(k) << endl;
	}
	return 0;
}
