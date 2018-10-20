#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PI;
#define EPS (1e-6)
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define REP(i, n) rep (i, n)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define min3(a,b,c) min((a),min((b),(c)))
#define min4(a,b,c,d) min((a),min3((b),(c),(d)))
#define SZ(a) (int)((a).size())
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) a.rbegin(),a.rend()
#define FLL(a,b) memset((a),b,sizeof(a))
#define CLR(a) memset((a),0,sizeof(a))
#define declare(a,it) __typeof(a) it=(a)
#define FOR(it,a) for(declare(a.begin(),it);it!=a.end();++it)
#define FORR(it,a) for(declare(a.rbegin(),it);it!=a.rend();++it)

template<typename T,typename U> ostream& operator<< (ostream& out, const pair<T,U>& val){return out << "(" << val.F << ", " << val.S << ")";}
template<class T> ostream& operator<< (ostream& out, const vector<T>& val){out << "{";rep(i,SZ(val)) out << (i?", ":"") << val[i];return out << "}";}
typedef double FP;
typedef complex<FP> pt;
typedef pt P;
typedef pair<pt,pt> line;
namespace std{
  bool operator<(const P&a,const P&b){
    if(abs(a.real()-b.real())>EPS)
      return a.real()<b.real();
    return a.imag()<b.imag();
  }
}
FP dot(P a,P b){return real(conj(a)*b);}
FP crs(P a,P b){return imag(conj(a)*b);}
P ortho(P a){return P(imag(a),-real(a));}
P ortho(line a){return ortho(a.S-a.F);}
P crspt(P a,P b,P c,P d){b-=a,d-=c;return a+b*crs(d,c-a)/crs(d,b);}
P crspt(line a,line b){return crspt(a.F,a.S,b.F,b.S);}
bool onl(P a1,P a2,P b){return abs(b-a1)+abs(b-a2)<abs(a1-a2)+EPS;}
bool onl(line a,P b){return onl(a.F,a.S,b);}
bool iscrs(line a,line b){P c=crspt(a,b);return onl(a,c)&&onl(b,c);}
void pkuassert(bool t){t=1/t;};
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,-1,1,1,-1};
enum{TOP,BTM,LFT,RGT,FRT,BCK};
int dxdy2ce[]={RGT,FRT,LFT,BCK};
int s2i(string& a){stringstream ss(a);int r;ss>>r;return r;}
template<class T> T shift(T a,int b,int c,int d,int e){
  __typeof(a[0])t=a[b];
  a[b]=a[c];a[c]=a[d];a[d]=a[e];a[e]=t;return a;}
template<class T> T rgt(T a){return shift(a,TOP,LFT,BTM,RGT);}
template<class T> T lft(T a){return shift(a,TOP,RGT,BTM,LFT);}
template<class T> T frt(T a){return shift(a,TOP,BCK,BTM,FRT);}
template<class T> T bck(T a){return shift(a,TOP,FRT,BTM,BCK);}
line mkl(P a,P v){return line(a,a+v);}
FP lpdist(line a,P b){return abs(b-crspt(a,mkl(b,ortho(a))));}
FP spdist(line a,P b){
  P c(crspt(a,mkl(b,ortho(a))));
  return onl(a,c)?abs(b-c):min(abs(a.F-b),abs(a.S-b));
}
FP ssdist(line a,line b){
  return
    iscrs(a,b)?0.:
    min4(spdist(a,b.F),spdist(a,b.S),
         spdist(b,a.F),spdist(b,a.S));
}

#include <random>
random_device rd;

vector<int> good(int n=1000){

  mt19937 mt(rd());
  
  vector<int> a(n);
  rep(i,n) a[i] = i;
  rep(i,n){
    uniform_int_distribution<int> randint(i,n-1);
    int p=randint(mt);
    swap(a[i],a[p]);
  }
  return a;
}

vector<int> bad(int n=1000){
  //random_device rd;
  mt19937 mt(rd());
  
  vector<int> a(n);
  rep(i,n) a[i] = i;
  rep(i,n){
    uniform_int_distribution<int> randint(0,n-1);
    int p=randint(mt);
    swap(a[i],a[p]);
  }
  return a;
}

void solve(int ca){
  int n;
  cin >> n;
  vector<int> in(n);
  rep(i,n) cin >> in[i];
  ll sum=0;
  rep(i,n) sum += sqrt(n-i)*abs(in[i]-i);
  cout << sum << endl;
  //printf("Case #%d: %s\n",ca,ans);
}

void test(){
  map<vector<int>,int> app;
  rep(i,100000){
    auto a=bad(3);
    ++app[a];
    //vector<int> b(a);
    //rep(j,4) b[a[j]]=j;
    //++app[b];
  }
  FOR(it,app) cout << *it << endl;
}

double pro[1000][1000];
double dp[2][1000];

void calc(int p,int n){
  memset(dp,0,sizeof(dp));
  dp[0][p]=1;
  
  for(int ii=0;ii<n;++ii){
    int cur=ii&1;
    int ne=~ii&1;
    //memset(dp[ne],0,sizeof(dp[ne]));
    rep(i,n){
      if(i==ii)
        dp[ne][i]=dp[cur][i]/n + (1-dp[cur][i])/n;
      else
        dp[ne][i]=dp[cur][i]*(n-1)/n+dp[cur][ii]/n;
    }
  }

  rep(i,n) pro[p][i]=dp[n&1][i];
  //cerr << accumulate(pro[p],pro[p]+n,0.0) << endl;
}

int main(int argc, char *argv[])
{

  // test();
  // return 0;
  
  int n=1000;
  rep(i,n){
    if(i%10==0)
      cerr << i << endl;
    calc(i,n);
  }
  
  // rep(i,n){
  //   rep(j,n) cerr << pro[i][j] << ' ';
  //   cerr << endl;
  // }
  
  //return 0;

  // ll sum = 0;
  // rep(i,100){
  //   auto a=good();
  //   rep(j,1000) sum += abs(j-a[j])*abs(j-a[j]);
  // }
  // cout << sum << endl;
  
  // sum = 0;
  // rep(i,100){
  //   auto a=bad();
  //   rep(j,1000) sum += abs(j-a[j])*abs(j-a[j]);    
  //   //rep(j,1000) sum += (1000-i)*abs(j-a[j]);
  // }
  // cout << sum << endl;  

  // return 0;
  
  int t;
  cin >> t;
  vector<pair<double,ll> > ans(t);
  rep(i,t){
    int n;
    cin >> n;
    double sum=0;
    rep(j,n){
      int a;
      cin >> a;
      sum += log(pro[a][j]);
    }
    cerr << sum << endl;
    ans[i]=mp(sum,i);
  }
  
  sort(ALL(ans));
  reverse(ALL(ans));
  string out[t];
  rep(i,t/2) out[ans[i].S]="BAD";
  rep(i,t/2) out[ans[i+t/2].S]="GOOD";
  rep(i,t) cout << "Case #"<<i+1<<": "<<out[i] << endl;
  //rep(i,t) solve(i+1);
  return 0;
}
