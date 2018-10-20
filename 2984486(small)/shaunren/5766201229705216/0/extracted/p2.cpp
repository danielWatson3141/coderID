#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stdint.h>
using namespace std;

int n;

bool visited[1001];
int size[1001];

int search(vector<int>* adj,int u)
{
    visited[u] = true;
    size[u] = 1;
    pair<int,int> a[1001];
    int i=0;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            int x = search(adj,v);
            a[i++] = make_pair(size[v]-x,v);
            size[u] += size[v];
        }
    }
    //if (!ret) return -1;
    if (i<2) return size[u]-1;
    else {
        sort(a,a+i);
        int r = size[a[i-1].second]-a[i-1].first + size[a[i-2].second]-a[i-2].first;
        for (int j=0;j<i-2;j++) r += size[a[j].second];
        return r;
    }
}

__attribute__((optimize("-O3")))
int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(0);

    int tcas;
    cin >> tcas;
    for (int cas=1;cas<=tcas;cas++) {
        vector<int> adj[1001];
        
        cin >> n;
        for (int i=0;i<n-1;i++) {
            int x,y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int best = 1000000, sz;
        for (int i=1;i<=n;i++) {
            memset(visited,0,sizeof(visited));
            best = min(best, search(adj,i));
        }
        cout<< "Case #" << cas << ": " << best << endl;
    }
    return 0;
}
