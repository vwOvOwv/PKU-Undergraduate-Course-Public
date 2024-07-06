#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	int t=0;
	cin>>n;
	for(int c=0;c<=n/5;c++){
		for(int b=0;b<=(n-5*c)/2;b++){
			int a=n-5*c-2*b;
			t++;
			cout<<setw(3)<<setfill('0')<<t;
			cout<<setw(12)<<setfill(' ')<<a;
			cout<<setw(12)<<setfill(' ')<<b;
			cout<<setw(12)<<setfill(' ')<<c;
			cout<<endl;
		}
	}
	return 0;
}
