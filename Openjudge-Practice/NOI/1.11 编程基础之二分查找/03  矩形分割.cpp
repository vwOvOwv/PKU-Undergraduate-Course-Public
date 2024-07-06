#include<iostream>
using namespace std;
const int N = 10005;
int r,n;
long long x[N],y[N],w[N],h[N],s[N];

long long f(int k){	//直线k 左边面积 - 右边面积
	long long zuos=0,yous=0;
	for (int i=1; i<=n; i++){
		if (x[i]>=k) { yous+=s[i]; continue; }		//小矩形在直线右边
		if (x[i]+w[i]<=k) { zuos+=s[i]; continue; }	//小矩形在直线左边
		zuos+=(k-x[i])*h[i];		//左边部分
		yous+=s[i]-(k-x[i])*h[i];	//右边部分
	}
	return zuos-yous;
}

int solve(int low,int high){
	int mid;
	while (low<=high){
		mid=low+(high-low)/2;
		if (f(mid)>0) high=mid-1;
		else low=mid+1;
	}
	//本题难点在于判断low和high哪一个是答案
	if (f(high)>=0 && f(high)<f(low)) return high;//尽量让线向右靠
	while (f(low)==f(low+1) && low<r) low++;	//low作为划分位置，保证大矩形在直线左边的的面积尽可能大
	return low;
}

int main(){
	cin>>r>>n;
	for (int i=1; i<=n; i++){
		cin>>x[i]>>y[i]>>w[i]>>h[i];
		s[i]=w[i]*h[i];
	}
	cout<<solve(0,r)<<endl;
	return 0;
}
