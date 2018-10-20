#include <cstdio>
#include <iostream>

using namespace std;

int N, L;
long long int ary[2][200];

void btoi( char * c , int i , int j )
{
    int k;
    long long int tmp = 0;
    for ( k = 0 ; k < L ; k ++ )
    {
        if ( c[k] == '1')
        {
            tmp += 1LL << (L-1-k);
        }
    }
    ary[i][j] = tmp;
}

int check ( )
{
    long long int match;
    int i, j, k, ans = 100, tmp;
    for ( i = 0 ; i < N ; i ++ )
    {
        match = ary[0][0]^ary[1][i];
        for ( j = 1 ; j < N ; j ++ )
        {
            for ( k = 0 ; k < N ; k ++ )
            {
                if ( (ary[0][j]^ary[1][k]) == match ) break;
            }

            if ( k == N ) break;
        }

        if ( j == N )
        {
            tmp = 0;
            for ( j = 0 ; j < L ; j ++ )
            {
                if ( (match&(1LL<<j)) != 0LL ) tmp ++;
            }
            ans = min(ans,tmp);
        }
    }
    return ans;
}


int main()
{
    freopen("A-Large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int i, j;
    int tcnt, t;
    char tmps[50];
    scanf("%d",&t);
    for ( tcnt = 1 ; tcnt <= t ; tcnt ++ )
    {
        scanf("%d %d",&N,&L);
        for ( i = 0 ; i <= 1 ; i ++ )
        {
            for ( j = 0 ; j < N ; j ++ )
            {
                scanf("%s",tmps);
                btoi(tmps,i,j);
            }
        }

        int ans = check();
        if ( ans == 100 )
        {
            printf("Case #%d: NOT POSSIBLE\n",tcnt);
        }
        else
        {
            printf("Case #%d: %d\n",tcnt,ans);
        }
    }
    return 0;
}
