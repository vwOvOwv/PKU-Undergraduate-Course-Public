//需要复写
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<climits>
using namespace std;

int target;
string input;
bool flag;
int cnt, maxi;
vector<string>ans;
vector<string>rec;
void dfs(string s, int now, vector<string>rec) {
	if (now > target)
		return;
	int tmp = atoi(s.c_str()) + now;
	if (tmp <= target) {
		flag = true;
		if (tmp > maxi) {
			cnt = 1;
			ans.clear();
			maxi = tmp;
			for (int i = 0; i < rec.size(); i++) {
					ans.push_back(rec[i]);
			}
			ans.push_back(s);
		}
		else if (tmp == maxi) {
			cnt++;
			/*vector<string>tmpans;
			for (int i = 0; i < rec.size(); i++) {
				tmpans.push_back(rec[i]);
			}
			tmpans.push_back(s);
			if (tmpans.size() != ans.size())
				cnt++;
			else {
				for (int i = 0; i < ans.size(); i++) {
					if (tmpans[i] != ans[i]) {
						cnt++;
						break;
					}
				}
			}*/
			/*for (int i = 0; i < tmpans.size(); i++)
				cout << tmpans[i] << ' ';
			cout << endl;
			for (int i = 0; i < ans.size(); i++)
				cout << ans[i] << ' ';
			cout << endl;*/
		}

	}
	if (s.size() == 1)
		return;
	//递归枚举所有切割方式
	for (int i = 0; i < s.size() - 1; i++) {//注意这里i不能取最后一个数！！！否则会出现重复情况！！！如"927468"与"null"&"null"与"927468"
		int t = atoi(s.substr(0, i + 1).c_str());
		rec.push_back(s.substr(0, i + 1));
		dfs(s.substr(i + 1, s.size() - i - 1), now + t, rec);//i=s.size()-1时这里传入了一个空串
		rec.erase(--rec.end());//回溯
	}
}

int main()
{
	while (cin >> target >> input) {
		if (target == 0 && input == "0")
			break;
		flag = false;
		maxi = INT_MIN;
		cnt = 0;
		rec.clear();
		ans.clear();
		dfs(input, 0, rec);
		if (flag) {
			if (cnt > 1) {
				//cout << maxi << ' ';
				cout << "rejected" << endl;
			}
			else {
				cout << maxi << ' ';
				for (int i = 0; i < ans.size(); i++) {
					cout << ans[i];
					if (i != ans.size() - 1)
						cout << ' ';
				}
				cout << endl;
			}
		}
		else {
			cout << "error" << endl;
		}
	}
	return 0;
}
