#include<iostream>
using namespace std;
int sum;
int judge(int n){
	sum=0;
	for(int i=1;;i++){
		sum+=i;
		if(sum>=n){
			sum-=i;
			return i;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int k=judge(n);
	if(k%2==1){//������
		for(int zi=k;zi>=1;zi--){
			sum++;
			if(sum==n)
				cout<<zi<<'/'<<k+1-zi<<endl;
		}
	}
	else{//ż����
		for(int zi=1;zi<=k;zi++){
			sum++;
			if(sum==n)
				cout<<zi<<'/'<<k+1-zi<<endl;
		}
	}
	return 0;
}
