#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

typedef std::vector<std::string> VS;

void Flip(VS& outlets, int position) {
  for (VS::iterator i = outlets.begin(); i != outlets.end(); ++i) {
    (*i)[position] = ((*i)[position] == '1' ? '0' : '1');
  }
}

int MinFilps(VS& outlets, const VS& devices, int current_position) {
  if (current_position >= outlets.front().size()) {
    VS o = outlets;
    VS d = devices;
    std::sort(o.begin(), o.end());
    std::sort(d.begin(), d.end());
    for (int i = 0; i < o.size(); ++i) {
      if (o[i] != d[i]) {
        return -1;
      }
    }
    return 0;
  }

  int o1count = 0;
  for (int i = 0; i < outlets.size(); ++i) {
    if (outlets[i][current_position] == '1') {
      ++o1count;
    }
  }
  int d1count = 0;
  for (int i = 0; i < devices.size(); ++i) {
    if (devices[i][current_position] == '1') {
      ++d1count;
    }
  }

  const int num_el = outlets.size();
  if (o1count * 2 == num_el) {
    const int res1 = MinFilps(outlets, devices, current_position + 1);
    Flip(outlets, current_position);
    const int res2 = MinFilps(outlets, devices, current_position + 1);
    Flip(outlets, current_position);
    if (res1 == -1 && res2 == -1) {
      return -1;
    }
    if (res1 == -1) {
      return res2 + 1;
    }
    if (res2 == -1) {
      return res1;
    }
    return res1 < (res2 + 1) ? res1 : (res2 + 1);
  }
  if (o1count == d1count) {
    return MinFilps(outlets, devices, current_position + 1);
  }
  if (o1count == num_el - d1count) {
    Flip(outlets, current_position);
    const int res = MinFilps(outlets, devices, current_position + 1);
    Flip(outlets, current_position);
    if (res == -1) {
      return -1;
    }
    return res + 1;
  }
  return -1;
}

int main() {
  int T = 0;
  scanf("%d", &T);

  VS outlets;
  outlets.reserve(150);
  VS devices;
  devices.reserve(150);

  for (int t = 1; t <= T; ++t) {
    int N = 0;
    int L = 0;
    scanf("%d %d", &N, &L);

    outlets.clear();
    devices.clear();

    static char buffer[200];
    for (int i = 0; i < N; ++i) {
      scanf("%s", buffer);
      outlets.push_back(std::string(buffer));
    }
    for (int i = 0; i < N; ++i) {
      scanf("%s", buffer);
      devices.push_back(std::string(buffer));
    }

    const int res = MinFilps(outlets, devices, 0);
    if (res == -1) {
      printf("Case #%d: NOT POSSIBLE\n", t);
    } else {
      printf("Case #%d: %d\n", t, res);
    }
  }
  return 0;
}
