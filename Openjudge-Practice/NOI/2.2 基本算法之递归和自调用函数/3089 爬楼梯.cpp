#include<iostream>
using namespace std;
int f(int n){
	if(n==1)//边界条件可以有多种选择
		return 1;
	if(n==2)
		return 2;
	return f(n-1)+f(n-2);//n级台阶的走法=先走一级后n-1级台阶的走法+先走两级后n-2级台阶的走法
}
int main()
{
	int n;
	cin>>n;
	cout<<f(n);
	return 0;
}
