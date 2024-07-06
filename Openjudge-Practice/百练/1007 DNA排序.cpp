#include<iostream>
#include<vector>
#include<iomanip>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>

using namespace std;

int n, m;
multimap<int, string>rec;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		string s;
		cin >> s;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (s[i] > s[j])
					cnt++;
			}
		}
		rec.insert(make_pair(cnt, s));
	}
	for (auto dna : rec) {
		cout << dna.second << endl;
	}
	return 0;
}
