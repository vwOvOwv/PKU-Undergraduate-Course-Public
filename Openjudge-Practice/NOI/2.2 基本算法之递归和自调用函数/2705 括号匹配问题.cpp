#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<pair<char, int> >st;
void solve(string s) {
	cout << s << endl;
	string ans = s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')
			st.push(make_pair('(', i));
		else if (s[i] == ')') {
			if (!st.empty()) {
				ans[st.top().second] = ' ';
				ans[i] = ' ';
				st.pop();
			}
			else
				ans[i] = '?';
		}
		else
			ans[i] = ' ';
	}
	while (!st.empty()) {
		ans[st.top().second] = '$';
		st.pop();
	}
	cout << ans << endl;
}
int main()
{
	string s;
	while (cin >> s)
		solve(s);
	return 0;
}
