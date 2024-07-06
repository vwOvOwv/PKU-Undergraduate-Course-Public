#include "../sort.h"
#include "LinkRadixSort.h"
//#define ARRAYSIZE 1000000
#define ARRAYSIZE 1000000
#define radix 16
#define DStep 4

int main()  {

/*	
	int listsize = 9;    
	Node *Array = new Node[9];
	
	Array[0].key = 97;
	Array[1].key = 53;
	Array[2].key = 88;
	Array[3].key = 59;
	Array[4].key = 26;
	Array[5].key = 41;
	Array[6].key = 88;
	Array[7].key = 31;
	Array[8].key = 22;

	cout << "����ǰ:" << endl;
	Print<Node>(Array, listsize);
	RadixSort<Node>(Array, listsize, DStep, radix);
	cout << "�����:" << endl;
	Print<Node>(Array, listsize);
*/	

	int input = -1;	   // ��������: -1 --����(����) ; +1 - ����(����); 0 -- ���

	Randomize();
 
	int listsize = 1000;
	Node *Array = new Node[ARRAYSIZE]; 

  /*
  // Ҳ���Բ������������е���ʽ
  // <sortname> [+/-] <size_of_test> <threshold>
  //        -1 --���� ; +1 - ����; �޲��� --  0 ���
  // <size_of_test> �������ݹ�ģ
  // <threshold> �������򡢹鲢�����ĳЩ��Ҫ��ֵ������

  int currarg;
  if ((argc < 2) || (argc > 4)) {
    cout << "Usage: <sortname> [+/-] <size> [<threshold>]\n";
    exit(-1);
  }
  currarg = 1;
  if (argv[currarg][0] == '-') {
    input = -1;
    currarg++;
  }
  else if (argv[currarg][0] == '+') {
    input = 1;
    currarg++;
  }
  listsize = atoi(argv[currarg++]);
  if (argc > currarg)
    THRESHOLD = atoi(argv[currarg]);
  if ((listsize > ARRAYSIZE) || (listsize < 0)) {
    cout << "Selected list size is too big\n";
    exit(-1);
  }
  cout << "Input: " << input << ", size: " << listsize << ", threshold: "
       << THRESHOLD << "\n";
  */

	int i, j;
	int k = ARRAYSIZE / listsize;

	if (input == -1)  {
		for (i=0; i<k; i++)							// ����
			for (j=0; j<listsize; j++)
				Array[i*listsize + j].key = listsize - j;
		}
	else if (input == 0)
		for (i=0; i<ARRAYSIZE; i++)
			Array[i].key = Random(32003);				// ���
			// Array[i].key = Random(1000000);			// <1M��20λ���������	
		else {											// ����
		for (i=0; i<k; i++)	 
			for (j=0; j<listsize; j++)
				Array[i*listsize + j].key = j;
		}

	Settime();
	for (i=0; i<ARRAYSIZE; i+=listsize)  {
//		cout << "����ǰ:" << endl;
//		PrintArray<Node>(&Array[i], i);
		RadixSort<Node>(&Array[i], listsize, DStep, radix);
//		cout << "�����:" << endl;
//		PrintAddr<Node>(&Array[i], listsize);
	}

	cout << "Sort with list size " << listsize
	   << ", Array size " << ARRAYSIZE << " : " 
       << Gettime()/k << " seconds\n";
	return 0;
}


