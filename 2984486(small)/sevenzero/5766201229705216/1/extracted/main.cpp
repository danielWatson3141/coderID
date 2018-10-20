#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<int> ed[1111];

int sz[1111]= {0};
int bn[1111]= {0};

void fc(int u,int f)
{
    sz[u]=1;
    int cnt=0;
    for(int i=0; i<ed[u].size(); i++)
    {
        if(f!=ed[u][i])
        {
            cnt++;
            fc(ed[u][i],u);
            sz[u]+=sz[ed[u][i]];
        }
    }
    int fst=0,sec=0;
    if(cnt>=2)
    {
        for(int i=0; i<ed[u].size(); i++)
            if(f!=ed[u][i])
            {
                if(sz[ed[u][i]]-bn[ed[u][i]]>fst)
                {
                    sec=fst;
                    fst=sz[ed[u][i]]-bn[ed[u][i]];
                }
                else if(sz[ed[u][i]]-bn[ed[u][i]]>sec)
                    sec=sz[ed[u][i]]-bn[ed[u][i]];
            }
        bn[u]=sz[u]-1-fst-sec;
    }
    else
        bn[u]=sz[u]-1;


}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cc=0; cc<t; cc++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            ed[i].clear();
        for(int i=0; i<n-1; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            a--;
            b--;
            ed[a].push_back(b);
            ed[b].push_back(a);
        }
        int ans=n;
        for(int i=0; i<n; i++)
        {
            memset(sz,0,sizeof(sz));
            memset(bn,0,sizeof(bn));
            fc(i,-1);
            //printf("bb%d\n",bn[i]);
            if(ans>bn[i])
                ans=bn[i];
        }
        printf("Case #%d: %d\n",cc+1,ans);
    }
    return 0;
}
