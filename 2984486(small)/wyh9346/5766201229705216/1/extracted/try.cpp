#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
struct graph{
    int y,next;
}tree[3000];
struct data{
    int v,i;
    data(int i1,int v1):v(v1),i(i1)
    {

    }
    bool operator < (const data &cmp)const
    {
        return v<cmp.v;
    }
};
int tot,first[1010];
void add(int x,int y)
{
    tot++;
    tree[tot].y=y;
    tree[tot].next=first[x];
    first[x]=tot;
}
int dfs(int i,int fa)
{
    priority_queue<data> v;
    for (int i1=first[i];i1;i1=tree[i1].next)
	{
		if (tree[i1].y==fa)
			continue;
        v.push(data(tree[i1].y,dfs(tree[i1].y,i)));
	}
    int m1=-1,m2=-1;
    while (!v.empty() && (m2==-1))
    {
        data tmp=v.top();
        v.pop();
        if (tmp.i==fa)
            continue;
        if (m1==-1)
        {
            m1=tmp.v;
            continue;
        }
        if (m2==-1)
        {
            m2=tmp.v;
            continue;
        }
    }
    if (m1==-1 || m2==-1)
        return 1;
    return m1+m2+1;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tk,tk1=0,n,i,x,y;
    scanf("%d",&tk);
    while (tk--)
    {
        int ans=0;
        tk1++;
        memset(first,0,sizeof(first));
        tot=0;
        scanf("%d",&n);
        for (i=1;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            add(x,y);
            add(y,x);
        }
        for (i=1;i<=n;i++)
        {
            int res=dfs(i,0);
            ans=max(ans,res);
        }
        printf("Case #%d: %d\n",tk1,n-ans);
    }
    return 0;
}
