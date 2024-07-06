#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int t;
string s;
int f[1010];//f[i]表示把前i个字符切成回文串的最少切割数
/*考虑从j到i的字符串，若s[j, i]已经是一个回文串了则可以不切，
只用先切出s[j,i]再把s[1, j - 1]切成回文串,因此f[i]=min{f[i],f[j-1]+1},j<=i
*/
bool check(string s) {
	int head = 0, tail = s.size() - 1;
	while (head <= tail) {//注意算法效率
		if (s[head] != s[tail])
			return false;
		else {
			head++;
			tail--;
		}
	}
	return true;
}
int main()
{
	cin >> t;
	while (t--) {
		memset(f, 0, sizeof(f));
		f[0] = -1;//重要的！考虑f[j-1]+1,当j=1
		f[1] = 0;
		s.clear();
		s.push_back(' ');
		string tmp;
		cin >> tmp;
		s += tmp;
		int n = s.size();
		for (int i = 2; i <= n; i++)
			f[i] = 1 << 30;//初始化成极大值
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				if (check(s.substr(j, i - j + 1)))
					f[i] = min(f[i], f[j - 1] + 1);
			}
		}
		cout << f[n] << endl;
	}
	return 0;
}
