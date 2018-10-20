#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <cassert>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 1005


int N;
vector<int> adj[MAXN];
int fix[MAXN], tsz[MAXN];
void dfs(int x, int p){
	int sz = adj[x].size();
	int b = 0;
	tsz[x] = 0;
	vector<int> cc;
	REP(i,0,sz){
		int y = adj[x][i];
		if(y==p) continue;
		dfs(y, x);
		tsz[x] += tsz[y];
		cc.push_back( fix[y]-tsz[y] );
		b++;
	}
	if(b==0){
		fix[x] = 0;
	}else if(b==2){
		fix[x] = 0;
		REP(i,0,sz){
			int y = adj[x][i];
			if(y==p) continue;
			fix[x] += fix[y];
		}
	}else if(b==1){
		fix[x] = tsz[x];
	}else{
		sort(cc.begin(), cc.end());
		fix[x] = tsz[x] + cc[0] + cc[1]; 
	}
	tsz[x] += 1;
}
int main(){
	int cs;
	cin >> cs;
	REP(csn,1,cs+1){
		printf("Case #%d: ", csn);
		cin >> N;
		REP(i,0,N) adj[i].clear();

		REP(i,0,N-1){
			int a,b;
			cin >> a >> b;
			a--; b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int ans = INF;
		REP(r,0,N){
			dfs(r, -1);
			
			/*
			REP(i,0,N){
				printf("%d: sz%d fix%d\n", i, tsz[i], fix[i]);
			}
			puts("---");
			*/
			ans = min(ans, fix[r]);
		}
		printf("%d\n", ans);
		
	}
	return 0;
}