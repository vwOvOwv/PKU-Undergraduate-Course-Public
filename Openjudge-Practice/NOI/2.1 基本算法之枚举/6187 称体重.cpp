#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<int,char>ans;
	int z,q,s,l;
	for(int z=10;z<=50;z+=10){
		for(int q=10;q<=50;q+=10){
			for(int s=10;s<=50;s+=10){
				for(int l=10;l<=50;l+=10){
					if(z+q==s+l&&z+l>s+q&&z+s<q){
						ans.insert(make_pair(z,'z'));
						ans.insert(make_pair(q,'q'));
						ans.insert(make_pair(s,'s'));
						ans.insert(make_pair(l,'l'));
						auto i=ans.begin();
						for(;i!=ans.end();++i){
							cout<<(*i).second<<' '<<(*i).first<<endl;
						}
						return 0;
					}
				}
			}
		}
	}
}
