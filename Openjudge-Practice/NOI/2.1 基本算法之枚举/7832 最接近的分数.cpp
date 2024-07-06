#include<iostream>
#include<climits>
using namespace std;
bool gcd(int a,int b){
	int sup=min(a,b);
	for(int i=2;i<=sup;i++){
		if(a%i==0&&b%i==0)
			return true;
	}
	return false;
}
int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	int ans[2]={0};
	double maxi=INT_MIN;
	double sup=(a*1.0)/b;
	for(int mu=1;mu<=n;mu++){
		for(int zi=1;;zi++){
			if((zi*1.0)/mu>=sup)
				break;
			if((zi*1.0)/mu>=maxi&&gcd(zi,mu)==false){
				maxi=(zi*1.0)/mu;
				ans[0]=zi;
				ans[1]=mu;
			}
		}
	}
	cout<<ans[0]<<' '<<ans[1]<<endl;
	return 0;
}
