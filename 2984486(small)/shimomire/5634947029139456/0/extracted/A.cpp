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
int INF=1<<28;

class Main{
public:
	void run(){
		ifstream cin("in");
		ofstream cout( "out" );

		int T;cin >> T;
		for(int tc=1;tc<=T;tc++){
			int N,L;cin >> N >> L;
			vector<string> as(N),bs(N);
			REP(i,N) cin >> as[i];
			REP(i,N) cin >> bs[i];


			// REP(i,N)REP(j,N){//対応を決める．
			// 	vector<int> fs(N);
			// 	REP(c,L)if(as[i][c]!=bs[j][c])fs[c]++;

			// 	REP()
			// }

			
			vector<int> ac(L),bc(L);
			REP(i,N)REP(c,L)if(as[i][c]=='1')ac[c]++;
			REP(i,N)REP(c,L)if(bs[i][c]=='1')bc[c]++;

			int flip=0;
			bool ok=true;
			vector<int> sels;
			REP(c,L){
				if(ac[c]==bc[c]){
					sels.push_back(c);
				}else if(ac[c]+bc[c]==N){
					REP(i,N){
						if(as[i][c]=='1')as[i][c]='0'; else as[i][c]='1';
					}
					flip++;
				}else{
					ok=false;
				}
			}
			sort(ALL(as));sort(ALL(bs));
			REP(i,N)if(as[i]!=bs[i])ok=false;
	
			if(ok){
				cout <<"Case #"<<tc<<": "<<flip<<endl;
			}else{
				cout <<"Case #"<<tc<<": "<<"NOT POSSIBLE"<<endl;			
			} 
		}

	}

	void rune(){
		ifstream cin("in");
		ofstream cout( "out" );

		int T;cin >> T;
		for(int tc=1;tc<=T;tc++){
			int N,L;cin >> N >> L;
			vector<string> as(N),bs(N);
			REP(i,N) cin >> as[i];
			REP(i,N) cin >> bs[i];
			sort(ALL(bs));


			int mv=INF;
			for(int bit=0;bit<(1<<L);bit++){
				int v=0;REP(l,L)if((bit>>l)&1)v++;
				vector<string> as2=as;
				REP(i,N)REP(l,L){
					if((bit>>l)&1){
						if(as2[i][l]=='1')as2[i][l]='0';
						else if(as2[i][l]=='0')as2[i][l]='1';
					}
				}
				sort(ALL(as2));bool ok=true;
				REP(i,N){
					bool ex=false;
					REP(j,N)if(as2[i]==bs[j])ex=true;
					if(!ex)ok=false;
				}
				if(ok)mv=min(mv,v);
			}			

			if(mv!=INF){
				cout <<"Case #"<<tc<<": "<<mv<<endl;
			}else{
				cout <<"Case #"<<tc<<": "<<"NOT POSSIBLE"<<endl;			
			} 
		}

	}

};
 int main(){
	 cout <<fixed<<setprecision(15);
	ios::sync_with_stdio(false);
 	Main().rune();
 	return 0;
 }