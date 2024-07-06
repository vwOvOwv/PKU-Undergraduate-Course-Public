#include<iostream>
#include<cmath>
#include<iomanip>
#include<climits>
using namespace std;
int main()
{
	double l,n,c;
	cin>>l>>n>>c;
	double ll=(1+n*c)*l;
	double L=l*2,R=INT_MAX,theta,mid;
	while(R-L>1e-5){
		mid=L+(R-L)/2;
  		theta=asin(l/(2*mid));
		if(theta*mid>ll/2)
			L=mid;
		else
			R=mid;
	}
	double ans=R*(1-cos(theta));
	cout<<fixed<<setprecision(3)<<ans<<endl;
	return 0;
}
