#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
vector<int> adj[1024];
int table[1024];
int table2[1024];

int go(int n, int p)
{
    if(table[n])
        return table[n] - 1;
    else
    {
        table2[n] = 1;
        int& v = table[n];
        int m[3] = {INT_MAX, INT_MAX};
        int s = 0;
        int total = 0;
        for(int i = 0; i < adj[n].size(); i++)
            if(adj[n][i] != p)
            {
                int ret = go(adj[n][i], n);
                table2[n] += table2[adj[n][i]];
                m[2] = ret - table2[adj[n][i]];
                s += ret - table2[adj[n][i]];
                sort(m, m + 3);
                v += ret;
                total++;
            }
        if(total == 1)
            v -= m[0];
        else if(total > 2)
            v -= s - m[0] - m[1];

        return v++;
    }
}


int main()
{
    int TT;
    scanf("%d", &TT);


    for(int tt = 1; tt <= TT; tt++)
    {
        printf("Case #%d:", tt);
        scanf("%d", &N);


        for(int i = 1; i <= N; i++)
            adj[i].clear();

        for(int i = 0; i < N - 1; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int ans = N;
        for(int i = 1; i <= N; i++)
        {
            memset(table2, 0, sizeof(table2));
            memset(table, 0, sizeof(table));
            ans = min(ans, go(i, 0));
        }
     
        printf(" %d\n", ans);
    }
    return 0;
}
