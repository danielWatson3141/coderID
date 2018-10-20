#include<algorithm>
#include<iostream>
#include<string.h>
#include<sstream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
//#pragma comment(linker,"/STACK:1024000000,1024000000")
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const double PI=acos(-1.0);
const int maxn=100010;
//typedef __int64 ll;
char el[200][50],de[200][50];
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
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&l);
        for(i=1;i<=n;i++)
            scanf("%s",el[i]+1);
        for(i=1;i<=n;i++)
        {
            scanf("%s",de[i]+1);
            base=0;
            for(j=1;j<=l;j++)
                base=base*2+de[i][j]-'0';
            dd[i]=base;
        }
        sort(dd+1,dd+1+n);
        ans=INF;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                tp=0;
                for(k=1;k<=l;k++)
                    if(el[i][k]!=de[j][k])
                        sw[k]=1,tp++;
                    else
                        sw[k]=0;
                for(p=1;p<=n;p++)
                {
                    base=0;
                    for(q=1;q<=l;q++)
                        base=base*2+((el[p][q]-'0')^sw[q]);
                    ch[p]=base;
                }
                sort(ch+1,ch+n+1);
                if(check())
                    ans=min(ans,tp);
            }
        }
        printf("Case #%d: ",cas++);
        if(ans!=INF)
            printf("%d\n",ans);
        else
            printf("NOT POSSIBLE\n");
    }
    return 0;
}
