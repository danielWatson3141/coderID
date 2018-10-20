/* 
 * File:   main.cpp
 * Author: tlatif
 *
 * Created on April 25, 2014, 8:40 PM
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>

#define INF 999999999
#define pb push_back
typedef long long LL;

using namespace std;

const int maxN = 1002;

bool visited[maxN];
int children[maxN][maxN];
int runNode = 0;
vector <vector <int> > graph(maxN);

void init_d(int nodes) {
    int i, j;
    for (i = 0; i <= nodes; i++) {
        visited[i] = false;
        graph[i].clear();
        for (j = 0; j <= nodes; j++) {
            children[i][j] = 0;
        }
    }
}

int dfs(int u) {
    int i, v;
    visited[u] = true;
    for (i = 0; i < graph[u].size(); i++) {
        v = graph[u][i];
        if (!visited[v]) {
            children[runNode][u] += dfs(v);
            
        }
    }
    //cout<<runNode<<" "<<u<<" "<<children[runNode][u]<<endl;
    return children[runNode][u] + 1;
}

int bfs(int s) {
    int i, j;
    int u, v;
    int res = 0;
    queue<int> q;
    vector<pair <int, int> > cand;
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        u = q.front();
        //cout<<u<<endl;
        q.pop();
        cand.clear();
        //cout<<graph[u].size()<<" "<<u<<endl;
        for (i = 0; i < graph[u].size(); i++) {
            v = graph[u][i];
            if (!visited[v]) {
                visited[v] = true;
                cand.pb(make_pair(children[s][v], v));
                //cout<<v<<" vs "<<u<<endl;
            }
            
        }
        sort(cand.begin(), cand.end());
        //cout<<cand.size()<<"size"<<endl;
        if (cand.size() == 1) {
            //cout<<u<<" here1 "<<cand[0].second<<endl;
            res += cand[0].first + 1;
            continue;
        }
        if (cand.size() == 0) continue;        
        q.push(cand[cand.size() - 1].second);
        q.push(cand[cand.size() - 2].second);
//        if (u == 5 && s == 3) {
//            for (i = 0; i < cand.size(); i++) {
//                cout<<cand[i].first<<" ";
//            }
//            cout<<endl;
//        }
        for (i = 0; i < cand.size() - 2; i++) {
      //      cout<<u<<" here "<<cand[i].first<<endl;
            res += cand[i].first + 1;
        }
        
        
    }
    //cout<<res<<" s "<<s<<endl;
    return res;
}

/*
 * 
 */
int main() {
    freopen("input3.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int tc = 0, t;
    cin>>t;
    while (tc++ < t) {
        int n, i, j;
        int a, b;
        cin>>n;
        
        init_d(n);
        for (i = 0; i < n - 1; i++) {
            cin>>a>>b;
            a--;
            b--;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        for (i = 0; i < n; i++) {
            runNode = i;
            for (j = 0; j <= n; j++) {
                visited[j] = false;
            }
            dfs(i);
            //cout<<"here"<<endl;
        }
        int res = INF;
        for (i = 0; i < n; i++) {
            for (j = 0; j <= n; j++) {
                visited[j] = false;
            }
            int cand = bfs(i);
            
            //cout<<cand<<endl;
            res = min(res, cand);
        }
        printf("Case #%d: %d\n", tc, res);
    }
    return 0;
}

