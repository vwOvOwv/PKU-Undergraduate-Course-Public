#include <iostream>
#include <stdlib.h>
#include "MinHeap.h"
#include "Buffer.h"
#include <memory.h>
using namespace std;
typedef unsigned char BYTE;

#define  MAX   7  // �Ѵ�С

//***************  file operation ****************//
// �������ܣ���ʼ���ļ�
int initFiles(FILE *&inputFile, FILE *&outputFile, const char *in, const char *out)  {
	if ((inputFile = fopen(in, "rb+")) == NULL)  {
		cout << "Cannot open file!!!" << endl;
		return 0; 
	}
	if ((outputFile = fopen(out, "rb+")) == NULL)  {
		cout << "Cannot open file!!!" << endl;
		return 0;	
	}
	return 1; 
}

// �������ܣ���ʼ����������ݣ��Ӵ����ļ���n��������������A
template <class T>
void initMinHeapArry(FILE *inputFile, int n, T *A)  {
	fread(A, sizeof(BYTE), n, inputFile);
//	cout << "file read!!!" << endl;
}

// �������ܣ���ʼ��input buffer, ����һ��������
template <class T>
void initInputBuffer(Buffer<T> &input, FILE *inputFile)  {
	input.L = (BYTE *)malloc(BUFFER_SIZE);
	memset(input.L, NULL, BUFFER_SIZE);
	input.nLen = fread(input.L, sizeof(BYTE), BUFFER_SIZE, inputFile);
//	cout << "InputBuffer initialised!!" << endl;
}

template <class T>
void initOutputBuffer(Buffer<T> & output)  {
	output.L = (BYTE *)malloc(BUFFER_SIZE);
}

// �������ܣ���mval����������������ͬʱ�����򻺳����ջ����������
template <class T>
void sendToOutputBuffer(Buffer<T> &input, Buffer<T> &output, FILE *inputFile, FILE *outputFile, T mval)  {
	// �������������д�ļ�

	if (output.isFull())  {
		output.flush(outputFile); // ������д����
//		cout<<"out buffer is full."<<endl;
	}
	
	output.insert(mval);         // ���뻺�����գ����ļ�������
//	cout<<"output.insert(mval)"<<endl;
	if (input.isEmpty() == true)   {
		if (!feof(inputFile))  {
			// �ļ�û�н���
			fillBuffer(inputFile, input);
		}
	} 
}

// �������ܣ��Ƚϴ�С
template <class T>
bool less(T r, T mval)  {
	if (r < mval)
		return true;
	else
		return false;
}

// �������ܣ��㷨�����������������������
template <class T>
void endUp(Buffer<T> output, FILE *inputFile, FILE *outputFile)  {
	fwrite(output.L, sizeof(BYTE), output.nLen, outputFile);
	fclose(inputFile);
	fclose(outputFile);
	cout << "output file." << endl;
}

template <class T>
void replacementSelection(T * A, int n, const char * in, const char * out)  {
	T mval;  //�����Сֵ�ѵ���Сֵ
	T r;     //��Ŵ����뻺�����ж����Ԫ��	
	FILE * inputFile;                   //�����ļ����
	FILE * outputFile;                  //����ļ����	
	Buffer<T> input;                   //����buffer
	Buffer<T> output;                  //���buffer	

	initFiles(inputFile, outputFile, in, out);  //��ʼ����������ļ�
	//��ʼ���ѵ����ݣ��Ӵ����ļ�����n��������������A
	initMinHeapArry(inputFile, n, A);  //�Ӵ����ļ�����n�����ݵ�������A
	MinHeap<T> H(A, n);          //������Сֵ��
	initInputBuffer(input, inputFile);    //��ʼ��input buffer������һ��������
	initOutputBuffer(output);	  //��ʼ��Output buffer

	for(int last = (n-1); last >= 0;)  {   //�Ѳ�Ϊ�գ��������ѭ��
		mval = H.heapArray[0];       //�ѵ���Сֵ
		//mval = H.RemoveMin();
		//��mval�͵������������ͬʱ�����򻺳����ջ�����ɵĸ�������
	
		sendToOutputBuffer(input, output, inputFile, outputFile, mval);

		input.read(r);  //�����뻺��������һ����¼

		if(!less(r, mval))  {    // rֵ���ڵ��ڸ����ֵ��r��Ѹ�
				H.heapArray[0] = r;
		}
		else  {                  // r������ѣ��ݴ������
			H.heapArray[0] = H.heapArray[last];  // ��lastλ�õļ�¼��������
			H.heapArray[last] = r;				// ��r�ŵ�lastλ��
			H.setSize(last);					// �ѹ�ģ��С1
			last--;
		}		
		if(last != 0)  {       //�������ж�
			H.SiftDown(0);  //�Ѹ�����¼�½������ʵ�λ��
		}

	}//endfor

	//�㷨�����������������������������/����ļ�
	endUp(output, inputFile, outputFile);
}


void main()  {
	char in[] = "file_in.txt";   // �����ļ�����
	char out[] = "file_out.txt"; // ����ļ�����
	int  n = MAX; // ����Ԫ�ظ��������ڴ���Ŀ 
	BYTE *A = new BYTE[MAX];
	replacementSelection(A, n, in, out);
}