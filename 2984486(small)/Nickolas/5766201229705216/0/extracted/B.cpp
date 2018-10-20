#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int> > edges;
int keep;
int visited;

bool isFull(int v) {
    // mark current vertice as visited
    visited = visited | (1 << v);
    // visit and count all childred (unvisited neighbors)
    int nc = 0;
    for (int i = 0; i < edges[v].size(); ++i) {
        int cur = edges[v][i];
        if (visited & (1 << cur)) {
            continue;
        }
        if (!(keep & (1 << cur))) {
            continue;
        }
        ++nc;
        if (!isFull(cur)) {
            return false;
        }
    }
    return (nc == 0 || nc == 2);
}

int solve(int ind) {
    // input
    int N;
    cin >> N;
    edges = vector<vector<int> >(N);
    for (int i = 0; i < N - 1; ++i) {
        int x, y;
        cin >> x >> y;
        edges[x - 1].push_back(y - 1);
        edges[y - 1].push_back(x - 1);
    }

    if (N == 2) {
        return 1;
    }
    if (N == 3) {
        return 0;
    }
    // try all possible removals of vertices and all possible roots
    int minrem = N + 1;
    for (keep = 0; keep < (2 << N); ++keep) {
        for (int root = 0; root < N; ++root) {
            visited = 0;
            if (!(keep & (1 << root))) {
                // continue;
            }
            if (!isFull(root)) {
                continue;
            }
            // check that all vertices are visited
            if (visited != keep) {
                continue;
            }
            // full tree - calculate how many vertices are not kept
            int rem = 0;
            for (int i = 0; i < N; ++i) {
                if (!(keep & (1 << i))) {
                    ++rem;
                }
            }
            minrem = min<int>(minrem, rem);
            break;
        }
    }

    return minrem;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": " << solve(i) << endl;
    }
}