#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
char a[200][50],b[200][50];
long long A[50],B[50],q;
int p[200];
main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("A-small.out","w",stdout);
    int T,Case=0;
    int n,l,cnt;
    int ans;
    bool val;
    scanf("%d",&T);
    while(T--)
    {
        cnt=val=0;
        ans=2147483647;
        scanf("%d%d",&n,&l);
        q=(1LL<<n)-1;
        for(int i=0; i<n; i++)p[i]=i;
        for(int i=0; i<n; i++)scanf("%s",a[i]);
        for(int i=0; i<n; i++)scanf("%s",b[i]);
        do
        {
            memset(A,0,sizeof(A));
            memset(B,0,sizeof(B));
            for(int i=0; i<l; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(a[j][i]=='1')A[i]=((A[i]<<1)|1);
                    else A[i]=A[i]<<1;
                }
            }
            for(int i=0; i<l; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(b[p[j]][i]=='1')B[i]=((B[i]<<1)|1);
                    else B[i]=B[i]<<1;
                }
            }
            val=cnt=0;
            for(int i=0; i<l; i++)
            {
                if(A[i]==B[i])continue;
                else if(A[i]==(B[i]^q))cnt++;
                else
                {
                    val=1;
                    break;
                }
            }
            if(!val&&cnt<ans)ans=cnt;
        }
        while(next_permutation(p,p+n));
        if(ans==2147483647)printf("Case #%d: NOT POSSIBLE\n",++Case);
        else printf("Case #%d: %d\n",++Case,ans);
    }
}
