#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;
typedef pair<int,int> ii;

#define INF 1000000000

int p[1010];
vector<int> raw[1010];
vector<int> children[1010];
int ch[1010];
int states[1010];

int T,N;

void root(int u){
	for(int i = 0; i < raw[u].size(); i++){
		int v = raw[u][i];
		if(v != p[u]){
			p[v] = u;
			children[u].push_back(v);
			root(v);
			ch[u] += ch[v];
		}
	}
	//cout << "children of " << u <<": " << ch[u] << endl;
}

int dp(int u){
	if(children[u].size() == 0 ) return 0;
	if(children[u].size() == 1) return ch[children[u][0]];
	
	int low1 = INF, low2 = INF;
	for(int i = 0; i < children[u].size(); i++){
		int v = children[u][i];
		int cur = dp(v) - ch[v];
		if(low1 > cur){
			low2 = low1;
			low1 = cur;
		}
		else if(low2 > cur){
			low2 = cur;
		}
	}
	return ch[u] + low1 + low2 - 1;
}
		
int main(){
	int i,j,k,t;
	cin >> T;
	for(t = 1; t<=T;t++){
		cout << "Case #" << t << ": ";
		cin >> N;
		
		//init
		for(i = 0; i < N + 1; i++ )raw[i].clear();
		
		
		for(i = 0; i < N -1; i++ ){
			int a,b;
			cin >> a >> b;
			raw[a].push_back(b);
			raw[b].push_back(a);
		}
		int best = INF;
		for(i = 1; i <= N; i++){
			fill(p, p + N + 1, -1);
			fill(ch, ch + N + 1, 1);
			for(j = 0; j < N + 1; j++ )children[j].clear();
			
			//cout<< "rooting " << i << endl;
			
			root(i);
			best = min(best, dp(i));
		}
		cout << best <<endl;
	}
}
		
		
			
