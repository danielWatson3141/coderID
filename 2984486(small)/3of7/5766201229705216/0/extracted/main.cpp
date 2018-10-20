#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector< vector< int > > edges;
vector<int> vis;

// <tree size, num to delete>
pair<int, int> rec(int me, int from) {
    pair<int, int> ret(1, 0);
    int ne = edges[me].size();
    vector<int> subtr;
    for(int i = 0; i < ne; i++) {
        if(edges[me][i] == from) continue;
        pair<int, int> res = rec(edges[me][i], me);
        ret.first += res.first;
        ret.second += res.second;
        subtr.push_back(res.first);
    }
    sort(subtr.begin(), subtr.end());
    if(subtr.size() == 0 || subtr.size() == 2) {
        return ret;
    }
    if(subtr.size() == 1) {
        ret.second += subtr[0];
        ret.first = 1;
        return ret;
    }
    ret.first = 1;
    for(int i = 0; i < subtr.size() - 2; i++) {
        ret.second += subtr[i];
    }
    return ret;
}

void flood(int me, int i) {
    vis[me] = 1;
    for(int j = 0; j < edges[me].size(); j++) {
        if(!vis[edges[me][j]] && (i & (1<<edges[me][j])))
            flood(edges[me][j], i);
    }
}

int main() {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-bf.out", "w", stdout);
    int T, N;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int ans = 10000;
        cin >> N;
        edges = vector< vector< int > >(N, vector<int>());
        for(int i = 0; i < N - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        // r is root node #
        for(int i = 1; i < (1 << N); i++) {
            bool can = false;
            if(i == (1<<N) - 1) {
                can = true;
            }
            for(int r = 0; r < N; r++) {
                if(!(i & (1<<r))) continue;
                vis = vector<int>(N, 0);
                bool good = true;
                flood(r, i);
                for(int j = 0; j < N; j++) {
                    if(i & (1<<j)) {
                        if(!vis[j]) {
                            good = false;
                            break;
                        }
                    }
                }
                if(!good) continue;
                for(int j = 0; j < N; j++) {
                    if(i & (1<<j)) {
                        int ge = 0;
                        for(int k = 0; k < edges[j].size(); k++) {
                            if(i & (1<<edges[j][k])) ge++;
                        }
                        if(j == r) {
                            if(ge != 0 && ge != 2) {
                                good = false;
                                break;
                            }
                        } else {
                            if(ge != 1 && ge != 3) {
                                good = false;
                                break;
                            }
                        }
                    }
                }
                if(good) {
                    int del = 0;
                    for(int j = 0; j < N; j++) {
                        if(!(i & (1<<j))) del++;
                    }
                    ans = min(ans, del);
                }
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}