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

/*int solve(vector<string> &dev, vector<string> &pow, int bit, int i, int j) {
  int cptdev = 0, cptpow = 0;;
  FOR(k,i,j+1) {
    if (pow[k][bit] == '0') cptpow++;
    if (dev[k][bit] == '0') cptdev++;
  }
 
  int mini = -1;
  if (cptdev == cptpow) {
    int last = j;
    for(k = i; k <= last; ) {
      if (dev[k][bit] == '1') {
	tmp = dev[last];
	dev[last] = dev[k];
	dev[k] = tmp;
	last--;
      }
      else
	k++;
    }
    int nb = j-last;
    int s1 = solve(dev,pow,bit+1,i,i+nb-1);
    int s2 = solve(dev,pow,bit+1,i+nb,j);
    if (s1 != -1 && s2 != -1) mini = 
  }
  if (cptdev == 1-cptpow) {
    int last = j;
    for(k = i; k <= last; ) {
      if (dev[k][bit] == '0') {
	tmp = dev[last];
	dev[last] = dev[k];
	dev[k] = tmp;
	last--;
      }
      else
	k++;
    }
    int nb = j-last;
    ok |= (solve(dev,pow,bit+1,i,i+nb-1) && solve(dev,pow,bit+1,i+nb,j));
  }
  return ok;
  }*/

int main() {
  int T;
  cin >> T;
  cout.precision(12);
  FOR (test, 1, T+1) {
    int n, L;
    cin >> n >> L;
    vector<string> dev(n);
    vector<string> pow(n);
    FOR(i,0,n) {
      cin >> pow[i];
    }
    FOR(i,0,n) {
      cin >> dev[i];
    }
    sort(all(dev));
    sort(all(pow));

    unsigned int i = 0;
    int mini = -1;
    
    FOR(i,0,1<<L) {
      int cpt = 0;
      FOR(j,0,L) {
	if (i & (1<<j)) {
	  cpt ++;
	  FOR(k,0,n) {
	    if (pow[k][j] == '0') pow[k][j]='1';
	    else pow[k][j] = '0';
	  }
	}
      }
      sort(all(pow));
      bool ok = true;
      FOR(k,0,n) if (pow[k]!=dev[k]) {
	ok = false;
	break;
      }
      if (ok && (mini == -1 || cpt < mini)) {
	mini = cpt;
      }
      FOR(j,0,L) {
	if (i & (1<<j)) {
	  cpt ++;
	  FOR(k,0,n) {
	    if (pow[k][j] == '0') pow[k][j]='1';
	    else pow[k][j] = '0';
	  }
	}
      }
    }
    if (mini == -1)
      cout << "Case #" << test << ": NOT POSSIBLE" << endl;
    else
      cout << "Case #" << test << ": " << mini << endl;
  }
  return 0;
}
