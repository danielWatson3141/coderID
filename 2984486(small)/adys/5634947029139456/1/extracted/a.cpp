#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N; int L;

int solve(vector<string> &flows, vector<string> &desired)
{
  int match = 0;
  int best = 1000;
  while (match < N) {
    vector<string> fs = flows; vector<string> des = desired;
    vector<int> switches;
    for (int i = 0; i < L; ++i)
      if (desired[0][i] != flows[match][i])
        switches.push_back(i);
    for (int i = 0; i < N; ++i)
      for (int s : switches)
        if (fs[i][s] == '1') fs[i][s] = '0';
        else fs[i][s] = '1';

    fs.erase(fs.begin()+match);
    des.erase(des.begin());

    sort(fs.begin(),fs.end());
    sort(des.begin(),des.end());

    if (fs == des) best = min(best,(int)switches.size());
    match++;
  }
  if (best == 1000) return -1;
  return best;
}

int main()
{
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> N >> L;
    vector<string> flows; vector<string> desired; 
    for (int i = 0; i < N; ++i) {
      string flow; cin >> flow;
      flows.push_back(flow);
    }
    for (int i = 0; i < N; ++i) {
      string des; cin >> des;
      desired.push_back(des);
    }
    int res = solve(flows, desired);
    if (res == -1)
      cout << "Case #" << t << ": " << "NOT POSSIBLE" << endl;
    else
      cout << "Case #" << t << ": " << res << endl;
  }
  return 0;
}
