#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int mini=INT_MAX;
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n/a;b++){
			if(n%(a*b)==0){
				int c=n/(a*b);
				mini=min(mini,2*(a*b+a*c+b*c));
			}
		}
	}
	cout<<mini;
}
