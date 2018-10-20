#include<iostream>
#define MIN(a,b) ((a)<(b)?(a):(b))

using namespace std;
int edge[1001][1001];
int es[1001];
int compdp[1001][1001];
int totdp[1001][1001];

int tot(int cur, int prev) {
  if (totdp[cur][prev] != -1) {
    return totdp[cur][prev];
  }
  int rtn = 1;
  for (int i=0; i<es[cur]; ++i) {
    int next = edge[cur][i];
    if (next == prev) continue;
    rtn += tot(next,cur);
  }
  totdp[cur][prev] = rtn;
  return rtn;
}

int comp(int cur, int prev) {
  if (compdp[cur][prev] != -1) {
    return compdp[cur][prev];
  }
  int edges = es[cur] - 1;
  if (prev == 1000) edges++;
  if (edges == 0) return 0;
  if (edges == 1) {
    for (int i=0; i<es[cur]; ++i) {
      if (edge[cur][i] != prev) {
        return tot(edge[cur][i], cur);
      }
    }
  }
  int rtn = 100000;
  for (int i=0; i<es[cur]; ++i) {
    int next1 = edge[cur][i];
    if (next1 == prev) continue;
    for(int j=i+1; j<es[cur]; ++j) {
      int next2 = edge[cur][j];
      if (next2 == prev) continue;
      int tokeep = comp(next1, cur) + comp(next2, cur);
      int tokill = 0;
      for(int k=0; k<es[cur]; ++k) {
        int die = edge[cur][k];
        if (k ==i || k==j || die == prev) continue; 
        tokill += tot(die, cur);
      }
      rtn = MIN(rtn, tokeep + tokill);
    }
  }
  compdp[cur][prev] = rtn;
  return rtn;
}
int main() {
  int cas;
  cin>>cas;
  for(int ca=1 ; ca<=cas; ++ca) {
    int n;
    cin>>n;
    int a,b;
    memset(es,0,sizeof(es));
    memset(compdp,-1,sizeof(compdp));
    memset(totdp,-1,sizeof(totdp));
    for(int i=0  ;i<n-1; ++i) {
      cin>>a>>b;
      a--; b--;
      edge[a][es[a]++] = b;
      edge[b][es[b]++] = a;
    }

    int rtn = 10000;
    for(int i=0 ;i<n; ++i) {
      int t = comp(i, 1000);
      rtn = MIN(t, rtn);
    }
    cout<<"Case #"<<ca<<": "<<rtn<<endl;
  }
}
