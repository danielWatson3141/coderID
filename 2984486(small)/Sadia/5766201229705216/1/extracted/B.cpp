#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<map>
#include<utility>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;
#define MAXI(a,b) ((a)>(b)?(a):(b))
#define MINI(a,b) ((a)<(b)?(a):(b))
#define MAXN 1006
vector < vector < int > > Edges(MAXN);
int subs[MAXN], dp[MAXN];
bool cmp(pair < int , int > a, pair < int , int > b)
{
    return a.second > b.second;
}
pair < int , int > dfs(int parent, int node) // cost, subtree size
{
    vector < pair < int , int > > V; V.clear();
    int i,now,c;
    int sub = 1;
    pair < int , int > pp;
    for (i=0; i<Edges[node].size(); ++i)
    {
        now = Edges[node][i];
        if (now == parent) continue;
        pp = dfs(node,now);
        V.push_back(make_pair(now,pp.first));
        sub += pp.second;
    }
    subs[node] = sub;
    if (V.size() == 0)
    {
        dp[node] = 0;
        return make_pair(0,sub);
    }
    if (V.size() == 1)
    {
        dp[node] = subs[node]-1;
        return make_pair(dp[node], sub);
    }
    for (i=0; i<V.size(); ++i)
    {
        now = V[i].first;
        V[i].second = subs[now] - dp[now];
    }
    sort (V.begin(), V.end(), cmp);
    /*if (parent == -1 && node == 1)
    {
        for (int i=0; i<V.size(); ++i) printf("(%d %d) ", V[i].first, V[i].second); puts("");
    }*/
    int c1 = V[0].first, c2 = V[1].first;
    //c = dp[c1] + dp[c2] + sub-1 - subs[c1] - subs[c2];
    c = sub-1 - V[0].second - V[1].second;
    dp[node] = c;
    return make_pair(dp[node],sub);
}
int main()
{
    //freopen("data.txt", "r", stdin);
    freopen("Bin.txt", "r", stdin);
    freopen("Bout.txt", "w", stdout);
    int t,T;
    int N,M,i,x,y;
    int temp,ans;
    scanf("%d", &T);
    for (t=1; t<=T; ++t)
    {
        scanf("%d", &N);
        for (i=1; i<=N; ++i) Edges[i].clear();
        M = N-1;
        while (M--)
        {
            scanf("%d %d", &x, &y);
            Edges[x].push_back(y);
            Edges[y].push_back(x);
        }
        ans = N;
        for (i=1; i<=N; ++i)
        {
            temp = dfs(-1,i).first;
            if (temp <= ans)
            {
                ans = temp;
                //printf("%d : %d\n", i, temp);
            }
            //if (t == 1 && i == 1) printf("%d\n", dp[1]);
        }
        printf("Case #%d: %d\n", t, ans);
        //break;
    }
    return 0;
}
