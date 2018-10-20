#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1005;
int a[maxn];
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,Case=0;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",&a[i]);
        int l=0,r=0;
        for(int i=1;i<n;++i)
        l+=a[i]-a[i-1];
       if(abs(l)<n/2)printf("Case #%d: GOOD\n",++Case);
       else printf("Case #%d: BAD\n",++Case);
    }
}
