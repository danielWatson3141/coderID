#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits>
#include<vector>
#include<bitset>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<map>

using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,FROM,n) for(int i=FROM;i<n;i++)
#define FORR(i,n) for(int i=n;i>=0;i--)
#define ll long long int
#define llu long long unsigned int
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define slu(n) scanf("%llu",&n)
#define sf(n) scanf("%f",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define PI pair<int,int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define V(x) vector<x>

ll gcd(ll r0, ll r1)
{
    if(r0==0 || r1==0)
    return 1;

    if(r0<r1)
    return gcd(r1,r0);

    if(r0%r1==0)
    return r1;

    return gcd(r1,r0%r1);
}
ll findInverse(ll a, ll b)
{
    ll x[3];
    ll y[3];
    ll quotient  = a / b;
    ll remainder = a % b;
    x[0] = 0;
    y[0] = 1;
    x[1] = 1;
    y[1] = quotient * -1;

    ll i = 2;
    for (; (b % (a%b)) != 0; i++)
    {
        a = b;
        b = remainder;
        quotient = a / b;
        remainder = a % b;
        x[i % 3] = (quotient * -1 * x[(i - 1) % 3]) + x[(i - 2) % 3];
        y[i % 3] = (quotient * -1 * y[(i - 1) % 3]) + y[(i - 2) % 3];
    }
    //x[i — 1 % 3] is inverse of a
    //y[i — 1 % 3] is inverse of b
    return x[(i - 1) % 3];
}

int t,n;

/*
bool myfunction(data i,data j)    //use it to sort vectors
{
    if( i.x < j.x ) return true;
    if( j.x < i.x ) return false;
    return j.y > i.y;
}
*/

int a[1000][1000];
int b[1000],v[1000];
int q[1000],qi,ti;

int isConn() {
  int st=0;
  REP(i,n) {
    if (b[i]==0) {
      st = i;
    }
    v[i]=0;
  }
  v[st]=1;
  q[0]=st;
  qi=0;
  ti=1;
  while(qi != ti) {
    int at = q[qi];
    qi++;
    REP(i,n) {
      if (b[i]==0 && v[i]==0 && a[at][i]) {
        v[i]=1;
        q[ti]=i;
        ti++;
      }
    }
  }
  REP(i,n) {
    if (b[i] ==0 && v[i] ==0) {
      return false;
    }
  }

  int c = 0;
  REP(i,n) {
    if (b[i]==0) {
      int d = 0;
      REP(j,n) {
        if (b[j]==0 && a[i][j]) {
          d++;
        }
      }
      if (d==2) {
        c++;
      }
      if (d!=2 && d!=3 && d!=1) {
        return false;
      }
    }
  }
  if (c!=1) {
    return false;
  }
  return true;
}

int main() {

  si(t);
  REP(prob, t) {
    si(n);
    memset(a,0,sizeof(a));
    REP(i,n-1) {
      int x,y;
      si(x);
      si(y);
      x--;
      y--;
      a[x][y]=1;
      a[y][x]=1;
    }
    int till = 1<<n;
    int ans = 10000;
    REP(i,till) {
      int x = i;
      int cnt = 0;
      REP(i,n) {
        if (x%2) {
          b[i]=1;
          cnt++;
        } else {
          b[i]=0;
        }
        x/=2;
      }
      if (cnt > ans) {
        continue;
      }
      if (cnt == n-1 || isConn()) {
        ans = cnt;
      }
    }
    printf("Case #%d: %d\n", prob+1, ans);
  }

  //system("pause");
  return 0;
}
