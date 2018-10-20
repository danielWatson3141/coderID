#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

const int MAX = 1500;

int flood(vector<int> adjacent[MAX], int parent[MAX], int num_children[MAX], int subtree_size[MAX], int i, int N)
{
  num_children[i] = 0;
  subtree_size[i] = 1;
  for (size_t j = 0; j < adjacent[i].size(); j++) {
    if (adjacent[i][j] != parent[i]) {
      parent[adjacent[i][j]] = i;
      num_children[i]++;
      subtree_size[i] += flood(adjacent, parent, num_children, subtree_size, adjacent[i][j], N);
    }
  }
  return subtree_size[i];
}

int solve(vector<int> adjacent[MAX], int parent[MAX], int num_children[MAX], int subtree_size[MAX], int i, int N)
{
  if (num_children[i] == 0) {
    return 0;
  }
  if (num_children[i] == 1) {
    for (size_t j = 0; j < adjacent[i].size(); j++) {
      if (adjacent[i][j] != parent[i]) {
        return subtree_size[adjacent[i][j]];
      }
    }
    assert(false);
    return -99999999;
  }
  if (num_children[i] == 2) {
    int ans = 0;
    for (size_t j = 0; j < adjacent[i].size(); j++) {
      if (adjacent[i][j] != parent[i]) {
        ans += solve(adjacent, parent, num_children, subtree_size, adjacent[i][j], N);
      }
    }
    return ans;
  }
  // num_children > 2
  int remove_all[MAX];
  int remove_some[MAX];
  int index = 0;
  for (size_t j = 0; j < adjacent[i].size(); j++) {
    if (adjacent[i][j] != parent[i]) {
      remove_all[index] = subtree_size[adjacent[i][j]];
      remove_some[index] = solve(adjacent, parent, num_children, subtree_size, adjacent[i][j], N);
      index++;
    }
  }

  int sum = 0;
  for (int j = 0; j < num_children[i]; j++) {
    sum += remove_all[j];
  }
  //cout << "sum: " << sum << "\n";

  int best = MAX;
  for (int j = 0; j < num_children[i]; j++) {
    for (int k = j + 1; k < num_children[i]; k++) {
      best = min(best, sum - remove_all[j] - remove_all[k] + remove_some[j] + remove_some[k]);
    }
  }
  return best;
}

int main()
{
  int T;
  cin >> T;
  for (int counter = 1; counter <= T; counter++) {
    int N;
    cin >> N;
    vector<int> adjacent[MAX];
    for (int i = 0; i < N - 1; i++) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      adjacent[x].push_back(y);
      adjacent[y].push_back(x);
    }

    int parent[MAX];
    int num_children[MAX];
    int subtree_size[MAX];
    int ans = MAX;
    for (int i = 0; i < N; i++) {
      // i is the guess for the root
      for (int j = 0; j < N; j++) {
        parent[j] = -1;
      }
      flood(adjacent, parent, num_children, subtree_size, i, N);
      //cout << i << "\n";
      //for (int j = 0; j < N; j++) {
      //  cout << "parent[" << j << "] = " << parent[j] << "\n";
      //}
      //cout << "solve: " << solve(adjacent, parent, num_children, subtree_size, i, N) << "\n";
      ans = min(ans, solve(adjacent, parent, num_children, subtree_size, i, N));
    }
    cout << "Case #" << counter << ": " << ans << "\n";
  }
  return 0;
}

