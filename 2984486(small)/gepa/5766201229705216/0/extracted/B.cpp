#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int buf[1010][1010];

int get_max(int node, int last, const vector <vector <int> > &adj) {
    if (buf[node][last] >= 0) {
        return buf[node][last];
    }
    vector <int> best = vector <int>();
    for (int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];
        if (next == last) {
            continue;
        }
        int m = get_max(next, node, adj);
        if (best.size() < 2) {
            best.push_back(m);
            sort(best.begin(), best.end());
        } else if (m > best[0]) {
            best[0] = m;
            sort(best.begin(), best.end());
        }
    }
    if (best.size() < 2) {
         buf[node][last] = 1;
    } else {
         buf[node][last] = 1 + best[0] + best[1];
    }
    return buf[node][last];
}

int invoke() {
    int N;
    int a, b;
    cin >> N;
    vector <vector <int> > adj(N + 1, vector <int>());
    for (int i = 1; i < N; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            buf[i][j] = -1;
        }
    }
    int max_nodes = 1;
    for (int r = 1; r <= N; r++) {
        int m = get_max(r, 0, adj);
        if (m > max_nodes) {
            max_nodes = m;
        }
    }
    return N - max_nodes;
}

int main(int argc, char *argv[]) {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int res = invoke();
        cout << "Case #" << i << ": " << res << endl;
    }
    return 0;
}

