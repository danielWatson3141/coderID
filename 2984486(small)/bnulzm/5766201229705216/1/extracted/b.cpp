#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> edge[1010];
int visited[1010];


int findallchild(int v,int parent) {
    int size = edge[v].size();
    int ans = 0;
    for (int i = 0; i < size; ++i) {
        int d = edge[v][i];
        if (d != parent) {
           ans += findallchild(d,v)+1;
        }
    }
    return ans;
}


int dfs(int v,int parent,int isroot=0) {
    int size = edge[v].size();
    
    if (isroot && size < 2 || !isroot && size < 3) {
       return 1;
    }
    
    int a[2] = {0,0};
    for (int i = 0; i < size; ++i) {
        int d = edge[v][i];
        if (d != parent) {
           int num = dfs(d,v);
           if ( num > a[0] ) {
              a[1] = a[0];
              a[0] = num;
           }
           else if (num > a[1]) {
                a[1] = num;
           }
        }
    }
    return a[0]+a[1]+1;
}

int main() {
    int kase = 0;
    int h = 1;
    freopen("B-large.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d", &kase);
    while (kase--) {
          int n;
          scanf("%d", &n);
          for (int i = 0; i < n-1; ++i) {
              int s, e;
              scanf("%d %d", &s, &e);
              s--;
              e--;
              edge[s].push_back(e);
              edge[e].push_back(s);
          }
          
          int ans = -1;
          for (int i = 0; i < n; ++i) {
              int num = n-dfs(i,-1,1);
              if (ans == -1 || ans > num) {
                 ans = num;
              }
          }
          
          printf("Case #%d:",h++);
          printf(" %d\n",ans);
          
          for (int i = 0; i < n; ++i) {
              edge[i].clear();
          }
    }
    return 0;    
}
