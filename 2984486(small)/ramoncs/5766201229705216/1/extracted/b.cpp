#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <bitset>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
const int INF = 2147483647;
//cout.setprecisiont(n)
//cout << fixed ;
//resetiosflags(ios::fixed) 
//std::cout << setfill ('x') << setw (n);

vvi tree(1010);
int memo_count[1010][1010];
int memo_solve[1010][1010];

int count_nodes( int root, int last ){
	int cont=0;
	if( memo_count[root][last]!=-1 ) return memo_count[root][last];
	//for(int u : tree[root]){
	for(int i=0; i<(int)tree[root].size(); i++){
		int u = tree[root][i];
		if(u!=last) cont += count_nodes(u,root);
	}
	return memo_count[root][last] = cont + 1;
}

int solve(int root, int last){
	int sz = tree[root].size();
	int cont = 0;

	if( memo_solve[root][last]!=-1) return memo_solve[root][last];
	//for(int u : tree[root]){
	for(int i=0; i<(int)tree[root].size(); i++){
		int u = tree[root][i];
		if(u != last) cont++;
	}
	int ret = INF;
	if(cont<=1){
		ret = count_nodes(root,last) - 1;
	}else{
		vector< pi > cand;
		//for(int u : tree[root]) if(u!=last){
		for(int i=0; i<(int)tree[root].size(); i++){
			int u = tree[root][i];
			if(u!=last)
				cand.push_back( pi(solve(u,root),u) );
		} 
		sort(all(cand));

		vi cnodes(cand.size());
		int sumsnodes=0;
		for(int i=0; i<(int)cand.size(); i++){
			cnodes[i] = count_nodes(cand[i].second,root);
			sumsnodes+=cnodes[i];
		}
		for(int i=0; i<(int)cand.size(); i++){			
			for(int j=i+1; j<(int)cand.size(); j++){
				int s = cand[i].first + cand[j].first + sumsnodes - cnodes[i] - cnodes[j];
				if(s<ret) ret = s;
			}
		}	
	}

	return memo_solve[root][last] = ret;
}

int main(){
	std::ios::sync_with_stdio(false);
	int n,t,a,b;
	cin >> t;
	for(int test=1; test<=t; test++){
		cin >> n;
		for(int i=0; i<=n; i++) tree[i].clear();
		for(int i=0; i<n-1; i++){
			cin >> a >> b;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
		int ans = INF;
		memset(memo_count,-1,sizeof memo_count);
		memset(memo_solve,-1,sizeof memo_solve);
		for(int i=1; i<=n; i++){
			ans = min(ans,solve(i,0));
		}
		cout << "Case #" << test << ": " << ans << "\n";
	}

	return 0;
}
