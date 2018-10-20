#include <bits/stdc++.h>
#define fr(i,a,b) for(int i = (a); i < (b); ++i)
#define pb push_back
#define eps 1e-7
#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;

int n, l, ord[160], ord2[160], z[50], u[50];
char mat[160][50], tar[160][50];

bool comp(int a, int b){
	return strcmp(mat[a], mat[b]) < 0;
}

bool comp2(int a, int b){
	return strcmp(tar[a], tar[b]) < 0;
}

int solve(int pos){
	if(pos == l){
		sort(ord, ord+n, comp);
	
		fr(i, 0, n){
			fr(j, 0, l){
				if(mat[ord[i]][j] != tar[ord2[i]][j]){
					return inf;
				}
			}
		}
		return 0;
	}
	int a = 0, b = 0;
	fr(i, 0, n){
		if(mat[i][pos] == '0') a++;
		else b++;
	}
	if(a != b){
		if(a == z[pos]) return solve(pos+1);
		if(a == u[pos]){
			fr(i, 0, n){
				if(mat[i][pos] == '0') mat[i][pos] = '1';
				else mat[i][pos] = '0';
			}
			int ans = 1+solve(pos+1);
			
			fr(i, 0, n){
				if(mat[i][pos] == '0') mat[i][pos] = '1';
				else mat[i][pos] = '0';
			}
			
			return ans;
		}
		return inf;
		
	}else{
		if(a != z[pos]) return inf;
		int ans = solve(pos+1);
		fr(i, 0, n){
			if(mat[i][pos] == '0') mat[i][pos] = '1';
			else mat[i][pos] = '0';
		}
		ans = min(ans, 1+solve(pos+1));
		fr(i, 0, n){
			if(mat[i][pos] == '0') mat[i][pos] = '1';
			else mat[i][pos] = '0';
		}
		
		return ans;
	}
}

int main(){
	int t, caso = 1;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &l);
		fr(i, 0, n) scanf("%s", mat[i]);
		fr(i, 0, n) scanf("%s", tar[i]);
		
		fr(i, 0, l){
			z[i] = 0;
			u[i] = 0;
			fr(j, 0, n){
				if(tar[j][i] == '0') z[i]++;
				else u[i]++;
			}
		}
		
		fr(i, 0, n){
			ord[i] = ord2[i] = i;
		}
		
		sort(ord2, ord2+n, comp2);
		
		int ans = solve(0);
		//cout << "->> " << ans << endl;
		if(ans > l){
			printf("Case #%d: NOT POSSIBLE\n", caso++);
		}else{
			printf("Case #%d: %d\n", caso++, ans);
		}
	}
	return 0;
}

