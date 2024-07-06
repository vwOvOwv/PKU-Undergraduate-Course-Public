#include<iostream>
#include<vector>
using namespace std;
bool gcd(int a,int b){
	int tmp;
	if(a<b)
		tmp=a;
	else
		tmp=b;
	for(int i=2;i<=tmp;i++){
		if(a%i==0&&b%i==0)
			return true;
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(!gcd(v[i],v[j]))
				cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
