#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

#define PRINT(x) cout << "DEBUG " << #x << " = " << x <<  endl;

#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fr(i, n) for(i = 0; i < (n); i++)
#define frr(i, n) for(int i = 0; i < (n); i++)
#define _cl(x) memset(x, 0, sizeof(x))
#define _rs(x) memset(x, -1, sizeof(x))

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef istringstream ISS;
typedef ostringstream OSS;
typedef long long ll;

int N, L;
ll a[100], b[100], ca[100];
int ans;

void read(ifstream &fin) {
 string s;

 fin >> N >> L;
 frr(i, N) {
  fin >> s;
  a[i] = 0;
  frr(j, L) if(s[j] == '1')
   a[i] |= 1 << j;
 }
 frr(i, N) {
  fin >> s;
  b[i] = 0;
  frr(j, L) if(s[j] == '1')
   b[i] |= 1 << j;
 }
}

void calc(ll n) {
 int c = 0;
 frr(j, L) if(n & (1 << j)) c++;

 frr(j, N)
  ca[j] = n ^ a[j];
 sort(ca, ca + N);
 bool found = true;
 frr(j, N) if(ca[j] != b[j]) found = false;

 if(found)
  ans = min(ans, c);
}

void proc(ofstream &fout) {
 ans = L + 1;

 sort(a, a + N);
 sort(b, b + N);

 calc(0);
 frr(i, N) {
  calc(a[i] ^ b[0]);
 }

 if(ans > L)
  fout << "NOT POSSIBLE" << endl;
 else
  fout << ans << endl;
}

int main() {
 int i;
 int NT;

 ifstream fin("in");
 ofstream fout("out");
 string ln;

 getline(fin, ln);
 istringstream is(ln);
 is >> NT;

 fr(i, NT)
 {
  read(fin);
  fout << "Case #" << i + 1 << ": ";
  cout << "Case #" << i + 1 << endl;
  proc(fout);
 }

 return 0;
}
