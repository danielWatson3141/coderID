#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>

using namespace std;

const int MAX_N = 1000;

int N; // number of nodes
vector<int> edges[MAX_N + 1];

void read()
{
  scanf("%d", &N);
  for ( int i=1; i<=N; ++i ) {
    edges[i].clear();
  }

  for ( int i=1; i<N; ++i ) {
    int x, y;
    scanf("%d %d", &x, &y);
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
}

int deg(int x)
{
  return edges[x].size();
}

int subtreeSize(int x, int parent)
{
  int size = 1;
  for ( int i=0; i<edges[x].size(); ++i ) {
    int y = edges[x][i];
    if ( y != parent ) {
      size += subtreeSize(y, x);
    }
  }
  return size;
}

int cost(int x, int parent)
{
  int children_count = 0;
  for ( int i=0; i<edges[x].size(); ++i ) {
    int y = edges[x][i];
    if ( y != parent ) {
      ++children_count;
    }
  }
  //printf("  cost(x=%d): children_count=%d\n", x, children_count);

  if ( children_count==0 ) {
    //printf("  cost(x=%d): cost=0\n", x);
    return 0;
  }
  else if ( children_count==1 ) {
    int child_cost = 0;
    for ( int i=0; i<edges[x].size(); ++i ) {
      int y = edges[x][i];
      if ( y != parent ) {
        child_cost += subtreeSize(y, x);
      }
    }
    //printf("  cost(x=%d): child_cost=%d\n", x, child_cost);
    return child_cost;
  }
  else if ( children_count==2 ) {
    int total_cost = 0;
    for ( int i=0; i<edges[x].size(); ++i ) {
      int y = edges[x][i];
      if ( y != parent ) {
        total_cost += cost(y,x);
      }
    }
    //printf("  cost(x=%d): total_cost=%d\n", x, total_cost);
    return total_cost;
  }
  else {
    vector<int> children;
    vector<int> children_cost;
    vector<int> children_size;
    int children_size_sum = 0;
    for ( int i=0; i<edges[x].size(); ++i ) {
      int y = edges[x][i];
      if ( y != parent ) {
        children     .push_back(y);
        children_cost.push_back(cost(y,x));
        children_size.push_back(subtreeSize(y, x));
        children_size_sum += children_size[children_size.size()-1];
      }
    }

    int min_total_cost = INT_MAX;
    int min_y1;
    int min_y2;
    for ( int i1=0; i1!=children.size(); ++i1 ) {
      for ( int i2=i1+1; i2!=children.size(); ++i2 ) {
        int y1 = children[i1];
        int y2 = children[i2];
        int c1 = children_cost[i1];
        int c2 = children_cost[i2];
        int s1 = children_size[i1];
        int s2 = children_size[i2];
        int total_cost = c1 + c2 + (children_size_sum - s1 - s2);
        //printf("    cost(x=%d): y1=%d, y2=%d, c1=%d, c2=%d, s1=%d, s2=%d\n", x, y1, y2, c1, c2, s1, s2);
        if ( total_cost < min_total_cost ) {
          min_y1 = y1;
          min_y2 = y2;
          min_total_cost = total_cost;
        }
      }
    }

    //printf("  cost(x=%d): min_y1=%d, min_y2=%d, min_total_cost=%d\n", x, min_y1, min_y2, min_total_cost);
    return min_total_cost;
  }
}

int minCost()
{
  if ( N==2 ) return 1;
  if ( N==3 ) return 0;

  int min_cost = INT_MAX;
  for ( int root=1; root<=N; ++root ) {
    //printf("root=%d\n", root);
    int root_cost = cost(root, -1);
    //printf("cost(%d) = %d\n\n", root, root_cost);
    if ( root_cost < min_cost ) {
      min_cost = root_cost;
    }
  }
  return min_cost;
}

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    read();
    printf("Case #%d: %d\n", t, minCost());
  }
}
