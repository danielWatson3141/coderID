#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 1010;
int N, V, dp[MAXN], tsize[MAXN];
bool used[MAXN];
vector <int> adja[MAXN], chosen[MAXN];

int solve(int now)
{
//    fprintf(stderr, "WHY ! %d\n", now);
    used[now] = true;
    chosen[now].clear();
    tsize[now] = 0;
    dp[now] = 0;

    for(int i = 0; i < adja[now].size(); i++)
    {
        int nextv = adja[now][i];

        if(used[ nextv ] == false)
        {
            solve( nextv ) ;
            tsize[ now ] += tsize[ nextv ]+1;
            chosen[now].push_back( tsize[nextv]+1-dp[ nextv ] );
            dp[now] += tsize[nextv]+1;
        }
    }

    if(chosen[now].size() >= 0) sort(chosen[now].begin(), chosen[now].end());

    if(chosen[now].size() >= 2)
    {

        for(int i = 0; i < 2; i++)
        {
            int offset = chosen[now].size()-1;
            dp[now] -= chosen[now][offset-i];
        }
    }

//    fprintf(stderr, "WHY FINAL ! %d - %d %d\n", now, dp[now], tsize[now]);
    return dp[now];
}

int main()
{
    int TC;
    scanf("%d", &TC);

    for(int tc = 1; tc <= TC; tc++)
    {
        scanf("%d", &N);
        V = 0;
        for(int i = 0; i < MAXN; i++)
            adja[i].clear();

        for(int i = 1; i < N; i++)
        {
            int f , t;
            scanf("%d%d", &f, &t);
            V = max(V, f);
            V = max(V, t);
            adja[f].push_back( t );
            adja[t].push_back( f );
        } 

        int theMin = 10000;
        for(int i = 1; i <= V; i++)
        {
            memset(used, 0, sizeof(used));
            theMin = min(theMin, solve(i));
        }

        printf("Case #%d: %d\n", tc, theMin);
    }

    return 0;
}
