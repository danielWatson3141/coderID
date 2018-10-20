#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

#define min(a,b) ((a<b)?a:b)

int main()
{
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int N, x, y;
        cin >> N;
        vector<vector<int> > adjs(N);
        for (int i = 0; i < N-1; i++) {
            cin >> x >> y;
            x--; y--;
            adjs[x].push_back(y);
            adjs[y].push_back(x);
        }
        vector<vector<int> > cnts(N, vector<int>(N, -1));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < adjs[i].size(); j++) {
                int cnt = 0;
                vector<bool> seen(N, false);
                seen[i] = true;
                seen[adjs[i][j]] = true;
                queue<int> Q;
                Q.push(adjs[i][j]);
                while(!Q.empty()) {
                    int node = Q.front();
                    Q.pop();
                    cnt++;
                    for (int k = 0; k < adjs[node].size(); k++) {
                        if (seen[adjs[node][k]]) continue;
                        else if (cnts[node][adjs[node][k]] != -1)
                            cnt += cnts[node][adjs[node][k]];
                        else {
                            Q.push(adjs[node][k]);
                            seen[adjs[node][k]] = true;
                        }
                    }
                }
                cnts[i][adjs[i][j]] = cnt;
                // cout << cnt << " nodes on " << adjs[i][j]
                //      << " side of " << i << endl;
            }
        }

        int smallest = 99999;
        for (int i = 0; i < N; i++) {
            if (adjs[i].size() < 2) continue;
            queue<int> Q;
            vector<bool> seen(N, false);
            int cnt = 0;
            seen[i] = true;
            Q.push(i);
            while(!Q.empty()) {
                int node = Q.front();
                Q.pop();
                vector<pair<int, int> > adjsizes;
                for (int j = 0; j < adjs[node].size(); j++)
                    if (!seen[adjs[node][j]])
                        adjsizes.push_back(make_pair(cnts[node][adjs[node][j]], adjs[node][j]));
                sort(adjsizes.begin(), adjsizes.end(), greater<pair<int, int> >());
                if (adjsizes.size() == 1)
                    cnt += adjsizes[0].first;
                else if (adjsizes.size() >= 2) {
                    Q.push(adjsizes[0].second);
                    seen[adjsizes[0].second] = true;
                    Q.push(adjsizes[1].second);
                    seen[adjsizes[1].second] = true;
                    for (int j = 2; j < adjsizes.size(); j++)
                        cnt += adjsizes[j].first;
                }
            }
            smallest = min(smallest, cnt);
        }

        cout << "Case #" << c << ": ";
        if (smallest == 99999)
            cout << 1 << endl;
        else
            cout << smallest << endl;
    }
    return 0;
}
