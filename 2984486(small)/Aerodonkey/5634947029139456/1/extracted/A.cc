#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int n;
int l;
std::vector<uint64_t> s;
std::vector<uint64_t> t;
std::vector<int> ones;
std::vector<std::unordered_map<uint64_t, int>> freq;
int y;

uint64_t binary(const std::string& s) {
  uint64_t i = 0;
  for (char c : s) {
    i <<= 1;
    if (c == '1') {
      i |= 1;
    }
  }
  return i;
}

void count(const std::vector<uint64_t> a, int w, std::unordered_map<uint64_t, int>& f) {
  uint64_t mask = (static_cast<uint64_t>(1) << w) - 1;
  for (int i = 0; i < n; i++) {
    f[a[i] & mask]++;
  }
}

void precompute() {
  for (int i = 0; i < l; i++) {
    count(t, i + 1, freq[i]);
  }
}

bool match(const std::unordered_map<uint64_t, int>& a, const std::unordered_map<uint64_t, int>& b) {
  for (const auto& p : a) {
    auto qi = b.find(p.first);
    if (qi == b.end()) {
      return false;
    }
    if (qi->second != p.second) {
      return false;
    }
  }
  return true;
}

void search(int depth, int switched) {
  if (y >= 0 && switched >= y) {
    return;
  }
  if (depth == l) {
    if (y == -1 || switched < y) {
      y = switched;
    }
    return;
  }
  uint64_t bit = static_cast<uint64_t>(1) << depth;
  for (int p = 0; p < 2; p++) {
    if (p) {
      for (int i = 0; i < n; i++) {
        s[i] ^= bit;
      }
    }
    std::unordered_map<uint64_t, int> f;
    count(s, depth + 1, f);
    if (match(f, freq[depth])) {
      search(depth + 1, switched + p);
    }
    if (p) {
      for (int i = 0; i < n; i++) {
        s[i] ^= bit;
      }
    }
  }
}

int main() {
  int c;
  std::cin >> c;
  for (int x = 1; x <= c; x++) {
    s.clear();
    t.clear();
    ones.clear();
    freq.clear();
    std::cin >> n >> l;
    s.resize(n);
    t.resize(n);
    ones.resize(l);
    freq.resize(l);
    for (int i = 0; i < n; i++) {
      std::string a;
      std::cin >> a;
      s[i] = binary(a);
    }
    for (int i = 0; i < n; i++) {
      std::string a;
      std::cin >> a;
      t[i] = binary(a);
    }
    precompute();
    y = -1;
    search(0, 0);
    if (y >= 0) {
      std::cout << "Case #" << x << ": " << y << std::endl;
    } else {
      std::cout << "Case #" << x << ": " << "NOT POSSIBLE" << std::endl;
    }
  }
}
