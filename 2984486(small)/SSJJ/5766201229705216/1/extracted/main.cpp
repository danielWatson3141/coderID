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


namespace std{
	bool operator<(pii &l,pii &r){
		if(l.second==r.second){
			return l.first>r.first;
		}
		return l.second>r.second;
	}
}

pii dfs(vvi &g,int pos,vi &used){
	used[pos]=1;
	vector<pii> children;
	int num_children=0;
	REP(i,g.size()){
		if(i!=pos&&!used[i]&&g[pos][i]){
			pii p=dfs(g,i,used);
			children.push_back(p);
			num_children+=p.second+1;
		}
	}
	int ret=0;
	if(children.size()==0){
		return make_pair(0,0);
	}else if(children.size()==1){
		return make_pair(num_children,num_children);
	}

	sort(ALL(children));
	REP(i,2){
		ret+=children[i].first;
	}
	FOR(i,2,children.size()){
		ret+=children[i].second+1;
	}
	return make_pair(ret,num_children);
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
		REP(root,n){
			vi used(n);
			pii p=dfs(g,root,used);
			int cnt=p.first;
			ans=min(ans,cnt);
		}
		cout<<"Case #"<<(test_case+1)<<": ";
		if(ans==INT_MAX){
			cout<<"NOT POSSIBLE"<<endl;
		}else{
			cout<<ans<<endl;
		}
	}
}