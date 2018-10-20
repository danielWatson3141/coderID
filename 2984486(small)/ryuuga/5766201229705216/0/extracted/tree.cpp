#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORI(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,b) FOR(i,0,b)
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
unordered_map<int, int> memo;

int key(int n, int from) {
    return n * 10009 + from;
}

int get_tree_size(const vector<vi>& edges, const int root, const int prev) {
    int& sol = memo[key(root, prev)];
    if (sol) { return sol; }

    vi children;
    for (int next: edges[root]) {
        if(next != prev) {
            children.push_back(next);
        }
    }

    if (children.size() < 2) return sol = 1;

    int A = 0, B = 0;
    for (int next: children) {
        int size = get_tree_size(edges, next, root);
        if(size > B) {
            B = size;
            if (B > A) {
                swap(A, B);
            }
        }
    }
    return sol = 1 + A + B;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        assert(2 <= N && N <= 1000);
        vector<vi> edges(N+1);
        REP(i, N-1) {
            int a, b;
            cin >> a >> b;
            assert(1 <= a && a <= N);
            assert(1 <= b && b <= N);
            assert(a != b);
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        memo.clear();

        int largest = 1;
        FOR(root, 1, N+1) {
            largest = max(largest, get_tree_size(edges, root, 0));
        }
        const int solution = N - largest;

        cout << "Case #" << (i+1) << ": " << solution << endl;
    }
}
