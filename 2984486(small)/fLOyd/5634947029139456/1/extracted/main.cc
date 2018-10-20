#include <iostream>
#include <string>

const int MAXN = 155;

int T, N, L;
std::string src[MAXN], trg[MAXN];
bool mark[MAXN];

char other(char c) {
  return (c == '0') ? '1' : '0';
}

void solve() {
  char c;

  std::cin >> T;
  for (int tt = 0; tt < T; ++tt) {
    std::cin >> N;
    std::cin >> L;

    for (int n = 0; n < N; ++n) {
      src[n].clear();
      for (int l = 0; l < L; ++l) {
        std::cin >> c;
        src[n].append(1, c);
      }
    }
    for (int n = 0; n < N; ++n) {
      trg[n].clear();
      for (int l = 0; l < L; ++l) {
        std::cin >> c;
        trg[n].append(1, c);
      }
    }

#if 0
    for (int n = 0; n < N; ++n) { std::cout << src[n] << " "; }
    std::cout << std::endl;
    for (int n = 0; n < N; ++n) { std::cout << trg[n] << " "; }
    std::cout << std::endl;
#endif
    int ans = 1000, current;
    for (int i = 0; i < N; ++i) {
      current = 0;
      for (int j = 0; j < L; ++j) {
        if (src[0][j] != trg[i][j]) {
          current++;
        }
      }

      for (int n = 0; n < N; ++n) { mark[n] = false; }
      mark[i] = true;

      bool good = true;

      for (int j = 1; j < N; ++j) {
        std::string convert = src[j];
        for (int k = 0; k < L; ++k) {
          if (src[0][k] != trg[i][k]) {
            convert[k] = other(src[j][k]);
          }
        }
        //std::cout << convert << std::endl;
        bool match = false;
        for (int k = 0; k < N; ++k) {
          if (convert.compare(trg[k]) == 0) {
            match = true;
            break;
          }
        }
        if (!match) {
          good = false;
          break;
        }
      }
      if (good) {
        if (current < ans) {
          ans = current;
        }
      }
    }
    std::cout << "Case #" << tt + 1 << ": ";
    if (ans != 1000) {
      std::cout << ans << std::endl;
    } else {
      std::cout << "NOT POSSIBLE\n";
    }
  }
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
