#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <cassert>

#define REP(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long LL;


int nextInt() {
  char c;
  int res = 0;
  while (!isdigit(c = getchar())){};
  do {
    res = res * 10 + c - '0';
  } while (isdigit(c = getchar()));
  return res;
}
int N;
int graph[1111][1111];
int count_c[1111][1111];
int dfs_c[1111][1111];

int count(int pos, int pre) {
  vector<int> next;
  int& res = count_c[pos][pre];
  if (res != -1) return res;
  for (int i = 1; i <= N; i++) {
    if (i == pre) continue;
    if (graph[pos][i]) next.push_back(i);
  }
  res = 0;
  REP(i, next.size()) {
    res += count(next[i], pos);
  }
  res++;
  return res;
}

int dfs(int pos, int pre) {
  vector<int> next;
  int& res = dfs_c[pos][pre];
  if (res != -1) return res;
  for (int i = 1; i <= N; i++) {
    if (i == pre) continue;
    if (graph[pos][i]) next.push_back(i);
  }

  if (next.size() == 0) {
    return res = 0;
  } else if (next.size() == 1) {
    return res = count(next[0], pos);
  } else {
    int res = 1 << 20;
    REP(i, next.size()) {
      REP(j, i) {
        int tmp = 0;
        REP(k, next.size()) {
          if (k == j || k == i) {
            tmp += dfs(next[k], pos);
          } else {
            tmp += count(next[k], pos);
          }
        }
        res = min(res, tmp);
      }
    }
    return res;
  }

}


void solve(int caseCnt) {
  cin >> N;
  memset(graph, false, sizeof(graph));
  memset(count_c, -1,sizeof(count_c));
  memset(dfs_c, -1,sizeof(dfs_c));
  REP(i, N - 1) {
    int a, b;
    cin >> a >> b;
    graph[a][b] = graph[b][a] = true;
  }
  int res = 1 << 20;
  REP(i, N) {
    int tmp = dfs(i+1, 0);
    res = min(res, tmp);
  }
  printf("Case #%d: %d\n", caseCnt, res);
}


int main(){
	int TestCase = nextInt();

	for(int caseCnt=1; caseCnt <= TestCase; caseCnt++){
		//solve_small(caseCnt);
		solve(caseCnt);
	}
	return 0;
}
