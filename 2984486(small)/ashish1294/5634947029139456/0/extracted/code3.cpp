#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<utility>
#include<math.h>
#include<string.h>
using namespace std;
int arr1[10000],arr2[10000],a1[10000],a2[10000];
int main()
{
    int n,l,i,t,mi;
    char str[10000], *e;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        scanf("%d%d",&n,&l);
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            arr1[i] = strtol(str,&e,2);
            //printf("input = %d\n",arr1[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            arr2[i] = strtol(str,&e,2);
            //printf("input = %d\n",arr1[i]);
            a2[i]=arr2[i];
        }

        sort(a2,a2+n);
        mi = 100000;
        for(i=0;i<(1<<l);i++)
        {
            int flag = 1;
            for(int j=0;j<n;j++)
            {
                a1[j] = arr1[j]^i;
            }
            sort(a1,a1+n);
            for(int j=0;j<n;j++)
            {
                if(a1[j]!=a2[j])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                int co=0;
                for(int k=0;k<l;k++)
                {
                    if((1<<k)&i)
                    {
                        co++;
                    }
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
