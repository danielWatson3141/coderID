#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

vector < vector<int> > tree;

int dfs(int x, int y)
{
  if (tree[x].size() <= 2)
    return 1;
  vector<int> num_descendents;
  for (int i=0; i<tree[x].size(); i++)
    if (tree[x][i] != y)
      num_descendents.push_back(dfs(tree[x][i], x));
  sort(num_descendents.begin(), num_descendents.end());
  return 1 + num_descendents[num_descendents.size()-1]
           + num_descendents[num_descendents.size()-2];
}

int main()
{
  int Nprob;
  cin >> Nprob;
  string s;
  for (int np=0; np<Nprob; np++)
  {
    cout << "Case #" << np+1 <<": ";
    int N;
    cin >> N;
    tree.resize(N);
    for (int i=0; i<N; i++)
      tree[i].clear();
    int x;
    int y;
    for (int i=0; i<N-1; i++)
    {
      cin >> x;
      cin >> y;
      tree[x-1].push_back(y-1);
      tree[y-1].push_back(x-1);
    }
    int best = N-1;
    for (int i=0; i<N; i++)
    {
      if (tree[i].size() == 2)
      {
        int num0 = dfs(tree[i][0], i);
        int num1 = dfs(tree[i][1], i);
        if (N-(1+num0+num1) < best)
          best = N-(1+num0+num1);
      }
      else if (tree[i].size() > 2)
      {
        vector<int> nums;
        for (int j=0; j<tree[i].size(); j++)
          nums.push_back(dfs(tree[i][j], i));
        sort(nums.begin(), nums.end());
        int result = N-(1+nums[nums.size()-1]+nums[nums.size()-2]);
        if (result < best)
          best = result;
      }
    }
    cout << best << "\n";
  }
  return 0;
}
