#include <bits/stdc++.h>
#define fr(i,a,b) for(int i = (a); i < (b); ++i)
#define pb push_back
#define eps 1e-7
#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;

int n, pd[1010][1010], mark[1010][1010], passo;
vector<int> lista[1010];

int go(int s, int p){
	if(mark[s][p] == passo) return pd[s][p];
	mark[s][p] = passo;
	if(lista[s].size() <= 2)
		return pd[s][p] = 1;
	
	int ans[3] = {0, 0, 0};
	fr(i, 0, lista[s].size()){
		if(lista[s][i] != p){
			ans[0] = go(lista[s][i], s);
			sort(ans, ans+3);
		}
	}
	
	return pd[s][p] = 1 + ans[1] + ans[2];
}

int solve(int r){
	if(lista[r].size() == 1)
		return 1;
	int ans[3] = {0, 0, 0};
	fr(i, 0, lista[r].size()){
		ans[0] = go(lista[r][i], r);
		sort(ans, ans+3);
	}	
	
	return 1+ans[1]+ans[2];
}

int main(){
	int t, caso = 1, a, b;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		fr(i, 0, n+1) lista[i].clear();
		fr(i, 0, n-1){
			scanf("%d%d", &a, &b);
			lista[a].push_back(b);
			lista[b].push_back(a);
		}
		
		passo++;
		int ans = 0;
		fr(i, 1, n+1){
			ans = max(ans, solve(i));
		}
		
		printf("Case #%d: %d\n", caso++, n-ans);		
	}
	return 0;
}

