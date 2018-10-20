#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char A[155][44], B[155][44];

bool f[44];
long long AA[155], BB[155];
int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++){
		int n, l, ans = 0x7fffffff;
		scanf("%d%d", &n, &l);
		memset(AA,0,sizeof(AA));
		memset(BB,0,sizeof(BB));

		for (int i = 0; i < n; i++){
			scanf("%s", &A[i]);
			for (int j = 0; j < l; j++)
				A[i][j] = A[i][j] - '0';
			for (int j = 0; j < l; j++){
				AA[i] <<=1;AA[i]|=A[i][j];
			}
		}
		sort(AA, AA + n);
		for (int i = 0; i < n; i++){
			scanf("%s", &B[i]);
			for (int j = 0; j < l; j++)
				B[i][j] = B[i][j] - '0';
		}
		for (int i = 0; i < n; i++){
			memset(f, 0, sizeof(f)); memset(BB,0,sizeof(BB)); int cnt = 0;
			for (int j = 0; j < l; j++){
				if (A[i][j] != B[0][j]){
					f[j] = true;
					cnt++;
				}
			}
			if (cnt >= ans)
				continue;
			for (int i = 0; i < n; i++){
				for (int j = 0; j < l; j++){
					BB[i] <<= 1; BB[i] |= (B[i][j] ^ f[j]);
				}
			}
			sort(BB, BB + n);
			bool ok = true;
			for (int i = 0; i < n; i++){
				if (BB[i] != AA[i]){
					ok = false;
					break;
				}
			}
			if (ok)
				ans = cnt;
		}
		if (ans != 0x7fffffff)
			printf("Case #%d: %d\n", cas, ans);
		else
			printf("Case #%d: NOT POSSIBLE\n", cas);
	}
}
