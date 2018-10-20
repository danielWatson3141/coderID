#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <set>
#include <cstring>
#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define VI vector <int>
#define VII vector < vector <int> >
#define S1(x) scanf("%llu",&x)
using namespace std;
// test 1 V 1.0
int n;
vector <int> aa,bb;
vector < vector <int> > s;
vector <bool> dp;
vector <int> down;
int ddd[1009][3];

int fun (int index, int x)
{
    if (x == 3) {
        return 10000;
    }
    if (index == aa.size()) {
        if (x == 1) {
            return 10000;
        }
        return 0;
    }

    int &result = ddd[index][x];
    if (result != -1) {
        return result;
    }
    result = fun (index+1, x) + bb[index];
    result = min (result, aa[index]+fun(index+1, x+1));
    return result;
}

int cal (vector <int> s, vector <int> a)
{
    aa = s;
    bb = a;
    if (s.size() == 0) {
        return 0;
    }
    if (s.size() == 1) {
        return a[0];
    }
    memset (ddd, -1, sizeof(ddd));
    return fun (0, 0);
}

int f (int x, int p)
{
    vector <int> aa;
    vector <int> bb;
    int i,sum=0;
    F (i, 0, s[x].size()) {
        int xx = s[x][i];
        if (xx == p) {
            continue;
        }
        int xxx = f (xx, x);
        aa.pb (xxx);
        bb.pb (down[xx]);
    }
    return cal (aa, bb);
}

int ff (int x, int p)
{
    down[x] = 1;
    int i,sum=0;
    F (i, 0, s[x].size()) {
        int xx = s[x][i];
        if (xx == p) {
            continue;
        }
        ff (xx, x);
        down[x] += down[xx];
    }
}

int main()
{
    int t;
    S (t);
    int ii = 1;
    while (t--) {
        cout << "Case #" << ii++<< ": ";

        cin >> n;
        s.clear();  s.resize (n);
        int sum = n;
        for (int i = 0; i < n-1; i++) {
            int x,y;
            cin >> x >> y;
            x--;
            y--;
            s[x].pb (y);
            s[y].pb (x);
        }


       for (int j = 0; j < n; j++) {
            dp.resize (n);
            down.resize (n);
            for (int ii = 0; ii < dp.size(); ii++) {
                dp[ii] = false;
                down[ii] = 0;
            }
            ff (j, j);
            sum = min (sum, f(j, j));
        }
        cout << sum << endl;
    }
    return 0;
}
