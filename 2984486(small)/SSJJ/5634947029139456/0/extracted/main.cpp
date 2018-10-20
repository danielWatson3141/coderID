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
		sort(ALL(outlets));
		sort(ALL(devices));
		int ans=INT_MAX;
		REP(mask,1<<l){
			vs new_outlets(outlets);
			int cnt=0;
			REP(i,l){
				if(mask&(1<<i)){
					cnt++;
					REP(j,n){
						flip(new_outlets[j][i]);
					}
				}
			}
			sort(ALL(new_outlets));
			bool ok=true;
			REP(i,n){
				if(new_outlets[i]!=devices[i]){
					ok=false;
				}
			}
			if(ok){
				ans=min(ans,cnt);
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