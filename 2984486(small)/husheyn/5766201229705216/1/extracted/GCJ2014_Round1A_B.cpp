#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int T, N;
vector<int> node[1000];
int s[1000];

void solve(int cur, int from) {
    for(int i = 0; i < node[cur].size(); i++)
        if (node[cur][i] != from)
            solve(node[cur][i], cur);
    int left = -1, right = -1;
    for(int i = 0; i < node[cur].size(); i++)
        if (node[cur][i] != from) {
            if (left == -1)
                left = s[node[cur][i]];
            else if (s[node[cur][i]] > left) {
                right = left;
                left = s[node[cur][i]];
            } else if (right == -1)
                right = s[node[cur][i]];
            else if (s[node[cur][i]] > right)
                right = s[node[cur][i]];
        }
    if (left == -1)
        s[cur] = 1;
    else if (right == -1)
        s[cur] = 1;
    else
        s[cur] = left + right + 1;
}

int main() {
    freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> N;
        for(int i = 0; i < N; i++) {
            node[i].clear();
            s[i] = -1;
        }
        int x, y;
        for(int i = 1; i < N; i++) {
            cin >> x >> y;
            x--; y--;
            node[x].push_back(y);
            node[y].push_back(x);
        }
        int ans = -1;
        for(int i = 0; i < N; i++) {
            solve(i, -1);
            if (ans == -1 || ans > N - s[i])
                ans = N - s[i];
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    //system("pause");
    return 0;
}
