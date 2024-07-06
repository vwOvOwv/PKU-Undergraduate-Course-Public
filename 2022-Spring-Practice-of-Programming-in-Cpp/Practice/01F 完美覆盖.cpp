#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
#include<vector>

using namespace std;
int n;
long long int f[40];//f[i]��ʾi�еĸ��Ƿ�ʽ����
/*
iΪ�������޷��������ǣ�f[i]=0;
iΪż��ʱ��f[0]=1,f[2]=3;
������i>=4,�����Խ�i��Ϊ��ߵ�i-2,i-4,...,2,0���ұߵ�2,4,...,i-2,i
ע��Ϊ�˱����ظ����ұߵĲ��ֱ�Ȼ�ǲ��ɷָ�ģ���4����������2ƴ��...
���ɿ��Է��֣������Ҳ��ƴ��a[i],a[i]=i>2?2:3
��f[i]=3*f[i-2]+2*(f[i-4]+f[i-6]+...+f[2]+f[0])
f[i-2]=3*f[i-4]+2*(f[i-6]+f[i-8]+...f[2]+f[0])
->f[i]=4*f[i-2]-f[i-4],i>=4
*/
int main()
{
	f[0] = 1;
	f[2] = 3;
	for (int i = 4; i <= 30; i++)
		f[i] = 4 * f[i - 2] - f[i - 4];
	while (cin >> n) {
		if (n == -1)
			break;
		if (n % 2 == 1) {
			cout << '0' << endl;
			continue;
		}
		cout << f[n] << endl;
	}
	return 0;
}
