#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int ans[9]={0};//����ʱ�Ӻ��ʱ��״̬
	int clock[9]={0};//��ʼʱ��״̬
	int mem_cnt[9];//ÿ�ֲ����Ĵ���
	int min_length=INT_MAX;//��̵Ĳ������г���
	for(int i=0;i<9;i++)
		cin>>clock[i];
	for(int i1=0;i1<4;i1++){//ÿ�ֲ���������3�Σ�����Ĳ�����û�������
		for(int i2=0;i2<4;i2++){
			for(int i3=0;i3<4;i3++){
				for(int i4=0;i4<4;i4++){
					for(int i5=0;i5<4;i5++){
						for(int i6=0;i6<4;i6++){
							for(int i7=0;i7<4;i7++){
								for(int i8=0;i8<4;i8++){
									for(int i9=0;i9<4;i9++){
										ans[0]=i1+i2+i4+clock[0];
										ans[1]=i1+i2+i3+i5+clock[1];
										ans[2]=i2+i3+i6+clock[2];
										ans[3]=i1+i4+i5+i7+clock[3];
										ans[4]=i1+i3+i5+i7+i9+clock[4];
										ans[5]=i3+i5+i6+i9+clock[5];
										ans[6]=i4+i7+i8+clock[6];
										ans[7]=i5+i7+i8+i9+clock[7];
										ans[8]=i6+i8+i9+clock[8];
										int i=0;
										for(i=0;i<9;i++){
											if(ans[i]%4!=0){//��δ��12���
												break;
											}
										}
										if(i==9){//ȫ����12�㣬��������
											int size=i1+i2+i3+i4+i5+i6+i7+i8+i9;//���г���
											if(size<min_length){
												min_length=size;
												mem_cnt[0]=i1;
												mem_cnt[1]=i2;
												mem_cnt[2]=i3;
												mem_cnt[3]=i4;
												mem_cnt[4]=i5;
												mem_cnt[5]=i6;
												mem_cnt[6]=i7;
												mem_cnt[7]=i8;
												mem_cnt[8]=i9;
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
	for(int i=0;i<9;i++){//�����������
		for(int j=0;j<mem_cnt[i];j++){
			cout<<i+1<<' ';
		}
	}
	return 0;
}
