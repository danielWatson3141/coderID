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

pair<int, int> m[1010][1010];

pair<int, int> root(int r, vector <vi> &g, int f){
    if(m[r][f].first != -1){return m[r][f];}
    //cerr<<"r"<<r<<"f"<<f<<endl;
    vi neig = g[r];
    FOR(i, sz(neig)){if(neig[i]==f){neig.erase(neig.begin()+i);break;}}
    if(sz(neig)==0){m[r][f]=mp(0,1); return mp(0,1);}
    if(sz(neig)==1){
        pair<int, int> p = root(neig[0], g, r);
        m[r][f]=mp(p.second, p.second+1); 
        return mp(p.second, p.second+1);          
    }
    if(sz(neig)==2){
        pair<int, int> p1 = root(neig[0], g, r);
        pair<int, int> p2 = root(neig[1], g, r);
        m[r][f]=mp(p1.first+p2.first, p1.second+p2.second+1);
        return mp(p1.first+p2.first, p1.second+p2.second+1);            
    }
    vi diff;
    int sum=0;
    FOR(i,sz(neig)){
        pair<int, int> p = root(neig[i], g, r);
        diff.pb(p.second-p.first);
        sum+=p.second;       
    }
    sort(all(diff));
    reverse(all(diff));
    m[r][f]=mp(sum-diff[0]-diff[1],sum+1);
    return mp(sum-diff[0]-diff[1],sum+1);
}


int main(void){
  cout.precision(15);
  int T;
  cin>>T;
  FOR(t,T){
    FOR(i,1005)FOR(j,1005)m[i][j]=mp(-1,-1);
    int n;
    cin>>n;
    vector<vi> g;
    FOR(i,n){g.pb(vi());}
    FOR(i,n-1){
        int x,y;
        cin>>x>>y;
        g[x-1].pb(y-1);
        g[y-1].pb(x-1);    
    }
    int best=-1;
    int v=0;
    FOR(i,n){
        pair<int, int> p = root(i, g, n+1);        
        //cerr<<"  --  "<<p.first<<endl;
        if(best == -1 || p.first<best){best=p.first;v=i;}
    }
            
    cerr<<n<<", "<<best<<", "<<v<<endl;
    end:
    cout<<"Case #"<<(t+1)<<": ";
    cout<<best<<endl;
//    if(best == -1){cout<<"NOT POSSIBLE"<<endl;}else{cout<<best<<endl;}
  }
  return 0;
}
