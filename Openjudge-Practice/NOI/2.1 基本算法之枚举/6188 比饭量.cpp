#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<int,char>ans;
	int A,B,C,a,b,c;
	for(a=1;a<=3;a++){
		for(b=1;b<=3;b++){
			if(b==a)
				continue;
			for(c=1;c<=3;c++){
				if(c==a||c==b)
					continue;
				A=(b>a)+(a==c);
				B=(a>b)+(a>c);
				C=(c>b)+(b>a);
				if(A+a==3&&B+b==3&&C+c==3){//饭量和正确断言的个数是反序关系
					ans.insert(make_pair(a,'A'));
					ans.insert(make_pair(b,'B'));
					ans.insert(make_pair(c,'C'));
					for(int i=1;i<=3;i++)
						cout<<ans[i];
					return 0;
				}
			}
		}
	}
}
