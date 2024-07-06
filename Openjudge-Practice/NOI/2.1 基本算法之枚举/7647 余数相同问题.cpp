#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	for(int x=2;x<=a[0];x++){
		int r1=a[0]%x;
		int r2=a[1]%x;
		int r3=a[2]%x;
		if(r1==r2&&r2==r3){
			cout<<x<<endl;
			return 0;
		}
	}
	return 0;
}
