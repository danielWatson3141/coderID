#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const int INF = 1029384756;

int N;
vector<int> edge[MAXN];
int weight[MAXN], rem[MAXN];

void dfs(int v)
{
    int chnum = 0;
    weight[v] = 1;
    vector<int> rank;

    for(int i=0; i<(int)edge[v].size(); i++)
    {
        int ch = edge[v][i];
        if(weight[ch] != -1)
            continue;

        dfs(ch);
        chnum++;
        weight[v] += weight[ch];
        rank.push_back(rem[ch]);
    }

    if(chnum < 2)
        rem[v] = 1;
    else
    {
        sort(rank.begin(), rank.end(), greater<int>());
        rem[v] = 1 + rank[0] + rank[1];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T;
    cin>>T;
    for(int tt=1; tt<=T; tt++)
    {
        cin>>N;

        for(int i=0; i<N; i++)
        {
            edge[i].clear();
        }

        for(int i=0; i<N-1; i++)
        {
            int a, b;
            cin>>a>>b;
            a--;
            b--;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        int ans = INF;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                weight[j] = -1;
                rem[j] = 0;
            }
            dfs(i);
            ans = min(ans, N - rem[i]);
        }

        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }

    return 0;
}
