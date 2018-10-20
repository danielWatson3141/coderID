#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <queue>
#include <cstring>

#define vs vector<string>
#define vi vector<int>
#define vpii vector< pair<int,int> >
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define sqr(x) ((x)*(x))
#define FOR(i,n) for (ll i = 0; i < ll(n); i++)
#define READ(v,n) { FOR(i,n){double x;cin>>x;v.pb(x);} }
#define FREAD(v,n) { FOR(i,n){int x;in>>x;v.pb(x);} }
#define WRITE(v) "";FOR(i,sz(v))cout<<v[i]<<" ";cout
#define FWRITE(v) "";FOR(i,sz(v))out<<v[i]<<" ";out
#define gmin(a,b) { if (b < a) a = b; }
#define gmax(a,b) { if (b > a) a = b; }
#define pb push_back
#define ppb pop_back
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

double h(vi a){
    double h=0;
    FOR(i,1000){
        if(a[i]<i){h+=a[i]+1000-i;}else{h+=a[i]-i;}    
    }    
    return h/1000;
}

int main(void){
    srand (time(NULL));
  cout.precision(15);
  int T;
  cin>>T;
  FOR(t,T){
    int n;
    cin>>n;
    vi a;
    FOR(i,1000){
        int x;
        cin>>x;
        a.pb(x);    
    }
    double d=h(a);

    end:
    cout<<"Case #"<<(t+1)<<": ";
    if(d<490.0){cout<<"BAD"<<endl;}else{cout<<"GOOD"<<endl;}
  }
  return 0;
}
