/*
����˼·��
�ѷ��鿴���ڵ㣬������������֮�����û��ǽ���ڷ���֮����һ���ߣ������Ǳ�����ת����һ��ͼ
�󷿼������Ϊ��ͼ�м�����ͨ��ͼ����Ŀ
��ÿһ��������������������������������ܹ����������λ��"Ⱦɫ"
���ͳ�����˼�����ɫ�Լ�ÿ����ɫ������
*/
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int R,C;
int rooms[60][60];//ͼ����Ϣ�Ѿ�������rooms��
int color[60][60];//����Ⱦɫ�ı��
int maxRoomArea=0,roomNum=0;
int roomArea;
void dfs(int i,int k){
	if(color[i][k]!=0)
		return;
	roomArea++;
	color[i][k]=roomNum;//�����
	//���ö�����
	if((rooms[i][k]&1)==0)//������
		dfs(i,k-1);
	if((rooms[i][k]&2)==0)//����
		dfs(i-1,k);
	if((rooms[i][k]&4)==0)//����
		dfs(i,k+1);
	if((rooms[i][k]&8)==0)//������
		dfs(i+1,k);
}
int main()
{
	cin>>R>>C;
	for(int i=1;i<=R;i++)
		for(int k=1;k<=C;k++)
			cin>>rooms[i][k];
	memset(color,0,sizeof(color));
	for(int i=1;i<=R;i++)
		for(int k=1;k<=C;k++){//����ÿһ������
			if(color[i][k]==0){
				roomNum++;
				roomArea=0;//ע��Ҫ����
				dfs(i,k);
				maxRoomArea=max(roomArea,maxRoomArea);
			}
		}
	cout<<roomNum<<endl;
	cout<<maxRoomArea<<endl;
}
