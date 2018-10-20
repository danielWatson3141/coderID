#include <bits/stdc++.h>
using namespace std;

int t, n, l, ans;
char out[200][50], in[200][50], aux[50];
bool fl[50], poss;

bool match(){
  for(int i = 0; i < l; i ++)
    if(fl[i])
      for(int j = 0; j < n; j ++)
        out[j][i] = (out[j][i] == '0') ? '1' : '0';

  for(int i = 0; i < n; i ++)
    for(int j = i + 1; j < n; j ++)
      if(strcmp(out[i], out[j]) > 0){
        strcpy(aux, out[i]);
        strcpy(out[i], out[j]);
        strcpy(out[j], aux);
      }

  bool m = true;
  for(int i = 0; m && i < n; i ++)
    if(strcmp(in[i], out[i]) != 0)
      m = false;
  
  for(int i = 0; i < l; i ++)
    if(fl[i])
      for(int j = 0; j < n; j ++)
        out[j][i] = (out[j][i] == '0') ? '1' : '0';
  
  return m;
}

void dfs(int p){
  if(p == l){
    bool ok = match();
    if(!ok) return;
    poss = true;
    int c = 0;
    for(int i = 0; i < l; i ++)
      if(fl[i])
        c ++;
    ans = min(ans, c);
    return;
  }
  fl[p] = false;
  dfs(p + 1);
  fl[p] = true;
  dfs(p + 1);
}

int main(){

  scanf("%d", &t);
  for(int ct = 1; ct <= t; ct ++){

    scanf("%d %d", &n, &l);
    
    for(int i = 0; i < n; i ++)
      scanf(" %s", out[i]);

    for(int i = 0; i < n; i ++)
      scanf(" %s", in[i]);

    for(int i = 0; i < n; i ++)
      for(int j = i + 1; j < n; j ++)
        if(strcmp(in[i], in[j]) > 0){
          strcpy(aux, in[i]);
          strcpy(in[i], in[j]);
          strcpy(in[j], aux);
        }
    
    poss = false;
    ans = 10000000;
    dfs(0);

    printf("Case #%d: ", ct);
    if(poss) printf("%d\n", ans);
    else printf("NOT POSSIBLE\n");
    
  }

  return 0;
}
