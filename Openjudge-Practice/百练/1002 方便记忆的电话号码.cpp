#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>

using namespace std;

int n;
map<string, int>rec;

string simplify(string s) {
	string ans;
	for (int i = 0; i < s.length(); i++) {
		if (ans.size() == 3)
			ans.push_back('-');
		if (s[i] >= '0' && s[i] <= '9')
			ans.push_back(s[i]);
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			switch (s[i])
			{
			case 'A':case 'B':case 'C':
				ans.push_back('2');
				break;
			case 'D':case 'E':case 'F':
				ans.push_back('3');
				break;
			case 'G':case 'H':case 'I':
				ans.push_back('4');
				break;
			case 'J':case 'K':case 'L':
				ans.push_back('5');
				break;
			case 'M':case 'N':case 'O':
				ans.push_back('6');
				break;
			case 'P':case 'R':case 'S':
				ans.push_back('7');
				break;
			case 'T':case 'U':case 'V':
				ans.push_back('8');
				break;
			case 'W':case 'X':case 'Y':
				ans.push_back('9');
				break;
			}
		}
	}
	return ans;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string ss;
		cin >> ss;
		string s = simplify(ss);
		if (rec.find(s) == rec.end())
			rec.insert(make_pair(s, 1));
		else
			rec[s]++;
	}
	bool f = 0;
	for (auto ans : rec) {
		if (ans.second >= 2) {
			f = 1;
			cout << ans.first << ' ' << ans.second << endl;
		}
	}
	if (!f)
		cout << "No duplicates." << endl;
	return 0;
}
