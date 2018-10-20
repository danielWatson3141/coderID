#include <algorithm>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <set>

int TreeSize(int v, std::unordered_map<int, std::set<int>> edje) {
  int res = 1;
  for (auto it = edje[v].begin(); it != edje[v].end(); ++it) {
    edje[*it].erase(v);
    res += TreeSize(*it, edje);
    edje[*it].insert(v);
  }

  return res;
}

int ChooseRoot(int v, std::vector<int> count, std::unordered_map<int, std::set<int>> edje) {
  if (count[v] == 0) return 0;
  if (count[v] == 1) {
    auto it = edje[v].begin();
    count[*it]--;
    edje[*it].erase(v);
    return TreeSize(*it, edje);
  }
  if (count[v] == 2) {
    auto it = edje[v].begin();
    count[*it]--;
    edje[*it].erase(v);
    auto it2 = it;
    it2++;
    count[*it2]--;
    edje[*it2].erase(v);
    return ChooseRoot(*it, count, edje) + ChooseRoot(*it2, count, edje);
  }
//  else {
//    int res = 1001;
//    for (auto it = edje[v].begin(); it != edje[v].end(); ++it) {
//      auto edje2 = edje;
//      count[v]--;
//      count[*it]--;
//      edje2[*it].erase(v);
//      edje2[v].erase(*it);
//      res = std::min(res, TreeSize(*it, edje2)) + ChooseRoot(v, count, edje2);
//      count[v]++;
//      count[*it]++;
//    }
//    return res;
//  }
  return 1001;
}

int main() {
  int T;
  std::cin >> T;

  for (int i = 1; i <= T; ++i) {
    std::cout << "Case #" << i << ": ";

    int N;
    std::cin >> N;

    std::vector<int> v_count(1000, 0);
    std::unordered_map<int, std::set<int>> edje;
    for (int j = 0; j < N-1; ++j) {
      int x, y;
      std::cin >> x >> y;
      x--; y--;

      v_count[x]++;
      v_count[y]++;

      edje[x].insert(y);
      edje[y].insert(x);
    }

    int res = 1001;
    for (int j = 0; j < N; ++j) {
      res = std::min(res, ChooseRoot(j, v_count, edje));
    }

    std::cout << res;

    std::cout << std::endl;
  }
}

