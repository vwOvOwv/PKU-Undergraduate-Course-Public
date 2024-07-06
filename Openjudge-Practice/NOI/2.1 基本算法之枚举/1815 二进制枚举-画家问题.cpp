//同1813熄灯问题
#include<iostream>
#include<climits>
#include<string>
#include<cstring>
using namespace std;

int GetBit(int c,int v){
	return (c>>v)&1;
}
void SetBit(int&c,int u,int v){
	if(v){
		c|=(1<<u);
	}
	else{
		c&=~(1<<u);
	}
}
void FlipBit(int&c,int v){
	c^=(1<<v);
}
int ori_wall[20];
int now_wall[20];
int result[20];
int main()
{
	int n;
	char c;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>c;
			if(c=='w'){
				SetBit(ori_wall[i],j,1);
			}
			else{
				SetBit(ori_wall[i],j,0);
			}
		}
	}
	int mini=INT_MAX;
	int cnt;
	int sup=1;
	for(int k=1;k<=n;k++){
		sup*=2;
	}
	for(int r=0;r<sup;r++){
		int switches=r;
		memcpy(now_wall,ori_wall,sizeof(ori_wall));
		for(int i=0;i<n;i++){
			result[i]=switches;
			for(int j=0;j<n;j++){
				if(GetBit(switches,j)==1){
					FlipBit(now_wall[i],j);
					if(j>0){
						FlipBit(now_wall[i],j-1);
					}
					if(j<n-1){
						FlipBit(now_wall[i],j+1);
					}
				}
			}
			if(i<n-1){
				now_wall[i+1]^=switches;
			}
			switches=now_wall[i];
		}
		if(now_wall[n-1]==0){
			cnt=0;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(GetBit(result[i],j)==1)
						cnt++;
				}
			}
			if(cnt<mini)
				mini=cnt;
		}
	}
	if(mini!=INT_MAX)
		cout<<mini;
	else
		cout<<"inf";
	return 0;
}
