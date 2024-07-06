#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int target;
string s;
int main()
{
	while (cin >> target >> s) {
		if (target == 0 && s == "END")
			break;
		bool flag = false;
		sort(s.begin(), s.end(), greater<char>());//逆序从而保证首个解字典序最大
		for (int i1 = 0; i1 < s.size(); i1++) {
			for (int i2 = 0; i2 < s.size(); i2++) {
				if (i1 == i2)
					continue;
				for (int i3 = 0; i3 < s.size(); i3++) {
					if (i1 == i3 || i2 == i3)
						continue;
					for (int i4 = 0; i4 < s.size(); i4++) {
						if (i1 == i4 || i2 == i4 || i3 == i4)
							continue;
						for (int i5 = 0; i5 < s.size(); i5++) {
							if (i1 == i5 || i2 == i5 || i3 == i5 || i4 == i5)
								continue;
							int a1 = s[i1] - 'A' + 1,
								a2 = s[i2] - 'A' + 1,
								a3 = s[i3] - 'A' + 1,
								a4 = s[i4] - 'A' + 1,
								a5 = s[i5] - 'A' + 1;
							if (a1 - a2 * a2 + a3 * a3 * a3 - a4 * a4 * a4 * a4 + a5 * a5 * a5 * a5 * a5 == target) {
								cout << s[i1] << s[i2] << s[i3] << s[i4] << s[i5] << endl;
								flag = true;
								i1 = i2 = i3 = i4 = i5 = s.size();
								break;
							}
						}
					}
				}
			}
		}
		if (!flag)
			cout << "no solution" << endl;
	}
	return 0;
}
