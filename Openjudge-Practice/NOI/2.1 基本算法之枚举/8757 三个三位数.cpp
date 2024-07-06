#include<iostream>
using namespace std;
bool judge(int a,int b,int c){
	int num[10]={0};
	while(a!=0){
		num[a%10]++;
		a/=10;
	}
	while(b!=0){
		num[b%10]++;
		b/=10;
	}
	while(c!=0){
		num[c%10]++;
		c/=10;
	}
	if(num[0]!=0)
		return false;
	for(int i=1;i<10;i++){
		if(num[i]!=1)
			return false;
	}
	return true;
}
int main()
{
	for(int i=100;i<=333;i++){
		if(judge(i,2*i,3*i))
			cout<<i<<' '<<2*i<<' '<<3*i<<endl;
	}
	return 0;
}
