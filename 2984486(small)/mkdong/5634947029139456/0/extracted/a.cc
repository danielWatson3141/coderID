#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

#include <sstream>

using namespace std;

int n, l;
string flow[500];
string dev[500];
int ans;

bool dfs(int d, int cnt)
{
    if (d == l) {
        sort(flow, flow + n);
        for (int i=0; i<n; ++i) {
            if (flow[i] != dev[i]) {
                return false;
            }
        }
        if (ans == -1 || ans > cnt) {
            ans = cnt;
        }
        return true;
    }
    dfs(d+1, cnt);
    for (int i=0; i<n; ++i) {
        if (flow[i][d] == '0') {
            flow[i][d] = '1';
        } else {
            flow[i][d] = '0';
        }
    }
    dfs(d+1, cnt+1);
    for (int i=0; i<n; ++i) {
        if (flow[i][d] == '0') {
            flow[i][d] = '1';
        } else {
            flow[i][d] = '0';
        }
    }
}

string solve()
{
    stringstream ss;
    ss.str("");
    ans = -1;
    dfs(0, 0);
    if (ans == -1) return "NOT POSSIBLE";
    else {
        ss << ans;
        return ss.str();
    }
}

int main()
{
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        cin >> n >> l;
        for (int i=0; i<n; ++i) {
            cin >> flow[i];
        }
        for (int i=0; i<n; ++i) {
            cin >> dev[i];
        }
        sort(dev, dev + n);
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}
