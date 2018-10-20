#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <strings.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <climits>
//#include <unordered_set>
//#include <unordered_map>
#include <assert.h>

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> int2;
typedef pair<float, float> float2;
typedef pair<ull, ull> ull2;

#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(s,i) for ( __typeof((s).begin()) i = ((s).begin())   ; i != (s).end(); ++i)  
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define mp(a,b) make_pair(a,b)
#define del(s,x) if(s.find(x)!=s.end()) s.erase(s.find(x))

#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)

bool comp(pair<int,int> a,pair<int,int> b) {return a.first < b.first; }

int tmp[1001];

int solve(vector<vector<int> > &v, int root, int father) {
  int n = v[root].size();
  assert (n > 0);
  if (n == 1 || (father != -1 && n == 2)) {
    return 1;
  }

  int i;
  int m1 = -1, m2 = -1;
  FOR(ind,0,n) {
    i = v[root][ind];
    if (i == father) continue;
    int z = solve(v,i,root);
    if (m1 == -1)
      m1 = z;
    else if (m2 == -1) {
      m2 = z;
      if (m2 > m1) swap(m1,m2);
    }
    else if (z >= m1) {
      m2 = m1;
      m1 = z;
    } else if (z > m2) {
      m2 = z;
    }
  }
  return m1 + m2 + 1;
}

int main() {
  int T;
  cin >> T;
  cout.precision(12);
  FOR (test, 1, T+1) {
    int n, tmp1, tmp2;
    cin >> n;
    vector<vector<int> > v(n);
    FOR(i,0,n-1) {
      cin >> tmp1 >> tmp2;
      tmp1--, tmp2--;
      v[tmp1].pb(tmp2);
      v[tmp2].pb(tmp1);
    }
    int maxi = 1; /* max number of remaining nodes */
    FOR(root,0,n) {
      int z = solve(v, root, -1);
      maxi = max(maxi,z);
    }
    
    cout << "Case #" << test << ": " << n - maxi << endl;
  }
  return 0;
}
