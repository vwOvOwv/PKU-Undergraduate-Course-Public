#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
int n;
int a[1010];
int f1[1010];//f1[i]��ʾ��iΪ�յ������������еĳ���
int f2[1010];//f2[i]��ʾ��iΪ������½������еĳ���
int ans[1010];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		//��ʼ��������
		f1[i] = 1;
		f2[i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j])
				f1[i] = max(f1[i], f1[j] + 1);
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = n; j > i; j--) {
			if (a[i] > a[j])
				f2[i] = max(f2[i], f2[j] + 1);
		}
	}
	for (int i = 1; i <= n; i++)
		ans[i] = f1[i] + f2[i] - 1;
	cout << *max_element(ans + 1, ans + n + 1);
	return 0;
}
