#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int N;
vector<vector<int> > edges;

pair<int, int> solve(int node, int parent = -1) {
    int size = 1;
    vector<pair<int, int> > children;
    for (int child : edges[node]) {
        if (child != parent) { pair<int, int> r = solve(child, node);
            children.push_back(r);
            size += r.second;
        }
    }
    if (children.size() == 0) return make_pair(0, size);
    if (children.size() == 1) return make_pair(children[0].second, size);
    int best = N;
    for (int i = 0; i < children.size(); ++i) {
        for (int j = i+1; j < children.size(); ++j) {
            best = min(best,
                    children[i].first + children[j].first
                    + (size - 1 - children[i].second - children[j].second));
        }
    }
    return make_pair(best, size);
}

void tc() {
    cin >> N;
    edges.assign(N, vector<int>());
    for (int i = 0; i < N-1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int val = N;
    for (int i = 0; i < N; ++i) {
        val = min(val, solve(i).first);
    }
    cout << val << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cout << "Case #" << (i+1) << ": ";
        tc();
    }
}
