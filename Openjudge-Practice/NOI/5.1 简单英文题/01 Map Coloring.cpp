#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int mian = 4000, jiao = 6, tang = 2000, you = 500, keke = 500;
int main()
{
	int maxi = 0, ansi, ansj;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if (250 * i + 200 * j <= mian && 2 * i <= jiao && 75 * i + 150 * j <= tang && 100 * i + 150 * j <= you && 75 * j <= 500) {
				if (40 * i + 45 * j > maxi) {
					maxi = 40 * i + 45 * j;
					ansi = i, ansj = j;
				}
			}
		}
	}
	cout << ansj << endl;
	cout << ansi << endl;
	return 0;
}
