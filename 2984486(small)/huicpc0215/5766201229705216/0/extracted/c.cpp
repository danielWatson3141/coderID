#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
using namespace std;
#define DEBUG
vector<int> v[1010];
bool ext[1010];
int ans,tmpans;
int dfs(int x,int f)
{
    int len = v[x].size();
    int cnt = 0;
    for(int i=0;i<len;i++)
        if(v[x][i]!=f)
        {
            cnt+=dfs(v[x][i],x);
        }
    if( cnt==0 || cnt==2) return 1;
    else
    {
        if(cnt==1)
        {
            tmpans++;
            for(int i=0;i<len;i++)
                if(v[x][i]!=f)
                    ext[v[x][i]]=false;
        }
        else
        {
            int remain = cnt-2;
            for(int i=0;i<len;i++)
            {
                if(v[x][i]!=f && remain )
                {
                    ext[v[x][i]] = false;
                    remain--;
                }
            }
            tmpans += cnt-2;
        }
        return 1;
    }
}
int dfsext(int x,int f)
{
    int len = v[x].size();
    int cnt = 1;
    for(int i=0;i<len;i++)
        if(v[x][i]!=f && ext[v[x][i]])
            cnt += dfsext(v[x][i],x);
    return cnt;
}
int main()
{
#ifdef DEBUG
freopen("B-small-attempt1.in","r",stdin);
freopen("B-small-attempt1.out","w",stdout);
#endif
    int casecnt=1,t,n;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case #%d: ",casecnt++);
        scanf("%d",&n);
        int a,b;
        for(int i=1;i<=n;i++)
            v[i].clear();
        for(int i=0;i<n-1;i++)
        {
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        ans = 2000;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                ext[j]=true;
            tmpans=0;
            dfs(i,-1);
            if(dfsext(i,-1)==n-tmpans)
            {
                ans = min ( ans , tmpans );
                //printf("update=%d\n",tmpans);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
