/*************************************************************************
    > File Name: c.cpp
    > Author: implus
    > Mail: 674592809@qq.com
    > Created Time: 六  4/26 10:55:20 2014
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define ls (rt<<1)
#define rs (rt<<1|1)
#define lson l,m,ls
#define rson m+1,r,rs

vector<int> gao1(int n){
  srand(time(NULL));
  vector<int> a(n);
  for(int i = 0; i < n; i++) a[i] = i;
  for(int i = 0; i < n; i++){
    int p;
    if(i < n - 1) p = rand() % (n - i - 1) + i;
    else p = i;

    swap(a[i], a[p]);
  }
  return a;
}

vector<int> gao2(int n){
  srand(time(NULL));
  vector<int> a(n);
  for(int i = 0; i < n; i++) a[i] = i;
  for(int i = 0; i < n; i++){
    int p = rand() % n;
    swap(a[i], a[p]);
  }
  return a;
}

const int maxn = 1111;
int tree[maxn];

void add(int p, int v){
  for(int i = p + 1; i < maxn; i += i & -i){
    tree[i] += v;
  }
}

int get(int p){
  int ans = 0;
  for(int i = p + 1; i; i -= i & -i){
    ans += tree[i];
  }
  return ans;
}

int gao(vector<int> a){
  int ans = 0;
  memset(tree, 0, sizeof(tree));
  for(int i = 0; i < a.size(); i++){
    ans += a.size() - i - 1 - get(a[i]);
    add(a[i], 1);
  }
  return ans;
}

int dis(vector<int> a, vector<int> b){
  int ans = 0;
  ans = abs(gao(a) - gao(b));
  return ans;
}

int main(){
  int T, n, icase = 1;
  scanf("%d", &T);
  srand(time(NULL));
  while(T--){
    scanf("%d", &n);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
      scanf("%d", &a[i]);
    }
    int time = 1000, g = 0, b = 0;
    while(time--){
      vector<int> v1 = gao1(n);
      vector<int> v2 = gao2(n);
      if(dis(v1, a) < dis(v2, a)) g++;
      else b++;
    }
    printf("Case #%d: %s\n", icase++, (g < b) ? "GOOD": "BAD");
  }
  return 0;
}
