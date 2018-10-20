#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <cassert>
#include <memory>
#include <time.h>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
const double EPS = 1e-9;
const double PI  = acos(-1.0);

bool is_binary_tree(vvi &g,int pos,vi &used){
	used[pos]=1;
	int num_children=0;
	REP(i,g.size()){
		if(i!=pos&&!used[i]&&g[pos][i]){
			num_children++;
			if(!is_binary_tree(g,i,used)){
				return false;
			}
		}
	}
	return (num_children==0||num_children==2);
}

int main(){
	int num_cases;
	cin>>num_cases;
	REP(test_case,num_cases){
		int n;
		cin>>n;
		vvi g(n,vi(n));
		REP(i,n-1){
			int f,t;
			cin>>f>>t,f--,t--;
			g[f][t]=1;
			g[t][f]=1;
		}
		int ans=INT_MAX;
		REP(mask,1<<n){
			vvi new_g(g);
			int cnt=0;
			vi deleted(n);
			int num_edges=n-1;
			REP(i,n){
				if(mask&(1<<i)){
					cnt++;
					REP(j,n){
						if(new_g[i][j]){
							new_g[i][j]=0;
							new_g[j][i]=0;
							num_edges--;
						}
					}
					deleted[i]=1;
				}
			}
			bool ok=false;
			if(num_edges==n-cnt-1){
				REP(i,n){
					if(!deleted[i]){
						vi used(n);
						if(is_binary_tree(new_g,i,used)){
							ok=true;
							break;
						}
					}
				}
				if(ok){
					ans=min(ans,cnt);
				}
			}
		}
		cout<<"Case #"<<(test_case+1)<<": ";
		if(ans==INT_MAX){
			cout<<"NOT POSSIBLE"<<endl;
		}else{
			cout<<ans<<endl;
		}
	}
}