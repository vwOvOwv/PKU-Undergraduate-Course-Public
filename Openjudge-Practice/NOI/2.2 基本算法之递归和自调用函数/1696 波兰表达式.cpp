#include<iostream>
#include<iomanip>
using namespace std;
double Polean(){
	char c=cin.peek();
	while(c==' '){
		cin.ignore();
		c=cin.peek();
	}
	if(c=='+'){
		cin.ignore();
		return Polean()+Polean();
	}
	else if(c=='-'){
		cin.ignore();
		return Polean()-Polean();
	}
	else if(c=='/'){
		cin.ignore();
		return Polean()/Polean();
	}
	else if(c=='*'){
		cin.ignore();
		return Polean()*Polean();
	}
	else if(c>='0'&&c<='9'){
		double s;
		cin>>s;
		return s;
	}
	else
		cin.ignore();
}

int main()
{
	cout<<fixed<<setprecision(6)<<Polean();
	return 0;
}
