#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int num=n+1;;num+=n){
		int tmp=num;
		int i;
		for(i=1;i<=n;i++){
			if(tmp%n==1&&tmp-1>=n){
				tmp-=1;
				tmp-=tmp/n;
			}
			else break;
		}
		if(i==n+1){
			cout<<num;
			return 0;
		}
	}
}
