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

ll a[155], b[155], c[155];
void solve(int test)
{
   int n, m;
   cin >> n >> m;
   for (int i = 0; i < n; i++)
   {
      string s;
      cin >> s;
      assert((int)s.size() == m);
      a[i] = 0;
      for (int j = 0; j < m; j++)
         if (s[j] == '1') a[i] |= 1ll << j; 
   }
   for (int i = 0; i < n; i++)
   {
      string s;
      cin >> s;
      assert((int)s.size() == m);
      b[i] = 0;
      for (int j = 0; j < m; j++)
         if (s[j] == '1') b[i] |= 1ll << j; 
   }
   sort(b, b + n);
   int ans = (int)1e9;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {
         ll mask = a[i] ^ b[j];
         int r = 0;
         for (int k = 0; k < m; k++)
             if (mask & (1ll << k)) r++;
         for (int k = 0; k < n; k++)
            c[k] = a[k] ^ mask;
         sort(c, c + n);
         bool ok = 1;
         for (int k = 0; k < n && ok; k++)
            if (c[k] != b[k]) ok = 0;
         if (ok) ans = min(ans, r);
      }
  cout << "Case #" << test << ": ";
  if (ans > (int)1e8) cout << "NOT POSSIBLE" << endl;
  else cout << ans << endl;
}


int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}