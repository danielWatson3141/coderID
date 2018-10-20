#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <string>
#define maxn 100010
#define ll long long
using namespace std;
string s1[210],s2[210];
int n,l;
int getnum(ll x)
{
    int sum=0;
    while(x)
    {
        sum+=x%2;
        x/=2;
    }
    return sum;
}
int check(ll x)
{
    string tmp[210],tmp2[210];
    for(int i=1;i<=n;i++)
    {
        tmp[i]=s1[i];
        tmp2[i]=s2[i];
    }
    for(int i=0;i<l;i++)
    {
        if((x>>i)&1)
        {
            for(int j=1;j<=n;j++)
            {
                if(tmp[j][i]=='0')
                tmp[j][i]='1';
                else
                tmp[j][i]='0';
            }
        }
    }
    sort(tmp+1,tmp+n+1);
    sort(tmp2+1,tmp2+n+1);
    for(int i=1;i<=n;i++)
    {
        if(tmp[i]!=tmp2[i])
        return 0;
    }
    return 1;
}
int main()
{
    freopen("dd.in","r",stdin);
    freopen("out.txt","w+",stdout);
    int ncase,T=0;
    scanf("%d",&ncase);
    while(ncase--)
    {
        printf("Case #%d: ",++T);
        scanf("%d%d",&n,&l);
        for(int i=1;i<=n;i++)
        cin>>s1[i];
        for(int i=1;i<=n;i++)
        cin>>s2[i];
        int ans=100;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                ll x=0,one=1;
                for(int k=0;k<l;k++)
                {
                    if(s1[i][k]!=s2[j][k])
                    {
                        x+=one<<k;
                    }
                }
                if(check(x))
                {
                    ans=min(ans,getnum(x));
                }
            }
        }
        if(ans<100)
        printf("%d\n",ans);
        else
        printf("NOT POSSIBLE\n");
    }
    return 0;
}
