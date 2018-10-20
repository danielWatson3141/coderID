#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

std::string diff(std::string &a, std::string &b) {
  std::string ans = "";
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) {
      ans += "1";
    } else {
      ans += "0";
    }
  }
  return ans;
}

// unique
int check(int n, const std::string &key, const std::vector<std::pair<int, int>> &pairs) {
  if (pairs.size() != n) {
    return -1;
  }
  
  return std::count(key.begin(), key.end(), '1');
}

int main() {
  int T;
  std::cin >> T;
  for (int t = 1, N, L; t <= T; ++t) {
    std::cout << "Case #" << t << ": ";
    std::cin >> N >> L;
    std::vector<std::string> outlet(N), device(N);
    for (int i = 0; i < N; ++i) {
      std::cin >> outlet[i];
    }
    for (int i = 0; i < N; ++i) {
      std::cin >> device[i];
    }
    std::unordered_map<std::string, std::vector<std::pair<int, int>>> all;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
	all[diff(outlet[i], device[j])].push_back(std::make_pair(i, j));
      }
    }
    int ans = -1;
    for (auto &e : all) {
      auto &key = e.first;
      auto &list = e.second;
      int c = check(N, key, list);
      if (c != -1 && (ans == -1 || ans > c)) {
	ans = c;
      }
    }
    std::cout << (ans == -1 ? "NOT POSSIBLE" : std::to_string(ans)) << std::endl;
  }
  return 0;
}
