#include<stdio.h>
struct node
{
    int a[1001];
    int size,valid_num;
} tree[1001];

void dfs(int o,int fa)
{
    tree[o].size=1;
    int p=0;
    for (int i=1;i<=tree[o].a[0];i++)
    if (tree[o].a[i]!=fa)
    {
        dfs(tree[o].a[i],o);
        tree[o].size+=tree[tree[o].a[i]].size;
        p++;
    }
    if (p==0)
    {
        tree[o].valid_num=0;
        return;
    }
    if (p==1)
    {
        tree[o].valid_num=tree[o].size-1;
        return;
    }
    int h=1;
    int x=0,y=0;
    while ((h<=tree[o].a[0])&&(p))
    {
        if (tree[o].a[h]==fa) {h++;continue;}
        int temp=tree[tree[o].a[h]].size-tree[tree[o].a[h]].valid_num;
        if (temp>x) {y=x;x=temp;} else y=temp;
        h++;p--;
    }
    for (int i=h;i<=tree[o].a[0];i++)
    if (tree[o].a[i]!=fa)
    {
        int temp=tree[tree[o].a[i]].size-tree[tree[o].a[i]].valid_num;
        if (temp>x) {y=x;x=temp;} else if (temp>y) y=temp;
    }
    tree[o].valid_num=tree[o].size-1-x-y;
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        int n;scanf("%d",&n);
        for (int i=1;i<=n;i++) tree[i].a[0]=0;
        for (int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            tree[x].a[++tree[x].a[0]]=y;
            tree[y].a[++tree[y].a[0]]=x;
        }
        int ans=1e9;
        for (int i=1;i<=n;i++)
        {
            dfs(i,-1);
            ans=(ans<tree[i].valid_num?ans:tree[i].valid_num);
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
