#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main()
{
	int n,m;
	int* p;
	cin>>n>>m;
	p=new int[n];
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	sort(p,p+n);//���ֲ��������������㷨
	//�ⷨһ
	int i;
	for(i=0;i<n;i++){
		if(binary_search(p+i+1,p+n,m-p[i])){//��ÿһ��p[i]�����ֲ���m-p[i](֮ǰ���Ѿ����ҹ���)
			cout<<p[i]<<' '<<m-p[i]<<endl;
			break;
		}
	}
	if(i==n)
		cout<<"none"<<endl;
	//�ⷨ��
	i=0;
	int j=n-1;
	while(p[i]+p[j]!=m){
		if(p[i]+p[j]>m){
			j--;//p[j]����
		}
		else
			i++;//p[i]С��
		if(i>=j)//û�ҵ�
			break;
	}
	if(i>=j)
		cout<<"none"<<endl;
	else
		cout<<p[i]<<' '<<p[j]<<endl;
	return 0;
}
