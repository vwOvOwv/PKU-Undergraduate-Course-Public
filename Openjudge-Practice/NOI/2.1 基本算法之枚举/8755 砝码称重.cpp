#include<iostream>
#include<set>
using namespace std;
set<int>weight;
int main()
{
	int a1,a2,a3,a4,a5,a6;
	int total=0;
	cin>>a1>>a2>>a3>>a4>>a5>>a6;
	for(int i1=0;i1<=a1;i1++){
		for(int i2=0;i2<=a2;i2++){
			for(int i3=0;i3<=a3;i3++){
				for(int i4=0;i4<=a4;i4++){
					for(int i5=0;i5<=a5;i5++){
						for(int i6=0;i6<=a6;i6++){
							if(i1==0&&i2==0&&i3==0&&i4==0&&i5==0&&i6==0)
								continue;
							int weights=i1+2*i2+3*i3+5*i4+10*i5+20*i6;
							auto i=weight.find(weights);
							if(i!=weight.end())
								continue;
							else{
								total++;
								weight.insert(weights);
							}
						}
					}
				}
			}
		}
	}
	cout<<"Total="<<total;
	return 0;
}
