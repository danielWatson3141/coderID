#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <limits.h>
#include <algorithm>
#define LL long long
//#define LL __int64
#define abs(x) ((x)>0?(x):-(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define max3(a, b, c) (a>b?max(a, c):max(b, c))
#define min3(a, b, c) (a<b?min(a, c):min(b, c))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define Ee 2.718281828459045
#define Pi acos(-1.0)
#define eps 1e-10
#define INF 1 << 28
using namespace std;
long long num1[155],num2[155];
int n,m,cnt,min1;
char s[100];
bool flat;
long long does()
{
    long long ans=0;
    for(int i=0; i<m; i++)
    {
        ans<<=1ll;
        if(s[i]=='1')ans++;
    }
    return ans;
}
bool judge()
{
    sort(num1,num1+n);
    for(int i=0; i<n; i++)
    {
        if(num1[i]!=num2[i])return false;
    }
    return true;
}
void dfs(int x,long long num)
{
    if(judge())
    {
        min1=min(cnt,min1);
        return ;
    }
    if(x==m)return;
    dfs(x+1,num<<1ll);
    for(int i=0; i<n; i++ )
    {
        num1[i]^=num;
    }
    cnt++;
    dfs(x+1,num<<1ll);
    for(int i=0; i<n; i++ )
    {
        num1[i]^=num;
    }
    cnt--;
}
int main()
{
    //freopen("A--small-attempt0.in","r",stdin);
    //freopen("data.out","w",stdout);
    int t,case1=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
        {
            scanf("%s",s);
            num1[i]=does();
            //printf("%d\n",num1[i]);
        }
        for(int i=0; i<n; i++)
        {
            scanf("%s",s);
            num2[i]=does();
        }
        sort(num2,num2+n);
        flat=false;
        cnt=0;
        min1=100;
        dfs(0,1);
        printf("Case #%d: ",case1++);
        if(min1==100)puts("NOT POSSIBLE");
        else printf("%d\n",min1);
    }
    return 0;
}
