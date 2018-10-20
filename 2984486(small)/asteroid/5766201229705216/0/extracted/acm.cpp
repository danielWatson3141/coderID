#include "cstdio"
#include "cstring"
#include "cstdlib"
#include "cmath"
#include "cctype"
#include "ctime"
#include "vector"
#include "algorithm"
#include "sstream"
#include "set"
#include "map"
#include "stack"
#include "queue"
#include "bitset"
#include "iostream"
typedef long long LL;
using namespace std;

int N, L;
int ans;
vector<string>initial;
vector<string>required;


int main() {
	freopen("/Users/asteroid/Desktop/A-large.in","r",stdin);
	freopen("/Users/asteroid/Desktop/out","w",stdout);
	int T, cas = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &L);
		initial.clear();
		required.clear();
		for (int i = 0; i < N; i++) {
			char str[50];
			scanf("%s", str);
			initial.push_back( string(str) );
		}
		for (int i = 0; i < N; i++) {
			char str[50];
			scanf("%s", str);
			required.push_back( string(str) );
		}
		sort(required.begin(),required.end());
		vector<int>pos;
		ans = L + 1;
		for(int i = 0; i < N; i ++) {
			pos.clear();
			for(int j = 0;j < L;j++ ) {
				if(required[0][j] != initial[i][j]) {
					pos.push_back(j);
				}	
			}
			vector<string>v = initial;
			for(int j =0;j < N;j ++) {
				for(int k= 0;k<pos.size();k++) {
					int x = pos[k];
					if(v[j][x] == '0') {
						v[j].replace(x,1,"1",0,1);
					}else v[j].replace(x,1,"0",0,1);
				}
			}
			sort(v.begin(),v.end());
			bool flag = true;
			for(int j =0;j<N;j++) {
				if(v[j] != required[j]) {
					flag = false;
					break;
				}
			}
			if(flag) ans = min(ans,(int)pos.size());
		}
		printf("Case #%d: ",++cas);
		if(ans == L+1) puts("NOT POSSIBLE");
		else printf("%d\n",ans);
	}
	return 0;
}
