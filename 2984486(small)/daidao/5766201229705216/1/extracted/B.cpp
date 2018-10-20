#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<stdlib.h>
#define nn 1100
#define inff 0x3fffffff
using namespace std;
int n;
struct node
{
    int en,next;
}E[nn*2];
int p[nn],num;
bool use[nn];
int fc[nn][nn];
void init()
{
    memset(p,-1,sizeof(p));
    num=0;
}
void add(int st,int en)
{
    E[num].en=en;
    E[num].next=p[st];
    p[st]=num++;
}
bool cmp(int x,int y)
{
    return x>y;
}
int dfs(int id)
{
    use[id]=true;
    int i,w;
    int ix=0;
    for(i=p[id];i!=-1;i=E[i].next)
    {
        w=E[i].en;
        if(!use[w])
        {
            fc[id][ix++]=dfs(w);
        }
    }
    if(ix==0||ix==1)
    {
        return 1;
    }
    sort(fc[id],fc[id]+ix,cmp);
    return fc[id][0]+fc[id][1]+1;
}
int main()
{
    freopen("Bin.txt","r",stdin);
    freopen("Bout.txt","w",stdout);
    int t,i,x,y;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        init();
        scanf("%d",&n);
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        int ans=inff;
        for(i=1;i<=n;i++)
        {
            memset(use,false,sizeof(use));
            ans=min(n-dfs(i),ans);
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
