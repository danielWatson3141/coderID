#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

#define REP(i,N) for (int i = 0; i < (N); ++i)

typedef vector<int> vi;

int checkCandidate(const vector<vi> & graph, int cand)
{
    int N = graph.size();
    vi level(N, -1);
    int maxLevel = 0;
    
    queue<int> q;
    q.push(cand);
    level[cand] = 0;
    
    while (!q.empty())
    {
        int curr = q.front(); q.pop();
        REP(i, graph[curr].size())
        {
            int next = graph[curr][i];
            if (level[next] >= 0)
                continue;
            
            level[next] = level[curr] + 1;
            maxLevel = max(maxLevel, level[next]);
            q.push(next);
        }
    }
    
    vector<vi> levelNodes(maxLevel + 1);
    REP(i, N)
    {
        levelNodes[level[i]].push_back(i);
    }
    
    vi dp(N);
    for (int currLevel = maxLevel; currLevel >= 0; --currLevel)
    {
        for (int t = 0; t < levelNodes[currLevel].size(); ++t)
        {
            int node = levelNodes[currLevel][t];
            int nodeLevel = level[node];

            vi childDp;
            REP(i, graph[node].size())
            {
                int nextNode = graph[node][i];
                if (level[nextNode] != level[node] + 1)
                    continue;
                
                childDp.push_back(dp[nextNode]);
            }
            
            dp[node] = 1;
            if (childDp.size() >= 2)
            {
                sort(childDp.begin(), childDp.end());
                dp[node] += childDp[childDp.size() - 1] + childDp[childDp.size() - 2];
            }
        }
    }
    
    return dp[cand];
}

int main()
{
    int caseCount;
    cin >> caseCount;
    
    for (int csIx = 1; csIx <= caseCount; ++csIx)
    {
        int N;
        cin >> N;
        vector<vi> graph(N);
        REP(i,N-1)
        {
            int X, Y;
            cin >> X >> Y;
            X--; Y--;
            graph[X].push_back(Y);
            graph[Y].push_back(X);
        }
        
        int res = 0;
        REP(i,N)
        {
            int currRes = checkCandidate(graph, i);
            res = max(res, currRes);
        }
        
        cout << "Case #" << csIx << ": " << N - res << endl;
    }
    
    return 0;
}
