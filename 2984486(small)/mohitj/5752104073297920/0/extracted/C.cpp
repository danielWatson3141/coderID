#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;


#if 0
const int N = 3;
const double CM = 1.0 / N;

double gprob[2][N][N] = {0.0};
double bprob[2][N][N] = {0.0};

void init()
{
  int cur = N & 1;
  int ncur = 1 - cur;

  for(int i = 0; i < N; ++i) {
    gprob[cur][i][i] = CM;
    bprob[cur][i][i] = 1.0;
  }

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      for(int k = 0; k < N; ++k) {
        const double fraction = bprob[cur][j][k] * CM;
        for(int z = 0; z < N; ++z) {
          bprob[ncur][j][k] += fraction;
        }
      }
    }
    swap(cur, ncur);
  }
}
#endif

void exec(int case_num) {
  int N;
  scanf("%d", &N);

  int cnt[2] = {0};
  int z1;
  cin >> z1;
  for(int i = 1; i < N; ++i) {
    int z2;
    cin >> z2;
    if(z1 < z2) cnt[0]++;
    else cnt[1]++;
    z1 = z2;
  }
  if(200 * abs(cnt[0] - cnt[1]) < 3 * N) cout << "Case #" << case_num << ": BAD\n";
  else cout << "Case #" << case_num << ": GOOD\n";
}

int main()
{
//  init();
//cerr << "Init done\n";
  int T;
  cin >> T;
  for(int cn = 1; cn <= T; ++cn) exec(cn);
  return 0;
}
