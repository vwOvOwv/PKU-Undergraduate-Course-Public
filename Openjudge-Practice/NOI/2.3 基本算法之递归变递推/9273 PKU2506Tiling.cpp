//递推打表加高精度运算
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
char ans[251][121];
void cal(int n) {
	char t1[121] = { 0 };
	char t2[121] = { 0 };
	strcpy(t1, ans[n - 1]);
	strcpy(t2, ans[n - 2]);
	//ans[i]=ans[i-1]+2*ans[i-2];
	for (int i = 119; t2[i] != '-'; i--) {
		int tmp = (t2[i] - '0') * 2;
		t2[i] = tmp + '0';
	}
	for (int i = 119; t2[i] != '-'; i--) {
		if (t2[i] > '9') {
			t2[i] -= 10;
			if (t2[i - 1] == '-')
				t2[i - 1] = '0';
			t2[i - 1] += 1;
		}
	}
	for (int i = 119; t1[i] != '-' || t2[i] != '-'; i--) {
		if (t1[i] == '-')
			t1[i] = '0';
		if (t2[i] == '-')
			t2[i] = '0';
		int tmp = (t1[i] - '0') + (t2[i] - '0');
		ans[n][i] = tmp + '0';
	}
	for (int i = 119; t1[i] != '-' || t2[i] != '-'; i--) {
		if (ans[n][i] > '9') {
			ans[n][i] -= 10;
			if (ans[n][i - 1] == '-')
				ans[n][i - 1] = '0';
			ans[n][i - 1] += 1;
		}
	}
}
int main()
{
	memset(ans, '-', sizeof(ans));
	ans[0][119] = '1';
	ans[1][119] = '1';
	ans[2][119] = '3';
	for (int i = 0; i < 251; i++)
		ans[i][120] = '\0';
	for (int i = 3; i < 251; i++)
		cal(i);
	int n;
	while (cin >> n) {
		for (int i = 0; i < 120; i++) {
			if (ans[n][i] == '-')
				continue;
			else
				cout << ans[n][i];
		}
		cout << endl;
	}
	return 0;
}
