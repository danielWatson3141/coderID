#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void solve()
{
  int N, L;
  cin >> N >> L;
  
  string out[200], in[200];
  for (int i = 0; i < N; i++) {
    cin >> out[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> in[i];
  }
  sort(out, out+N);

  int ans = 1000;
  for (int i = 0; i < N; i++) {
    bool flip[200] = {false};
    for (int b = 0; b < L; b++) {
      flip[b] = (out[i][b] != in[0][b]);
    }
    string temp_in[200];
    for (int j = 0; j < N; j++) {
      for (int b = 0; b < L; b++) {
	if (flip[b]) {
	  temp_in[j] += (in[j][b] == '1') ? '0' : '1';
	} else {
	  temp_in[j] += in[j][b];
	}
      }
    }
    sort(temp_in, temp_in+N);
    if (equal(temp_in, temp_in+N, out)) {
      ans = min(ans, (int)count(flip, flip+L, true));
    }
  }

  if (ans > L) {
    cout << "NOT POSSIBLE" << endl;
  } else {
    cout << ans << endl;
  }
}

int main()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
