#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>

using namespace std;
//̰�ģ�ֻҪǰһλ�Ⱥ�һλ��Ͱ�ǰһλɾ�������û�������Ĺ�ϵ����12345���ֵ����ģ���ɾ���һλ
//�ص��������ʵ��ɾ������
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
