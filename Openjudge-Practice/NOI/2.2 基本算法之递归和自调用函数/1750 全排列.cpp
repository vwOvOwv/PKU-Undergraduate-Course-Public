#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
void permutation(char s[], int start, int end) {

	if (start == end) {
		cout << s << endl;
		return;
	}
	//sort(s + start, s + end); ���ˣ��������ܱ�֤�����ʱ���Ѿ����к�˳��
	for (int i = start; i < end; i++) {
		swap(s[start], s[i]);
		char tmp[10];
		strcpy(tmp, s);
		sort(tmp + start + 1, tmp + end);//����ֱ��sort s,�����ı���s,�Ӷ������޷��ָ�s״̬��
		permutation(tmp, start + 1, end);//�����s���βΣ�����ԭ����s��ʵû��
		swap(s[start], s[i]);//Ҫ�ָ�ԭ��s��״̬
	}
}
int main()
{
	char s[10];
	cin >> s;
	int i;
	for (i = 0; s[i] != '\0'; i++);
	permutation(s, 0, i);
	return 0;
}
