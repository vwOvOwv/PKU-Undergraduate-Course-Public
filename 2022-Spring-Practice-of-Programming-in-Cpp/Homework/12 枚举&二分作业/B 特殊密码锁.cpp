//����������
#include<iostream>
#include<string>
#include<cstring>
#include<climits>
using namespace std;
int main()
{
	char ori[30];//ԭʼ�ַ���
	char des[30];//Ŀ���ַ���
	char tmp[30];
	cin>>ori>>des;
	strcpy(tmp,ori);
	int cnt=0;
	int min_cnt=INT_MAX;//���ٰ���ť��������
	int size=0;
	for(;ori[size]!='\0';size++);//���ַ������ȣ�������sizeof()
	for(int i=0;i<size;i++){
		if(i==0){//����һ����ť��֮���ÿ����ť�Ƿ���Ҫ������֮ȷ������
			tmp[0]^=1;
			tmp[1]^=1;//^1���ɸı�״̬
			cnt++;
		}
		else if(i<size-1) {//�м�İ�ť
			if(tmp[i-1]!=des[i-1]){//ǰһ���ַ�������Ҫ���Ǳ���Ҫ����ǰ��ť�������û�л���ı�ǰһ���ַ���
				tmp[i]^=1;
				tmp[i-1]^=1;
				tmp[i+1]^=1;
				cnt++;
			}
		}
 		else{
			if(tmp[i-1]!=des[i-1]){//���İ�ť
				tmp[i]^=1;//���һ���ַ������ܱ�֤��Ŀ���ַ������һ���ַ�����ͬ
				tmp[i-1]^=1;
				cnt++;
			}
		}
	}
	if(strcmp(tmp,des)==0&&cnt<min_cnt)//��������
		min_cnt=cnt;
	//���ǲ�������һ����ť�����
	cnt=0;
	strcpy(tmp,ori);
	for(int i=0;i<size;i++){
		if(i==0){
			tmp[0]^=0;
			tmp[1]^=0;
		}
		else if(i<size-1){
			if(tmp[i-1]!=des[i-1]){
				tmp[i]^=1;
				tmp[i-1]^=1;
				tmp[i+1]^=1;
				cnt++;
			}
		}
		else{
			if(tmp[i-1]!=des[i-1]){
				tmp[i]^=1;
				tmp[i-1]^=1;
				cnt++;
			}
		}
	}
	if(strcmp(tmp,des)==0&&cnt<min_cnt)
		min_cnt=cnt;
	if(min_cnt!=INT_MAX)//�к��ʴ�
		cout<<min_cnt;
	else
		cout<<"impossible";
 	return 0;
}
