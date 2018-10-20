#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
#include <iomanip>
using namespace std;

#define mset(A,B) memset(A,B,sizeof(A));
#define mcpy(A,B) memcpy(A,B,sizeof(B));
typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
//typedef vector<string> vstr;
#define FI(I,L,U) for (int I=L;I<U;I++)
#define sqr(x) ((x)*(x))

ld p[1000][1000] = {};

int main()
{
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
		int i,j;
		int n;
		fin >> n;
		if (tind == 1) {
            for (i = 0; i < n; i++) p[i][i] = n;
            for (int k = 0; k < n; k++) {
                for (i = 0; i < n; i++) {
                    if (i == k) continue;
                    for (j = 0; j < n; j++) p[i][j] += 1.0 * (p[k][j] - p[i][j]) / n;
                }
                for (j = 0; j < n; j++) p[k][j] = 1.0;
/*
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        cout << p[i][j] << ' ';
                    }
                    cout << endl;
                }
                cout << endl;*/
            }
                    for (j = 0; j < n; j++) {
                        cout << p[0][j] << ' ';
                    }
                    cout << endl;
		}
		ld ans = 1.0;
		for (i = 0; i < n; i++) {
            fin >> j;
            ans *= p[i][j];
		}
		cout << tind << ' ' << ans << endl;
		if (ans == 1.0) {
            cout << "tie " << tind << ' ' << ans << endl;
		}
        if (ans > 1.0 || (ans == 1.0 && rand()*2 < RAND_MAX))
            fout << "Case #" << tind << ": BAD" << endl;
        else
            fout << "Case #" << tind << ": GOOD" << endl;
	}
	return 0;
}
