#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<map>
#include<algorithm>
#define maxn 100005
using namespace std;

char a[200][50],b[200][50];
int sw[50],n;
long long ee[150],dd[150],ch[150];

bool check()
{
    int i;
    for(i=1;i<=n;i++)
        if(ch[i]!=dd[i])
            return false;
    return true;
}

int main()
{
    int t,l,i,j,k,p,q,cas=1,tp,ans;
    long long base;
    freopen("p.in","r",stdin);
    freopen("p.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&l);
        for(i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        for(i=1;i<=n;i++)
        {
            scanf("%s",b[i]+1);
            base=0;
            for(j=1;j<=l;j++)
                base=base*2+b[i][j]-'0';
            dd[i]=base;
        }
        sort(dd+1,dd+1+n);
        ans=100000;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                tp=0;
                for(k=1;k<=l;k++)
                    if(a[i][k]!=b[j][k])
                        sw[k]=1,tp++;
                    else
                        sw[k]=0;
                for(p=1;p<=n;p++)
                {
                    base=0;
                    for(q=1;q<=l;q++)
                        base=base*2+((a[p][q]-'0')^sw[q]);
                    ch[p]=base;
                }
                sort(ch+1,ch+n+1);
                if(check())
                    ans=min(ans,tp);
            }
        }

        printf("Case #%d: ",cas++);

        if(ans!=100000)
            printf("%d\n",ans);
        else
            printf("NOT POSSIBLE\n");
    }
    return 0;
}



