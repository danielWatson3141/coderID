#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

#define REP(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long LL;

int nextInt() {
  char c;
  int res = 0;
  while (!isdigit(c = getchar())){};
  do {
    res = res * 10 + c - '0';
  } while (isdigit(c = getchar()));
  return res;
}



void solve(int caseCnt) {
  vector<string> initial, target;
  int N, L;
  cin >> N >> L;
  REP(i, N) {
    string s;
    cin >> s;
    initial.push_back(s);
  }
  REP(i, N) {
    string s;
    cin >> s;
    target.push_back(s);
  }
  sort(target.begin(), target.end());
  int res = 1 << 20;
  REP(i, N) {
    vector<string> initial_copy = initial;
    string s = initial[0];
    int cnt = 0;
    REP(j, s.size()) {
      if (s[j] != target[i][j]) {
        cnt++;
        REP(k, initial_copy.size()) {
          initial_copy[k][j] = initial_copy[k][j] == '0' ? '1' : '0';
        }
      }
    }
    sort(initial_copy.begin(), initial_copy.end());
    if (initial_copy == target) {
      res = min(res, cnt);
    }
  }
  if (res < (1 << 20)) {
    printf("Case #%d: %d\n", caseCnt, res);
  } else {
    printf("Case #%d: NOT POSSIBLE\n", caseCnt);
  }
}


int main(){
	int TestCase = nextInt();

	for(int caseCnt=1; caseCnt <= TestCase; caseCnt++){
		//solve_small(caseCnt);
		solve(caseCnt);
	}
	return 0;
}
