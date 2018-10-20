#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int T,n,l,a[155][45],a0[155][45],b[155][45],b0[155][45],ans; bool s[45];
map<long long,bool> cnt;
void shuffle()
{
    int c[45];
    for(int i=0;i<l;++i) c[i]=i;
    for(int i=0;i<100;++i)
    {
        int x=rand()%l,y=rand()%l;
        swap(c[x],c[y]);
    }
    for(int i=0;i<n;++i)
        for(int j=0;j<l;++j) {a[i][j]=a0[i][c[j]]; b[i][j]=b0[i][c[j]];}
}
bool check()
{
    cnt.clear();
    for(int i=0;i<n;++i)
    {
        long long x=0;
        for(int j=0;j<l;++j) x+=(a[i][j]<<j);
        ++cnt[x];
    }
    for(int i=0;i<n;++i)
    {
        long long x=0;
        for(int j=0;j<l;++j) x+=((b[i][j]^s[j])<<j);
        if(!cnt[x]) return 0;
    }
    return 1;
}
void go(int x,int y)
{
    if(x==l)
    {
        if(check()) ans=min(ans,y);
        return;
    }
    int c=0,d=0;
    for(int i=0;i<n;++i) {c+=a[i][x]; d+=b[i][x];}
    if(c*2!=n||d*2!=n)
        if(c==d) {s[x]=0; go(x+1,y);}
        else if(c==n-d) {s[x]=1; go(x+1,y+1);}
        else return;
    else
    {
        s[x]=0; go(x+1,y);
        s[x]=1; go(x+1,y+1);
    }
}
int main()
{
    freopen("i.txt","r",stdin);
    freopen("o.txt","w",stdout);
    scanf("%d",&T);
    for(int I=1;I<=T;++I)
    {
        scanf("%d%d",&n,&l); scanf("\n");
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<l;++j) a0[i][j]=getchar()-'0';
            getchar();
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<l;++j) b0[i][j]=getchar()-'0';
            getchar();
        }
        shuffle(); ans=l+1; go(0,0);
        printf("Case #%d: ",I);
        if(ans>l) printf("NOT POSSIBLE\n");
        else printf("%d\n",ans);
    }
    return 0;
}
