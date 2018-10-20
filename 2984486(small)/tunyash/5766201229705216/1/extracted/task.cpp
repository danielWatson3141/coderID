#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const int INF = 1000000000;
const int prime = 9241;
const ld pi = acos(-1.);

vector<int> con[1005];

int dfs(int v, int p)
{
   int best[2] = {-10000,-10000};
   for (int i = 0; i < (int)con[v].size(); i++)
   {
      if (con[v][i] == p) continue;
      int vv = dfs(con[v][i], v);
      if (vv >= best[0]) {best[1] = best[0]; best[0] = vv;}
      else if (vv >= best[1]) best[1] = vv;
   }
   return  max(1, best[0] + best[1] + 1);
}

void solve(int test)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) con[i].clear();
    for (int i = 0; i < n-1; i++)
    {
       int a,b;
       cin >> a >> b;
       a--; b--;
       con[a].pb(b);
       con[b].pb(a);
    }
    int ans = 0;
    for (int root = 0; root < n; root++) 
    {
       int cur = dfs(root, -1);
      // cout << "root=" << root << " cur=" <<cur <<  endl;
       ans = max(ans, cur);
    }
    
    cout << "Case #" << test << ": " << n-ans << endl;
}


int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}