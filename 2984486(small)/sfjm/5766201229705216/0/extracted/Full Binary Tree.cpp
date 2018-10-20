#include<cstdio>
#include<cstring>
#include<vector>
using namespace std ;

int dis[1010];
vector<int>G[1010];
int r ;

int calc(int u,int la)
{
    int x=1;
    for ( int i = 0 ; i < G[u].size() ;i++ )
    {
        if(G[u][i] != la)
        x+=calc(G[u][i],u);
    }
    return x ;
}

int root(int u , int la)
{
    if ( dis[u] == 1 )
        return 0 ;
    if (dis[u] == 2 && la!= -1 )
    {
        int x = 0;
        for ( int i = 0 ; i < G[u].size() ;i++ )
        {
            if(G[u][i] != la )
            x=calc(G[u][i],u);
        }
        return x ;
    }
    if ( dis[u] > 2 )
    {
        int step = 0;
        int ans = G[u].size();
        for ( int i = 0 ; i < G[u].size() ;i++ )
        {
            for ( int j = i+1 ; j < G[u].size() ;j++ )
            {
                if(G[u][i] != la&&G[u][j]!=la)
                {
                    step=root(G[u][i],u);
                    step+=root(G[u][j],u);
                    for ( int k = 0 ; k < G[u].size() ;k++ )
                    {
                         if(G[u][k] != la&&k!=i&&k!=j)
                            step+=calc(G[u][k],u);
                    }
                    if ( ans > step )ans =step ;
                }

            }
        }
        return ans ;
    }
    int step=0;
     for ( int i = 0 ; i < G[u].size() ;i++ )
        {
            if(G[u][i] != la)
            step+=root(G[u][i],u);
        }
        return step;
}
int main()
{
     freopen("B-small-attempt6.in","r",stdin);
    freopen("out.txt","w",stdout);
    int _ , ca = 1 ;
    int n , i , j , a , b ;
    int step,ans;
    scanf ("%d",&_);
    while(_--)
    {
        scanf ("%d",&n);
        memset(dis,0,sizeof(dis));
        for ( i =1 ; i <= n ; i++)
            G[i].clear();
        for ( i = 1 ; i < n ; i++ )
        {
            scanf ("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
            dis[a]++;
            dis[b]++;
        }
        ans=n-1;

        for ( i = 1 ; i <=  n ; i++ )
        {
            if ( dis[i] > 1 )
            {
                step=root(i,-1);
                if ( step<ans)
                    {
                        ans = step ;

                    }
            }
        }
        printf("Case #%d: %d\n",ca++ ,ans);
    }
    return  0 ;
}
