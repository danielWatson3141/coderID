// written by lonerdude(dvdreddy)
// all rights reserved
//the template by dvdreddy
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>

using namespace std;

#define si(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)

#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;
typedef pair<int, int> pii;

vector<vector<int> > edges;
vector<int> par;

bool comp(pii x, pii y) {
  if (x.second > y.second) {
    return  1;
  } else if (x.second < y.second) {
    return 0;
  } else {
    return (x.first < y.first);
  }
  
}


pair<int, int> res_comp(int x) {
  if (edges[x].size() == 1) {
    if (par[x] == -1) {
      return make_pair(par.size() - 1, 0);
    } else {
      return make_pair(1, 1);
    }
  }

  vector<pii> vp;  
  fr (i, edges[x].size()) {
    if (par[x] != edges[x][i]) {
      vp.push_back(res_comp(edges[x][i]));
    }
  }
  
  sort(vp.begin(), vp.end(), comp);

  if (vp.size() == 1) {
    return make_pair(vp[0].first + 1, 1);
  } else {
    int cnt = 0;
    fr (i, vp.size()) {
      cnt += vp[i].first;
    }
    return make_pair(cnt + 1, vp[0].second + vp[1].second + 1);
  }
}

int main() {
  int ti;
  si(ti);
  f (t, 1, ti + 1) {
    fr (i, edges.size()) {
      edges[i].clear();      
    }
    edges.clear();
    int n; si(n);
    edges.resize(n);
    fr (i, n - 1) {
      int a, b;
      si(a); si(b); a--; b--;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }

    int maxi = n - 1;
    fr (i, n) {
      par.clear();
      par.resize(n);
      par[i] = -1;
      queue<int> q;
      q.push(i);
      while (!q.empty()) {
        int x = q.front();
        fr (j, edges[x].size()) {
          if (edges[x][j] != par[x]) {
            par[edges[x][j]] = x;
            q.push(edges[x][j]);
          }
        }
        q.pop();
      }
      maxi = min(maxi, res_comp(i).first - res_comp(i).second);
    }   

    printf("Case #%d: %d\n", t, maxi);
  }
  return 0;
}
