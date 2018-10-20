#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


#define swap(i,j) int temp = a[i]; a[i] = a[j]; a[j] = temp;

int a[2000];
int n;

int b[2000];
void algo1()
{

    for (int i=0;i<n;i++) b[i] = a[i];
    for (int i=n-1;i>=0;i--)
    {
        int x = rand()%(i+1) ;
        int temp = b[x];
        b[x] = b[i];
        b[i] = temp;
    }

}


int c[2000];
void algo2()
{

    for (int i=0;i<n;i++) c[i] = a[i];
    for (int i=n-1;i>=0;i--)
    {
        int x = rand()%n; 
        int temp = c[x];
        c[x] = b[i];
        c[i] = temp;
    }   

}


void compare()
{
    int ans1 = 0, ans2 = 0;

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if ( i< b[j] )
                ans1++;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if ( i < c[j] )
                ans2++;


    if ( ans2 > ans1 )
        printf("GOOD\n");
    else printf("BAD\n");
}


void solve()
{

    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);

    algo1();
    algo2();
    compare();

}


int main()
{

    int t;
    scanf("%d",&t);
    for (int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        solve();
    }

}
