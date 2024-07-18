#include <cstdlib>
#include <iostream>

#include "arrStack.h" 

using namespace std;

long factorial(long n);

int main(int argc, char *argv[])
{
    long x, m;
	cin >> x;
    cout << "the factioral of "
         << x 
         << "is " ;
	m = factorial(x);
	cout << m 
       <<endl;
    cin >> x;
}


/* recurive version
long factorial(long n)  {
	if (n <= 0) 
		return 1;
	return n * factorial(n-1);
}


// iterated version 
long factorial(long n) {
		long  m = 1;
		long  i ;
		if (n > 0)
			for ( i = 1;  i <= n;  i++ )
				m = m * i ;
		return m ;
}    

*/

// nonrevursive with stack
long factorial(long n) {
     arrStack<long> s(20);
	 long tmp;
     
	 long m = 1;
	 while (n > 0)                  	// ������ݹ����      
		s.push(n--);				// ���ݹ�������Ӧ����ѹջ
	 while (!s.isEmpty()) {			// �ݹ�������㣬��ʼ���з��ش���
		s.pop(&tmp);
		m *= tmp;
     } 
	 return m ;
}   

