#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
#define N 100000
#define LL long long
#define INF 0xfffffff
const double eps = 1e-8;
const double pi = acos(-1.0);
const double inf = ~0u>>2;
struct node
{
    char st[20];
}s[20],ss[20],sr[20];
bool cmp(node x,node y)
{
    return strcmp(x.st,y.st)<0;
}
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int n,l,i,j,t,g;
    cin>>t;
    int kk = 0;
    while(t--)
    {
        cin>>n>>l;
        for(i = 0 ;i <n  ;i++)
        cin>>s[i].st;
        for(i = 0;i < n ;i++)
        cin>>ss[i].st;
        sort(ss,ss+n,cmp);
        int minz =INF;
        for(i = 0;i < (1<<l) ; i++)
        {
            int o = 0;
            for(j =0 ; j < n  ;j++)
            strcpy(sr[j].st,s[j].st);
            for(j = 0;j < l ;j++)
            if((1<<j)&i)
            {
                o++;
                for(g = 0 ; g < n ; g++)
                {
                    if(sr[g].st[j]=='0')
                    sr[g].st[j] = '1';
                    else
                    sr[g].st[j] = '0';
                }
            }
            sort(sr,sr+n,cmp);
            for(j = 0; j < n ;j++)
            if(strcmp(sr[j].st,ss[j].st)!=0)
            break;
            if(j==n)
            minz = min(o,minz);
        }
        printf("Case #%d: ",++kk);
        if(minz!=INF)
        printf("%d\n",minz);
        else puts("NOT POSSIBLE");
    }
    return 0;
}
