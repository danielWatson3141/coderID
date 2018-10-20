#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
using namespace std;
int map[1000][1000],visited[1000],good[1000],bad[1000];
int N;

void dfs(int v)
{
    int count=0;
    visited[v]=1;
    int tmpv[1000];
    memset(tmpv,0,sizeof(tmpv));
    for(int i=0;i<N;i++)
    {
        tmpv[i]=visited[i];
        if(map[v][i]&&!visited[i])
        {
            dfs(i);
            count++;
        }
    }
    if(count==0)
    {
        good[v]=1;
        bad[v]=0;
    }
    else if(count==1)
    {
        for(int i=0;i<N;i++)
        {
            if(map[v][i]&&!tmpv[i])
            {
                good[v]=1;
                bad[v]=good[i]+bad[i];
            }
        }
    }
    else if(count==2)
    {
        for(int i=0;i<N;i++)
        {
            if(map[v][i]&&!tmpv[i])
            {
                good[v]+=good[i];
                bad[v]+=bad[i];
            }
        }
        good[v]++;
    }
    else if(count>2)
    {
        int m1=-1,m2=-1,tmp,i1=0,i2=0;
        for(int i=0;i<N;i++)
        {
            if(map[v][i]&&!tmpv[i])
            {
                if(good[i]>m2)
                {
                    m2=good[i];
                    i2=i;
                }
                if(m2>m1)
                {
                    tmp=m1;
                    m1=m2;
                    m2=tmp;
                    tmp=i1;
                    i1=i2;
                    i2=tmp;
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(map[v][i]&&!tmpv[i])
            {
                if(i1==i||i2==i)
                {
                    good[v]+=good[i];
                    bad[v]+=bad[i];
                }
                else
                {
                    bad[v]+=(good[i]+bad[i]);
                }
            }
        }
        good[v]++;
    }
}
int main()
{
    int t,T;
    freopen("B-small-attempt0.in.txt","r",stdin);
	freopen("B-small-attempt0.out.txt","w",stdout);
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        memset(map,0,sizeof(map));
        int X,Y;
        scanf("%d",&N);
        for(int i=0;i<N-1;i++)
        {
            scanf("%d%d",&X,&Y);
            map[X-1][Y-1]=1;
            map[Y-1][X-1]=1;
        }
        int ans=N;
        for(int i=0;i<N;i++)
        {
            memset(good,0,sizeof(good));
            memset(bad,0,sizeof(bad));
            memset(visited,0,sizeof(visited));
            dfs(i);
            if(ans>bad[i])
            {
                ans=bad[i];
            }
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}