#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<queue>
#include<algorithm>
using namespace std;
int a[1010];
int main()
{
    srand(time(NULL));
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tk,tk1=0,n,i,j;
    scanf("%d",&tk);
    while (tk--)
    {
        tk1++;
        scanf("%d",&n);
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        int std=n*(n-1)/4;
        int res=0;
        for (i=0;i<n;i++)
            for (j=i;j<n;j++)
                if (a[i]>a[j])
                    res++;
        int dt=0.8*max(res-std,0);
        double p=exp(4*(double)dt/n/(n-1))/exp(1.0);
        double r=(double)(rand())/RAND_MAX;
        if (r>p)
            printf("Case #%d: GOOD\n",tk1);
        else printf("Case #%d: BAD\n",tk1);


    }
    return 0;
}
