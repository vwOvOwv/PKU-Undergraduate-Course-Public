#include <cstdlib>
#include <iostream>

using namespace std;

#include <cstdlib>
#include <iostream>

#include "lnkstack.h" 

using namespace std;

long f(long n);

int main(int argc, char *argv[])
{
    Link<int>* test = new Link<int>(10, NULL);
    
    cout << test->data << endl;
    long x, m;
	cin >> x;
    
    
    cout << "the factioral of "
         << x 
         << "  is " ;
	m = f(x);
	cout << m 
       <<endl;
    cin >> x;
}


// nonrevursive with stack
long f(long n) {
     lnkStack<long> s(0);
    
	 long tmp;
     
	 long m = 1;
	 while (n > 1) {                  	// ������ݹ����      
		s.push(n);
        n--;
     }				// ���ݹ�������Ӧ����ѹջ
	 while(s.pop(&tmp)) 		// �ݹ�������㣬��ʼ���з��ش���
		m *= tmp;
	 return m ;
}   
