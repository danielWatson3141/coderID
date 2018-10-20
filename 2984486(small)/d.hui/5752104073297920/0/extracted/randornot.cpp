#include<cstdio>
#include<cstdlib>
#include<fstream>
using namespace std;
int a[2000],t,N;
int main()
{
    freopen("csmall0.in","r",stdin);
    freopen("csmall0.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int c=0;
        scanf("%d\n",&N);
        N--;
        for(int j=0;j<=N;j++)
        {
            scanf("%d",&a[j]);
        }
        for(int j=0;j<=N;j++)
            for(int k=j+1;k<=N;k++)
                if(a[j]>a[k])
                    c++;
        printf("Case #%d: ",i);
        if(c>=240000)
            printf("GOOD");
        else
            printf("BAD");
        printf("\n");
    }
    fclose(stdout);
    fclose(stdin);
}
