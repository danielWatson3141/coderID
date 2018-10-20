#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cctype>
#include <complex>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
using namespace std;


//common
using i32=int;using i64=long long;using ll =i64;
using uint=unsigned int;using ull=unsigned long long;
template<typename T> using matrix=vector<vector<T> >;

#define BR "\n"
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,l,r) for(int i=(int)l;i<(int)(r);++i)
#define EACH(it,o) for(auto it = (o).begin(); it != (o).end(); ++it)
#define IN(l,v,r) ((l)<=(v) && (v)<(r))

//config
//#define NDEBUG

//debug
#ifdef NDEBUG
#define DUMP(x)
#define DUMPLN(x)
#define DEBUG(x)
#define DEBUGLN(x)
#define LINE()
#define LINELN()
#define CHECK(exp,act)
#define STOP(e)
#else
#define DUMP(x)  cerr << #x << " = " << (x)
#define DUMPLN(x)  DUMP(x) <<endl
#define DEBUG(x) DUMP(x) << LINE() << " " << __FILE__
#define DEBUGLN(x) DEBUG(x)<<endl
#define LINE()    cerr<< " (L" << __LINE__ << ")"
#define LINELN()    LINE()<<endl
#define CHECK(exp,act)  if(exp!=act){DUMPLN(exp);DEBUGLN(act);}
#define STOP(e)  CHECK(e,true);if(!(e)) exit(1);
#endif

template<class T> inline string toString(const vector<T>& x) {
	stringstream ss;
	REP(i,x.size()){
		if(i!=0)ss<<" ";
		ss<< x[i];
	}
	return ss.str();
}

template<class T> inline string toString(const vector<vector<T> >& map) {
	stringstream ss;
	REP(i,map.size()){
		if(i!=0)ss<<BR;
		ss<< toString(map[i]);
	}
	return ss.str();
}
template<class K,class V>  string toString(map<K,V>& x) {
	string res;stringstream ss;
	for(auto& p:x)ss<< p.first<<":" << p.second<<" ";
	return ss.str();
}

string BITtoString(int bit){
    stringstream ss;
    while(bit!=0){ss<<(bit%2);bit/=2;}
    string res=ss.str();reverse(ALL(res));
    return res;
}

template<typename T,typename V> inline T pmod(T v,V MOD){
	return (v%MOD+MOD)%MOD;
}
#define nextInt(n) scanf("%d",&n)
#define nextLong(n) scanf("%I64d",&n)
#define nextDouble(n) scanf("%lf",&n)


//#define INF 1<<30
//#define EPS 1e-8
//const ll MOD =100000007;

typedef int Cost;
 struct Edge{
        int from,to;Cost cost;
        Edge(int from,int to,Cost cost)
            : from(from),to(to),cost(cost) {};
  };
  ostream& operator <<(ostream& os,const Edge& e){
          os<<"("<<e.from<<"->"<<e.to<<")";
          return os;
  }
  typedef vector<vector<Edge> > Graph;

int INF=1<<28;

class Main{
public:

	vector<bool> passed;
	vector<int> dp;//最小ツリーコスト
	vector<int> chc;//最小ツリーコスト
	int root;
	int chdfs(int p){
		passed[p]=true;
		int cs=1;
		EACH(e1,g[p])if(!passed[e1->to]){
			cs+=chdfs(e1->to);
		}
		return chc[p]=cs;
	}
	void dfs(int p){
		if(dp[p]!=-1)return;
		int parent=-1;
		int c=0;EACH(e1,g[p])if(passed[e1->to])parent=e1->to;else c++;
		EACH(e1,g[p])if(!passed[e1->to]){
			passed[e1->to]=true;dfs(e1->to);
		}
		int mv=INF;
		if(c==0){mv=min(mv,0);}
		if(c==1){
			EACH(e1,g[p])if(e1->to!=parent){
				mv=min(mv,chc[e1->to]);
			}
		}
		if(c>=2){//最小の2個選ぶ．
			int sum=0;EACH(e1,g[p])if(e1->to!=parent){sum+=(chc[e1->to]);};
			EACH(e1,g[p])if(e1->to!=parent)EACH(e2,g[p])if(e2->to!=parent)if(e1->to !=e2->to){
				mv=min(mv,sum-(chc[e1->to]+chc[e2->to])+dp[e1->to]+dp[e2->to]);
			}
		}
		dp[p]=mv;
	}

	Graph g;
	void run(){
		ifstream cin("in");
		ofstream cout( "out" );

		int T;cin >> T;
		for(int tc=1;tc<=T;tc++){
			int N;cin >> N;
			g=Graph(N);
			REP(i,N-1){
				int f,t;cin >> f >> t;f--;t--;
				g[f].push_back(Edge(f,t,1));
				g[t].push_back(Edge(t,f,1));
			}
			int mv=INF;
			REP(i,N){
				passed=vector<bool>(N);
				chc=vector<int>(N);
				chdfs(i);
				passed=vector<bool>(N);
				dp=vector<int>(N,-1);
				root=i;
				passed[i]=true;
				dfs(i);
				mv=min(mv,dp[i]);
			}
			cout <<"Case #"<<tc<<": "<<mv<<endl;
		}

	}
};
 int main(){
	 cout <<fixed<<setprecision(15);
	ios::sync_with_stdio(false);
 	Main().run();
 	return 0;
 }