#include<iostream>
#include<string>
using namespace std;
int transform(string num,int n){
	int size=num.size();
	int ans=0;
	int power=1;
	for(int i=size-1;i>=0;i--){
		if(num[i]-'0'>=n)
			return -1;
		ans+=(num[i]-'0')*power;
		power*=n;
	}
	return ans;
}
int main()
{
	string p,q,r;
	cin>>p>>q>>r;
	int i;
	for(i=2;i<=16;i++){
		if(transform(p,i)*transform(q,i)==transform(r,i)){
			cout<<transform(p,i)<<' '<<transform(q,i)<<' '<<transform(r,i)<<endl;
			cout<<i<<endl;
			break;
		}
	}
	if(i==17)
		cout<<0<<endl;
}
