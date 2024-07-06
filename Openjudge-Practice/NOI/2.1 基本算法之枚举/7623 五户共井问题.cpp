#include<iostream>
using namespace std;
int main()
{
	int k,n1,n2,n3,n4,n5;
	cin>>k>>n1>>n2>>n3>>n4>>n5;
	int max_depth=k*100;
	int flag=0;
	for(int i=1;i<=max_depth;i++){
		for(int a=0;a<=i/n1;a++){
			int b=i-n1*a;
			if(b==a)
				continue;
			int c=i-n2*b;
			if(c==b||c==a)
				continue;
			int d=i-n3*c;
			if(d==c||d==b||d==a)
				continue;
			int e=i-n4*d;
			if(e==d||e==c||e==b||e==a)
				continue;
			if(n5*e+a==i&&a>=0&&b>=0&&c>=0&&d>=0&&e>=0){
				cout<<i<<' '<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<endl;
				i=max_depth+1;
				flag=1;
				break;
			}
		}
	}
	if(!flag){
		cout<<"not found"<<endl;
	}
	return 0;
}
