#include <stdio.h>
#include <map>

using namespace std;

int bitova(long long n)
{
    int rez=0;
    while(n)
    {
        n&=n-1;
        rez++;
    }
    return rez;
}

long long broj(char *s)
{
    long long rez=0;
    for(;*s;s++)
        rez=2*rez+*s-'0';
    return rez;
}

int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        int n,l;
        scanf("%d %d",&n,&l);
        int i,j;
        long long a[n],b[n];
        int rez=l+1;

        for(i=0;i<n;i++)
        {
            char niz[100];
            scanf("%s",niz);
            a[i]=broj(niz);
        }

        for(i=0;i<n;i++)
        {
            char niz[100];
            scanf("%s",niz);
            b[i]=broj(niz);
        }

        map<long long,int> mapa;

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                mapa[a[i]^b[j]]=mapa[a[i]^b[j]]+1;


        for(map<long long, int>::iterator it=mapa.begin();it!=mapa.end();it++)
            if (it->second==n)
            {
                int k=bitova(it->first);
                if (k<rez)
                    rez=k;
            }

        printf("Case #%d: ",t);
        if (rez<=l)
            printf("%d",rez);
        else
            printf("NOT POSSIBLE");
        printf("\n");
    }

    return 0;
}
