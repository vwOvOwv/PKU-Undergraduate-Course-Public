#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
//�����Ͼ�������ǽ������г��ȣ�Ȼ������
int t;
string s;
int f[1010];//f[i]��ʾ��s[i]Ϊ�յ����ǽ������г���
int main()
{
	cin >> t;
	while (t--) {
		cin >> s;
		memset(f, 0, sizeof(f));
		for (int i = 0; i < s.length(); i++)
			f[i] = 1;
		for (int i = 1; i < s.length(); i++) {
			for (int j = 0; j < i; j++) {
				if (s[i] >= s[j])
					f[i] = max(f[i], f[j] + 1);
			}
		}
		cout << s.length() - *max_element(f,f+s.length()) << endl;
	}
	return 0;
}
