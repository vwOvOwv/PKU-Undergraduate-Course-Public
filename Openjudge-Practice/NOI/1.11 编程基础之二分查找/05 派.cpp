#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

const double pi=acos(-1);
int main()
{
	int n,f;
	cin>>n>>f;
	int r[10010];
	for(int i=0;i<n;i++){
		cin>>r[i];
	}
	sort(r,r+n);//������
	double L=0;//ÿ������½�
	double R=pi*r[n-1]*r[n-1];//ÿ������Ͻ�
	double ans=0;//������,ע�ⲻҪ���ó�-1����Ϊ�ڼ������������������Ϊ0.0000000...
	             //��ʱ�޷������·���whileѭ����ansû�б��ı䣬�����-1.000������0.000
    while(R-L>1e-5){//��ȷ��Ҫ�ﵽҪ��
    	int pie_num=0;
    	double mid=L+(R-L)/2;//���ֲ���
    	for(int i=0;i<n;i++){
    		pie_num+=int(pi*r[i]*r[i]/mid);
    	}
    	if(pie_num<f+1){//���̫����
    		R=mid;
    	}
    	else{
    		if(mid>ans)//����㹻
				ans=mid;
    		L=mid;//�����Ƿ��и���ģ�ע����һ�������޷���ִ�У���ѭ��������Ҫ���ж�һ��
    	}
    }
	cout<<fixed<<setprecision(3)<<ans<<endl;
    return 0;
 }
