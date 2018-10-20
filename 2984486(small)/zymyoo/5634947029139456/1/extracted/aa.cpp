/*************************************************************************
    > File Name: a.cpp
    > Author: implus
    > Mail: 674592809@qq.com
    > Created Time: 六  4/26 08:59:16 2014
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

const int maxn = 155;
const int maxl = 44;
int N, L;
char out[maxn][maxl];
char dev[maxn][maxl];

bool gao(vector<string>& out, vector<string>& dev, vector<int>& out0, vector<int>& dev0, string& change, int& ops){
  bool ok = 1;
  change = "";
  ops = 0;
  int n = out.size();
  for(int j = 0; j < L; j++){
    if(out0[j] == dev0[j]) {
      change.append(1, '0');
    }else if( out0[j] + dev0[j] == n){
      change.append(1, '1');
      ops++;
      for(int i = 0; i < n; i++){
        if(out[i][j] == '0') out[i][j] = '1';
        else out[i][j] = '0';
      }
    }else {
      ok = 0; break;
    }
  }

  if(ok){
    vector<string> vo, vd;
    for(int i = 0; i < out.size(); i++){
      vo.push_back(out[i]);
      vd.push_back(dev[i]);
    }
    sort(vo.begin(), vo.end());
    sort(vd.begin(), vd.end());
    for(int i = 0; i < vo.size(); i++){
      if(!(vo[i] == vd[i])) {
        ok = 0; break;
      }
    }
  }
  if(ok) return true;
  return false;
}

int main(){
  int T, icase = 1;
  scanf("%d", &T);
  while(T--){
    scanf("%d%d", &N, &L);
    for(int i = 0; i < N; i++){
      scanf("%s", out[i]);
    }
    for(int i = 0; i< N; i++){
      scanf("%s", dev[i]);
    }
    vector<int> out0(L, 0), dev0(L, 0);

    for(int i = 0; i < N; i++){
      for(int j = 0; j < L; j++){
        if(out[i][j] == '0') out0[j]++;
        if(dev[i][j] == '0') dev0[j]++;
      }
    }
    bool ok = 1;
    string str;int ans = 0;
    if(N % 2){
      vector<string> vo;
      for(int k = 0; k < N; k++) { vo.push_back(out[k]); }
      vector<string> vd;
      for(int k = 0; k < N; k++) { vd.push_back(dev[k]); }
      ok = gao(vo, vd, out0, dev0, str, ans);
    }else{// N % 2 == 0
      ans = (1<<30);
      for(int i = 0; i < 1; i++){
        for(int j = 0; j < N; j++){// i, j out
          
          //cerr<<out[i]<<" "<<dev[j]<<endl;
          vector<string> vo;
          for(int k = 0; k < N; k++) if(k != i){ vo.push_back(out[k]); }
          vector<string> vd;
          for(int k = 0; k < N; k++) if(k != j){ vd.push_back(dev[k]); }
          
          vector<int> out0(L, 0);
          vector<int> dev0(L, 0);
          int n = N - 1;
          for(int k = 0; k < n; k++){
            for(int kk = 0; kk < L; kk++){
              if(vo[k][kk] == '0') out0[kk]++;
              if(vd[k][kk] == '0') dev0[kk]++;
            }
          }
          string c; int ops;
          bool res = gao(vo, vd, out0, dev0, c, ops);
          //cerr<<"res = "<<res<<" change = "<<c<<" ops = "<<ops<<endl;
          if(!res) continue;
          
          // change i -> by c
          string oi = out[i];
          //cerr<<"before oi = "<<oi<<endl;
          for(int k = 0; k < c.size(); k++){
            if(c[k] == '1') {
              if(oi[k] == '1') oi[k] = '0';
              else oi[k] = '1';
            }
          }
          if(oi == dev[j]){
            ans = min(ans, ops);
          }
        }
      }
    }
    if(ans == (1<<30)) ok = 0;
    if(ok){
      printf("Case #%d: %d\n", icase++, ans);
    }else 
      printf("Case #%d: NOT POSSIBLE\n", icase++);
  }
  return 0;
}

