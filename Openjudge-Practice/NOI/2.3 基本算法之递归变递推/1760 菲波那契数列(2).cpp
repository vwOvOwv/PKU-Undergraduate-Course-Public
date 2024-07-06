#include<iostream>
#include<vector>
using namespace std;
vector<int>mem(1000010,-1);
int main()
{
	mem[1] = 1;
	mem[2] = 1;
	for (int i = 3; i <= 1000000; i++)
		mem[i] = (mem[i - 1] + mem[i - 2]) % 1000;
	int t;
	cin >> t;
	while (t--) {
		int a;
		cin >> a;
		cout << mem[a] << endl;
	}
	return 0;
}

