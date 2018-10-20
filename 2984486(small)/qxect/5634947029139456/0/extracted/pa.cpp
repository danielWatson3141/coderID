#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<cmath>

#include<algorithm>
#include<bitset>
#include<complex>
#include<deque>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<vector>
using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(a) (int((a).size()))
#define all(a) (a).begin(), (a).end()

#define For(it,c) for(typeof(c) it = ((c).begin()); it != ((c).end()) ; ++it)

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef complex<int> cI;
typedef complex<double> cD;

typedef pair<int,int> pI;
typedef pair<ll, ll> pL;

vector< string > in, out, tem;

int main()
{
  int T;
  int n, l;
  int ans;
  int S, i, j;
  bool flag;
  string str;
  
  cin >> T;
  for(int z=1;z<=T;z++){
    cin >> n >> l;
    ans = l;
    flag = false;
    in.clear();
    out.clear();
    for(i=0;i<n;i++){
      cin >> str;
      in.pb(str);
      
    }
    for(i=0;i<n;i++){
      cin >> str;
      out.pb(str);
    }
    sort(all(out));
    for(S=0;S<(1<<l);S++){
      int cnt = 0;
      for(j=0;j<l;j++) if(S & (1<<j)) cnt++;
      tem.clear();
      for(i=0;i<n;i++){
        str = in[i];
        for(j=0;j<l;j++){
          int t = (str[j]=='1');
          if(S & (1<<j)) str[j] = '0' + (t^1);
          else str[j] = '0' + t;
        }
        tem.pb(str);
      }
      sort(all(tem));
      for(i=0;i<n;i++) if(tem[i]!=out[i])break;
      if(i==n){
        flag = true;
        ans = min(ans, cnt);
      }
    }
    printf("Case #%d: ", z);
    if(!flag) puts("NOT POSSIBLE");
    else printf("%d\n", ans);
  }
  return 0;
}
