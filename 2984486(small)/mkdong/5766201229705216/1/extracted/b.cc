#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <sstream>

#include <list>

using namespace std;

int n, l;


list<int> edges[2000];

/// dep[i][j] root is i, do not use j , max height of full binary tree
int dep[2000][2000];
bool dep_ok[2000][2000];

inline int min(int a, int b) { return a < b ? a : b; }

void calc(int root, int except)
{
    if (dep_ok[root][except]) {
        return;
    }
    list<int>::iterator iter = edges[root].begin();
    while (iter != edges[root].end()) {
        if (*iter != except) {
            calc(*iter, root);
        }
        ++iter;
    }
    
    int ret = 1;
    int firstDep = 0;
    int secondDep = 0;
    iter = edges[root].begin();
    while (iter != edges[root].end()) {
        if (*iter != except) {
            //cout << *iter << endl;
            if (dep[*iter][root] > firstDep) {
                secondDep = firstDep;
                firstDep = dep[*iter][root];
            } else if (dep[*iter][root] > secondDep) {
                secondDep = dep[*iter][root];
            }
        }
        ++iter;
    }
    if (firstDep * secondDep == 0) {
        ret = 1;
    } else {
        ret = 1 + (firstDep + secondDep);
    }

    dep_ok[root][except] = true;
    dep[root][except] = ret;
    //cout << firstDep << " " << secondDep << endl;
    //cout << root << " " << except << " " << dep[root][except] << endl;
}

int solve()
{
    memset(dep, 0, sizeof(dep));
    memset(dep_ok, 0, sizeof(dep_ok));
    for (int i=1; i<=n; ++i) {
        list<int>::iterator iter = edges[i].begin();
        while (iter != edges[i].end()) {
            calc(i, *iter);
            ++iter;
        }
    }
    int ans = 1;
    for (int i=1; i<=n; ++i) {
        int ret = 1;
        int firstDep = 0;
        int secondDep = 0;
        list<int>::iterator iter = edges[i].begin();
        while (iter != edges[i].end()) {
            if (dep[*iter][i] > firstDep) {
                secondDep = firstDep;
                firstDep = dep[*iter][i];
            } else if (dep[*iter][i] > secondDep) {
                secondDep = dep[*iter][i];
            }
            ++iter;
        }
        if (firstDep * secondDep == 0) {
            ret = 1;
        } else {
            ret = 1 + (firstDep + secondDep);
        }
        //cout << ret << endl;
        if (ret > ans) {
            ans = ret;
        }
    }
    /*
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            if (dep_ok[i][j]) {
                cout << -1 << "\t";
            } else {
                cout << dep[i][j] << "\t";
            }
        }
        cout << endl;
    }
    */
    return n - ans;
}

int main()
{
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        cin >> n;
        for (int i=1; i<=n; ++i) {
            edges[i].clear();
        }
        for (int i=1; i<n; ++i) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}
