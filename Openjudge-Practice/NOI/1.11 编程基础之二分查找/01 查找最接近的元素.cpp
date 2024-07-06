#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;
vector<int>v;
void BinarySearch(int n,int size){
	int L=0,R=size-1;
	int mid;
	int mini_dis=INT_MAX;
	int mem_mid;
	while(L<=R){
		mid=L+(R-L)/2;
		if(v[mid]<n){
			L=mid+1;
			if(abs(v[mid]-n)<=mini_dis){
				mini_dis=abs(v[mid]-n);
				mem_mid=mid;
			}
		}
		else if(v[mid]>n){
			R=mid-1;
			if(abs(v[mid]-n)<mini_dis){
				mini_dis=abs(v[mid]-n);
				mem_mid=mid;
			}
		}
	 	else{
			cout<<v[mid]<<endl;
			return;
		}
	}
	cout<<v[mem_mid]<<endl;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int s;
		cin>>s;
		v.push_back(s);
	}
	int m;
	cin>>m;
	while(m--){
		int k;
		cin>>k;
		BinarySearch(k,n);
	}
	return 0;
}
