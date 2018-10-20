#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << (x) << endl;

const int MAXN = 20;
int T, N;
bool adjMat[MAXN][MAXN];

bool contains(vector<int> v, int n) {
    for (int i = 0; i < v.size(); ++i)
        if (v[i] == n)
            return true;
    return false;
}

bool isFBTRoot(int node, vector<int> component, vector<int> toDelete) {
    vector<int> children;
    for (int i = 1; i <= N; ++i) {
        if (i != node && adjMat[node][i] && !contains(toDelete, i) && contains(component, i)) {
            children.push_back(i);
        }
    }
    if (children.size() == 0)
        return true;
    else if (children.size() == 2) {
        vector<int> newToDelete (toDelete);
        newToDelete.push_back(node);
        return isFBTRoot(children[0], component, newToDelete) && isFBTRoot(children[1], component, newToDelete);
    } else
        return false;
}

vector<int> findComponent(int node, vector<int> toDelete) {
    vector<int> res;

    // Bfs
    bool used[MAXN] = {false};
    queue<int> q;
    q.push(node);
    used[node] = true;

    while(!q.empty()) {
        int now = q.front(); q.pop();
        res.push_back(now);
        for (int i = 1; i <= N; ++i)
            if (i != now && !contains(toDelete, i) && !used[i] && adjMat[now][i]) {
                q.push(i);
                used[i] = true;
            }
    }

    return res;
}

bool isInFBT(int node, vector<int> toDelete) {
    vector<int> component = findComponent(node, toDelete);
    for (int i = 0; i < component.size(); ++i)
        if (isFBTRoot(component[i], component, toDelete))
            return true;
    return false;
}

bool isOk(vector<int> toDelete) {
    for (int i = 1; i <= N; ++i) {
        if (!contains(toDelete, i)) {
            vector<int> component = findComponent(i, toDelete);
            if (component.size() + toDelete.size() < N)
                return false;
            break;
        }
    }
    for (int i = 1; i <= N; ++i)
        if (!contains(toDelete, i))
            if (!isInFBT(i, toDelete))
                return false;
    return true;
}

int main() {
    // FUUUCK, READ THE QUESTION WRONG
    cin >> T;
    for (int Ti = 1; Ti <= T; ++Ti) {
        // Input
        for (int i = 0; i < MAXN; ++i)
            for (int j = 0; j < MAXN; ++j)
                adjMat[i][j] = 0;
        cin >> N;
        for (int i = 0; i < N - 1; ++i) {
            int x, y;
            cin >> x >> y;
            adjMat[x][y] = 1;
            adjMat[y][x] = 1;
        }

        // Bfs
        int res = -1;
        queue<vector<int> > q;
        vector<int> v;
        q.push(v);

        while(!q.empty()) {
            vector<int> toDelete = q.front(); q.pop();

            if (isOk(toDelete)) {
                res = toDelete.size();
                break;
            }

            int largest = (toDelete.size() == 0 ? 0 : toDelete.back());

            for (int i = largest + 1; i <= N; ++i) {
                vector<int> newToDelete (toDelete);
                newToDelete.push_back(i);
                q.push(newToDelete);
            }
        }

        // Output result
        cout << "Case #" << Ti << ": " << res << endl;
    }

    return 0;
}