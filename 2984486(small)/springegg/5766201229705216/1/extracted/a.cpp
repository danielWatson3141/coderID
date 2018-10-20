#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <cmath>
#include <set>
#define maxl 1000000000
#define maxn 1010
#define maxs 150
using namespace std;

typedef long long ll;

bool visit[maxn];
int nxt[maxn*2],first[maxn],en[maxn*2],tot=0;

void tjb(int x,int y){
	nxt[++tot]=first[x];
	first[x]=tot;
	en[tot]=y;
}

int dfs(int s){
	visit[s]=true;
	int k=first[s],j;
	int best1 = -maxl, best2 = -maxl;
	while(k!=0){
		j=en[k];
		if(!visit[j]){
			int tmp = dfs(j);
			if(tmp > best1){
				best2 = best1;
				best1 = tmp;
			}else if(tmp > best2){
				best2 = tmp;
			}
		}
		k=nxt[k];
	}
	if(best2 == -maxl) return 1;
	return best1 + best2 + 1;
}

int n;

int did(int root){
	for(int i = 1; i <= n; ++i) visit[i] = false;
	return dfs(root);
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i) first[i] = 0;
	tot = 0;
	for(int i=1;i<n;++i){
		int x, y;
		cin >> x >> y;
		tjb(x,y);
		tjb(y,x);
	}
	int best = 0;
	for(int i = 1; i <= n; ++i){
		best = max(best, did(i));
	}
	cout << n - best << endl;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}