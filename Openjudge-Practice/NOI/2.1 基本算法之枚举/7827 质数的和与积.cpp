#include<iostream>
using namespace std;
bool is_prime(int n){
	int i;
	for(i=2;i<n;i++){
		if(n%i==0)
			break;
	}
	if(i==n)
		return true;
	else
		return false;
}
int main()
{
	int s;
	cin>>s;
	for(int i=s/2;i>=2;i--){
		if(is_prime(i)&&is_prime(s-i)){
  		 	cout<<i*(s-i);
  		 	return 0;
		}
	}
}
