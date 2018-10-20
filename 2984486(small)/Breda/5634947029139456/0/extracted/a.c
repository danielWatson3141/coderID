#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, l;
char c[10000];
int o[1000], d[1000];

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int rec(int p)
{
    int i, ok;
    if(p==l)
    {
        ok = 1;
        qsort(o, n, sizeof(int), compare);
        for(i=0;i<n;i++)
        {
            if(o[i]!=d[i])
                ok = 0;
        }
        if(ok==1)
        {
            return 0;
        }
        else
            return -1;
    }
    int ret1 = rec(p+1);
    for(i=0;i<n;i++)
    {
        o[i] = o[i]^(1<<p);
    }
    int ret2 = rec(p+1);
    for(i=0;i<n;i++)
    {
        o[i] = o[i]^(1<<p);
    }
    if(ret1==-1 && ret2==-1)
        return -1;
    if(ret1==-1)
        return ret2+1;
    if(ret2==-1)
        return ret1;
    if(ret2+1<ret1)
        return ret2+1;
    return ret1;
}

int main()
{
    int t, q=1;
    scanf("%i", &t);
    while(t--)
    {
        int i, j;
        //memset(o, sizeof(o), 0);
        //memset(d, sizeof(d), 0);
        scanf("%i %i", &n, &l);
        scanf("%*c%[^\n]", c);
        int p=0;
        for(i=0;i<n;i++)
        {
            o[i]=0;
            for(j=0;j<l;j++)
            {
                o[i]*=2;
                o[i]+=c[p]-'0';
                p++;
            }
            //printf("%i\n", o[i]);
            p++;
        }
        scanf("%*c%[^\n]", c);
        p=0;
        for(i=0;i<n;i++)
        {
            d[i]=0;
            for(j=0;j<l;j++)
            {
                d[i]*=2;
                d[i]+=c[p]-'0';
                p++;
            }
            //printf("%i\n", d[i]);
            p++;
        }
        qsort(o, n, sizeof(int), compare);
        qsort(d, n, sizeof(int), compare);
        int r = rec(0);
        printf("Case #%i: ", q++);
        if(r==-1)
            printf("NOT POSSIBLE\n");
        else
            printf("%i\n", r);
    }
    return 0;
}
