#include<iostream>
#include<cmath>
using namespace std;
int n;
int queen_pos[100];
void n_queen(int k){//��0~k-1�лʺ��Ѿ��ںõ�����°ڵ�k�м������Ļʺ�
	if(k==n){//n���ʺ��Ѿ��ں�
		for(int i=0;i<n;i++)
			cout<<queen_pos[i]+1<<' ';
		cout<<endl;
		return;
	}
	for(int i=0;i<n;i++){
		int j;
		for(j=0;j<k;j++){//���Ѿ��ںõ�k���ʺ��λ�ñȽϣ����Ƿ��ͻ
			if(queen_pos[j]==i||abs(k-j)==abs(queen_pos[j]-i))//��ͻ��������һ��λ��
				break;
		}
		if(j==k){
			queen_pos[k]=i;
			n_queen(k+1);
		}
	}
}
int main()
{
	cin>>n;
	n_queen(0);//�ӵ����п�ʼ�ڷ�
	return 0;
}
