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
int l, ans=-1;
char a[1000][1000], b[1000][1000], c[1000][1000];
int d[150];

void calc(int turn, int at) {
  if (at == l) {
    if (ans != -1 && turn > ans) {
      return;
    }
    int f=0, done=0;
    REP(i,n) {
      d[i]=0;
    }
    REP(i,n) {
      done = 0;
      REP(k,n) {
        if(d[k]) {
          continue;
        }
        f=0;
        REP(j,l) {
          if (a[i][j] != c[k][j]) {
            f = 1;
            break;
          }
        }
        if (!f) {
          done =1;
          d[k]=1;
          break;
        }
      }
      if (!done) {
        break;
      }
    }
    if (done) {
      ans = turn;
    }
    return;
  }

  REP(i,n) {
    c[i][at]= b[i][at];
  }
  calc(turn, at+1);
  REP(i,n) {
    if (b[i][at] == '1') {
      c[i][at]= '0';
    } else {
      c[i][at] = '1';
    }
  }
  calc(turn+1, at+1);
}

int main() {

  si(t);
  REP(prob, t) {
    si(n);
    si(l);
    REP(i,n) {
      ss(a[i]);
    }
    REP(i,n) {
      ss(b[i]);
    }
    ans = -1;
    calc(0,0);
    if (ans == -1) {
      printf("Case #%d: NOT POSSIBLE\n",prob+1);
    } else {
      printf("Case #%d: %d\n",prob+1,ans);
    }
  }

  //system("pause");
  return 0;
}
