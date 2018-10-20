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

int N;
bool con[1100][1100];
bool v[1100];
int aSize[1100][1100];
int aMinCut[1100][1100];

void read(ifstream &fin) {
 int x, y;

 fin >> N;
 _cl(con);

 frr(i, N - 1) {
  fin >> x >> y;
  x--, y--;
  con[x][y] = true;
  con[y][x] = true;
 }
}

void calc(int n, int &size, int &minCut) {
 size = 1;
 minCut = 0;
 v[n] = true;

 int K = 0;
 frr(i, N) if(!v[i] && con[n][i]) {
  int s, m;
  calc(i, s, m);
  aSize[n][K] = s;
  aMinCut[n][K] = m;
  K++;
  size += s;
 }

 if(K == 1) {
  minCut = size - 1;
 } else if(K > 1) {
  minCut = size;
  frr(i, K) for(int j = i + 1; j < K; ++j) {
   minCut = min(minCut, size - 1 - aSize[n][i] - aSize[n][j] + aMinCut[n][i] + aMinCut[n][j]);
  }
 }
}

void proc(ofstream &fout) {
 int size, minCut;
 int ans = N;

 frr(i, N) {
  _cl(v);

  calc(i, size, minCut);
  ans = min(ans, minCut);
 }

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
