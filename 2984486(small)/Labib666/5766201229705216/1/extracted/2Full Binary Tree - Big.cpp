/*
ID: Labib Rashid
LANG: C++
TASK: Codejam R1A 2014, Task - Full Binary Tree
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>

#define LL long long
#define PB push_back
#define X first
#define Y second
#define INF 1000000007
#define PI 2*asin(1)
#define PII pair<int,int>
#define VI vector <int>
#define EPS 1e-9

using namespace std;

int gcd (int a, int b)
{
    if (b > a) return gcd (b,a);
    return (b == 0) ? a : gcd (b, a%b);
}

int bitcount (int a)
{
    return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;
}

int N;
VI E[1020];

int dfs (int pos, int par) {
    //cout << "in " << pos << endl;
    int sz = 1, m[2] = {0,0}, i, j, k;

    if (par == -1 && E[pos].size() < 2) return 1;
    else if (par > -1 && E[pos].size() < 3) return 1;

    for (i = 0; i < E[pos].size(); i++)
    {
        if (E[pos][i] == par) continue;
        k = dfs (E[pos][i], pos);
        //cout << E[pos][i] << " " << k << endl;
        if (k > m[0]) m[1] = m[0], m[0] = k;
        else if (k > m[1]) m[1] = k;
    }

    return sz + m[0] + m[1];
}


int main()
{
    //freopen ("2Full Binary Tree.txt","r",stdin);
    freopen ("B-large.in","r",stdin);
    freopen ("B-large.txt","w",stdout);

    int j, k, t, tc = 0, ans;

    cin >> t;
    while (tc < t) {
        tc++;
        for (int i = 0; i < 1020; i++) E[i].clear();

        cin >> N;
        ans = 0;

        for (int i = 0; i < N-1; i++) {
            cin >> j >> k;
            E[j].PB (k);
            E[k].PB (j);
        }

        for (int i = 1; i <= N; i++) {
            ans = max (dfs (i, -1), ans);
        }


        printf ("Case #%d: %d\n", tc, N-ans);

    }


    return 0;
}
