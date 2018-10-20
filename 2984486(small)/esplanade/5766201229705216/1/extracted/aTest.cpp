//#define __test__aTest__
#ifndef __test__aTest__

#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <assert.h>
#include <stdexcept>

using namespace std;

#define ll long long
#define ull size_t

int N;
vector<int> used;
vector<int> sz;
vector<vector<int> > child;
map<int, vector<int> > edges;

void buildTree(int idx) {
    if (used[idx])  return;
    used[idx] = 1;
    sz[idx] = 1;
    for (int i = 0; i < edges[idx].size(); i++) {
        int j = edges[idx][i];
        if (!used[j]) {
            child[idx].push_back(j);
            buildTree(j);
            sz[idx] += sz[j];
        }
    }
}

int getFull(int idx) {
    if (child[idx].size() <= 1)  return 1;
    vector<int> v;
    int n = (int)child[idx].size();
    for (int i = 0; i < n; i++) {
        v.push_back(getFull(child[idx][i]));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    return 1 + v[0] + v[1];
}

void process(int index) {
    cin >> N;
    edges.clear();
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int d = N - 1;
    for (int i = 0; i < N; i++) {
        child  = vector<vector<int> >(N, vector<int>());
        used = vector<int>(N, 0);
        sz = vector<int>(N, 0);
        buildTree(i);
        int ff = getFull(i);
        d = min(d, N - ff);
    }
    cout<<"Case #"<<index<<": "<<d<<endl;
}

int main() {
    
    freopen("/Users/zishirs/Documents/workspace/test/test/test.txt", "r", stdin);
    freopen("/Users/zishirs/Documents/workspace/test/test/output.txt", "w", stdout);
    
    
    
    int T;
    cin >> T;
    for (int index = 1; index <= T; ++index) {
        //cout<<"Case #"<<index<<": ";
        process(index);
    }
    
    /*
    int F;
    cin >> F;
    int n;
    vector<long long> v;
    while (cin >> n) {
        v.push_back(n);
    }
    vector<int> v1(v.begin(), v.begin() + v.size()/2), v2(v.begin() + v.size()/2, v.end());
     */ 
    
    return 0;
}

#endif