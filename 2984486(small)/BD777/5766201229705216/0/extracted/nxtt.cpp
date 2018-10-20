#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define bug puts("here");

using namespace std;

typedef long long ll;

const int maxn = 10086;
const ll mod = 1e9+7;
const int inf = 0x3f3f3f3f;
const double PI = atan(1.0) * 4.0;

vector<int> head[1200];
int in[1200];
queue<int> que;
bool vis[1200];

int main()
{
    freopen("B-small-attempt4.in","r",stdin);
    freopen("B-small-attempt4.txt","w+",stdout);
    int T;
    int kase = 0;
    scanf("%d",&T);
    while(T--)
    {
        kase ++;
        int n;
        scanf("%d",&n);
        int i;
        for(i=1;i<=n;i++) head[i].clear();
        memset(in,0,sizeof(in));
        while(!que.empty()) que.pop();
        for(i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            head[u].push_back(v);
            head[v].push_back(u);
            in[u] ++;
            in[v] ++;
        }
        if(n == 2)
        {
            printf("Case #%d: %d\n",kase,1);
            continue;
        }
        int x[1200];
        memset(x,0,sizeof(x));
        int xx = 0;
        int ans = 0;
        for(i=1;i<=n;i++)
        {
            x[in[i]] ++;
            if(in[i] == 1) que.push(i);
            if(in[i] > 3) xx ++;
        }
        memset(vis,false,sizeof(vis));
        while(!que.empty())
        {
            if(x[2] == 1 && xx == 0) break;
            int now = que.front();
            que.pop();
            bool flag = false;
            for(i=0;i<head[now].size();i++)
            {
                int v = head[now][i];
                if(vis[v]) continue;
                if(in[v] > 3) flag = true;
                if(x[2] > 1 && in[v] == 2) flag = true;
                if(x[2] == 0 && in[v] == 3) flag = true;
            }
            if(flag)
            {
                vis[now] = true;
                ans ++;
                for(i=0;i<head[now].size();i++)
                {
                    int v = head[now][i];
                    if(vis[v]) continue;
                    if(in[v] == 4) xx --;
                    x[in[v] --] --;
                    x[in[v]] ++;
                    if(in[v] == 1) que.push(v);
                }
            }
        }
        printf("Case #%d: %d\n",kase,ans);

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
