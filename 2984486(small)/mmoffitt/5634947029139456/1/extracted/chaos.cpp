#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int diff(string& a, string& b, string& d) {
  int cost = 0;
  for (int i = 0;i < a.length();i++) {
    if (a[i] != b[i]) {
      d += '1';
      cost++;
    }
    else d += '0';
  }
  return cost;
}

int cost(const string& s) {
  int cost = 0;
  for (int i = 0;i < s.length();i++) if (s[i] == '1') cost++;
  return cost;
}

int solve(int N, int L, std::vector<string>& init, std::vector<string>& flow) {
  map<string,int> themap;
  for (int i = 0;i < N;i++) {
    for (int j = 0;j < N;j++) {
      string d;
      diff(init[i], flow[j], d);
      themap[d]++;
    }
  }
  int min_cost = INT_MAX;
  for (map<string,int>::iterator i = themap.begin();i != themap.end();i++) {
    if (i->second != N) continue;
    int c = cost(i->first);
    if (min_cost > c) min_cost = c;
  }
  return min_cost;
}

int main(int argc, char* argv[]) {
  int T;
  std::cin >> T;
  std::string s;
  for (int t = 0;t < T;t++) {
    int N, L;
    std::cin >> N >> L;
    std::vector<string> init, flow;
    for (int i = 0;i < N;i++) { std::cin >> s; init.push_back(s); }
    for (int i = 0;i < N;i++) { std::cin >> s; flow.push_back(s); }
    int cost = solve(N, L, init, flow);
    std::cout << "Case #" << (t+1) << ": ";
    if (cost == INT_MAX) std::cout << "NOT POSSIBLE";
    else std::cout << cost;
    std::cout << endl;
  }
  return 0;
}

