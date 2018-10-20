#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

const int limit = 1000 + 5;
vector<int> a[limit];
int s[limit], f[limit];
int n;
const int maxn = (int)1e9 + 7;

void dfs(int i){
	vector<int> d;
//	if (s[i] > 0) return;
	s[i] = 1;
	for(int k = 0; k < a[i].size(); ++k) {
//		cout << i << " " << a[i][k] << endl;
		int j = a[i][k];
		if (s[j] != 0) continue;
		dfs(j);
		s[i] += s[j];
		d.push_back(f[j] - s[j]);
	}
	
	f[i] = s[i]-1;
	sort(d.begin(), d.end());
	if (d.size() >= 2) f[i] += d[0] + d[1];
//	cout << i << " " << f[i] << endl;
}

int main(){
	freopen("b.inp","r",stdin);
	freopen("b.out","w",stdout);
	int test;
	scanf("%d",&test);
	for(int T = 1; T <= test; ++T){
		printf("Case #%d: ",T);
		scanf("%d",&n);
		for(int i = 1; i <= n; ++i) a[i].clear();
		for(int k = 1; k < n; ++k){
			int i , j;
			scanf("%d%d",&i,&j);
			a[i].push_back(j);
			a[j].push_back(i);	
		}
		
		int kq = maxn;
		for(int i = 1; i <= n; ++i){
			for(int k = 1; k <= n; ++k) f[k] = 0, s[k] = 0;
			dfs(i);
			kq = min(kq , f[i]);
		}
		printf("%d\n",kq);
	}	
	
}
