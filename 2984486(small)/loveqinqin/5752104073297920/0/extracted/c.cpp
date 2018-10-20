#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<iostream>
#include<sstream>
using namespace std;
#define ll long long
int T,cas=0,N,a[1000];
int main()
{
    freopen("C-small-attempt4.in","r",stdin);
    freopen("C-small-attempt4.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        bool ans=true;
        int cnt=0;
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==i)
                cnt++;
        }
        ans=(cnt<=2);
        printf("Case #%d: %s\n",++cas,ans?"GOOD":"BAD");
    }
}

