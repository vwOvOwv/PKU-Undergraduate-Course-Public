#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int t;
string s;
int f[1010];//f[i]��ʾ��ǰi���ַ��гɻ��Ĵ��������и���
/*���Ǵ�j��i���ַ�������s[j, i]�Ѿ���һ�����Ĵ�������Բ��У�
ֻ�����г�s[j,i]�ٰ�s[1, j - 1]�гɻ��Ĵ�,���f[i]=min{f[i],f[j-1]+1},j<=i
*/
bool check(string s) {
	int head = 0, tail = s.size() - 1;
	while (head <= tail) {//ע���㷨Ч��
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
		f[0] = -1;//��Ҫ�ģ�����f[j-1]+1,��j=1
		f[1] = 0;
		s.clear();
		s.push_back(' ');
		string tmp;
		cin >> tmp;
		s += tmp;
		int n = s.size();
		for (int i = 2; i <= n; i++)
			f[i] = 1 << 30;//��ʼ���ɼ���ֵ
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
