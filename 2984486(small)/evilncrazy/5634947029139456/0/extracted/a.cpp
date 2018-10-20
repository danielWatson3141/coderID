#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>

#define REP(i, n) for (int i = 0; i < (n); i++)

std::vector<std::string> energy;
std::vector<std::string> device;

int n, l;

int swaps()
{
  // This is the matching
  int swap = 0;
  REP (i, l) {
    int incorrect = 0;
    REP (j, n) {
      if (energy[j][i] != device[j][i]) {
        incorrect++;
      }
    }

    if (incorrect == n)
      swap++;
    
    if (!(incorrect == 0 || incorrect == n))
      return (1 << 30);
  }

  return swap;
}

void docase(int tcase) {
  scanf("%d %d", &n, &l);

  energy.clear(); device.clear();

  REP(i, n) {
    char buf[1000];
    scanf("%s", buf);
    energy.push_back(buf);
  }

  REP(i, n) {
    char buf[1000];
    scanf("%s", buf);
    device.push_back(buf);
  }

  std::sort(energy.begin(), energy.end());

  int best = (1 << 30);
  do {
    int r = swaps();
    best = std::min(best, r);
  } while (std::next_permutation(energy.begin(), energy.end()));

  if (best == (1 << 30)) {
    printf("Case #%d: NOT POSSIBLE\n", tcase, best);
  } else {
    printf("Case #%d: %d\n", tcase, best);
  }
}

int main() {
  int t; scanf("%d", &t);
  for (int i = 0; i < t; i++) docase(i+1);
}
