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

void flip(char &c){
	if(c=='0'){
		c='1';
	}else{
		c='0';
	}
}

int MAX=INT_MAX/10;

int dfs(vs &outlets,vs &devices,int pos,int l){
	if(pos==l){
		return 0;
	}
	int ret=MAX;
	int ones_o=0;
	int ones_d=0;
	REP(i,outlets.size()){
		ones_o+=outlets[i][pos]=='1';
	}
	REP(i,devices.size()){
		ones_d+=devices[i][pos]=='1';
	}
	bool must_flip=(ones_o!=ones_d);
	bool must_remain=(ones_o==ones_d&&(ones_o!=outlets.size()/2||outlets.size()%2==1));
	REP(i,2){
		if((must_flip&&i==1)||(must_remain&&i==0)){
			continue;
		}
		vs new_outlets(outlets);
		if(i==0){
			REP(j,new_outlets.size()){
				flip(new_outlets[j][pos]);
			}
		}
		bool ok=true;
		sort(ALL(new_outlets));
		REP(j,new_outlets.size()){
			REP(k,pos+1){
				if(new_outlets[j][k]!=devices[j][k]){
					ok=false;
				}
			}
		}
		if(ok){
			ret=min(ret,dfs(new_outlets,devices,pos+1,l)+(i==0));
		}
	}
	return ret;
}

int main(){
	int num_cases;
	cin>>num_cases;
	REP(test_case,num_cases){
		int n,l;
		cin>>n>>l;
		vs outlets(n),devices(n);
		REP(i,n){
			cin>>outlets[i];
		}
		REP(i,n){
			cin>>devices[i];
		}
		sort(ALL(devices));
		int ans=dfs(outlets,devices,0,l);
		cout<<"Case #"<<(test_case+1)<<": ";
		if(ans>=MAX){
			cout<<"NOT POSSIBLE"<<endl;
		}else{
			cout<<ans<<endl;
		}
	}
}