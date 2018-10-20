#include <stdio.h>
#include <list>
#include <map>

#define MIN(X,Y) ((X)>(Y)?(Y):(X))
#define MAX(X,Y) ((X)<(Y)?(Y):(X))

using namespace std;

struct Node
{
  int me;
  list<int> neigh;
  map<int, int> children;
  map<int, int> size;

  int getSubtreeSize(int excl = 0);
  int getChildren(int excl = 0);
};

int num;
Node nodes[1024];

void input()
{
  for (int i = 0; i < 1024; i++) {
    nodes[i].neigh.clear();
    nodes[i].size.clear();
    nodes[i].children.clear();
  }

  scanf("%d", &num);
  int a, b;
  for (int i = 1; i < num; i++) {
    scanf("%d%d", &a, &b);
    nodes[a].neigh.push_back(b);
    nodes[b].neigh.push_back(a);
  }
}

int
Node::getSubtreeSize(int excl)
{
  if (size.find(excl) != size.end()) {
    return size[excl];
  }

  if (neigh.size() == 1) {
    return 1;
  }

  if (neigh.size() == 2 && excl) {
    return 1;
    //return getChildren(excl);
  }

  int max1 = -1, max2 = -1;
  for (auto it = neigh.begin(); it != neigh.end(); it++) {
    if (*it == excl) {
      continue;
    }

    int res = nodes[*it].getSubtreeSize(me);
    if (res > max1 || res > max2) {
      max2 = MAX(max1, max2);
      max1 = res;
    }
  }

  //printf("%d - %d = %d\n", me, excl, max1 + max2 + 1);

  return (size[excl] = max1 + max2 + 1);
}

int
Node::getChildren(int excl)
{
  if (children.find(excl) != children.end()) {
    return children[excl];
  }

  int count = 0;

  for (auto it = neigh.begin(); it != neigh.end(); it++) {
    if (*it == excl) {
      continue;
    }

    count += nodes[*it].getChildren(me);
  }

  return (children[excl] = count);
}

void solve()
{
  input();

  int best = -1;
  for (int i = 1; i <= num; i++) {
    int res = nodes[i].getSubtreeSize();
    best = MAX(res, best);
  }

  //printf("most nodes: %d; deleted: %d\n", best, num - best);
  printf("%d\n", num - best);
}

int main()
{
  for (int i = 0; i < 1024; i++) {
    nodes[i].me = i;
  }

  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++) {
    printf("Case #%d: ", i);
    solve();
  }

  return 0;
}
