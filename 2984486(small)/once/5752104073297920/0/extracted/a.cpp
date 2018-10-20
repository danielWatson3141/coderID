#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <time.h>
#define P 1000000007
#define LL long long
#define N 1007
#define M 2007
using namespace std;
int a[N],n;
void add(int x) {for (;x<=n;x+=x&(-x)) a[x]++;}
int get(int x)
{
    int res=0;
    for (;x;x-=x&(-x)) res+=a[x];
    return res;
}
int main()
{
    freopen("A.in","r",stdin);
    freopen("a.out","w",stdout);
    srand(time(NULL));
    int cnt,x,ans;
    scanf("%d",&cnt);
    for (int run=1;run<=cnt;run++)
    {
        scanf("%d",&n);
        ans=0;
        memset(a,0,sizeof a);
        for (int i=0;i<n;i++)
        {
            scanf("%d",&x);
            x++;
            ans+=i-get(x);
            add(x);
        }
        printf("Case #%d: %s\n",run,ans>n*(n-1)/4||rand()%3==0?"GOOD":"BAD");
    }
    return 0;
}
