#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main()
{
	int l,n,m;
	cin>>l>>n>>m;
	vector<int>v(n+2);
	v[0]=0;v[n+1]=l;//起点和终点
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	int L=0,R=l;//在[L,R]内查找  重要！！！
	while(L<=R){
		int mid=L+(R-L)/2;
		int tmp=0;//参考点记录，初始在起点
		int cnt=0;
		for(int i=1;i<=n+1;i++){
			if(v[i]-tmp<mid){//小于猜测的最大最小跳跃距离，要删除
				cnt++;
			}
			else{
				tmp=v[i];//参考点变了
			}
		}
		if(cnt>m){
			R=mid-1;
		}
		else{
			L=mid+1;
		}
	}
	cout<<R<<endl;//最后输出L还是R可以尝试着看一下
	return 0;
}
