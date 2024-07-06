#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int d,n,x,y,i;
	int mem_trash[21]={0};//记录垃圾数量
	int mem_x[21]={0};//记录垃圾位置
	int mem_y[21]={0};//记录垃圾位置
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
	for(int j=0;j<n;j++){//炸弹必定要投放在能清理到垃圾的位置
		for(int h=mem_x[j]-d;h<=mem_x[j]+d;h++){
			for(int l=mem_y[j]-d;l<=mem_y[j]+d;l++){
				cnt_trash=0;
				bool flag=false;
				if(h>=0&&h<1025&&l<1025&&l>=0){
					for(int r=0;r<checked_x.size();r++){//检查是否已经计过数
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
						if(mem_x[r]>=h-d&&mem_x[r]<=h+d&&mem_y[r]>=l-d&&mem_y[r]<=l+d){//统计可以清理到的垃圾数目
							cnt_trash+=mem_trash[r];
						}
					}
					if(cnt_trash>max_cnt_trash){
						max_cnt_trash=cnt_trash;
						cnt_point=1;//最大值已经变了，要重置投放点数目
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
