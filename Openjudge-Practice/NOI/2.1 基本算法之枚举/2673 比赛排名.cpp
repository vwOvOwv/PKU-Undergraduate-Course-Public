#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,e;
	int A,B,C,D,E;
	for(a=1;a<6;a++){
		for(b=1;b<6;b++){
			if(b==a)
				continue;
			for(c=1;c<6;c++){
				if(c==a||c==b)
					continue;
				for(d=1;d<6;d++){
					if(d==c||d==b||d==a)
						continue;
					for(e=1;e<6;e++){
						if(e==d||e==c||e==b||e==a||e==2||e==3)
							continue;
						A=(e==1);
						B=(b==2);
						C=(a==5);
						D=(c!=1);
						E=(d==1);
						int cnt=0;
						if((a<3&&A==1)||(a>=3&&A==0)){
							if(a<3&&A==1)
								cnt++;
							if((b<3&&B==1)||(b>=3&&B==0)){
								if(b<3&&B==1)
									cnt++;
								if((c<3&&C==1)||(c>=3&&C==0)){
									if(c<3&&C==1)
										cnt++;
									if((d<3&&D==1)||(d>=3&&D==0)){
										if(d<3&&D==1)
											cnt++;
										if((e<3&&E==1)||(e>=3&&E==0)){
											if(e<3&&E==1)
												cnt++;
											if(cnt==2)
												{cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl;}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
