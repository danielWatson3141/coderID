#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector<int>> neighbors;

int ncount(int root, int from);

int check(int root, int from) {
    // ok won't be faster, we can pray ;)
    //cerr << "Checking: " << root << "from: " << from << endl;
    int valid = 0;
    for (int x : neighbors[root]) {
        if (x == from) continue;
        valid++;
    }
    if (valid == 0) {
        int res = 0;
        //cerr << "Returning: " << res << endl;
        return res;
    } else if (valid == 1) {
        int res = ncount(root, from) - 1;
        //cerr << "Returning: " << res << endl;
        return res;
    } else if (valid == 2) {
        int res = 0;
        for (int x : neighbors[root]) {
            if (x == from) continue;
            res += check(x, root);
        }
        //cerr << "Returning: " << res << endl;
        return res;
    } else {
        vector<int> targets;
        vector<int> removals;
        for (int x : neighbors[root]) {
            if (x == from) continue;
            targets.push_back(check(x, root));
            removals.push_back(ncount(x, root));
        }
        int mincost = -1;
        int cost = 0;
        vector<int> diffs;
        for (int i = 0; i < targets.size(); i++) {
            diffs.push_back(removals[i] - targets[i]);
            cost += removals[i];
        }
        sort(diffs.begin(), diffs.end());
        reverse(diffs.begin(), diffs.end());
/*        for (int i = 0; i < targets.size(); i++) {
            for (int j = i+1; j < targets.size(); j++) {
                // we picked these two:
                cost -= removals[i];
                cost -= removals[j];
                cost += targets[i];
                cost += targets[j];
                if (mincost == -1) mincost = cost;
                mincost = min(mincost, cost);
                // undo
                cost += removals[i];
                cost += removals[j];
                cost -= targets[i];
                cost -= targets[j];
            }
        }
        */
        mincost = cost - diffs[0] - diffs[1];
        int res = mincost;
        //cerr << "Returning: " << res << endl;
        return res;
    }
}

int ncount(int root, int from) {
    int res = 1;
    for (int i = 0; i < neighbors[root].size(); i++) {
        int x = neighbors[root][i];
        if (x == from) continue;
        res += ncount(x, root);
    }
    return res;
}

int main()
{
    int T; cin >> T;
    for (int I = 1; I <= T; I++) {
        int res = 0;
        int n; cin >> n;
        // construct a tree
        neighbors.clear();
        neighbors.resize(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y; cin >> x >> y;
            x--; y--;
            neighbors[x].push_back(y);
            neighbors[y].push_back(x);
        }
        // for each vertex:
        int mincount = -1;
        for (int i = 0; i < n; i++) {
            // check this vertex.
            int t = check(i, -1);
            if (mincount == -1) mincount = t;
            mincount = min(mincount, t);
        }
        res = mincount;

        cout << "Case #" << I << ": " << res << endl;
    }
    return 0;
}

