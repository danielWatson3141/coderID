#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define For(i,N) for(int i=0; i<N; i++)
#define Fore(i,C) for(__typeof((C).begin()) i =(C).begin(); i != (C).end(); ++i)
#define FOR(i,j,k) for(int i=j; i<k; i++)
#define Fors(i,s) for(int i=0; s[i]; i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef long long ll;
using namespace std;

int T,N,L;
char c[100];

int binint(char *c){
  int res = 0;
  Fors(i,c){ res*=2; res += (c[i]-'0'); }
  return res;
}

vector<int> A,B;

int main(){
  scanf("%d", &T);
  For(t,T){
    A.clear(); B.clear();
    scanf(" %d %d", &N, &L);
    For(i,N){ scanf(" %s ", c); A.pb( binint(c)); }
    For(i,N){ scanf(" %s ", c); B.pb( binint(c)); }
    //For(i,N) printf("%d ", A[i]); printf("\n");
    //For(i,N) printf("%d ", B[i]); printf("\n");
    
    sort(A.begin(), A.end());
    int mini = L;
    For(i,1<<L){
      int jed=0; For(j,L) if(i & 1<<j) jed++;
      For(j,N) B[j] ^= i;
      sort(B.begin(), B.end()); 
      if( A == B) mini = min(mini,jed);
      For(j,N) B[j] ^= i;
    }
    if(mini == L)
      printf("Case #%d: NOT POSSIBLE\n", t+1);
    else
      printf("Case #%d: %d\n", t+1,mini);
  }
  return 0;
}