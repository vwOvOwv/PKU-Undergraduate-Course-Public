/*
����һ����׺���ʽ�ַ���s��ת��Ϊһ����׺���ʽ����postexp�������е�ÿһ��Ҫô��ʾһ����������Ҫô��ʾһ������������������ԶԱ��ʽ������ֵ��
����׺���ʽ�ͺ�׺���ʽ�У������������˳���ǲ���ģ�ֻ�ǲ�������λ�÷����˸ı䣬��ȥ�������ţ���ת���Ĺ����У���Ҫ��������������ȼ���ֻ����С���ź�+ - * / ���㣩��������ù�ϣ��ķ�ʽ������������ȼ�������ԽС�����ȼ�Խ�ߣ�������ͬ���ȼ���ͬ����������һ������ջ op ���������������������׺���ʽs��ת���������£�

1������ǰ���ַ������֣�����ͬ�����������������Ϊһ����������������ַ�������ʽ���뵽��׺���ʽ������postexp����Ϊһ�

2������ǰ�ַ��������š���������ֱ�ӽ���ѹ�������ջop�У�

3������ǰ�ַ��������š��������������ջ�е���������ŵ���׺���ʽ�����У�ÿ���������Ϊһ�ֱ������һ�������š����������������ų�ջ���������׺���ʽ��

4������ǰ�ַ�����������򽫴�ջ����ʼ���ȼ��ȵ�ǰ������߻�ͬ���ȼ������γ�ջ�������׺���ʽ�У�ֱ�� ջΪ�� | ջ���ַ�Ϊ������ | ջ����������ȼ��ȵ�ǰ������ͣ�Ȼ�󽫵�ǰ�����ѹջ��

5����������׺���ʽ֮�󣬽�ջ��ʣ�µ���������μ����׺���ʽĩβ��
*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;
string tran(string s) {
	stack<char>op;
	stack<char>num;
	string ans;
	int flag = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')
			op.push('(');
		else if (s[i] == '|' || s[i] == '&') {
			while (!op.empty()&&op.top()!='(') {
				ans += op.top();
				op.pop();
			}
			op.push(s[i]);

		}
		else if (s[i] == ')') {
			while (!op.empty() && op.top() != '(') {
				ans += op.top();
				op.pop();
			}
			op.pop();
		}
		else if (s[i] == '!')
			op.push('!');
		else if (s[i] == 'V' || s[i] == 'F') {
			if (ans.empty())
				ans = s[i];
			else
				ans += s[i];
		}
	}
	while (!op.empty()) {
		ans += op.top();
		op.pop();
	}
	return ans;
}
char cal(string s) {
	stack<bool>num;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'V')
			num.push(true);
		else if (s[i] == 'F')
			num.push(false);
		else if (s[i] == '|' || s[i] == '&') {
			bool t1 = num.top();
			num.pop();
			bool t2 = num.top();
			num.pop();
			if (s[i] == '|') {
				num.push(t1 || t2);
			}
			else {
				num.push(t1 && t2);
			}
		}
		else if (s[i] == '!') {
			bool t = num.top();
			num.pop();
			num.push(!t);
		}
	}
	if (num.top())
		return 'V';
	else
		return 'F';
}
int main()
{
	string s;
	int cnt = 0;
	while (getline(cin, s)) {
		cnt++;
		cout << "Expression " << cnt << ": ";
		string m = tran(s);
		cout << cal(m) << endl;
	}
	return 0;
}
