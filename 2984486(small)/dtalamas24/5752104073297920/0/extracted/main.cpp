#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int A[1005][1005], B[1005][1005], Z[1005], pos, m, ctos, casos, que, suma;

int main()
{
    freopen("guarda.txt","r",stdin); // precalculations done by myself
    for(int i=1; i<=1000; i++){
        for(int e=1; e<=1000; e++){
            scanf("%d",&A[i][e]);
        }
    }

    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&casos);
    for(int v=1; v<=casos; v++){
        scanf("%d",&ctos);
        suma=0;
        for(int i=1; i<=ctos; i++){
            scanf("%d",&que);
            suma+=A[que][i];
        }
        //printf("%d\n",suma);
        if(suma>2010000){
            printf("Case #%d: BAD\n",v);
        }
        else
            printf("Case #%d: GOOD\n",v);
    }
    return 0;
}
