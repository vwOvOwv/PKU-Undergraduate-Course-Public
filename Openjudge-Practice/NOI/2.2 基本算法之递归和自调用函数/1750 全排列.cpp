#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
void permutation(char s[], int start, int end) {

	if (start == end) {
		cout << s << endl;
		return;
	}
	//sort(s + start, s + end); 错了，这样不能保证输出的时候已经排列好顺序
	for (int i = start; i < end; i++) {
		swap(s[start], s[i]);
		char tmp[10];
		strcpy(tmp, s);
		sort(tmp + start + 1, tmp + end);//不能直接sort s,这样改变了s,从而导致无法恢复s状态！
		permutation(tmp, start + 1, end);//传入的s是形参，所以原来的s其实没变
		swap(s[start], s[i]);//要恢复原来s的状态
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
