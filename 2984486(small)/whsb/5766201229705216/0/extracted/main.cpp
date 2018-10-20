#line 2 "TorusSailing.cpp"
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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

map<int,int> dp[1024];
int N;
vector<int> son[1024];

void init()
{
    for(int i=0;i<=N;i++)
    {
        dp[i].clear();
        son[i].clear();
    }
}

int DP(int x,int fa)
{
    if(dp[x].find(fa)!=dp[x].end()) return dp[x][fa];
    int sonnum=son[x].size();
    int mx[2]={-1,-1};
    for(int ii=0;ii<sonnum;ii++)
    {
        int v=son[x][ii];
        if(v==fa) continue;
        mx[1]=max(mx[1],DP(v,x));
        if(mx[0]<mx[1]) swap(mx[0],mx[1]);
    }
    int ret=1;
    if(mx[1]>=1)
    {
        ret+=mx[0]+mx[1];
    }
    dp[x].insert(pair<int,int>(fa,ret));
    return ret;
}

int main()
{
    int x,y;
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
        int casT;
        scanf("%d",&casT);
        for(int cas=1;cas<=casT;cas++)
        {
            scanf("%d",&N);
            init();
            for(int i=1;i<N;i++)
            {
                scanf("%d%d",&x,&y);
                son[x].push_back(y);
                son[y].push_back(x);
            }
            int ans=N+100;
            for(int i=1;i<=N;i++)
            {
                ans=min(ans,N-DP(i,-1));
            }
            printf("Case #%d: %d\n",cas,ans);
        }

        return 0;
}

