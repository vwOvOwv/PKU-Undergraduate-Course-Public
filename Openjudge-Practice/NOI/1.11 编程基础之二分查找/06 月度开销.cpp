#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
	int m,n;
	cin>>n>>m;
	vector<int>v(n);
	int L=0,R=0,mid,fajo;
	int maxi=INT_MIN;
	for(int i=0;i<n;i++){
		cin>>v[i];
		R+=v[i];
		if(v[i]>maxi){
			maxi=v[i];
		}
	}
	L=maxi;
	while(R>=L){
		mid=L+(R-L)/2;
		//cout<<L<<' '<<R<<' '<<mid;
		int cnt=v[0];fajo=1;
		for(int i=1;i<n;i++){
			if(v[i]==mid)
				fajo++;
			else{
				cnt+=v[i];
				if(cnt>mid){
					i--;
					fajo++;
					cnt=0;
				}
				else if(cnt==mid){
					fajo++;
					cnt=0;
				}
			}
		}
		//cout<<"fajo="<<fajo<<endl;
		if(fajo<=m){
			R=mid-1;
		}
		else if(fajo>m){
			L=mid+1;
		}
	}
	cout<<mid;
	return 0;
}
