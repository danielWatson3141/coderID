#include<cstdio>
#include<vector>
#define F first
#define S second
using namespace std;
vector<int> ed[1005];
int DP(int nw,int pr)
{
    int cnt=0,mx[5]={1005},all=0;
    for(int i=0,n=ed[nw].size(),k;i<n;i++)
        if(ed[nw][i]!=pr)
        {
            cnt++;
            mx[3]=DP(ed[nw][i],nw);
            k=3;
            while(mx[k]>mx[k-1])
            {
                swap(mx[k],mx[k-1]);
                k--;
            }
        }
    if(cnt>=2)
        return mx[1]+mx[2]+1;
    else
        return 1;

}
int main()
{
    freopen("Full Binary Tree-small-attempt0.in","r",stdin);
    freopen("Full Binary Tree-small-attempt0.out","w",stdout);
    int T,n,ans;
    scanf("%d",&T);
    for(int I=1;I<=T;I++)
    {
        ans=1000;
        scanf("%d",&n);
        for(int i=1,a1,a2;i<n;i++)
        {
            scanf("%d%d",&a1,&a2);
            ed[a1].push_back(a2);
            ed[a2].push_back(a1);
        }
        for(int i=1;i<=n;i++)
        {
            //printf("@ %d = %d\n",i,n-DP(i,0));
            ans=min(ans,n-DP(i,0));
        }
        printf("case #%d: %d\n",I,ans);
        for(int i=1;i<=n;i++)
            ed[i].clear();
    }
}
