/*
n������24,����������Ҫ���㣬����������Ľ��
��ʣ���������͹�����n-1������24������
*/
#include<iostream>
#include<cmath>
using namespace std;
#define EPS 1e-6
bool is_zero(double x){//�������ȴ�С������==
	return fabs(x)<=EPS;
}
bool count24(double a[],int n){//��a�е�n������24
	if(n==1){//��������Ҫ���ϣ�������ֻʣ��1����
		if(is_zero(a[0]-24))
			return true;
		else
			return false;
	}
	double b[5];
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){//ö���������������
			int m=0;
			for(int k=0;k<n;k++){
				if(k!=i&&k!=j){
					b[m]=a[k];
					m++;
				}
			}
			b[m]=a[i]+a[j];
			if(count24(b,m+1))//m+1=n-1
				return true;
			b[m]=a[i]-a[j];
			if(count24(b,m+1))
				return true;
			b[m]=a[j]-a[i];
			if(count24(b,m+1))
				return true;
			b[m]=a[i]*a[j];
			if(count24(b,m+1))
				return true;
			if(!is_zero(a[i])){//ע���ж�
				b[m]=a[j]/a[i];
				if(count24(b,m+1))
					return true;
			}
			if(!is_zero(a[j])){
				b[m]=a[i]/a[j];
				if(count24(b,m+1))
					return true;
			}
		}
	}
	return false;
}
int main()
{
	double a[5];
	for(int i=0;i<4;i++)
		cin>>a[i];
	if(count24(a,4))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}

