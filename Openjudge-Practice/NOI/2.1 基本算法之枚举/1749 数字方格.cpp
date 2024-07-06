#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a,b,c,maximum=0;
	for(a=0;a<=n;a++)
		for(b=0;b<=n;b++)
			for(c=0;c<=n;c++){
				if((a+b)%2==0&&(b+c)%3==0&&(a+b+c)%5==0&&a+b+c>maximum)
					maximum=a+b+c;
			}
	cout<<maximum;
	return 0;
}
