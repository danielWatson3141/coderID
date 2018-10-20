#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long int binario(char *s)
{
    long long int val = 0;
    for(int i=0;i<strlen(s);i++)
        val = 2*val + s[i] - '0';
    return val;
}

int compare(const void *a, const void *b)
{
    long long int la = *(long long int *)a;
    long long int lb = *(long long int *)b;

    if( la < lb )
        return -1;
    if( la == lb )
        return 0;
    return 1;
}

bool iguales(int n, long long int *a, long long int *b)
{
    for(int i=0;i<n;i++)
        if( a[i] != b[i] )
            return false;
    return true;
}

int numberOfBits(long long int v)
{
    int ret = 0;
    while(v)
    {
        ret += (v&1);
        v >>= 1;
    }
    return ret;
}

main(){

int T, N, L;
long long int con[150];
long long int dev[150];
long long int conorg[150];
long long int res;
char str[41];

scanf("%d", &T);

for(int caso=1;caso<=T;caso++)
{
    printf("Case #%d: ", caso);

    scanf("%d %d", &N, &L);
    for(int i=0;i<N;i++)
    {
        scanf("%s", str);
        con[i] = binario(str);
        conorg[i] = con[i];
    }
    qsort(con, N, sizeof(con[0]), compare);

    for(int i=0;i<N;i++)
    {
        scanf("%s", str);
        dev[i] = binario(str);
    }
    qsort(dev, N, sizeof(dev[0]), compare);

    if( iguales(N, con, dev) )
    {
        printf("0\n");
        continue;
    }
    for(res=1;res < (1<<L);res++)
    {
        for(int i=0;i<N;i++)
            con[i] = conorg[i] ^ res;
        qsort(con, N, sizeof(con[0]), compare);

        if( iguales(N, con, dev) )
            break;
    }
    
    if( res == (1<<L) )
        printf("NOT POSSIBLE\n");
    else
        printf("%d\n", numberOfBits(res));
}

return 0;
}

