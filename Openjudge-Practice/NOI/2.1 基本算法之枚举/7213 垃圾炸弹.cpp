#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int d,n,x,y,i;
	int mem_trash[21]={0};//��¼��������
	int mem_x[21]={0};//��¼����λ��
	int mem_y[21]={0};//��¼����λ��
	vector<int>checked_x;
	vector<int>checked_y;
	cin>>d>>n;
	for(int k=0;k<n;k++){
		cin>>x>>y>>i;
		mem_trash[k]=i;
		mem_x[k]=x;
		mem_y[k]=y;
	}
	int cnt_trash,cnt_point=0;
	int max_cnt_trash=0;
	for(int j=0;j<n;j++){//ը���ض�ҪͶ����������������λ��
		for(int h=mem_x[j]-d;h<=mem_x[j]+d;h++){
			for(int l=mem_y[j]-d;l<=mem_y[j]+d;l++){
				cnt_trash=0;
				bool flag=false;
				if(h>=0&&h<1025&&l<1025&&l>=0){
					for(int r=0;r<checked_x.size();r++){//����Ƿ��Ѿ��ƹ���
						if(checked_x[r]==h&&checked_y[r]==l){
							flag=true;
							break;
						}
					}
					if(flag)
						continue;
					checked_x.push_back(h);
					checked_y.push_back(l);
					for(int r=0;r<n;r++){
						if(mem_x[r]>=h-d&&mem_x[r]<=h+d&&mem_y[r]>=l-d&&mem_y[r]<=l+d){//ͳ�ƿ���������������Ŀ
							cnt_trash+=mem_trash[r];
						}
					}
					if(cnt_trash>max_cnt_trash){
						max_cnt_trash=cnt_trash;
						cnt_point=1;//���ֵ�Ѿ����ˣ�Ҫ����Ͷ�ŵ���Ŀ
					}
					else if(cnt_trash!=0&&cnt_trash==max_cnt_trash){
						cnt_point++;
					}
				}
			}
		}
	}
	cout<<cnt_point<<' '<<max_cnt_trash<<endl;
	return 0;
}
