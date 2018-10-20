#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

int n;
vector<int> G[1500];

int dfs(int x, int last, int &num)
{
    int tot = G[x].size();
    if(tot == 1 && last != 0)
    {
        num = 1;
        return 1;
    }

    int res = 0, max1 = -1, max2 = -1;
    for(int i = 0 ; i < tot ; i++)
    if(G[x][i] != last)
    {
        int cn;
        int temp = dfs(G[x][i], x, cn);
        res += cn;
//        cout<<x<<" "<<G[x][i]<<"  "<<temp<<endl;

        if(temp <= max2)continue;
        if(temp <= max1)max2 = temp;
        else           {max2 = max1; max1 = temp;}
    }
    num = res + 1;

    if(tot == 2 && last != 0)return 1;
    if(max2 == -1)return 1;

    return max1 + max2 + 1;
}

int main()
{
    freopen("x.in", "r", stdin);
    freopen("x.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int cas = 1 ; cas <= T ; cas++)
    {
        scanf("%d", &n);
        for(int i = 0 ; i <= n ; i++)G[i].clear();
        for(int i = 1 ; i < n ; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
        }

        int ans = 1;
        for(int i = 1 ; i <= n ;i++)
        {
//            cout<<"-------"<<i<<endl;
            int k;
            ans = max(ans, dfs(i, 0, k));
//            cout<<"-------"<<k<<endl;
        }

        printf("Case #%d: %d\n", cas, n - ans);
    }
    return 0;
}
