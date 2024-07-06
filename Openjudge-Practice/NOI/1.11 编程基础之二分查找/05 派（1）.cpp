#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;
const double pi=acos(-1);
int main()
{
	int n,f;
	cin>>n>>f;
	vector<int>v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	double L=0,R=pi*v[n-1]*v[n-1],mid;
	while(R-L>=1e-5){
		mid=L+(R-L)/2;
		int cnt=0;
		for(int i=0;i<n;i++){
			cnt+=(pi*v[i]*v[i])/mid;
		}
		if(cnt<f+1){
			R=mid;
		}
		else{
			L=mid;
		}
	}
	cout<<fixed<<setprecision(3)<<mid;
	return 0;
}
