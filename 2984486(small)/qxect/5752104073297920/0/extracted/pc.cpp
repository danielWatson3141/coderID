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

int arr[1020];

int main()
{
  int T;
  int typ;
  int n;
  int i,j;
  int cnt;
  srand(time(0));
  cin >> T;
  for(int z=1;z<=T;z++){
    int cnt22 =0;
    cin >> n;
    for(i=0;i<n;i++){
      cin >> arr[i];
      cnt22 += (arr[i]==i);
    }
    cnt = 0;
    for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
        if(arr[i] > arr[j]) cnt++;
      }
    }
    typ = (cnt * 4 + ( cnt22 * 2) <= (n*(n-1)));
    printf("Case #%d: %s\n", z, typ==0?"GOOD":"BAD");
  }
  return 0;
}
