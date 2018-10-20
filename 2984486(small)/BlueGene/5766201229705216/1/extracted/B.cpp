#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <iterator>
#include <utility>
#include <numeric>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>

using namespace std;

const int MaxN = 1100, MaxE = MaxN*2;

int n, ENum, Next[MaxE], Head[MaxN], v[MaxE], root;
bool View[MaxN];
int f[MaxN], s[MaxN];

inline void AddEdge(const int &x, const int &y)
{
    Next[++ENum] = Head[x];
    v[Head[x] = ENum] = y;
    Next[MaxE-ENum] = Head[y];
    v[Head[y] = MaxE-ENum] = x;
}

void DFS(const int &t)
{
    s[t] = 1;
    View[t] = 1;
    int x = 0x7FFFFFFF, y = 0x7FFFFFFF, cnt = 0;
    for (int i = Head[t]; i; i = Next[i])
        if (! View[v[i]])
        {
            ++cnt;
            DFS(v[i]);
            s[t] += s[v[i]];
            if (f[v[i]]-s[v[i]] <= x)
            {
                y = x;
                x = f[v[i]]-s[v[i]];
            }
            else if (f[v[i]]-s[v[i]] <= y)
                y = f[v[i]]-s[v[i]];
        }
    f[t] = s[t]-1;
    if (cnt >= 2)
        f[t] = min(f[t], s[t]-1+x+y);
}

int main()
{
    freopen("B-large.in.txt", "r", stdin);
    freopen("B-large.out.txt", "w", stdout);
    int TestCase;
    cin >> TestCase;
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        cout << "Case #" << Test << ": ";
        ENum = 0;
        memset(Head, 0, sizeof(Head));
        memset(Next, 0, sizeof(Next));
        cin >> n;
        for (int i = 1, x, y; i < n; ++i)
        {
            cin >> x >> y;
            AddEdge(x, y);
        }
        int Ans = 0x7FFFFFFF;
        for (int i = 1; i <= n; ++i)
        {
            root = i;
            memset(View, 0, sizeof(View));
            DFS(root);
            Ans = min(Ans, f[root]);
        }
        cout << Ans << endl;
    }
    return 0;
}
