#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
using namespace std;

bool usd[200];
vector<int> pos[200][200];
string s[200];
string t[200];

void solve(){
	int n, l;
	scanf("%d%d",&n,&l);
	for( int i = 0; i < n; i++) cin >> s[i];
	for( int i = 0; i < n; i++) cin >> t[i];
	for( int i = 0; i < n; i++){
		for( int j = 0; j < n; j++){
			pos[i][j].clear();
		}
	}
	for( int i = 0; i < n; i++){
		for( int j = 0; j < n; j++){
			for( int k = 0; k < l; k++){
				if ( s[i][k] != t[j][k] ){
					pos[i][j].push_back(k);
				}
			}
		}
	}
	int w = 0, res = 1 << 30;
	while( w < n ){
			for( int i = 0; i < n; i++) usd[i] = 0;
			usd[w] = 1;
			for( int j = 1; j < n; j++){
				bool found = false;
				for( int k = 0; k < n; k++){
					if ( usd[k] ) continue;
					if ( pos[0][w].size() != pos[j][k].size()) continue;
					found = true;
					for( int e = 0; e < pos[j][k].size() ; e++){
						if (pos[0][w][e] != pos[j][k][e]) {
							found = false;
							break;
						}
					}
					if ( found ){
						usd[k] = 1;
						break;
					}
				}
				if ( !found )  goto hell;
			}
			res = min( res, (int)pos[0][w].size());
			hell:
			w++;
	}
	if ( res == 1 << 30 ) puts("NOT POSSIBLE");
	else printf("%d\n", res);
	

}

int main(){
	int runs;
	scanf("%d",&runs);
	for( int r = 1; r <= runs; r++){
		printf("Case #%d: ",r);
		solve();
	}


	return 0;
}
