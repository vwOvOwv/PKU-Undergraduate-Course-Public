//����ݹ��Ͷ�̬�滮
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 101
int D[MAX][MAX];
int n;
int maxSum[MAX][MAX];
int MaxSum(int i, int j) {
	if (maxSum[i][j] != -1)
		return maxSum[i][j];
	if (i == n) {//�߽�����
		maxSum[i][j] = D[i][j];
		return maxSum[i][j];
	}
	else {
		int x = MaxSum(i + 1, j);
		int y = MaxSum(i + 1, j + 1);
		maxSum[i][j] = max(x, y) + D[i][j];//�ݹ鷽��
		return maxSum[i][j];
	}
}
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= i; j++) {
			cin >> D[i][j];
			maxSum[i][j] = -1;//��ʼ������Ҫ
		}
	cout << MaxSum(1, 1) << endl;
}
