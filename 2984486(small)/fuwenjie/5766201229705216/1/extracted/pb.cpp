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

vector<vector<int> > e;

int getMaxH(int x, int p) {
    if (p != -1 && e[x].size() <= 2) {
        return 1;
    }
    int top1 = 0, top2 = 0;
    for (int i = 0; i < e[x].size(); ++i) {
        int y = e[x][i];
        if (y == p) continue;
        int j = getMaxH(y, x);
        if (j > top1) {
            top2 = top1;
            top1 = j;
        } else if (j > top2) {
            top2 = j;
        }
    }
    if (top2 == 0) return 1;
    return top1 + top2 + 1;
}

int main()
{
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
		int i,j,k;
		int n;
		fin >> n;
		e.clear();
		e.resize(n);
		for (i = 1; i < n; ++i) {
            fin >> j >> k;
            j--; k--;
            e[j].push_back(k);
            e[k].push_back(j);
		}
		int maxH = 1;
		for (i = 0; i < n; ++i) {
            j = getMaxH(i, -1);
            if (j > maxH) maxH = j;
		}
		fout << "Case #" << tind << ": " << n - maxH << endl;
	}
	return 0;
}
