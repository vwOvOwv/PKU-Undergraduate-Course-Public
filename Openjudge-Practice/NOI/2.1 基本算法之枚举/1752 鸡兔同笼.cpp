#include<iostream>
using namespace std;
int main()
{
	int a;
	cin>>a;
	if(a%2==0)
		cout<<a/4+a%4/2<<' '<<a/2<<endl;
	else
		cout<<"0 0"<<endl;
	return 0;
}
