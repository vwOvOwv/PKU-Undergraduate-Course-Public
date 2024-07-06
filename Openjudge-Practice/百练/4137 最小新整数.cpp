#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>

using namespace std;
//贪心，只要前一位比后一位大就把前一位删掉，如果没有这样的关系（如12345这种递增的）就删最后一位
//重点在于如何实现删数操作
int main() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		string s, ans;
		cin >> s >> k;
		int size = s.size();
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < size-1; j++) {
				if (s[j] > s[j + 1]) {
					for (int l = j; l < size - 1; l++)
						s[l] = s[l + 1];
					break;
				}
			}
			size--;
		}
		for (int i = 0; i < size; i++)
			cout << s[i];
		cout << endl;
	}
	return 0;
}
