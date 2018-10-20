#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void print_vector(vi v);
void print_array(int* array, int start, int end);

#define FOR(i,a,b) for (int i = (a),_b = (b); i < _b; i++)
#define DOW(i,b,a) for (int i = (b),_a = (a); i > _a; i--)
#define fill(a,v) memset(a, v, sizeof a)
#define checkbit(n,b) ((n >> b) & 1)
#define pb(a) push_back(a)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()

#define INF 1e9
#define PI acos(-1.0)

#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

vvi graph;
int tc, cse = 1, u, v;
int n, parent[1040], weightmemo[1040];

void dfs(int u){
  FOR(i, 0, SZ(graph[u])){
    if(graph[u][i] != parent[u]){
      parent[graph[u][i]] = u;
      dfs(graph[u][i]);
    }
  }
}

int weight(int u){
  if(weightmemo[u] != -1) return weightmemo[u];
  int count = 0;
  FOR(i, 0, SZ(graph[u])){
    if(graph[u][i] != parent[u]) count++;
  }
  if(count == 0) return weightmemo[u] = 1;
  else {
    int result = 1;
    FOR(i, 0, SZ(graph[u])){
      if(graph[u][i] != parent[u]){
        result += weight(graph[u][i]);
      }
    }
    return weightmemo[u] = result;
  }
}

int magic(int u){
  int count = 0;
  FOR(i, 0, SZ(graph[u])){
    if(graph[u][i] != parent[u]) count++;
  }
  if(count == 0) return 0;
  else if (count == 1) {
    FOR(i, 0, SZ(graph[u])){
      if(graph[u][i] != parent[u]){
        return weight(graph[u][i]);
      }
    }
  } else if (count == 2){
    int result = 0;
    FOR(i, 0, SZ(graph[u])){
      if(graph[u][i] != parent[u]){
        result += magic(graph[u][i]);
      }
    }
    return result;
  } else {

    int best = 0, secondbest = 0, bestindex = -1, secondbestindex = -1;
    FOR(i, 0, SZ(graph[u])){
      if(graph[u][i] != parent[u]){
        int v = graph[u][i];
        int w = weight(v);
        if(w >= best){
          secondbest = best;
          secondbestindex = bestindex;
          best = w;
          bestindex = v;
        } else if (w >= secondbest){
          secondbest = w;
          secondbestindex = v;
        }
      }
    }
    int result = 0;
    FOR(i, 0, SZ(graph[u])){
      
      if(graph[u][i] == bestindex || graph[u][i] == secondbestindex){
        result += magic(graph[u][i]);
      } else if (graph[u][i] != parent[u]){
        result += weight(graph[u][i]);
      }
    }
    return result;
  }
  return 0;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
    s(tc);
    while(tc--){
      s(n);
      graph.assign(n, vi());
      FOR(i, 0, n-1){
        s(u), s(v);
        graph[u-1].pb(v-1);
        graph[v-1].pb(u-1);
      }
      int mini = 10000;
      FOR(i, 0, n){
        fill(parent, -1);
        fill(weightmemo, -1);
        dfs(i);
        weight(i);
        //print_array(parent, 0, n);
        //print_array(weightmemo, 0, n);
        mini = min(mini, magic(i));
      }
      printf("Case #%d: %d\n", cse++, mini);
    }
    return 0;
}

void print_array(int* array, int start, int end){
  printf("[");
  FOR(i, start, end){
    printf("%d ", array[i]);
  }
  printf("]");
  printf("\n");
}

void print_vector(vi v){
  printf("[");
  FOR(i, 0, v.size()){
    printf("%d ", v[i]);
  }
  printf("]");
  printf("\n");
}