#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

int N;
vector<vector<int> > tree;
vector<vector<int> > children;

vector<int> nums;
vector<int> childrennums;

int calcminfull(int r) {
    if (nums[r] != -1) return nums[r];
    if (children[r].size() == 0) return 0;
    if (children[r].size() == 1) return childrennums[children[r][0]];

    int total = 0;
    for (int i = 0; i < children[r].size(); ++i) {
        total += childrennums[children[r][i]];
    }

    int ans = 12345;
    for (int i = 0; i < children[r].size(); ++i) for (int j = i+1; j < children[r].size(); ++j) {
        int t1 = calcminfull(children[r][i]);
        int t2 = calcminfull(children[r][j]);

        int t = t1 + t2 + total - childrennums[children[r][i]] - childrennums[children[r][j]];
        if (t < ans) ans = t;
    }

    return nums[r] = ans;
}

int calcchildrennums(int r) {
    if (childrennums[r] != -1) return childrennums[r];
    int ans = 1;
    for (int i = 0; i < children[r].size(); ++i) {
        ans += calcchildrennums(children[r][i]);
    }
    return childrennums[r] = ans;
}

int calc(int root) {
    children.clear();
    children.resize(N);
    queue<int> q;
    q.push(root);
    
    vector<int> visited(N);
    visited[root] = 1;

    /*
    vector<int> level;
    level.push_back(root);
    vector<int> nums;
    while (!level.empty()) {
        nums.push_back(level.size());
        vector<int> level1;
        for (int i = 0; i < level.size(); ++i) {
            int cur = level[i];
            for (int i = 0; i < tree[cur].size(); ++i) {
                int j = tree[cur][i];
                if (!visited[j]) {
                    visited[j] = 1;
                    level1.push_back(j);
                }
            }
        }

        level.swap(level1);
    }

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i-1]*2) {
            if (i == 1) return nums[i];
            return min(nums[i], nums[i-1]);
        }
    }

    return 0;
    */

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 0; i < tree[cur].size(); ++i) {
            int j = tree[cur][i];
            if (!visited[j]) {
                visited[j] = 1;
                children[cur].push_back(j);
                q.push(j);
            }
        }
    }

    childrennums.clear();
    childrennums.resize(N, -1);
    calcchildrennums(root);

    nums.clear();
    nums.resize(N, -1);
    return calcminfull(root);
}

int calc()
{
    cin >> N;
    tree.clear();
    tree.resize(N);
    for (int i = 0; i < N-1; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for (int i = 0; i < N; ++i) {
        sort(tree[i].begin(), tree[i].end());
    }

    int ans = N - 1;
    for (int i = 0; i < N; ++i) {
        int t = calc(i);
        if (t < ans) ans = t;
    }
    return ans;
}

int main(void)
{
	int T;
	cin >> T;
	for (int ca=1; ca<=T; ++ca) {
		cout << "Case #" << ca << ": " << calc() << endl;
	}
	return 0;
}
