#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#define inf 2000000000
#define ll long long
#define Max
#define M 160067000

using namespace std;

int n,a[1005];


int main()
{
    int i,j,k,T,cas,ret=0,cnt=0;

    freopen("C-small-attempt9.in","r",stdin);
    freopen("c-brandten.txt","w",stdout);

    scanf("%d",&T);

    for(cas=0;cas<T;cas++)
    {
        scanf("%d",&n);

        for(k=i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            k+=(i-a[i])*(i-a[i]);
        }

        //cout<<k<<endl;

        printf("Case #%d: ",cas+1);

        if(k>=M)
        {
            printf("GOOD\n");
            cnt++;
        }
        else printf("BAD\n");

    }

    cout<<cnt<<endl;

    return 0;
}
