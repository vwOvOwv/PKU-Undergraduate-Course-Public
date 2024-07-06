#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int i;
	for(i=1;i<m;i++){
		if(n%i==0&&n%(m-i)==0){
			cout<<i;
			break;
		}
	}
	if(i==m)
		cout<<-1;
	return 0;
}
