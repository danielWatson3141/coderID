#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> has[1000];

int dp[1000][1001];
int dp2[1000][1001];

int count(int at, int parent)
{
    int& res = dp2[at][parent];
    if(res != -1)
        return res;
    res = 0;
    for(int i=0; i<has[at].size(); i++)
    {
        if(has[at][i]==parent)
            continue;
        res += count(has[at][i], at)+1;
    }
    return res;
}

int go(int at, int parent)
{
    int& res = dp[at][parent];
    if(res != -1)
        return res;
    res = count(at, parent);
    int costs[1000];
    int f=0;
    int r2=0;
    for(int i=0; i<has[at].size(); i++)
    {
        int next=has[at][i];
        if (next == parent)
            continue;
        int c = count(next, at)+1;
        r2 += c;
        costs[f++] = go(next, at) - c;
    }
    if (f<2)
        return res;
    nth_element(costs, costs+1, costs+f);
    res = r2+costs[0] + costs[1];
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        for(int i=0; i<1000; i++)
            has[i].clear();
        memset(dp, -1, sizeof(dp));
        memset(dp2, -1, sizeof(dp2));
        int N;
        scanf("%d", &N);
        for(int i=0; i<N-1; i++)
        {
            int X, Y;
            scanf("%d%d", &X, &Y);
            X--;
            Y--;
            has[X].push_back(Y);
            has[Y].push_back(X);
        }
        int res = 9999;
        for(int i=0; i<N; i++)
        {
            int lres = go(i, N);
            //printf("%d: %d\n", i, lres);
            res=min(res, lres);
        }
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
