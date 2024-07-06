#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n,cnt=0;
	vector<int>v;
	while(cin>>n){
		if(n==0)
			break;
		v.push_back(n);
	}
	sort(v.begin(),v.end());
	int size=v.size();
	for(int i=0;i<size;i++){
		for(int j=i+1;j<size;j++){
			if(v[j]==2*v[i])
				cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
