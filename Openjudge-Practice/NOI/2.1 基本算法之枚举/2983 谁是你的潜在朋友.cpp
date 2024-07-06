#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>reader(n);
	vector<int>cnt(n,0);
	for(int i=0;i<n;i++)
		cin>>reader[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j==i)
				continue;
			if(reader[i]==reader[j])
				cnt[i]++;
		}
	}
	for(int i=0;i<n;i++){
		if(cnt[i]==0)
			cout<<"BeiJu"<<endl;
		else
			cout<<cnt[i]<<endl;
	}
	return 0;
}
