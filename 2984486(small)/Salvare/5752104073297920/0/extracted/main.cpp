#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

/*
int cnt[200],a[200];
#include<ctime>
int main()
{
    srand(time(NULL));
    int n=8;
    for(int i=0;i<10000000;i++)
    {
        for(int j=0;j<n;j++)a[j]=j;
        for(int j=0;j<n;j++)
        {
            int x=rand()%n;
            swap(a[j],a[x]);
        }
        int b=0;
        for(int j=0;j<n;j++)
            for(int k=j+1;k<n;k++)
                b+=a[j]>a[k];
        cnt[b]++;
    }
    for(int i=0;i<=n*(n-1)/2;i++)
        printf("%d\n",cnt[i]);
    return 0;
}*/



pair<int,int>a[2000];
int bit[2000];
int query(int x)
{
    int s=0;
    while(x<1050)s+=bit[x],x+=x&-x;
    return s;
}
void updat(int x)
{
    while(x)bit[x]++,x-=x&-x;
}
int main()
{
    freopen("C-small-attempt3.in","r",stdin);
    freopen("C-small-attempt3.out","w",stdout);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n,x;scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&x),a[i]=make_pair(x,i+1);
        sort(a,a+n);
        int ans=0;
        double tot=n*(n-1)/4.0;
        memset(bit,0,sizeof(bit));
        for(int i=0;i<n;i++)
            ans+=query(a[i].second),updat(a[i].second);
        printf("Case #%d: ",ti++);
        if((ans-tot)/tot>-0.005)puts("GOOD");
        else puts("BAD");
    }
    return 0;
}
