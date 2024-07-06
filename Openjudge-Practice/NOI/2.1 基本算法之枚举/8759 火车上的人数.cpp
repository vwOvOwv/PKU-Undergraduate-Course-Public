#include<iostream>
#include<vector>
using namespace std;
int main(){
	int a,n,m,x;
	cin>>a>>n>>m>>x;
	vector<int>up(n+2);
	vector<int>down(n+2);
	for(int k=0;;k++){
		up[0]=0;
		up[1]=a;
		down[0]=0;
		down[1]=0;
		up[2]=k;
		down[2]=k;
		for(int i=3;i<n;i++){
			up[i]=up[i-1]+up[i-2];
			down[i]=up[i-1];
		}
		int u=0,d=0,u_x=0,d_x=0;
		for(int i=1;i<n;i++){
			u+=up[i];
			d+=down[i];
			if(i<=x){
				u_x+=up[i];
				d_x+=down[i];
			}
		}
		if(u-d==m){
			cout<<u_x-d_x;
			break;
		}
		up.clear();
		down.clear();
	}
	return 0;
}
