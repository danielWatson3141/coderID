#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

using namespace std;

#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define DWN(i,h,l) for(int i=(h);i>=(l);--i)
#define CLR(arr) memset(arr,0,sizeof(arr))
#define MAX3(a,b,c) max(a,max(b,c))
#define MAX4(a,b,c,d) max(max(a,b),max(c,d))
#define MIN3(a,b,c) min(a,min(b,c))
#define MIN4(a,b,c,d) min(min(a,b),min(c,d))
#define MST(arr,val) memset(arr,val,sizeof(arr))
#define PI acos(-1.0)
#define oo 1000000000
#define loo 1000000000000000000LL
#define eps 1e-8

typedef long long ll;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

int g[20][20],tg[20][20],visit[20],n;
bool flag;

void dfs(int u)
{
    int total = 0;
    FOR(i,1,n)
    {
        if(!visit[i] && tg[u][i] )
        {
            total++;
        }
    }
    if(total == 0 || total == 2)
    {
        FOR(i,1,n)
        {
            if(!visit[i] && tg[u][i] )
            {
                visit[i] = 1;
                dfs(i);
            }
        }
    }
    else
    {
        flag = false;
        return ;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,cs=0,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        CLR(g);
        REP(i,n-1)
        {
            scanf("%d%d",&x,&y);
            g[x][y] = g[y][x] = 1;
        }
        int total,ans=oo;
        REP(i,(1<<n))
        {
            FOR(j,1,n)
            FOR(k,1,n)
            tg[j][k] = g[j][k];
            total = 0;
            REP(j,n)
            {
                if(i & (1<<j))
                {
                    total++;
                    FOR(k,1,n)
                    tg[j+1][k] = tg[k][j+1] = 0;
                }
            }
            FOR(j,1,n)
            {
                int kk = 0;
                flag = true;
                CLR(visit);
                visit[j] = 1;
                dfs(j);
                FOR(k,1,n)
                if(visit[k]) kk++;
                if(kk + total != n) flag = false;
                if(flag)
                break;
            }
            if(flag && total < ans){
                ans =min(total,ans);
            }
        }
        printf("Case #%d: %d\n",++cs,ans);
    }
    return 0;
}
