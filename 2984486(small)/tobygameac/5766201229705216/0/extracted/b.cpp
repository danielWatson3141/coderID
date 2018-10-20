#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int N;
int ans;
set<int> con[1001];
bool del[1001];

bool check(int delNum) {
  for (int i = 1; i <= N; i++) {
    if (!del[i]) {
      bool full = true;
      int count = 0;
      queue<int> q;
      bool visited[1001] = {};
      q.push(i);
      visited[i] = true;
      while (!q.empty()) {
        int now = q.front();
        count++;
        q.pop();
        vector<int> next;
        for (set<int>::iterator it = con[now].begin(); it != con[now].end(); it++) {
          if (!visited[*it]) {
            next.push_back(*it);
          }
        }
        if (!next.size()) {
          continue;
        }
        if (next.size() == 2) {
          int l = next[0], r = next[1];
          q.push(l);
          q.push(r);
          visited[l] = visited[r] = true;
        } else {
          full = false;
          break;
        }
      }
      if (full) {
        full = count == (N - delNum);
      }
      if (full) {
        return true;
      }
    }
  }
  return false;
}

void solve(int now, int delNum) {
  if (delNum >= ans) {
    return;
  }
  if (check(delNum)) {
    ans = min(ans, delNum);
    return;
  }
  if (now > N) {
    return;
  }
  solve(now + 1, delNum);
  vector<int> restore;
  for (set<int>::iterator it = con[now].begin(); it != con[now].end(); it++) {
    int j = *it;
    restore.push_back(j);
  }
  for (int i = 0; i < restore.size(); i++) {
    int j = restore[i];
    con[now].erase(con[now].find(j));
    con[j].erase(con[j].find(now));
  }
  del[now] = true;
  solve(now + 1, delNum + 1);
  del[now] = false;
  for (int i = 0; i < restore.size(); i++) {
    int j = restore[i];
    con[now].insert(j);
    con[j].insert(now);
  }
}

int main() {
  int T, C = 1;
  scanf("%d", &T);
  while (T--) {
    printf("Case #%d: ", C++);
    scanf("%d", &N);
    for (int i = 0; i <= N; i++) {
      con[i].clear();
    }
    for (int i = 0; i < N - 1; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      con[x].insert(y);
      con[y].insert(x);
    }
    ans = 2e9;
    memset(del, 0, sizeof(del));
    solve(1, 0);
    printf("%d\n", ans);
  }
  return 0;
}
