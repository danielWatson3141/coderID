#define _USE_32BIT_TIME_T 1
#include <vector> // headers {{{
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>

#define DEBUG(x) cout << #x << ": " << x << "\n"
using namespace std; // }}}

vector<string> build(const vector<vector<int> >& v, const vector<string>& need)
{
    vector<string> res;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            res.push_back(need[v[i][j]]);
        }
    }
    return res;
}

int doit(const vector<string>& has, const vector<string>& need, int idx, const vector<vector<int> >& V)
{
    int n = V.size();
    if (idx == need[0].size())
        return 0;
    vector<int> flip(n), no_flip(n), full(n, 1);
    vector<vector<int> > W, needW, needFlipW;
    int now = 0;
    for (int i = 0; i < V.size(); ++i) {
        int amt0 = 0, amt1 = 0;
        vector<int> v0, v1, need0, need1;
        int m = V[i].size();
        for (int j = 0; j < m; ++j, ++now) {
            int cur = V[i][j];
            //amt0+= need[now][idx] == '0';
            //amt1+= has[cur][idx] == '0';
            if (need[now][idx] == '0') {
                ++amt0;
                need0.push_back(now);
            } else {
                need1.push_back(now);
            }
            if (has[cur][idx] == '0') {
                ++amt1;
                v0.push_back(cur);
            } else {
                v1.push_back(cur);
            }
        }
        if (amt0 == amt1)
            no_flip[i] = 1;
        if (amt0 == m - amt1)
            flip[i] = 1;
        if (!flip[i] && !no_flip[i])
            return 1000;
        if (!v0.empty())
            W.push_back(v0);
        if (!v1.empty())
            W.push_back(v1);
        if (!need0.empty())
            needW.push_back(need0);
        if (!need1.empty())
            needW.push_back(need1);
        if (!need1.empty())
            needFlipW.push_back(need1);
        if (!need0.empty())
            needFlipW.push_back(need0);
    }
    int res = 1000;
    if (no_flip == full) {
        int cur = doit(has, build(needW, need), idx + 1, W);
        res = min(res, cur);
    }
    if (flip == full) {
        int cur = 1 + doit(has, build(needFlipW, need), idx + 1, W);
        res = min(res, cur);
    }
    return res;
}

string result(vector<string>& has, vector<string>& need)
{
    const string& BAD = "NOT POSSIBLE";
    sort(need.begin(), need.end());
    vector<int> v;
    for (int i = 0; i < has.size(); ++i) {
        v.push_back(i);
    }
    vector<vector<int> > V;
    V.push_back(v);
    int res = doit(has, need, 0, V);
    if (res >= 1000)
        return BAD;
    stringstream ss0;
    ss0 << res;
    return ss0.str();
}

int main()
{
    time_t start, end;
    time(&start);
    
    ifstream cin("test.in");
    ofstream cout("test.out");
    //cout.precision(6);
    //cout.setf(ios::fixed,ios::floatfield);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int N, L;
        cin >> N >> L;
        vector<string> outlets(N), required(N);
        for (int j = 0; j < N; ++j)
            cin >> outlets[j];
        for (int j = 0; j < N; ++j)
            cin >> required[j];
        cout << "Case #" << i << ": " << result(outlets, required) << endl;
        time(&end);
        ::cout << i << " " << difftime(end, start) << endl;
    }

    return 0;
}
