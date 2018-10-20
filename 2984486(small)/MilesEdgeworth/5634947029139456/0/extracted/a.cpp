#include <cstdio>
#include <iostream>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <utility>
#include <cstring>
#include <sstream>

const int MAX_N = 155;
const int MAX_L = 45;
int N, L;
long long initial[MAX_N];
long long outlet[MAX_N];
long long adj[MAX_N][MAX_N];
bool matching[MAX_N][MAX_N];

int num_matches(int n, int side) {
  int num = 0;
  for (int i = 0; i < N; ++i) {
    if ((!side ? matching[i][n] : matching[n][i])) {
      num++;
    }
  }
  return num;
}

bool bipartite(int n, int val, int last_idx, int side) {
  int match_idx = -1;
  for (int i = 0; i < N; ++i) {
    if (matching[n][i]) {
      match_idx = i;
      break;
    }
  }

  for (int i = 0; i < N; ++i) {
    if (i != last_idx && (side ? adj[i][n] == val : adj[n][i] == val) && !matching[n][i]) {
      if (num_matches(i, side) == 0) {
        if (match_idx == last_idx) {
          matching[n][i] = true;
          return true;
        } else if (match_idx == -1) {
          matching[n][i] = true;
          return false;
        }
      } else {
        if (bipartite(i, val, n, !side)) {
          matching[n][i] = !matching[n][i];
          return true;
        }
      }
    }
  }

  return false;
}

int bitcount(long long a) {
  int total = 0;
  for (int i = 0; i < 63; ++i) {
    total += (bool) (a & (1LL << i));
  }
  return total;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    memset(initial, 0, MAX_N * sizeof(long long));
    memset(outlet, 0, MAX_N * sizeof(long long));
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; ++i) {
      char buf[500];
      scanf(" %s ", buf);
      for (int k = 0; k < L; ++k) {
        initial[i] = (initial[i] << 1LL) | (buf[k] == '0' ? 0LL : 1LL);
      }
    }
    for (int i = 0; i < N; ++i) {
      char buf[500];
      scanf(" %s ", buf);
      for (int k = 0; k < L; ++k) {
        outlet[i] = (outlet[i] << 1LL) | (buf[k] == '0' ? 0LL : 1LL);
      }
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        adj[i][j] = initial[i] ^ outlet[j];
      }
    }
    int min = 1000000000;
    for (int k = 0; k < N; ++k) {
      memset(matching, 0, MAX_N * MAX_N);
      while (1) {
        bool done = true;
        for (int i = 0; i < N; ++i) {
          bipartite(i, adj[0][k], -1, false);
        }
        if (done) {
          break;
        }
      }

      int total = 0;
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          total += matching[i][j];
        }
      }
      if (total >=  N) {
        int bc = bitcount(adj[0][k]);
        min = std::min(min, bc);
      }
    }
    printf("Case #%d: ", t);
    if (min == 1000000000) {
      printf("NOT POSSIBLE\n");
    } else {
      printf("%d\n", min);
    }
  }
}
