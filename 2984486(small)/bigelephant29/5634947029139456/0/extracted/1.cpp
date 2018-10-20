#include<cstdio>
#include<set>
using namespace std;
const int INF = 2147483647;
const int MINF = -INF;
const int MAXN = 150 + 10;
const int MAXL = 40 + 10;
int n, m;
int r1[MAXN];
int r2[MAXN];
char a1[MAXN][MAXL];
char a2[MAXN][MAXL];

multiset<int> s;

bool check(){
	s.clear();
	for(int i = 0 ; i < n ; i++)
		s.insert(r1[i]);
	for(int i = 0 ; i < n ; i++){
		multiset<int> :: iterator itr = s.find(r2[i]);
		if(itr == s.end()) return false;
		s.erase(itr);
	}
	return true;
}

int main(){
	int TN;
	scanf("%d", &TN);
	for(int casen = 1 ; casen <= TN ; casen++){
		scanf("%d %d", &n, &m);
		for(int i = 0 ; i < n ; i++){
			scanf("%s", a1[i]);
			int sum = 0;
			for(int j = 0 ; j < m ; j++){
				if(a1[i][j]=='1'){
					sum += 1<<j;
				}
			}
			r1[i] = sum;
		}
		for(int i = 0 ; i < n ; i++){
			scanf("%s", a2[i]);
			int sum = 0;
			for(int j = 0 ; j < m ; j++){
				if(a2[i][j]=='1'){
					sum += 1<<j;
				}
			}
			r2[i] = sum;
		}
		int ans = INF;
		for(int i = 0 ; i < (1<<m) ; i++){
			int cnt = 0;
			for(int j = 0 ; j < m ; j++)
				if(i&(1<<j)) cnt++;
			if(cnt >= ans) continue;
			for(int j = 0 ; j < n ; j++)
				r1[j] ^= i;
			if(check()) ans = min(ans, cnt);
			for(int j = 0 ; j < n ; j++)
				r1[j] ^= i;
		}
		printf("Case #%d: ", casen);
		if(ans==INF) puts("NOT POSSIBLE");
		else printf("%d\n", ans);
	}
	return 0;
}
