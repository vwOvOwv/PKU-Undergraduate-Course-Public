/*
��i��ƻ������k��������ķŷ�������f(i,k),��
k>iʱ,f(i,k)=f(i,i��
k<=iʱ���ܷŷ�=������Ϊ�յķŷ�+û����Ϊ�յ�����
f(i,k)=f(i,k-1)��������һ��Ϊ�գ�+f(i-k,k)������һ��Ҫ����ÿ���������һ��ƻ����
*/
#include<iostream>
using namespace std;
int f(int m,int n){//m��ƻ��n������
	if(n>m){
		return f(m,m);
	}//֮��n<=m
	if(m==0)
		return 1;//û��ƻ���������ӣ�����ƻ������Ҳ��һ�ַŷ���
	if(n==0)
		return 0;
	return f(m,n-1)+f(m-n,n);//m-n�Ǹ�
}
int main()
{
	int t,m,n;
	cin>>t;
	while(t--){
		cin>>m>>n;
		cout<<f(m,n)<<endl;
	}
	return 0;
}
