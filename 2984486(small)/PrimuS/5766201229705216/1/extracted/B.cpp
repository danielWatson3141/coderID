#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> edges[1010];
vector<int> processed_edges[1010];
bool visited[1010];

struct dfs_result
{
  int mandatory_remove;
  int tree_size;

  dfs_result()
    : mandatory_remove(0)
    , tree_size(1)
  {}
};

dfs_result dfs(int v, int parent)
{
  dfs_result res;
  res.tree_size = 1;
  vector<dfs_result> child_res;

  for (int i = 0; i < edges[v].size(); ++i)
  {
    if (edges[v][i] == parent)
      continue;

    child_res.push_back(dfs(edges[v][i], v));
  }

  if (child_res.size() == 0)
    return res;

  for (int i = 0; i < child_res.size(); ++i)
    res.tree_size += child_res[i].tree_size;

  if (child_res.size() == 1)
  {
    res.mandatory_remove = child_res[0].tree_size;
  }
  else
  {
    sort(child_res.begin(), child_res.end(), [](const dfs_result & a, const dfs_result & b) -> bool
    {
      return (a.tree_size - a.mandatory_remove) > (b.tree_size - b.mandatory_remove);
    });

    res.mandatory_remove += child_res[0].mandatory_remove + child_res[1].mandatory_remove;
    for (int i = 2;i < child_res.size(); ++i)
      res.mandatory_remove += child_res[i].tree_size;
  }

  return res;
}

int main()
{
  freopen("B-large.in", "r", stdin);
  freopen("b-result-large.txt", "w", stdout);
  int T;
  scanf("%d", &T);

  for (int i = 0; i < T; ++i)
  {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
      edges[i].clear();
      processed_edges[i].clear();
    }
    for (int i = 0; i < N-1; ++i)
    {
      int a, b;
      scanf("%d%d", &a, &b);
      edges[a-1].push_back(b-1);
      edges[b-1].push_back(a-1);
    }

    int best_res = N-1;

    for (int i = 0; i < N; ++i)
    {
      dfs_result res = dfs(i, i);
      if (res.mandatory_remove < best_res)
        best_res = res.mandatory_remove;
    }

    //for (int m = 0; m < (1 << N); ++m)
    //{
    //  for (int i = 0; i < N; ++i)
    //  {
    //    processed_edges[i].clear();
    //    if (m & (1 << i))
    //      continue;
    //    for (int j = 0; j < edges[i].size(); ++j)
    //    {
    //      if (m & (1 <<  edges[i][j]))
    //        continue;
    //      processed_edges[i].push_back(edges[i][j]);
    //    }
    //  }

    //  bool is_ok = false;

    //  for (int i = 0; i < N && !is_ok; ++i)
    //  {
    //    if (m & (1 << i))
    //      continue;

    //    memset(visited, 0, sizeof(visited));

    //    bool is_fully_binary = true;
    //    queue<int> q;
    //    q.push(i);
    //    visited[i] = true;

    //    while (!q.empty() && is_fully_binary)
    //    {
    //      int x = q.front();
    //      q.pop();
    //      visited[x] = true;

    //      int childs_count = 0;
    //      for (int j = 0; j < processed_edges[x].size(); ++j)
    //      {
    //        if (!visited[processed_edges[x][j]])
    //        {
    //          q.push(processed_edges[x][j]);
    //          childs_count++;
    //        }
    //      }

    //      if (childs_count != 0 && childs_count != 2)
    //        is_fully_binary = false;
    //    }

    //    if (is_fully_binary)
    //    {
    //      for (int j = 0; j < N; ++j)
    //      {
    //        if (m & (1 << j))
    //          continue;

    //        if (!visited[j])
    //          is_fully_binary = false;
    //      }
    //    }

    //    if (is_fully_binary)
    //      is_ok = true;
    //  }

    //  if (is_ok)
    //  {
    //    int res = 0;
    //    for (int i = 0; i < N; ++i)
    //    {
    //      if (m & (1<<i))
    //        res++;
    //    }

    //    if (res < best_res)
    //      best_res = res;
    //  }

    //}

    printf("Case #%d: %d", i + 1, best_res);

    printf("\n");
  }

  fclose(stdin);
  fclose(stdout);

  return 0;
}