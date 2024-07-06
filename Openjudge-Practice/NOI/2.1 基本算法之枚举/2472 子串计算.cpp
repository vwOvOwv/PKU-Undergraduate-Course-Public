#include<iostream>
#include<string>
#include<map>
using namespace std;
string s;
int main()
{
	cin>>s;
	map<string,int>ans;
	int size=s.size();
	int cnt=0;
	string tmp;
	for(int start=0;start<size;start++){
		for(int length=0;length<=size-start;length++){
			tmp=s.substr(start,length);
			int tmp_size=tmp.size();
			cnt=0;
			for(int i=0;i<=size-tmp_size;i++){
				if(s.compare(i,tmp_size,tmp)==0){
					cnt++;
				}
			}
			if(cnt>=2){
				ans.insert(make_pair(tmp,cnt));
			}
		}
	}
	int num=ans.size();
	auto i=ans.begin();
	for(;i!=ans.end();++i){
		if((*i).first!="\0")
			cout<<(*i).first<<' '<<(*i).second<<endl;
	}
	return 0;
}
