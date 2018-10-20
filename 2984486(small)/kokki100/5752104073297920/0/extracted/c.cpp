#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>
#include<algorithm>
using namespace std;
int t,n,p;
int ar[1005],tes[1005];
int main()
{
    freopen("C-small-attempt4.in","r",stdin);
    freopen("C-small-attempt4.out","w",stdout);
    srand(time(NULL));
    scanf("%d",&t);
    for (int ll=1;ll<=t;ll++)
    {
        int baik,jahat;
        baik=jahat=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&ar[i]);

        for (int i=1;i<=1000;i++)
        {
            for (int j=1;j<=n;j++)
                tes[j]=j;

            for (int j=1;j<=n;j++)
            {
                p=rand()%(n-j+1)+j;
                swap(tes[j],tes[p]);
            }

            for (int j=1;j<=n;j++)
                if (tes[j]==ar[j])
                    baik++;
        }

        for (int i=1;i<=1000;i++)
        {
            for (int j=1;j<=n;j++)
                tes[j]=j;

            for (int j=1;j<=n;j++)
            {
                p=rand()%n+1;
                swap(tes[j],tes[p]);
            }

            for (int j=1;j<=n;j++)
                if (tes[j]==ar[j])
                    jahat++;
        }

        printf("Case #%d: ",ll);
        if (baik>=jahat) printf("GOOD\n");
        else printf("BAD\n");
    }

    return 0;
}
