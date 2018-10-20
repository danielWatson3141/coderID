#include <cstdio>
#include <cassert>
#include <algorithm>
#include <memory.h>
using namespace std;

const int n = 1000;

void solve(int cs)
{
    scanf("%d", new int);
    int q;
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        q += t < i;
    }
    printf("Case #%d: %s\n", cs + 1, (q > (471 + 500) / 2 ? "GOOD" : "BAD"));
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i);
}
