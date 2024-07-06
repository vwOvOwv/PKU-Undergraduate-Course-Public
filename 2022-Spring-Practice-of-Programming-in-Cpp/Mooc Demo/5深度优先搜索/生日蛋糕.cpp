#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;
int N, M;
int min_area = INT_MAX;//���ű����
int area = 0;//���ڴ�еĵ���ı����
void dfs(int v, int n, int r, int h) {//��n������v����ײ�뾶���ܳ���r���߶Ȳ��ܳ���h
    //�����Կ��ǻ�û�����������½�����ȱ������Ĺ�ϵ���п����Լ�֦
    if (h < n || r  < n)//�����Լ�֦
        return;
    if (n == 0) {
        if (v)
            return;
        else {
            min_area = min(min_area, area);
            return;
        }
    }
    if (v <= 0)
        return;
    for (int rr = r; rr >= n; rr--) {//��n��뾶����Ϊn
        if (n == M)//��ײ�
            area = rr * rr;//ͶӰ
        for (int hh = h; hh >= n; hh--) {//��n��߶�����Ϊn
            if (area + 2 * rr * hh < min_area) {//�����Լ�֦
                area += 2 * rr * hh;
                dfs(v - rr * rr * hh, n - 1, rr - 1, hh - 1);
                area -= 2 * rr * hh;
            }
        }
    }
}
int main()
{
    cin >> N >> M;
    int max_r = sqrt(N);
    int max_h = N;
    dfs(N, M, max_r, max_h);
    if (min_area == INT_MAX)
        cout << 0;
    else
        cout << min_area;
    return 0;
}
