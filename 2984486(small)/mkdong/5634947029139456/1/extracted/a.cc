#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sstream>

using namespace std;

int n, l;
string flow[500];
string dev[500];
int flow0[500];
int flow1[500];
int dev0[500];
int dev1[500];
int ans;

/*
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
*/

struct Node{
    Node *zero;
    Node *one;
    int cnt;
    Node() {
        //zero = one = cnt = 0;
    }
};

void insert(Node *t, string s)
{
    t->cnt++;
    if (s.length() == 1) return;
    if (s[0] == '0') {
        if (t->zero == NULL) {
            t->zero = new Node();
        }
        insert(t->zero, s.substr(1));
    } else {
        if (t->one == NULL) {
            t->one = new Node();
        }
        insert(t->one, s.substr(1));
    }
}

void clean(Node *t)
{
    if (t->zero) clean(t->zero);
    if (t->one) clean(t->one);
    delete t;
}

void dfs(int d, int cnt)
{
    if (ans != -1 && cnt >= ans) return;
    if (d == l) {
        sort(flow, flow + n);
        for (int i=0; i<n; ++i) {
            if (flow[i] != dev[i]) {
                return;
            }
        }
        if (ans == -1 || cnt < ans) {
            ans = cnt;
        }
        return;
    }
    sort(flow, flow + n);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<d; ++j) {
            if (flow[i][j] != dev[i][j]) {
                return;
            }
        }
    }

    //
    /*
    iter = bounds.begin();
    for (int i=0; i<n; ++i) {
        if (i < 
    }
    */
    if (dev0[d] == flow0[d] && dev1[d] == flow1[d]) {
        dfs(d+1, cnt);
    }
    if (dev0[d] == flow1[d] && dev1[d] == flow0[d]) {
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
        memset(dev0, 0, sizeof(dev0));
        memset(dev1, 0, sizeof(dev1));
        memset(flow0, 0, sizeof(flow0));
        memset(flow1, 0, sizeof(flow1));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<l; ++j) {
                if (dev[i][j] == '0') {
                    dev0[j]++;
                } else {
                    dev1[j]++;
                }
            }
        }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<l; ++j) {
                if (flow[i][j] == '0') {
                    flow0[j]++;
                } else {
                    flow1[j]++;
                }
            }
        }
        sort(dev, dev + n);
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}
