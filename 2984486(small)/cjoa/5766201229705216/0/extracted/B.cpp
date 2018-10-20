#include <iostream>

#include <cstring>

#include <vector>

using namespace std;

#define SZ(a) int((a).size())

#define REP(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)

typedef vector<int> VI;
typedef vector<VI> VVI;

const int INF = 0x3f3f3f3f;

int N;

VI adj[1004];

int subtree_size[1004];
int DP[1004];

int ROOT;
void dfs(int u, int p = 0) {
// DP[u] = INF;
   subtree_size[u] = 1;
   int nchildren = 0;
   REP(j, SZ(adj[u])) {
      int v = adj[u][j];
      if (v == p) continue;
      ++nchildren;
      dfs(v, u);
      subtree_size[u] += subtree_size[v];
   }

//   if (ROOT == 2 && u == 2) {
//   }

   switch ( nchildren ) {
      case 0:
         DP[u] = 0;
         break;
      case 1: {
         int v = adj[u][0];
         if (v == p) v = adj[u][1];
         DP[u] = subtree_size[ v ];
         break;
      }
      case 2: {
         int v1 = 0, v2 = 0;
         REP(j, SZ(adj[u])) {
            int v = adj[u][j];
            if (v == p) continue;
            if (!v1) v1 = v;
            else if (!v2) v2 = v;
         }
         DP[u] = DP[ v1 ] + DP[ v2 ];
         break;
      }
      default:
         DP[u] = subtree_size[u] - 1;  // delete all, except node u

         // keep two children
         REP(j1, SZ(adj[u])) {
            int v1 = adj[u][j1];
            if (v1 == p) continue;
            FOR(j2, j1+1, SZ(adj[u])-1) {
               int v2 = adj[u][j2];
               if (v2 == p) continue;
               int cur = DP[ v1 ] + DP[ v2 ] +
                         subtree_size[u] - 1 - subtree_size[v1] - subtree_size[v2];
               if (DP[u] > cur) {
                  DP[u] = cur;
               }
            }
         }

         break;
   }
}

int solve(int root) {
//   memset(DP, 0x3f, sizeof(DP[0])*(N+2));
   ROOT = root;

   dfs(root);

// cerr << "root = " << root << "  ->  " << DP[root] << endl;

   return DP[root];
}

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int TC;
   cin >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      cin >> N;
      for (int j = 1; j < N; ++j) {
         int u, v;
         cin >> u >> v;
      // --u, --v;
         adj[u].push_back(v);
         adj[v].push_back(u);
      }

      int res = N;
      for (int u = 1; u <= N; ++u) {
         int cur = solve(u);
         if (res > cur) {
            res = cur;
         }
      }

      cout << "Case #" << tc << ": " << res << endl;

      for (int u = 1; u <= N; ++u)
         adj[u].clear();
   }

   return 0;
}
