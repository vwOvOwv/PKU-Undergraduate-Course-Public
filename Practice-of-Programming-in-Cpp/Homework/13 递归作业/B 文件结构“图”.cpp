#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define _tab  "|     "
using namespace std;
vector<string>v;//���������ļ���Ŀ¼��
vector<string>layer_0;//�����Ŀ¼�µ��ļ���������������
int start = 0;//��¼��ʼλ��
void output(vector<string>v,int layer) {//�����ʽ����
	int cnt = 0;
	sort(v.begin(), v.end());//ע���ļ����������
	for (int i = 0; i < v.size(); i++) {
		for (int i = 0; i < layer; i++)
			cout << _tab;
		cout << v[i] << endl;
	}
}
void f(int layer) {
	vector<string>tmp;
	for (int i = start; i < v.size(); i++) {
		if (v[i][0] == 'f')
		{
			if (layer > 0)
				tmp.push_back(v[i]);
			else
				layer_0.push_back(v[i]);
		}
		else if (v[i][0] == 'd') {
			for (int i = 0; i < layer + 1; i++)
				cout << _tab;
			cout << v[i] << endl;
			start = i + 1;//�ӵ�ǰ�ַ�������һ����ʼ
			f(layer + 1);
			i = start - 1;//ע������Ҫ��-1����Ϊ��i++
		}
		else if (v[i][0] == ']') {
			output(tmp, layer);
			tmp.clear();//  ��յ�ǰ���tmp����ʵ���п���
			start = i + 1;//�����Ѿ���¼����
			return;
		}
	}
	output(layer_0, 0);//��������Ŀ¼�µ��ļ�
}
int main()
{
	string s;
	int cnt = 0;
	while (1) {
		cin >> s;
		if (s[0]=='*') {
			cnt++;
			cout << "DATA SET " << cnt << ':' << endl;
			cout << "ROOT" << endl;
			f(0);
			start = 0;
			v.clear();
			layer_0.clear();//����ȫ�ֱ���
			cout << endl;//ע��
		}
		else if (s[0] == '#') {
			break;
		}
		else {
			v.push_back(s);
		}
	}
	return 0;
}
