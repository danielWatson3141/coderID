#include<cstdio>
#include<fstream>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int> adj[2000];
int sz[2000];
int t,x,y,best,n;
void dfs(int par,int x)
{
    int b1,b2,z;
    b1=0;
    b2=0;
    sz[x]=1;
    if(adj[x].size()-(par>0?1:0)>=2)
        for(int i=0;i<adj[x].size();i++)
            if(adj[x][i]!=par)
            {
                dfs(x,adj[x][i]);
                z=sz[adj[x][i]];
                if(z>=b1)
                {
                    b2=b1;
                    b1=z;
                }
                else if(z>=b2)
                    b2=z;
            }
    sz[x]+=b1+b2;
    //printf("%d %d %d\n",x,b1,b2);
}
int main()
{
    freopen("bsmall.in","r",stdin);
    freopen("bsmall.out","w",stdout);
    cin>>t;
    for(int test=1;test<=t;test++)
    {
        scanf("%d",&n);
        best=n+1;
        for(int i=1;i<=n;i++)
            adj[i].clear();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        //printf("TEST %d\n",test);
        for(int i=1;i<=n;i++)
        {
            memset(sz,0,sizeof(sz));
            //printf("->%d\n",i);
            dfs(-1,i);
            best=min(best,n-sz[i]);
        }
        printf("Case #%d: %d\n",test,best);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
