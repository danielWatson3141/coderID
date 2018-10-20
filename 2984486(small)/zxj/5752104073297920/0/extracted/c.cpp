#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
int a[1005];
int main()
{
    int i,j,t;
//    freopen("C-small-attempt1.in","r",stdin);
//    freopen("out1.txt","w",stdout);

    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        int sum=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(a[j]<a[i])sum++;
            }
        }
        int x = n*5/7;
        x = x*(x+1)/2;
        if(sum<=x)printf("Case #%d: GOOD\n",++cas);
        else printf("Case #%d: BAD\n",++cas);
        //cout<<sum<<endl;
    }
}
