#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <bitset>
#include <queue>
using namespace std;

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long ll;

//container util
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

//constant
const double EPS = 1e-10;
const int MAXI = 1234567890;

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;



void printList(const vector<bitset<10> >& v) {
  for (size_t i = 0; i < v.size(); i++) {
	cout << v[i] << " ";
  }
  cout << endl;
}

void printMatrix(vector< vector<bitset<10> > >& v) {
  for (size_t i = 0; i < v.size(); i++) {
	printList(v[i]);
  }
  cout << endl;
}


int flip(int b, const vector<bitset<10> >& flow, vector<bitset<10> >& fliped) {
  int ans = 0;
  fliped = flow;
  int k = -1;
  while (b > 0) {
    k++;
    int t = b % 2;
    b = b / 2;
    if (t == 0) continue;
    ans++;
    for (size_t i = 0; i < flow.size(); i++) {
      fliped[i].flip(k);
    }
  }
  return ans;
}

bool is_ok(const vector<bitset<10> >& a,
	   const vector<bitset<10> >& b) {
  for (size_t i = 0; i < a.size(); i++) {
    bool found = false;
    for (size_t j = 0; j < b.size(); j++) {
      if (a[i] != b[j]) continue;
      found = true;
    }
    if (!found) return false;
  }
  return true;
}


int solve(int N, int L, vector<string>& flow0, vector<string>& req0) {
  vector< bitset<10> > flow;
  vector< bitset<10> > req;
  for (size_t i = 0; i < flow0.size(); i++) {
    flow.push_back(bitset<10>(flow0[i]));
    req.push_back(bitset<10>(req0[i]));
  }
  int minv = 100;
  if (is_ok(flow, req)) minv = 0;
  for (int i = 1; i < 1 << L; i++) {
    vector< bitset<10> > fliped;
    int t = flip(i, flow, fliped);
    if (is_ok(fliped, req)) {
      minv = min(minv, t);
    }
  }
  return minv;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int N, L;
    cin >> N >> L;
    vector<string> flow;
    vector<string> req;
    for (int j = 0; j < N; j++) {
      string s;
      cin >> s;
      flow.push_back(s);
    }
    for (int j = 0; j < N; j++) {
      string s;
      cin >> s;
      req.push_back(s);
    }
    int ans = solve(N, L, flow, req);
    cout << "Case #" << i + 1 << ": ";
    if (ans < 100) cout << ans << endl;
    else cout << "NOT POSSIBLE" << endl;
  }
  return 0;
}
