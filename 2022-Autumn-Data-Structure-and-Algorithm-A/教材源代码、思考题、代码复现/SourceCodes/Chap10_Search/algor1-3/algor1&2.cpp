#include "iostream"


#include <vector>
#include "time.h"
using namespace std;



template  <class Type>  class Item {
	public: 
		Item(Type value):key(value) {}
        Type getKey() {
			return key;
		}         //��ȡ�ؼ���ֵ;
        void setKey(Type k){
			key=k;
		}
	private:
		Type  key;                           //�ؼ�����
		//...
		//������;                              //������
};

 



 template  <class Type>  int SeqSearch (vector<Item<Type>*>& datavector,int length, Type k)  {
    int i=length;
   datavector[0]->setKey (k);        //����0��Ԫ����Ϊ������ֵ
  while(datavector[i]->getKey()!=k)
	  i--;     //�Ӻ���ǰ����Ƚ�
    return i;           //����Ԫ��λ��
}


 template  <class Type>  int SimpleSearch (vector<Item<Type>*>& datavector,int length, Type k)  {
    int i=length;
  
  while(datavector[i]->getKey()!=k&&i>0)
	  i--;     //�Ӻ���ǰ����Ƚ�
    return i;           //����Ԫ��λ��
}


template  <class Type>  int BinSearch (vector<Item<Type>*>& datavector,int length,Type k)  {
   int low=1,high=length,mid;   //low, high�ֱ��¼������βλ��
   while (low<=high){
	   mid=(low+high)/2;
	   if (k<datavector[mid]->getKey()) 
		   high = mid-1;               //������������
	   else if (k>datavector[mid]->getKey())
		   low = mid+1;           //������������
       else
		   return mid;                            //�����ɹ�������Ԫ��λ��
   } 
	   return 0;                                 //����ʧ�ܣ�����0
}


// ʱ�������ʱ�亯��
clock_t tstart = 0;  


void Settime()
  { 
	tstart = clock(); 
}


double Gettime()
  {
	return (double)((double)clock() - (double)tstart)/(double)CLOCKS_PER_SEC; 
}




int main()
{ 
vector<Item<int>*> datavector(200001);
 	
Item<int>* darray[200001];

  for(int j=0;j<200001;j++)
  darray[j]=new Item<int>(j);
          
  vector<Item<int>*>::iterator outputIterator = datavector.begin();
  copy(darray, darray +200001, outputIterator);
 
  

	int k;




    Settime();//��ʼ��ʱ
      k= SeqSearch(datavector, datavector.size()-1,7);
    
	
	cout << "-->������˳�������ʱ : " ;
	cout << Gettime()<< endl ;
    


 
   Settime();//��ʼ��ʱ
      k= SimpleSearch(datavector, datavector.size()-1,7);
	cout << "-->һ��˳�������ʱ : " ;
   cout << Gettime()<< endl ;
  

    
return 0;   
}
       