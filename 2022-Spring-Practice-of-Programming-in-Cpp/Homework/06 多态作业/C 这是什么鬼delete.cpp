#include <iostream>
using namespace std;
class A
{
public:
	A() { }
	//
virtual ~A() { cout << "destructor A" << endl; }
	/*paָ��B, B��A����������B�а���һ��A�������ʽָ��ָ��A��
	delete paʱӦ����A��������������A�������������麯�������ִ
	��paָ��Ķ���B����������������B����һ��ָ��A��ָ�룬���
	����ִ��A����������*/
	//
};
class B:public A {
	public:
	~B() { cout << "destructor B" << endl; }
};
int main()
{
	A * pa;
	pa = new B;
	delete pa;
	return 0;
}
