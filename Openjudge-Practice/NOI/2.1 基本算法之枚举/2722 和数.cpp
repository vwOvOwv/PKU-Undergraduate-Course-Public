#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[110]={0};
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int cnt=0;
	for(int i=2;i<n;i++){
		for(int k=0;k<i;k++){
			for(int j=k+1;j<i;j++){
				if(a[k]+a[j]==a[i]){
					cnt++;
					k=i;
					break;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
