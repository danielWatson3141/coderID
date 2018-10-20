#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#define N 160
#define L 50
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, n, l, ans;
char d[N][L], c[N][L];
bool h[L];
map<string, int> m;

void solve(){
	scanf("%d %d", &n, &l);
	fi(i, 0, n) scanf("%s", c[i]);
	fi(i, 0, n) scanf("%s", d[i]);
	
	ans = l + 1;
	fi(i, 0, n){
		int cnt = 0;
		fi(j, 0, l)
			cnt += h[j] = d[0][j] != c[i][j];
		
		if(ans <= cnt) continue;
		
		m.clear();
		
		fi(j, 0, n){
			string temp(c[j]);
			fi(k, 0, l) if(h[k]) temp[k] = '0' + '1' - temp[k];
			m[temp]++;
		}
		
		fi(j, 0, n){
			string temp(d[j]);
			m[temp]--;
		}
		
		bool ok = 1;
		for(map<string, int>::iterator i = m.begin(); i != m.end(); i++)
			if(i->second) ok = 0;
			
		if(ok) ans = cnt;
	}
	
	if(ans == l + 1) puts("NOT POSSIBLE");
	else printf("%d\n", ans);
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		printf("Case #%d: ", z);
		solve();
	}
	scanf("\n");
}
