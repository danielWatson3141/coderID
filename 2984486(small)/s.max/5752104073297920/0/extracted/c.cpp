#include <stdio.h>
#include <string>
#include <map>
#include <iostream>
#include<math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int t,T;
    int i;
    scanf("%d",&T);

    for(t=1;t<=T;t++)
    {
        int n;
        scanf("%d",&n);
        int k=0;
        for(i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if (x!=0 && x==i+1)
                k++;
        }
        printf("Case #%d: ",t);
        if (k>1)
            printf("GOOD\n");
        else
            printf("BAD\n");
    }


    return 0;
}
