#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n;
vector<vector<int> > nodes;
bool visited[1005];

int countMin(int cur) {
    visited[cur] = true;
    vector<int> nums;
    for (int i = 0; i < nodes[cur].size(); i++) {
        if (visited[nodes[cur][i]]) continue;
        nums.push_back(countMin(nodes[cur][i]));
    }
    // sort(nums.begin(), nums.end());
    int cum = 0;
    for (int i = 0; i < nums.size(); i++) {
        cum += nums[i];
        if (i >= 2) cum++;
    }
    if (nums.size() == 1) cum++;
    // cout << cur << " " << nums.size() << " " << cum << endl;
    return cum;
}

int main() {
    int t;
    cin >> t;
    for (int cases = 1; cases <= t; cases ++) {
        cin >> n;
        nodes.clear();
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            nodes.push_back(tmp);
        }
        for (int i = 0; i < n - 1; i++) {
            int x,y;
            cin >> x >> y;
            // cout << n << " " << x << " " << y << endl;
            nodes[x-1].push_back(y - 1);
            nodes[y-1].push_back(x - 1);
        }
        int lowest = 99999;
        for (int i = 0; i < n; i++) {
            if (nodes[i].size() == 1) continue;
            memset(visited, 0, sizeof(visited));
            visited[i] = true;
            int tmp = countMin(i);
            // cout << i << " " << tmp << endl;
            if (tmp < lowest) lowest = tmp;
        }
        if (lowest == 99999) lowest = 1;
        cout << "Case #" << cases << ": " << lowest << endl;
    }
}