#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sus[1010];
int sts[1010];

int subtree_size(int root, int parent) {
  int res = 1;
  for (int i = 0; i < sus[root].size(); ++i) {
    int next = sus[root][i];
    if (next == parent) continue;
    res += subtree_size(next, root);
  }
  //cout << "subtree_size(" << root << ", " << parent << ") = " << res << endl;
  sts[root] = res;
  return res;
}

struct option {
  int root;
  int mmd;
};

bool operator<(option a, option b) {
  if (a.mmd < b.mmd) return true;
  if (a.mmd > b.mmd) return false;
  return sts[a.root] < sts[b.root];
}

int min_must_del(int root, int parent) {
  int cnt = sus[root].size();
  if (parent != -1) --cnt;

  if (cnt == 0) return 0;
  if (cnt == 1) return sts[root] - 1;

  vector<option> options;

  for (int i = 0; i < sus[root].size(); ++i) {
    if (sus[root][i] == parent) continue;
    option opt;
    opt.root = sus[root][i];
    opt.mmd = min_must_del(opt.root, root);
    options.push_back(opt);
  }

  int all_sts = 0;
  for (int i = 0; i < options.size(); ++i) {
    all_sts += sts[options[i].root];
  }

  int best = 1234567890;

  for (int a = 0; a < options.size()-1; ++a) {
    for (int b = a+1; b < options.size(); ++b) {
      int cur = all_sts;
      cur -= sts[options[a].root];
      cur -= sts[options[b].root];
      cur += options[a].mmd;
      cur += options[b].mmd;
      if (cur < best) best = cur;
    }
  }

  //cout << "mmd(" << root << "," << parent << ") = " << best << endl;

  return best;
}

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) sus[i].clear();

    for (int i = 0; i < n-1; ++i) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      sus[a].push_back(b);
      sus[b].push_back(a);
    }

    int best = 1234567890;
    for (int root = 0; root < n; ++root) {
      //cout << "trying root " << root << endl;
      subtree_size(root, -1);
      int mmd = min_must_del(root, -1);
      if (mmd < best) best = mmd;
    }

    cout << "Case #" << tt << ": " << best << endl;
  }
}
