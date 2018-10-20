#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int>gra[2000];
int deg[2000],root;
pair<int,int>dfs(int s,int p)
{
    int y,b=0,m1=0,m2=0,cnt=0;
    pair<int,int>t;
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])!=p)
        {
            cnt++;
            t=dfs(y,s);
            b+=t.second;
            if(t.second-t.first>m1)
            {
                m2=m1;
                m1=t.second-t.first;
            }
            else if(t.second-t.first>m2)m2=t.second-t.first;
        }
    if(cnt>=2)return make_pair(b-m1-m2,b+1);
    else return make_pair(b,b+1);
}
int main()
{
    freopen("B-large.in","r",stdin);
    //freopen("B-large.out","w",stdout);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n,x,y;scanf("%d",&n);
        for(int i=1;i<=n;i++)gra[i].clear(),deg[i]=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            gra[x].push_back(y);
            gra[y].push_back(x);
            deg[x]++;deg[y]++;
        }
        int ans=n-1;
        for(int i=1;i<=n;i++)
            if(deg[i]>=2)
                root=i,ans=min(ans,dfs(i,0).first);
        printf("Case #%d: %d\n",ti++,ans);
    }
    return 0;
}
