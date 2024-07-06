//化实数为整数，控制精确度
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		double s;
		cin>>s;
		v[i]=s*100.0;
	}
	sort(v.begin(),v.end());
	bool flag=false;
	int L=1,R=v[n-1],mid,cnt=0;
	while(R>=L){
		mid=L+(R-L)/2;
		//cout<<"L="<<L<<" R="<<R<<" mid="<<mid<<' ';
		cnt=0;
		for(int i=0;i<n;i++){
			cnt+=v[i]/mid;
		}
		cout<<"cnt="<<cnt<<endl;
		if(cnt<k){
			R=mid-1;
		}
		else{
			flag=true;
			L=mid+1;
		}
	}
		//cout<<"L="<<L<<" R="<<R<<" mid="<<mid<<" cnt="<<cnt<<endl;
	if(flag)
		cout<<fixed<<setprecision(2)<<R/100.0<<endl;
	else
		cout<<"0.00"<<endl;
	return 0;
}
