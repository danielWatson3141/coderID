#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
const int N=1100;
vector<int> v[N];
int f[N],num[N];

int dfs(int now)
{
    vector<int> a;
    a.clear();
    num[now]=1;
    for (int i=0; i<v[now].size(); i++)
    {
        int x=v[now][i];
        if (x==f[now]) continue;
        f[x]=now;
        a.push_back(dfs(x)-num[x]);
        num[now]+=num[x];
    }
    if (a.size()==0) return 0;
    if (a.size()==1) return num[now]-1;
    sort(a.begin(),a.end());
    return num[now]-1+a[0]+a[1];
}

int main()
{
    int o,n,x,y,cas=0;
    scanf("%d",&o);
    while (o--)
    {
        scanf("%d",&n);
        for (int i=1; i<=n; i++) v[i].clear();
        for (int i=1; i<n; i++)
        {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        int ans=-1;
        for (int i=1; i<=n; i++)
        {
            memset(f,0,sizeof(f));
            memset(num,0,sizeof(num));
            f[i]=-1;
            int s=dfs(i);
            if (ans==-1 || ans>s) ans=s;
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
}