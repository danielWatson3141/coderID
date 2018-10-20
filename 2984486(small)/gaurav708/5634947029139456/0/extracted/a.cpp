#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <functional>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<string> vs;

#define rep(i,n) for(int i=0;i<(n);i++)
#define forup(i,a,b) for(int i=(a);i<(b);i++)
#define fordn(i,a,b) for(int i=(a);i>(b);i--)
#define all(x) x.begin(),x.end()
#define permute(x) next_permutation(all(x))
#define gi(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int inv=int(1e9);
const int max_n=200;
int T;
int n,l;
string x;
vector<string> req,flow;

int main() {
	gi(T);
	for(int z=1;z<=T;z++) {
		gi(n); gi(l);
		flow.clear();
		req.clear();
		rep(i,n) {
			scanf(" ");
			cin>>x;
			flow.pb(x);
		}
		rep(i,n) {
			scanf(" ");
			cin>>x;
			req.pb(x);
		}
		sort(all(req));
		int ans=inv;
		rep(i,n) {
			vector<int> pos;
			rep(j,l) if(req[0][j]!=flow[i][j]) pos.pb(j);
			vector<string> tmp;
			rep(j,n) {
				tmp.pb(flow[j]);
				rep(k,(int)pos.size())
					tmp[j][pos[k]]^=1;
			}
			//printf("%d %d\n",i,(int)pos.size());
			sort(all(tmp));
			bool match=true;
			rep(j,n)
				if(req[j]!=tmp[j]) {
					match=false;
					break;
				}
			if(match) {
				ans=min(ans,(int)pos.size());
				//printf("%d %d\n",i,(int)pos.size());
			}
		}
		printf("Case #%d: ",z);
		if(ans<inv) printf("%d\n",ans);
		else printf("NOT POSSIBLE\n");
	}
	return 0;
}
