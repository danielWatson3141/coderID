#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> edgev[1010];
int n;
int tofull[1010];
int sons[1010];

int dfs(int cnt, int father)
{
    for (int i=0; i<(int)edgev[cnt].size(); i++)
        if (edgev[cnt][i]!=father)
        {
            dfs(edgev[cnt][i], cnt);
            sons[cnt]+=sons[edgev[cnt][i]]+1;
        }
    int childs=edgev[cnt].size()-(father!=0);
    if(childs==1)
        tofull[cnt]=sons[cnt];
    else if (childs>=2)
    {
        int s=0, t=0;
        for (int i=0; i<(int)edgev[cnt].size(); i++)
            if (edgev[cnt][i]!=father)
            {
                int v=edgev[cnt][i];
                if (sons[v]+1-tofull[v]>=s)
                {
                    t=s;
                    s=sons[v]+1-tofull[v];
                }
                else if (sons[v]+1-tofull[v]>=t)
                    t=sons[v]+1-tofull[v];
            }
        tofull[cnt]=sons[cnt]-s-t;

    }
    else
        tofull[cnt]=0;
    return tofull[cnt];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int CAS1;
    scanf("%d", &CAS1);
    for (int CAS=1; CAS<=CAS1; CAS++)
    {
        scanf("%d", &n);
        for (int i=1; i<=n; i++)
            edgev[i].clear();
        for (int i=1; i<n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            edgev[u].push_back(v);
            edgev[v].push_back(u);
        }
        int ans=n;
        for (int i=1; i<=n; i++)
        {
            memset(tofull, 0, sizeof(tofull));
            memset(sons, 0, sizeof(sons));
            int temp=dfs(i, 0);
            if (temp<ans)
                ans=temp;
        }
        printf("Case #%d: %d\n", CAS, ans);
    }
    return 0;
}
