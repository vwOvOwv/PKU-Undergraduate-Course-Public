#include <iostream>
#include <string>

using namespace std;
template <class T>
class CMyistream_iterator
{
	//
private:
	T* p;
public:
	CMyistream_iterator(istream& c) {
		p = new T;//��̬����һ��T���ڴ棬��ҪдΪ
		/* T n;
		* cin>>n;
		* p=&n;
		����n����ʱ����������p�Ͳ�֪��ָ��������
		*/
		cin >> *p;
	}
    T operator*() {
		return *p;
	}
	CMyistream_iterator operator++(int k) {//����++
		cin >> *p;
		return *this;
	}
//������
//
};



int main()
{
	int t;
	cin >> t;
	while( t -- ) {
		 CMyistream_iterator<int> inputInt(cin);
		 int n1,n2,n3;
		 n1 = * inputInt; //���� n1
		 int tmp = * inputInt;
		 cout << tmp << endl;
		 inputInt ++;
		 n2 = * inputInt; //���� n2
		 inputInt ++;
		 n3 = * inputInt; //���� n3
		 cout << n1 << " " << n2<< " " << n3 << " ";
		 CMyistream_iterator<string> inputStr(cin);
		 string s1,s2;
		 s1 = * inputStr;
		 inputStr ++;
		 s2 = * inputStr;
		 cout << s1 << " " << s2 << endl;
	}
	 return 0;
}
