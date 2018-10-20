#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

std::vector<int> permutate(std::vector<int> vt) {
  for (int k = 0; k < vt.size(); ++k) {
    // int p = rand() % (vt.size() - k) + k;
    int p = rand() % vt.size();
    std::swap(vt[k], vt[p]);
  }
  return vt;
}

int code(std::vector<int> &vt) {
  int ans = 0, p = 1;
  for (int i = 0; i < vt.size(); ++i) {
    ans += vt[i] * p;
    p *= (i + 1);
  }
  return ans;
}

bool monotonical(std::vector<int> &vt) {
  bool ok = true;
  for (int i = 1; i < vt.size(); ++i) {
    if (vt[i] > vt[i-1]) {
      ok = false;
    }
  }
  if(ok) {
    return ok;
  }
  ok = true;
  for (int i = 1; i < vt.size(); ++i) {
    if (vt[i] < vt[i-1]) {
      ok = false;
    }
  }
  return ok;
}

int main() {
  int T, n = 1000;
  std::cin >> T;
  for (int t = 1, n; t <= T; ++t) {
    std::cin >> n;
    std::vector<int> vt(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> vt[i];
    }
    
    std::cout << "Case #" << t << ": " << (monotonical(vt) ? "BAD" : (rand() % 2 ? "GOOD": "BAD")) << std::endl;
  }

  /*
  srand(time(NULL));
  int n = 4;
  int count[100] = {0};
  for (int c = 0; c < 24; ++c) {
    std::vector<int> vt;
    for (int i = 0; i < n; ++i) {
      vt.push_back(i);
    }
    vt = permutate(vt);
    for (auto v : vt) {
      std::cout << v << " ";
    }
    std::cout << std::endl;
    ++ count[code(vt)];
  }
  for (int i = 0; i < 24; ++i) {
    std::cout << i << " " << count[i] << std::endl;
    }*/
  return 0;
}
