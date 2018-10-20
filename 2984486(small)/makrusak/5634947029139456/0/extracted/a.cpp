#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <ctime>

#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define ALL(x) x.begin(), x.end()
#define F first
#define S second
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,-1,sizeof(x))
#define pw(x) (1ull<<(x))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

string a[200];
string b[200];
int te,n,l;
string at[200];
string bt[200];

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> te;
  for (int tee=0;tee<te;tee++) {
    cout << "Case #" << tee+1 << ": ";
    cin >> n >> l;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];
    int ans = INF;
    sort(b, b+n);
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
        for (int q=0;q<n;q++) at[q] = a[q], bt[q] = b[q];
        int co = 0;
        for (int pos=0;pos<l;pos++) {
          if (a[i][pos]==b[j][pos]) continue;
          co++;
          for (int k=0;k<n;k++) if(at[k][pos]=='0') at[k][pos] = '1'; else at[k][pos] = '0';
        }
        sort(at, at+n);
        int good = 1;
        for (int k=0;k<n;k++) if (at[k]!=bt[k]) good = 0;
        if (good) ans = min(ans, co);
      }
    }
    if (ans==INF) {
      cout << "NOT POSSIBLE\n";
    }
    else {
      cout << ans << "\n";
    }
  }
  return 0;
}
