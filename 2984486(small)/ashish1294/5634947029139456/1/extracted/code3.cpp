#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<string.h>
using namespace std;
long long int arr1[10000],arr2[10000],a1[10000],a2[10000];
bool isdone[10000];
int main()
{
    int n,l,i,t,mi,done;
    char str[10000], *e;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        scanf("%d%d",&n,&l);
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            arr1[i] = strtoll(str,&e,2);
            isdone[i]=false;
            //printf("input = %d\n",arr1[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            arr2[i] = strtoll(str,&e,2);
            //printf("input = %d\n",arr1[i]);
            a2[i]=arr2[i];
        }
        done=0,mi=100000;
        for(int i=0;i<n;i++)
        {
            long long int ans = arr1[0]^arr2[i];
            //printf("ans = %lld\n",ans);
            for(int j=0;j<n;j++) isdone[j]=false;
            done=1;
            for(int j=0;j<n;j++)
            {
                if(j==i) continue;
                done=0;
                for(int k=1;k<n;k++)
                {
                    //printf("j=%d k=%d v=%lld ans = %lld\n",j,k,arr2[j]^arr1[k],ans);
                    if((arr2[j]^arr1[k])==ans && isdone[k]==false)
                    {
                        //printf("done here\n");
                        isdone[k] = true;
                        done=1;
                        break;
                    }
                }
                if(done==0) break;
            }
            //printf("done=%d\n",done);
            if(done==1)
            {
                int co = 0;
                for(int j=0;j<l;j++)
                {
                    if(ans&(1<<j)) co++;
                }
                if(co<mi) mi=co;
            }
        }


        if(mi == 100000)
        {
            printf("Case #%d: NOT POSSIBLE\n",tt);
        }
        else
        {
            printf("Case #%d: %d\n",tt,mi);
        }
    }
    return 0;
}
