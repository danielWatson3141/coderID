#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, L;


int cal_(int j_, vector<string> d, vector<string> ot)
{
  int ret = 0;
  const string &di = d[0];
  const string &oi = ot[j_];
  for(int i = 0; i < L; ++i) {
    if(di[i] != oi[i]) {
      ++ret;
      for(int j = 0; j < N; ++j) {
        ot[j][i] = ('1' - ot[j][i]) + '0';
      }
    }
  }

  sort( d.begin(), d.end() );
  sort( ot.begin(), ot.end() );

  for(int i = 0; i < N; ++i) if(d[i] != ot[i]) return 500;
  return ret;
}

int main()
{
  int T;
  cin >> T;
  for(int case_num = 1; case_num <= T; ++case_num) {
    int ans = 500;
    cin >> N >> L;
    vector<string> dev(N), otlets(N);

    for(int i = 0; i < N; ++i) {
      cin >> dev[i];
    }

    for(int i = 0; i < N; ++i) {
      cin >> otlets[i];
    }

    for(int j = 0; j < N; ++j) {
      const int ret = cal_(j, dev, otlets);
      ans = min(ans, ret);
    }

    if(ans != 500) cout << "Case #" << case_num << ": " << ans << endl;
    else cout << "Case #" << case_num << ": NOT POSSIBLE" << endl;
  }
  return 0;
}

