#include <stdio.h>
#include <vector>
#define INF 1000000

using namespace std;

vector<int> to[1010];
int del[1010], bin[1010];
int N;
int bestAns;

void DFS(int cur, int from){
  //printf("DFS %d %d\n", cur, from);
  int sumdel = 0;
  int sumbin = 0;
  int ct = 0;
  int delbin1=-1, delbin2=-1;
  
  for(vector<int>::iterator i = to[cur].begin(); i != to[cur].end(); i++){
    int next = *i;
    if(next == from) continue;
    DFS(next, cur);
    
    ct++;
    sumdel += del[next];
    sumbin += bin[next];
    
    int delbin = del[next] - bin[next];
    if(delbin > delbin1){
      delbin2 = delbin1;
      delbin1 = delbin;
    }
    else if(delbin > delbin2) delbin2 = delbin;
  }
  
  del[cur] = sumdel+1;
  if(ct == 0) bin[cur] = 0;
  else if(ct == 1) bin[cur] = sumdel;
  else bin[cur] = sumdel - delbin1 - delbin2;
  //printf("%d del=%d bin=%d\n", cur, del[cur], bin[cur]);
}

void Root(int r){
  //printf("root %d\n", r);
  DFS(r, -1);
  if(bin[r] < bestAns) bestAns = bin[r];
}

int main(){
  int jcase;
  int a, b;
  
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B-small-attempt0.out", "w", stdout);
  
  scanf("%d", &jcase);
  for(int icase=0; icase<jcase; icase++){
    scanf("%d", &N);
    for(int i=0; i<N; i++) to[i].clear();
    
    for(int i=1; i<N; i++){
      scanf("%d %d", &a, &b);
      a--; b--;
      to[a].push_back(b);
      to[b].push_back(a);
    }
    
    bestAns = INF;
    for(int i=0; i<N; i++){
      Root(i);
    }
    
    printf("Case #%d: %d\n", icase+1, bestAns);
  }
  
  return 0;
}
