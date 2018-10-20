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

const ll N = 1000;
const ll it = 100000;
int T;

vector<ll> S(N,0);
vector<ll> I(N);

ll zla(bool mem){
  For(i,N) I[i] = i;
  For(i,N) swap( I[i], I[ rand()%N ]);
  if(mem){ For(i,N) S[i] += I[i]; return 0;}
  else{ll vys=0; For(i,N) vys+= S[i] * I[i]; return vys;}
}

ll dobra(bool mem){
  For(i,N) I[i] = i;
  For(i,N) swap( I[i], I[i + rand()%(N-i) ]);
  if(mem){ For(i,N) S[i] += I[i]; return 0;}
  else{ll vys=0; For(i,N) vys+= S[i] * I[i]; return vys;}
}

double sqr(double x){ return x*x;}

ll calc(vector<ll> &V){
  ll vys=0; For(i,V.size()) vys+= S[i] * V[i]; return vys;
}



int main(){
  srand(time(NULL));
  For(i,it) zla(1);
  
  double vard = 0, avgd =0;
  For(i,10000) avgd += dobra(0)/double(N*it);  
  avgd /=10000;
  For(i,10000) vard += sqr( dobra(0)/double(N*it) - avgd);
  vard = sqrt( vard/10000 );
  //printf("dobra: %lf %lf\n",avgd/10000, vard/10000);
  
  
  double varz = 0, avgz =0;
  For(i,10000)avgz += zla(0)/double(N*it);  
  avgz /= 10000;
  For(i,10000)varz += sqr( zla(0)/double(N*it) - avgz);
  varz = sqrt( varz/10000 );
  //printf("zla: %lf %lf\n",avgz/10000, varz/10000);
  
  int w;
  scanf("%d", &T);
  For(t,T){
    scanf(" %d", &w);
    vector<ll> V(w,0);
    For(i,w) scanf(" %lld", &V[i]);
    ll x = calc(V);
      double vz = fabs (x/double(N*it)-avgz) / varz;
      double vd = fabs (x/double(N*it)-avgd) / vard;
    if( vz > vd)
      printf("Case #%d: BAD\n",t+1);
    else
      printf("Case #%d: GOOD\n",t+1);
  }
  
  
  /*int d = 0;
  For(i,100)
    if( rand()%2 ==0){
      ll x = zla(0);
      double vz = fabs (x/double(N*it)-avgz) / varz;
      double vd = fabs (x/double(N*it)-avgd) / vard;
      if (vd > vz) d++;
    }
    else{
      ll x = dobra(0);
      double vz = fabs (x/double(N*it)-avgz) / varz;
      double vd = fabs (x/double(N*it)-avgd) / vard;
      if (vd < vz) d++;
    }
  printf("%d\n", d);
  */
  
  return 0;
}