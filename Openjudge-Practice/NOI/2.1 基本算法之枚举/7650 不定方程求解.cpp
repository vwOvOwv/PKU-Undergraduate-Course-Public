#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int cnt=0;
	for(int x=0;;x++){
		if(a*x>c)
			break;
		for(int y=0;;y++){
			if(a*x+b*y>c)
				break;
			if(a*x+b*y==c){
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
