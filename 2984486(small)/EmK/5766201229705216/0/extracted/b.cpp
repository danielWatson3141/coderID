#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<numeric>
#include<functional>
#include<complex>
#include<bitset>
#include<cassert>

using namespace std;
#define BET(a,b,c) ((a)<=(b)&&(b)<(c))
#define FOR(i,n) for(int i=0,i##_end=(int(n));i<i##_end;i++)
#define FOR3(i,a,b) for(int i=a,i##_end=b;i<i##_end;i++)
#define FOR_EACH(it,v) for(__typeof(v.begin()) it=v.begin(),it_end=v.end() ; it != it_end ; it++)
#define SZ(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define MP make_pair
#define CLS(x,val) memset((x) , val , sizeof(x)) 
typedef long long ll_t;
typedef long double ld_t;
typedef vector<int> VI; 
typedef vector<VI> VVI;
typedef complex<int> xy_t;

template<typename T> void debug(T v , string delimiter = "\n")
{ for(__typeof(v.begin()) it=v.begin(),it_end=v.end() ; it != it_end ; it++) cout << *it << delimiter; cout << flush ;}

int dx[]  = {0,1,0,-1};
int dy[]  = {1,0,-1,0};
string ds = "SENW";

const double PI = 4.0*atan(1.0);

VVI adj;

int sison[1111];
int memo[1111];

int dfs(int p, int parent = -1) {
  sison[p] = 0;
  for(auto child : adj[p]) {
    if(child == parent) continue;
    sison[p] += dfs(child, p);
  }
  sison[p]++;
  return sison[p];
}

int solve(int p, int parent = -1) {
  int& ret = memo[p];
  if(ret != -1) return ret;
  int val = 1<<28;
  vector<pair<int,pair<int,int> > > sub;
  for(auto child : adj[p]) {
    if(child == parent) continue;
    int del = sison[child];
    int rec = solve(child, p);
    sub.push_back(MP(del-rec, MP(del, rec)));
  }
  sort(ALL(sub));
  reverse(ALL(sub));
  val = 0;
  if(SZ(sub) >= 2) {
    FOR(i,SZ(sub)) {
      if(i < 2) val += sub[i].second.second;
      else      val += sub[i].second.first;
    }
  }else {
    FOR(i,SZ(sub)) {
      val += sub[i].second.first;
    }
  }

  return ret = val;
}

int main() {

  int t,caseNo=1;
  cin>>t;
  while(t--){
    int N;
    cin>>N;
    adj = VVI(N);
    FOR(i,N-1) {
      int a,b;
      scanf("%d%d",&a,&b);
      a--; b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    int ans = 1<<28;
    FOR(root,N) {
      memset(memo , -1 , sizeof(memo));
      memset(sison , -1 , sizeof(sison));
      dfs(root);
      //cout<<" "<<root<<" "<<solve(root)<<endl;
      ans = min(ans, solve(root));
    }
    printf("Case #%d: %d\n", caseNo++, ans);
  }
  return 0 ;
}
