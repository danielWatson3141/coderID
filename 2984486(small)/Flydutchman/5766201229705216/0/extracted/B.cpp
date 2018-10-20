#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007

int v[MaxN], next[MaxN], h[MaxN], tot;
void add(int b,int e) {
	v[++tot] = e; next[tot] = h[b]; h[b] = tot;
	v[++tot] = b; next[tot] = h[e]; h[e] = tot;
}

int vis[MaxN], f[MaxN];
void dfs(int now, int label) {
	vis[now] = label;
	f[now] = 1;
	vector<int> vv;
	for (int z = h[now]; z; z = next[z]) if (vis[v[z]] != label) {
		dfs(v[z],label);
		vv.push_back(f[v[z]]);
	}
	sort(vv.begin(),vv.end());
	if (vv.size() < 2) return ;
	reverse(vv.begin(), vv.end());
	f[now] += vv[0] + vv[1];
}

int n;
int main() {
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int T; cin >> T;
	For(TTT,1,T) {
		printf("Case #%d: ",TTT);
		cin >> n;
		Fill(h,tot = 0);
		For(i,1,n - 1) {
				int b,e;
			scanf("%d%d",&b,&e);
			add(b,e);
		}
		Fill(vis,0);
		int ans = 0;
		For(Root,1,n) {
			dfs(Root,Root);
			ans = max(ans,f[Root]);
		}
		cout << n - ans << endl;
	}
	return 0;
}

