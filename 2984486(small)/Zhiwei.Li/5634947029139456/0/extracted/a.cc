#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Data {
 public:
  Data() { }
  Data(const string &s) {
    m_ = (s.size() + 31) / 32;
    memset(a_, 0, sizeof(a_));
    for (int i = 0; i < (int)s.size(); ++i) {
      int p = s[i] - '0';
      a_[i / 32] |= (p << (i & 31));
    }
  }
  int Count() const {
    int c = 0;
    for (int i = 0; i < m_; ++i) {
      int v = a_[i];
      while (v) {
        ++c;
        v ^= (v&(-v));
      }
    }
    return c;
  }
  Data operator ^(const Data &o) const {
    Data d = *this;
    for (int i = 0; i < m_; ++i) {
      d.a_[i] = (a_[i] ^ o.a_[i]);
    }
    return d;
  }
  bool operator <(const Data &o) const {
    for (int i = 0; i < m_; ++i) {
      if (a_[i] != o.a_[i]) return a_[i] < o.a_[i];
    }
    return false;
  }

  int a_[10];
  int m_;
};

bool cmp(const Data &a, const Data &b) { return a.Count() < b.Count(); }

Data st[150], en[150];
int main() {
  int tc;
  cin >> tc;
  int n, m;
  for (int cas = 1; cas <= tc; ++cas) {
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      st[i] = Data(s);
    }
    set<Data> g;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      en[i] = Data(s);
      g.insert(en[i]);
    }
    vector<Data> fs;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        fs.push_back(st[i] ^ en [j]);
      }
    sort(fs.begin(), fs.end(), cmp);
    int ans = -1;
    for (int i = 0; i < (int)fs.size() && ans < 0; ++i) {
      int j = 0;
      for (; j < n; ++j) {
        if (g.find(st[j] ^ fs[i]) == g.end()) break;
      }
      if (j == n) {
        ans = fs[i].Count();
      }
    }
    cout << "Case #" << cas << ": ";
    if (ans < 0) {
      cout << "NOT POSSIBLE" << endl;
    } else {
      cout << ans << endl;
    }
  }
}
