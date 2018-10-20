#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
using namespace std;

int main()
{
    
    long long int t, n, l, i, j;
    long long int ccase=1, flip=0, sum1=0, sum2=0;
    char **gpow, **rpow;
    bool flag=false;
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &l);
        
		gpow=new char *[n];
        for (i=0; i<n; i++)
        {
            gpow[i]=new char[l];
        }
        
		rpow=new char *[n];
        for (i=0; i<n; i++)
        {
            rpow[i]=new char[l];
        }
        
		for (i=0; i<n; i++)
        {
            scanf("%s", gpow[i]);
        }
        
		for (i=0; i<n; i++)
        {
            scanf("%s", rpow[i]);
        }
        
		for (i=0; i<l; i++)
        {
            sum1=0;
            sum2=0;
            for (j=0; j<n; j++)
            {
                if (gpow[j][i]=='1')
                {
                    sum1++;
                }
            }
            for (j=0; j<n; j++)
            {
                if (rpow[j][i]=='1')
                {
                    sum2++;
                }
            }
            if (sum1!=sum2 && sum1!=(n-sum2))
            {
                flag=true;
                break;
            }
            else
            {
                if (sum1!=sum2)
                {
                    flip++;
                }
            }
        }
        if (flag)
        {
            printf("Case #%lld: NOT POSSIBLE\n", ccase);
            flag=false;
        }
        else
        {
            printf("Case #%lld: %lld\n", ccase, flip);
        }
        ccase++;
        flip=0;
    }
    return 0;
}