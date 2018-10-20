#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 200
#define LL long long

char s1[N][50],s2[N][50],s3[N][50];
LL p[N],q[N];

LL get(char s[])
{
    int n=strlen(s);
    LL ans=0,ret=1;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='1') ans+=ret;
        ret*=2;
    }
//    printf("%lld **\n",ans);
    return ans;
}

char rev(char c)
{
    if(c=='0') return '1';
    return '0';
}

int main()
{

    freopen("a1.in","r",stdin);
    freopen("a1.out","w",stdout);
    int T;
    scanf("%d",&T);
    for( int ca=1;ca<=T;ca++)
    {
        int n,l;
        scanf("%d%d",&n,&l);
        for(int i=0;i<n;i++) scanf("%s",s1[i]);
        for(int i=0;i<n;i++) scanf("%s",s2[i]);

//        for(int i=0;i<n;i++) puts(s1[i]);
//        for(int i=0;i<n;i++) puts(s2[i]);
  memset(p,0,sizeof p);
        for(int i=0;i<n;i++) p[i]=get(s2[i]);

        int ans=l+1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){
                for(int k=0;k<=l;k++) s3[j][k]=s1[j][k];
            }

            int ret=0;
            for(int j=0;j<l;j++)
            {
                if(s3[i][j]!=s2[n-1][j])
                {   ret++;
                    for(int k=0;k<n;k++) s3[k][j]=rev(s3[k][j]);
                }
            }
           // for(int j=0;j<n;j++) puts(s3[j]);
            if(ret> ans) continue;

              memset(q,0,sizeof q);
            int k=0;
            for(int j=0;j<n;j++)
              if(j!=i)
             {
                q[k++] = get(s3[j]);
             }

             if(k>0)
             {
                 sort(q,q+k);
                 sort(p,p+k);
             }

             bool f=true;
             for(int j=0;j<k;j++) if(p[j]!=q[j]) f=false;
             if(f) ans=ret;
        }

        printf("Case #%d: ",ca);

        if(ans>l)puts("NOT POSSIBLE") ;
        else printf("%d\n",ans);

    }
    return 0;
}
