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

int V[20], C[20], i, N;
VI E[20];

void dfs (int pos, int parent) {
    V[pos] = 1;
    for (int j = 0; j < E[pos].size(); j++) {
        int k = E[pos][j];
        if (V[k]) continue;
        if (i&(1<<(k-1))) continue;
        if (k == parent) continue;
        C[pos] ++;
        dfs(k, pos);
    }
    return;
}

bool check () {
    for (int j = 1; j <= N; j++)
    {
        if (i&(1<<(j-1))) continue;
        if (!V[j]) return 0;
        if (C[j]%2) return 0;
        if (C[j] > 2) return 0;
    }
    return 1;
}

int main()
{
    //freopen ("2Full Binary Tree.txt","r",stdin);
    freopen ("B-small-attempt0.in","r",stdin);
    freopen ("B-small-attempt0.txt","w",stdout);

    int j, k, t, tc = 0, ans;

    cin >> t;
    while (tc < t) {
        tc++;
        for (i = 0; i < 20; i++) E[i].clear();


        cin >> N;
        ans = N-1;

        for (i = 0; i < N-1; i++) {
            cin >> j >> k;
            E[j].PB (k);
            E[k].PB (j);
        }

        for (i = 0; i < (1<<N); i++) {
            for (j = 1; j <= N; j++) {
                if (!(i&(1<<(j-1)))) {
                    memset(V, 0, sizeof (V));
                    memset(C, 0, sizeof (C));
                    dfs (j, -1);
                    if (check()) ans = min (ans, bitcount(i));
                }
            }
        }

        printf ("Case #%d: %d\n", tc, ans);

    }


    return 0;
}
