//���ö�������ö��

#include<iostream>
#include<string>
#include<cstring>
#include<memory>
using namespace std;
char oriLights[5];
char lights[5];
char result[5];
//һ��charΪ1���ֽڣ�8��������λ
int GetBit(char c,int i){//��ȡc�ڵĵ�iλ
	return (c>>i)&1;
}
void SetBit(char&c,int i,int v){//��c�ĵ�iλ��Ϊv
	if(v){
		c|=(1<<i);
	}
	else{
		c&=~(1<<i);
	}
}
void FlipBit(char& c,int i){//��c�ĵ�iλ��ת
	c^=(1<<i);
}
void OutputResult(char result[]){//������
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			cout<<GetBit(result[i],j);
			if(j<5)
			cout<<' ';
		}
		cout<<endl;
	}
}

int main()
{
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			int s;
			cin>>s;
			SetBit(oriLights[i],j,s);
		}
	}
	for(int n=0;n<64;n++){//ÿһ�ж���2^6��ö�ٷ�ʽ
		int switchs=n;
		memcpy(lights,oriLights,sizeof(oriLights));//ÿ��Ҫ��lights�ָ���ԭ��״̬
		for(int i=0;i<5;i++){
			result[i]=switchs;
			for(int j=0;j<6;j++){
				if(GetBit(switchs,j)){//��1��Ҫ�ı��Ӧ�Ŀ���״̬
					if(j>0)
						FlipBit(lights[i],j-1);
					FlipBit(lights[i],j);
					if(j<5)
						FlipBit(lights[i],j+1);
				}
			}
			if(i<4)
				lights[i+1]^=switchs;
			switchs=lights[i];//������һ�м���ȷ����һ��
		}
		if(lights[4]==0){
			OutputResult(result);
			break;
		}
	}
}

