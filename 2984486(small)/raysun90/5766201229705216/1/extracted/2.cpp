#include<cstdio>
#include<iostream>
#include<string>
#include <vector>
#include<cstring>
#include<algorithm>
using namespace std;
vector <int> vi[1010];
int gao(int a,int fa)
{
    int size=vi[a].size();
    if(fa!=-1)
        size--;
    int ret=1;
    if(size<=1)
        return ret;
    for(int i=0;i<vi[a].size();i++)
        for(int j=i+1;j<vi[a].size();j++)
        {
            if(vi[a][i]==fa|| vi[a][j]==fa)
                continue;
            ret=max(ret,1+gao(vi[a][i],a)+gao(vi[a][j],a));
        }
    return ret;
}
int main()
{
    int ntotal,nid;
    scanf("%d",&ntotal);
    for(nid=1;nid<=ntotal;nid++)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            vi[i].clear();
        int m=n-1;
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            vi[a].push_back(b);
            vi[b].push_back(a);
        }
        int ans=1;
        for(int i=1;i<=n;i++)
            ans=max(ans,gao(i,-1));
        printf("Case #%d: ",nid);
        printf("%d\n",n-ans);
    }
    return 0;
}
