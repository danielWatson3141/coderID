#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <cmath>
#include <list>
#include <cstring>
#include <cstdlib>
#include <limits>
#include <stack>
#include <iomanip>

using namespace std;

ofstream fout ("B-small-attempt0.out");
ifstream fin ("B-small-attempt0.in");
int degree[1010];
bool visit[1010];

int main() {
    int T;
    fin >> T;
    for (int t = 1; t <= T; t++) {
        int N, L;
        fin >> N;
        memset(degree, 0, sizeof(degree));
        vector<vector<int> > tree(N+1);
        fout << "Case #" << t << ": ";
        int from, to;
        for (int i = 0; i < N-1; ++i) {
            fin >> from >> to;
            tree[from].push_back(to);
            tree[to].push_back(from);
            degree[from]++;
            degree[to]++;
        }
        //for (int i = 1; i <= N; i++) cout << degree[i] << endl;
        int ans = N+1;
        int k = N;
        for (int i = 1; i <= N; i++) {
            if (degree[i] != 2) continue;
            int cut = 1;
            queue<int> S;
            S.push(i);
            memset(visit, false, sizeof(visit));
            visit[i] = true;
            while (!S.empty()) {
                int front = S.front();
                S.pop();
                vector<int> neighbor = tree[front];
                for (int j = 0; j < neighbor.size(); j++) {
                    if (visit[neighbor[j]]) continue;
                    if (degree[neighbor[j]] == 3) {
                        cut++;
                        visit[neighbor[j]] = true;
                        /*for (int k = 0; k < tree[neighbor[j]].size(); k++) {
                            if (tree[neighbor[j]][k] == front) continue;
                            S.push(tree[neighbor[j]][k]);
                        }*/
                        S.push(neighbor[j]);
                    }
                    else cut++;
                }
            }
            ans = min(ans, k - cut);
        }
        fout << ans << endl;
    }
    return 0;
}
