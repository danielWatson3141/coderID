#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

long long lib[200],to[200],te[200];
char s[50];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        memset(lib,0,sizeof(lib));
        memset(to,0,sizeof(to));
        int n,l;scanf("%d%d",&n,&l);
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            for(int j=0;s[j];j++)
                lib[i]=lib[i]*2+s[j]-'0';
        }
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            for(int j=0;s[j];j++)
                to[i]=to[i]*2+s[j]-'0';
        }
        sort(lib,lib+n);
        int ans=10000;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            long long dif=lib[0]^to[i],ha=0;
            for(int j=0;j<l;j++)
                if((1<<j)&dif)ha|=1<<j,cnt++;
            for(int j=0;j<n;j++)
                te[j]=to[j]^ha;
            sort(te,te+n);
            bool f=1;
            for(int j=0;j<n;j++)
                if(te[j]!=lib[j]){f=0;break;}
            if(f)ans=min(ans,cnt);
        }
        if(ans<10000)printf("Case #%d: %d\n",ti++,ans);
        else printf("Case #%d: NOT POSSIBLE\n",ti++);
    }
    return 0;
}
