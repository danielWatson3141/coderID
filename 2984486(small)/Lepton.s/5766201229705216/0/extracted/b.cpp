#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <numeric>
using namespace std;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<25;
typedef pair<int,int> P;
typedef long long ll;
typedef unsigned long long ull;
#define MAX_N 1000

bool used[MAX_N];

int dfs(vector<vector<int> > &g, int u){
	used[u] = true;
	int res1,res2;
	res1 = res2 = 0;
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(used[v]) continue;
		res1 = max(res1,dfs(g,v));
		if(res1>res2) swap(res1,res2);
	}
	if(res1<1) return 1;
	else return res1+res2+1;
}

int main(){
	int T;
	cin>>T;
	for(int Case = 1; Case <= T; Case++){
		int N;
		cin>>N;
		vector<vector<int> > g(N);
		for(int i = 0; i < N-1; i++){
			int a,b;
			cin>>a>>b;
			a--;b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		int res = N-1;
		for(int i = 0; i < N; i++){
			memset(used,0,sizeof(used));
			res = min(res,N-dfs(g,i));
		}
		printf("Case #%d: %d\n",Case,res);
	}
	return 0;
}

