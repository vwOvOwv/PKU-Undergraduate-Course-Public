#include <iostream>
#include <string>

using namespace std;

#define MAX 102
#define INFINITY 65536

#include "Floyd.h" 

//void Floyd(Graph& G, Dist** &D); 

int BrokerToPassRomour (Graph& G )  {	
	Dist **D ;							// ����Floyd�㷨�Ĳ������������������̾���
	int* max = new int[G.VerticesNum()];				// ��¼ÿ�����㵽����������̾�������ֵ
	int min = 0;						// ��¼max�����е���Сֵ
	int pos = 0;// ��¼max��������Сֵ��λ��
	int i;                                
	for( int i = 0; i < G.VerticesNum(); i++ )   	// ��ʼ��max����
		max[i] = -1 ;		

	Floyd(G,  D);						// ����Floyd�㷨��ÿ�����֮�����̾���

	for (i = 0; i < G.VerticesNum();i ++ )  {  // �ҳ�ÿ�е����ֵ
		for (int j = 0; j < G. VerticesNum(); j ++ )  {
			if ( D[i][j].length > max[i] )
				max[i] = D[i][j].length ;
		}
	}

	min = max[0];
	for ( i = 1 ; i < G.VerticesNum(); i++ )		    // ��max�������Сֵ
		if ( max[i] < min )  {
			min = max[i];
			pos = i;							
		}
		if (min == INFINITY)  {
			cout<<"��ͼ����ͨ"<<endl;
			return -1;
		}
		return pos;								// ��������ʵĿ�ʼ����
}

