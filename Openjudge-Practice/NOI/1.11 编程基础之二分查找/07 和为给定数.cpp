#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	int m;
	cin>>m;
	sort(v.begin(),v.end());//有序
	for(int i=0;i<n-1;i++){
		int tg=m-v[i];
		int l=i+1;
		int r=n-1;
		while(l<=r){
			int mid=l+(r-l)/2;
			if(v[mid]<tg)
				l=mid+1;
			else if(v[mid]>tg)
				r=mid-1;
			else{
				cout<<v[i]<<' '<<v[mid];
				return 0;
			}
		}
	}
	cout<<"No";
	return 0;
}
