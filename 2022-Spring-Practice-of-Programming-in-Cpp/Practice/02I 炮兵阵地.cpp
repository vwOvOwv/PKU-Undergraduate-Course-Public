//�����״ѹdp���⣬�������ö������
//Ԥ�����ǹؼ�
//�������ݽ��������Ż�����AC
//�����ù��������Ż���dp[110][1 << 10][1 << 10]->dp[2][1<<10][1<<10],dp[0]��¼ǰһ�㣬dp[1]��¼����
#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
#include<vector>
#include<queue>

using namespace std;

int n, m;
int dp[2][1 << 10][1 << 10];//dp[i][j][k]��ʾ��i��״̬Ϊj��i-1��״̬Ϊkʱ���ڷŵ��ڱ���
int map[110];//�����Ƶ�ͼ
vector<int>pre[1 << 10];//Ԥ����ÿ�п��еİڷ�״̬
vector<int>state;//��¼���п��ܵ�״̬(ֻҪ���п��м��������ܵ�״̬)
int cnt[1 << 10];//��¼ÿ��״̬���ڱ���
string s;//������ַ���
int count(int a) {
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		if (a & (1 << i))
			ans++;
	}
	return ans;
}
bool check(int a) {//����Ƿ��ڱ��г�ͻ
	for (int i = 0; i < m; i++)
		if (a & (a << 1) || a & (a << 2))
			return false;
	return true;
}
int main()
{
	int ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'H') {
				map[i] |= (1 << j);
			}
		}
	}
	//��¼���п���״̬
	for (int i = 0; i < 1 << m; i++) {
		if (check(i)) {
			state.push_back(i);
			cnt[i] = count(i);
		}
	}
	//Ԥ������ת�Ƶ�״̬i������״̬
	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state.size(); j++) {
			if (!(state[i] & state[j]))
				pre[state[i]].push_back(state[j]);
		}
	}
	for (int i = 1; i <= n + 2; i++) {//ö��ÿһ�㣬ע�����ڵ�i�����i-1,i-2����أ���iҪ��n+2
		for (auto i_state : state) {//ö�ٵ�i�㣬�ø��跶Χ��forѭ�����Դ���д��
			if(!(i_state&map[i]))//�Ϸ�
				for(auto j_state:pre[i_state])
					if(!(j_state&map[i-1]))
						for(auto k_state:pre[j_state])
							if ((i >= 2 && !(k_state & map[i - 2])) || (i < 2)) {
								if (!(i_state & k_state))
									dp[i&1][i_state][j_state] = max(dp[i&1][i_state][j_state], dp[i - 1&1][j_state][k_state] + cnt[i_state]);//ȡһ������
							}
		}
	}
	cout << dp[n + 2&1][0][0] << endl;//ע����Ϊmap[i+1]=map[i+2]=0,���Գ���һ���ڱ�������(0)û�кϷ�״̬��
	return 0;
}
