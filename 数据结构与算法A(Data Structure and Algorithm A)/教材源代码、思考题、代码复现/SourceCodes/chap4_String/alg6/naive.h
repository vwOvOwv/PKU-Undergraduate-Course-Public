#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int NaiveStrMatching(string T, string P)  { 
    int i = 0;							// ģʽ���±����
    int j = 0;							// Ŀ����±����
    int pLen = P.length( );             		// ģʽ�ĳ���
    int tLen = T.length( );					// Ŀ��ĳ���

	if  (tLen < pLen) 				    // ���Ŀ���ģʽ�̣�ƥ���޷��ɹ�
        return (-1);          			
    while ( i < pLen  &&  j < tLen)  {  		// �����Ƚ϶�Ӧ�ַ�����ʼƥ��
   		if (T[j] == P[i]) 
			i++,  j++;
		else  { 
 			j = j - i + 1; 
			i = 0;
		}
	}
	if ( i >= pLen)
		return (j - pLen+1);
	else return (-1);
 }
