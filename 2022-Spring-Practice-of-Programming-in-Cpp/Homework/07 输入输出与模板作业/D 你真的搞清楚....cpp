#include <iostream>
using namespace std;
class MyCin
{
	//
    bool judge;
public:
    MyCin():judge(true){}//��ʼ��judgeΪtrue
    operator bool() { return judge; }//����bool��ʹ��������ж������Ƿ����
    MyCin& operator>>(int &n) {//����int n�������ʵ����ֵ��
        cin >> n;
        if (n == -1)//�������
            judge = false;
        return *this;
    }
    //
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2)
        cout  << n1 << " " << n2 << endl;
    return 0;
}
