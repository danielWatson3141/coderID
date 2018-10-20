#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#define nn 1100
using namespace std;
int n;
int a[nn];
int b[nn];
int randint(int x,int y)
{
    int ix=rand()%(y+1);
    if(ix>=x)
        return ix;
}
int main()
{
    freopen("Cin.txt","r",stdin);
    freopen("Cout.txt","w",stdout);
    int t,i,ix,k,p;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        scanf("%d",&n);
        ix=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>i-1)
                ix++;
        }
        printf("Case #%d: ",cas++);
        if(ix>=n/2)
            puts("GOOD");
        else
            puts("BAD");
    }
    return 0;
}
