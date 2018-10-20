#include <set>
#include <map>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstddef>
#include <sstream>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0 ? -x : x; }

#define N 33
int ii = 0;
int y[N], x[N], p[N], deg[N], a[N], b[N];
bool used[N], u[N];

void addedge(int a, int b)
{
	y[++ii] = b;
	p[ii] = x[a];
	x[a] = ii;
}

void dfs(int v)
{
    if (used[v] || used[0])
        return;
    used[v] = true;
    int cnt = 0;
    for (int q = x[v]; q; q = p[q])
        if (!used[y[q]])
            cnt += 1;

    if (cnt != 0 && cnt != 2)
    {
        used[0] = true;
        return;
    }
    for (int q = x[v]; q; q = p[q])
        dfs(y[q]);
}

int main()
{
//*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
//*/
    int TESTS;
    scanf("%d\n", &TESTS);
    for (int tests = 1; tests <= TESTS; tests++)
    {
        int n;
    	cin >> n;
    	for (int i = 1; i < n; i++)
    		cin >> a[i] >> b[i];

        int Min = (int) 1e9;
    	for (int mask = 0; mask < (1 << n); mask++)
    	{
            int v = 0;
    		memset(u, 0, sizeof u);
    		for (int i = 0; i < n; i++)
    			if (mask & (1 << i))
                    u[i + 1] = true;
                else
                    v += 1;

            if (v == 1)
            {
                Min = min(Min, n - 1);
                continue;
            }
            ii = 0;
            memset(x, 0, sizeof x);
            memset(y, 0, sizeof y);
            memset(p, 0, sizeof p);
            memset(deg, 0, sizeof deg);
            for (int i = 1; i < n; i++)
                if (!u[a[i]] && !u[b[i]])
                {
                    addedge(a[i], b[i]);
                    addedge(b[i], a[i]);
                    deg[a[i]] += 1;
                    deg[b[i]] += 1;
                }

            memset(used, 0, sizeof used);
            int count_used = 0;
            for (int i = 1; i <= n; i++)
                if (deg[i] == 2)
                {
                    dfs(i);
                    for (int j = 1; j <= n; j++)
                        count_used += used[j];
                    break;
                }

            if (count_used == v && !used[0])
                Min = min(Min, n - v);
    	}
        printf("Case #%d: %d\n", tests, Min);
    }
    return 0;
}
