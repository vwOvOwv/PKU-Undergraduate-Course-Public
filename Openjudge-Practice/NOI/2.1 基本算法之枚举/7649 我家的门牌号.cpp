#include<iostream>
using namespace std;
int n;
int main()
{
	cin>>n;
	for(int i=1;;i++){
		int sum=(i+1)*i/2;
		for(int k=0;k<=i;k++){
			if(sum-2*k==n){
				cout<<k<<' '<<i<<endl;
				return 0;
			}
		}
    }
}
