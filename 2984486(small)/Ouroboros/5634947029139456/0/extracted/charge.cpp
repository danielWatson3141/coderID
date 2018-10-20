#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

vector<long long> need;
vector<long long> outlet;
long long mask[41];
int N, L;

void readData() {
  cin >> N >> L;
  need.resize(N);
  outlet.resize(N);
//  for (int i = 0;i < N;i++) {
//    need[i].resize(L);
//    outlet[i].resize(L);
//  }
  string st;
  for (int i = 0;i < N;i++) {
    cin >> st;
    outlet[i] = 0;
    for (int j = 0;j < L;j++) 
      if (st[j]=='1') outlet[i] += mask[L-j-1];

    //printf("outlet %d = %lld\n",i,outlet[i]);
  }
  for (int i = 0;i < N;i++) {
    cin >> st;
    need[i] = 0;
    for (int j = 0;j < L;j++) 
      if (st[j]=='1') need[i] += mask[L-j-1];
    //printf("need %d = %lld\n",i,need[i]);
  }
}


int result;

bool check() {
  sort(outlet.begin(),outlet.end());
  for (int i = 0;i < N;i++)
    if (outlet[i] != need[i]) return false;

  return true;

}

void dfs(int bit,int num_flip) {
  if (bit < L) {
    //dont flip
    dfs(bit+1,num_flip);

    for (int i = 0;i < N;i++) {
      outlet[i] = outlet[i] ^ mask[bit];
    }
    dfs(bit+1,num_flip+1);
    for (int i = 0;i < N;i++) {
      outlet[i] = outlet[i] ^ mask[bit];
    }
  } else {
    if (check() && num_flip < result) result = num_flip;
  }

}

void process() {
  sort(need.begin(),need.end());
  result = L+1;
  dfs(0,0);
}


int main() {
  //freopen("ex.1.in","r",stdin);
  freopen("A-small-attempt1(1).in","r",stdin);
  int T;
  cin >> T;
  int case_id = 0;

  mask[0] = 1;
  for (int i = 1;i < 41;i++) mask[i] = mask[i-1] << 1;
  while (T--) {
    case_id++;
    fprintf(stderr,"Doing case %d\n",case_id);

    readData();
    process();
    if (result <= L) 
      cout << "Case #" << case_id << ": " << result << endl; 
    else
      cout << "Case #" << case_id << ": NOT POSSIBLE" << endl; 

  }
}
