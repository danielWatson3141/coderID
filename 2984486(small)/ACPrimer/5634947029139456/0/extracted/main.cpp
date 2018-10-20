#include <iostream>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
using namespace std;
const int maxn = 12;
const int maxL = 12;
char s[maxL];
int a[maxn],b[maxn];
int va[1<<maxL],vb[1<<maxL],vis[maxL];
int n,L,ans;
int trans(char s[])
{
    int n=strlen(s),ans=0;
    for(int i=0;i<n;i++) ans=(ans<<1)+(s[i]=='1'?1:0);
    return ans;
}
int ok()
{
    for(int i=0;i<n;i++) if(va[b[i]]==0)
        return 0;
    return 1;
}
void dfs(int la)
{
    if(ok())
    {
        if(la<ans) ans=la;
        return;
    }
    if(la>L) return;
    for(int i=0;i<L;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            for(int j=0;j<n;j++) b[j]^=1<<i;
            dfs(la+1);
            vis[i]=0;
            for(int j=0;j<n;j++) b[j]^=1<<i;
        }
    }
}
int main()
{
    int T,ncase=0;
    scanf("%d",&T);
    while(T--){
        memset(va,0,sizeof(va));
        memset(vb,0,sizeof(vb));
        scanf("%d%d",&n,&L);
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            a[i]=trans(s);
            va[a[i]]=1;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            b[i]=trans(s);
            vb[b[i]]=1;
        }
        ans=L+1;
        dfs(0);
        if(ans<=L)
        {
            printf("Case #%d: %d\n",++ncase,ans);
        }
        else printf("Case #%d: NOT POSSIBLE\n",++ncase);
    }
    return 0;
}

